<!--
	Natives Interface
	
	Copyright 2016 IS2T. All rights reserved.
	Modification and distribution is permitted under certain conditions.
	IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
-->
<nativesInterface>

	<nativesPool name="com.is2t.microjvm.watchdog.WatchdogNativePool">
		<native name="ej.lang.WatchdogNativeSupport.supportEnabled()boolean"/>
		
		<native name="ej.lang.WatchdogNativeSupport.claimWatchdog(int)int"/>
		<native name="ej.lang.WatchdogNativeSupport.startWatchdog(int,int,long,java.lang.Object)void"/>
		<native name="ej.lang.WatchdogNativeSupport.claimAndStartWatchdog(int,long,java.lang.Object)int"/>
		<native name="ej.lang.WatchdogNativeSupport.cancelWatchdog(int,int)void"/>
		
		<native name="ej.lang.WatchdogNativeSupport.registerContextHandlerThreads()void"/>
		<native name="ej.lang.WatchdogNativeSupport.getNextContext()java.lang.Object"/>
		<native name="ej.lang.WatchdogNativeSupport.pauseContextHandlerThread()void"/>
	</nativesPool>
	
</nativesInterface>