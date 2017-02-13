<!--
	Natives Interface
	
	Copyright 2014-2016 IS2T. All rights reserved.
	Modification and distribution is permitted under certain conditions.
	IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
-->
<nativesInterface>

	<nativesPool name="ist.mowana.vm.GenericNativesPool">
		<native name="java.lang.ref.ReferenceQueue.enqueue(java.lang.ref.Reference)boolean"/>
		<native name="java.lang.ref.ReferenceQueue.poll(java.lang.ref.ReferenceQueue)java.lang.ref.Reference"/>
		<native name="java.lang.ref.ReferenceQueue.waitForReference(long)void"/>
		<native name="java.lang.Thread.interrupted()boolean"/>
		<native name="java.lang.Thread.isInterrupted()boolean"/>
		<native name="java.lang.Class.getSuperclass()java.lang.Class"/>
		<native name="java.lang.StackTraceElement.getLineNumber(int,int)int"/>
		<native name="java.lang.StackTraceElement.getMethodNameLength(int)int"/>
		<native name="java.lang.StackTraceElement.fillWithMethodName(int,char[])int"/>
		<native name="java.lang.System.nanoTime()long"/>
		<native name="java.lang.Thread.getStateNative()int"/>
		<native name="java.lang.ref.SoftReference.getTimestamp()long"/>
	</nativesPool>
	
	<nativesPool name="ist.microjvm.NativesPool">
		<native name="java.lang.Double.doubleToRawLongBits(double)long"/>
		<native name="java.lang.Float.floatToRawIntBits(float)int"/>
		<native name="java.lang.Thread.enumerate(java.lang.Thread[])int"/>
		<native name="java.lang.Thread.holdsLock(java.lang.Object)boolean"/>
		<native name="java.lang.Math.acos(double)double"/>
		<native name="java.lang.Math.asin(double)double"/>
		<native name="java.lang.Math.atan(double)double"/>
		<native name="java.lang.Math.atan2(double,double)double"/>
		<native name="java.lang.Math.cbrt(double)double"/>
		<native name="java.lang.Math.copySignD(double,double)double"/>
		<native name="java.lang.Math.copySignF(float,float)float"/>
		<native name="java.lang.Math.cosh(double)double"/>
		<native name="java.lang.Math.exp(double)double"/>
		<native name="java.lang.Math.expm1(double)double"/>
		<native name="java.lang.Math.hypot(double,double)double"/>
		<native name="java.lang.Math.IEEEremainder(double,double)double"/>
		<native name="java.lang.Math.log(double)double"/>
		<native name="java.lang.Math.log10(double)double"/>
		<native name="java.lang.Math.log1p(double)double"/>
		<native name="java.lang.Math.nextAfterD(double,double)double"/>
		<native name="java.lang.Math.nextAfterF(float,double)float"/>
		<native name="java.lang.Math.pow(double,double)double"/>
		<native name="java.lang.Math.rint(double)double"/>
		<native name="java.lang.Math.scalbD(double,int)double"/>
		<native name="java.lang.Math.scalbF(float,int)float"/>
		<native name="java.lang.Math.sinh(double)double"/>
		<native name="java.lang.Math.tanh(double)double"/>
	</nativesPool>
	
</nativesInterface>