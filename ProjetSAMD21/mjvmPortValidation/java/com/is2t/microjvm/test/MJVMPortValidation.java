/*
 * Java
 *
 * Copyright 2013-2016 IS2T. All rights reserved.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
package com.is2t.microjvm.test;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;

import com.is2t.testsuite.support.CheckHelper;

import ej.bon.Immortals;
import ej.bon.Immutables;
import ej.bon.Util;

/**
 * Tests for MicroJvm ports. Before releasing a MicroJvm, TCK should be:
 * <ul>
 * <li>caffeineMark results should be similar to caffeineMark results without RTOS</li>
 * <li>this test must pass</li>
 * </ul>
 * Test features:
 * <ul>
 * <li>FPU</li>
 * <li>Read Only Memory</li>
 * <li>Visible clock</li>
 * <li>Time</li>
 * <li>Monotonic Time</li>
 * <li>Java Round robin</li>
 * </ul>
 */
public class MJVMPortValidation {
	public static final String VERSION = "2.2.3";

	static Class THIS_CLASS = MJVMPortValidation.class;

	// Time constants
	public static final int MAX_SLEEP_DELTA = 10;

	// Round Robin constants
	public static final int NB_THREADS = 4;
	public static final int MAX_STABILIZATION_LOOP = 1000000;
	public static final int MAX_STABILIZATION_DELTA_PER10000 = 50;
	public static final int MIN_STABILIZATION_NBLOOPS = 1000;

	public static volatile boolean ROUND_ROBIN_IS_RUNNING;
	public static Object ROUND_ROBIN_LOCK = new Object();
	public static int[] ROUND_ROBIN_TASK_COUNTERS;

	public static void main(String[] args) {
		printProduct();

		checkVisibleClock();
		System.out.println();
		checkTime();		
		System.out.println();
		checkFPU();
		System.out.println();
		checkIsInReadOnlyMemory();
		System.out.println();
		checkMonotonicTime();
		System.out.println();
		checkJavaRoundRobin();

		CheckHelper.endCheck(THIS_CLASS);
	}

	private static void printProduct() {
		final String sep = "*************************************************************************";
		System.out.println(sep);
		System.out.println("*                    LLMJVM Port Validation - " + VERSION + "                     *");
		System.out.println(sep);
		System.out.println("* Copyright 2013-2016 IS2T. All rights reserved.                             *");
		System.out.println("* Modification and distribution is permitted under certain conditions.  *");
		System.out.println("* IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.       *");
		System.out.println(sep);
		System.out.println();
	}

	public static void checkVisibleClock() {
		System.out.println("-> Check visible clock (LLMJVM_IMPL_getCurrentTime validation)...");
		// Check if a message is printed every seconds in terminal:
		long timeStart = System.currentTimeMillis();
		int seconds = 0;
		while (true) {
			long time = System.currentTimeMillis();
			long delta = time - timeStart;
			int newSecond = (int) (delta / 1000);
			if (newSecond > seconds) {
				System.out.println(newSecond);
				seconds = newSecond;
			}

			if (delta > 10000) {
				break; // end of test
			}
		}

		// ensure both API returns same value
		long timeEnd1 = System.currentTimeMillis();
		long timeEnd2 = Util.platformTimeMillis();
		long delta = timeEnd2 - timeEnd1;
		CheckHelper.check(THIS_CLASS, "Util.platformTimeMillis() != System.currentTimeMillis()" + MAX_SLEEP_DELTA, delta <= MAX_SLEEP_DELTA);

		// ensure nano time is valid
		delta = (Util.platformTimeNanos()/1000000) - Util.platformTimeMillis();
		CheckHelper.check(THIS_CLASS, "Util.platformTimeNanos()/1000000 != Util.platformTimeMillis()" + MAX_SLEEP_DELTA, delta <= MAX_SLEEP_DELTA);
	}

	public static void checkTime() {
		System.out.println("-> Check schedule request and wakeup (LLMJVM_IMPL_scheduleRequest and LLMJVM_IMPL_wakeupVM validation)...");
		long delay = 5 * 1000;
		System.out.println("Waiting for " + delay / 1000 + "s...");
		long timeBefore = System.currentTimeMillis();
		try {
			Thread.sleep(delay);
		} catch (InterruptedException e) {
			throw new Error();
		}
		long timeAfter = System.currentTimeMillis();
		System.out.println("...done");
		long realDelay = timeAfter - timeBefore;
		CheckHelper.check(THIS_CLASS, "realDelay>=delay", realDelay >= delay);
		long delta = realDelay - delay;
		CheckHelper.check(THIS_CLASS, "delta(=" + delta + ")<=" + MAX_SLEEP_DELTA, delta <= MAX_SLEEP_DELTA);
	}

	public static void checkMonotonicTime() {
		System.out.println(
				"-> Check monotonic time (LLMJVM_IMPL_getCurrentTime, LLMJVM_IMPL_setApplicationTime validation)...");
		long delay = 5 * 1000;
		long elapsedTime = 100;
		long timeOffset = 50_000;
		System.out.println("Waiting for " + delay / 1000 + "s...");
		long monotonicTimeBefore = Util.platformTimeMillis();
		Util.setCurrentTimeMillis(System.currentTimeMillis() + timeOffset);

		try {
			Thread.sleep(delay);
		} catch (InterruptedException e) {
			throw new Error();
		}
		long montonicTimeAfter = Util.platformTimeMillis();
		System.out.println("...done");
		CheckHelper.check(THIS_CLASS, "monotonic time not set", montonicTimeAfter >= monotonicTimeBefore + delay
				&& montonicTimeAfter <= monotonicTimeBefore + delay + elapsedTime);
	}

	public static void checkJavaRoundRobin() {
		System.out.println("-> Check Java round robin (LLMJVM_IMPL_scheduleRequest validation)...");
		int nbThreads = NB_THREADS;
		CheckHelper.check(THIS_CLASS, "nbThreads >= 2", nbThreads >= 2);

		ROUND_ROBIN_TASK_COUNTERS = new int[nbThreads];
		int priority = Thread.currentThread().getPriority();
		Thread[] threads = new Thread[nbThreads];
		for (int i = threads.length; --i >= 0;) {
			Thread t = new Thread(new Task(i));
			threads[i] = t;
			t.setPriority(priority);
			t.start();
		}

		// Poll until all threads are waiting on the monitor
		while (Task.COUNTER < NB_THREADS) {
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		System.out.println("Starting tasks...");
		synchronized (ROUND_ROBIN_LOCK) {
			ROUND_ROBIN_IS_RUNNING = true;
			ROUND_ROBIN_LOCK.notifyAll(); // start !
		}

		// check delta between threads - delta shall be stabilized if round robin occur
		int maxDelta = 0;
		int maxDeltaLoopCount = 0;
		for (int loop = -1; ++loop < MAX_STABILIZATION_LOOP;) {
			for (int i = threads.length - 1; --i >= 0;) {
				int delta = Math.abs(ROUND_ROBIN_TASK_COUNTERS[i + 1] - ROUND_ROBIN_TASK_COUNTERS[i]);
				if (delta > maxDelta) {
					maxDelta = delta;
					maxDeltaLoopCount = loop;
				}
			}
		}
		System.out.println("...done. Stopping tasks...");

		// stop threads
		ROUND_ROBIN_IS_RUNNING = false;
		for (int i = threads.length; --i >= 0;) {
			try {
				threads[i].join();
			} catch (InterruptedException e) {
				throw new Error();
			}
		}
		System.out.println("...done.");

		int maxResult = 0;
		for (int i = threads.length; --i >= 0;) {
			int v = ROUND_ROBIN_TASK_COUNTERS[i];
			if (v > maxResult) {
				maxResult = v;
			}
		}

		CheckHelper.check(THIS_CLASS, "maxResults(=" + maxResult + ")>0)", maxResult > 0);

		System.out.println("MAX DELTA = " + maxDelta + ", at " + maxDeltaLoopCount + " loops");

		// consider Round Robin is good if:
		// - it has been stabilized before N last loops / and delta
		CheckHelper.check(THIS_CLASS, "maxDeltaLoopCount=" + maxDeltaLoopCount,
				maxDeltaLoopCount < MAX_STABILIZATION_LOOP - MIN_STABILIZATION_NBLOOPS);
		// - delta is lower than a threshold
		int delta10000 = ((maxDelta * 10000) / maxResult);
		CheckHelper.check(THIS_CLASS, "deltaPer10000=" + delta10000, delta10000 < MAX_STABILIZATION_DELTA_PER10000);
	}

	public static void checkIsInReadOnlyMemory() {
		System.out.println("-> Check isInReadOnlyMemory (LLBSP_IMPL_isInReadOnlyMemory validation)...");

		try {
			String s = "literal string";
			synchronized (s) {
				System.out.println("Test synchronize on literal string");
			}
		} catch (IllegalMonitorStateException e) {
			CheckHelper.check(THIS_CLASS,
					"IllegalMonitorStateException during synchronization on immutable object (literal string)", false);
		}

		try {
			synchronized (MJVMPortValidation.class) {
				System.out.println("Test synchronize on class");
			}
		} catch (IllegalMonitorStateException e) {
			CheckHelper.check(THIS_CLASS,
					"IllegalMonitorStateException during synchronization on immutable object (class)", false);
		}

		/*
		 * There is a limit of the number of the synchronized monitors in flash but not in ram. We test this limit is
		 * reached for the objects in flash but not for the objects in ram. If the LLBSP_IMPL_isInReadOnlyMemory
		 * function is not correctly implemented this test can highlight it.
		 */
		System.out.println("Test multiple synchronize");
		tryToSynchronizeOn(objectsFromRam(), false);
		tryToSynchronizeOn(stringsFromImmutables(), true);
		tryToSynchronizeOn(classes(), true);
		tryToSynchronizeOn(objectsFromImmortals(), false);
		tryToSynchronizeOn(objectsFromImmutables(), true);
	}

	private static void tryToSynchronizeOn(List<Object[]> objects, boolean mustFail) {
		MonitorKeeper.errorCount = 0;
		Thread[] threads = new Thread[MonitorKeeper.THREAD_COUNT];

		try {
			for (int i = 0; i < threads.length; i++) {
				threads[i] = new Thread(new MonitorKeeper(objects.get(i)));
			}

			for (Thread thread : threads) {
				thread.start();
			}

			for (Thread thread : threads) {
				try {
					thread.join();
				} catch (InterruptedException e) {
				}
			}

			boolean success;
			if (mustFail) {
				success = MonitorKeeper.errorCount > 0;
			} else {
				success = MonitorKeeper.errorCount == 0;
			}
			CheckHelper.check(THIS_CLASS, "too many synchronized monitors", success);
		} catch (IndexOutOfBoundsException ioobe) {
			CheckHelper.check(THIS_CLASS, "No objects to synchronize on, aborting.", false);
		}
	}

	private static List<Object[]> objectsFromRam() {
		List<Object[]> objects = new ArrayList<>();

		for (int i = 0; i < MonitorKeeper.THREAD_COUNT; i++) {
			Object[] objects2 = new Object[MonitorKeeper.MONITOR_PER_THREAD_COUNT];
			for (int j = 0; j < objects2.length; j++) {
				objects2[j] = new Object();
			}
			objects.add(objects2);
		}

		return objects;
	}

	private static List<Object[]> objectsFromImmortals() {
		List<Object[]> objects = new ArrayList<>();

		for (int i = 0; i < MonitorKeeper.THREAD_COUNT; i++) {
			Object[] objects2 = new Object[MonitorKeeper.MONITOR_PER_THREAD_COUNT];
			for (int j = 0; j < objects2.length; j++) {
				Object object = new Object();
				Immortals.setImmortal(object);
				objects2[j] = object;
			}
			objects.add(objects2);
		}

		return objects;
	}

	private static List<Object[]> objectsFromImmutables() {
		List<Object[]> objects = new ArrayList<>();
		int objectID = 0;

		try {
			for (int i = 0; i < MonitorKeeper.THREAD_COUNT; i++) {
				Object[] objects2 = new Object[MonitorKeeper.MONITOR_PER_THREAD_COUNT];
				for (int j = 0; j < objects2.length; j++) {
					Object object = Immutables.get("array" + objectID++);
					objects2[j] = object;
				}
				objects.add(objects2);
			}
		} catch (NoSuchElementException nsee) {
			System.out.println("Can't find the requested object in the immutables, check your configuration.");
		}

		return objects;
	}

	private static List<Object[]> stringsFromImmutables() {
		List<Object[]> objects = new ArrayList<>();

		objects.add(new String[] { "0", "1", "2", "3", "4", "5", "6" });
		objects.add(new String[] { "7", "8", "9", "10", "11", "12", "13" });
		objects.add(new String[] { "14", "15", "16", "17", "18", "19", "20" });
		objects.add(new String[] { "21", "22", "23", "24", "25", "26", "27" });
		objects.add(new String[] { "28", "29", "30", "31", "32", "33", "34" });

		return objects;
	}

	private static List<Object[]> classes() {
		List<Object[]> objects = new ArrayList<>();

		objects.add(new Class[] { Integer.class, Boolean.class, Long.class, Float.class, Double.class, Thread.class,
				Object.class });
		objects.add(new Class[] { Byte.class, Character.class, Calendar.class, ArrayList.class, List.class, Class.class,
				Exception.class });
		objects.add(new Class[] { InputStream.class, OutputStream.class, Map.class, HashMap.class, Hashtable.class,
				Reader.class, Writer.class });
		objects.add(new Class[] { Number.class, Throwable.class, String.class, Short.class, Enum.class, Runtime.class,
				Package.class });
		objects.add(new Class[] { System.class, Math.class, StringBuilder.class, StringBuffer.class, Runnable.class,
				Iterable.class, Iterator.class });

		return objects;
	}

	public static void checkFPU() {
		System.out.println("-> Check FPU (soft/hard FP option)...");
		System.out.println("In BSP, write and compile the following functions:");
		System.out.println("--------------------");
		System.out.println("#include \"sni.h\"");
		System.out.println(
				"jfloat Java_com_is2t_microjvm_test_MJVMPortValidation_testFPU__FF (jfloat a, jfloat b) {return a * b;}");
		System.out.println(
				"jdouble Java_com_is2t_microjvm_test_MJVMPortValidation_testFPU__DD (jdouble a, jdouble b) {return a * b;}");
		System.out.println("--------------------");
		CheckHelper.check(THIS_CLASS,
				"test 'float * float' in Java: FPU option is not coherent between MicroEJ Platform and BSP",
				(int) testFPUJava(3, 4), 12);
		CheckHelper.check(THIS_CLASS,
				"test 'double * double' in Java: FPU option is not coherent between MicroEJ Platform and BSP",
				(int) testFPUJava((double) 3, (double) 4), 12);
		CheckHelper.check(THIS_CLASS,
				"test 'float * float' in C: FPU option is not coherent between MicroEJ Platform and BSP",
				(int) testFPU(3, 4), 12);
		CheckHelper.check(THIS_CLASS,
				"test 'double * double' in C: FPU option is not coherent between MicroEJ Platform and BSP",
				(int) testFPU((double) 3, (double) 4), 12);
	}

	static native float testFPU(float a, float b);

	static native double testFPU(double a, double b);

	static float testFPUJava(float a, float b) {
		return a * b;
	}

	static double testFPUJava(double a, double b) {
		return a * b;
	}
}

// Synchronizes on a list of monitors and sleeps for a while.
class MonitorKeeper implements Runnable {
	static final int THREAD_COUNT = 5;
	static final int MONITOR_PER_THREAD_COUNT = 7;
	static final int SLEEP_TIME = 5_000;
	static int errorCount;

	private final Object[] monitors;

	public MonitorKeeper(Object[] monitors) {
		this.monitors = monitors;
	}

	@Override
	public void run() {
		try {
			synchronizeAll(0);
		} catch (Error e) {
			errorCount++;
		}
	}

	private void synchronizeAll(int monitorIndex) {
		if (monitorIndex < this.monitors.length) {
			synchronized (this.monitors[monitorIndex]) {
				synchronizeAll(monitorIndex + 1);
			}
		} else {
			try {
				Thread.sleep(SLEEP_TIME);
			} catch (InterruptedException e) {
			}
		}
	}
}

class Task implements Runnable {

	public static int COUNTER = 0;

	private final int id;

	public Task(int id) {
		this.id = id;
	}

	@Override
	public void run() {
		synchronized (MJVMPortValidation.ROUND_ROBIN_LOCK) {
			if (!MJVMPortValidation.ROUND_ROBIN_IS_RUNNING) {
				++COUNTER;
				System.out.println("Task " + this.id + "is waiting for start...");
				try {
					MJVMPortValidation.ROUND_ROBIN_LOCK.wait();
				} catch (InterruptedException e) {
					throw new Error();
				}
			}
		}
		System.out.println("Task " + this.id + " starts.");
		while (MJVMPortValidation.ROUND_ROBIN_IS_RUNNING) {
			++MJVMPortValidation.ROUND_ROBIN_TASK_COUNTERS[this.id];
		}
		System.out.println("Task " + this.id + " ends.");
	}
}