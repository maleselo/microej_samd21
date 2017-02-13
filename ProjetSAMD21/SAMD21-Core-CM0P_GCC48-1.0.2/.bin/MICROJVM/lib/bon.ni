<!--
	Natives Interface
	
	Copyright 2011-2016 IS2T. All rights reserved.
	Modification and distribution is permitted under certain conditions.
	IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
-->
<nativesInterface>

	<nativesPool name="ist.mowana.vm.GenericNativesPool">
		<native name="com.is2t.bon.ImmutablesNatives.fillImmutableKeys(java.lang.String[])void"/>
		<native name="com.is2t.bon.ImmutablesNatives.get(java.lang.String)java.lang.Object"/>
		<native name="com.is2t.bon.ImmutablesNatives.getNbImmutableKeys()int"/>
		<native name="com.is2t.bon.ImmutablesNatives.isImmutable(java.lang.Object)boolean"/>
		<native name="com.is2t.bon.ImmutablesNatives.initialImmutableMemory()long"/>
		<native name="ej.bon.Immortals.isImmortal(java.lang.Object)boolean"/>
		<native name="ej.bon.Immortals.totalMemory()long"/>
		<native name="ej.bon.Immortals.freeMemory()long"/>
		<native name="ej.bon.Immortals.setImmortal(java.lang.Object)java.lang.Object"/>
		<native name="ej.bon.Immortals.switchAllocationIntoImmortals(boolean)void"/>
	</nativesPool>
	
	<nativesPool name="com.is2t.bon.Bon12NativesPool">
		<native name="ej.bon.Util.throwExceptionInThread(java.lang.RuntimeException,java.lang.Thread,boolean)void"/>
		<native name="ej.bon.Util.isInInitialization()boolean"/>
		<native name="ej.bon.CurrentTime.get(boolean)long"/>
		<native name="ej.bon.CurrentTime.getNanos()long"/>
		<native name="ej.bon.CurrentTime.set(long)void"/>
		<native name="ej.bon.XMath.acos(double)double"/>
		<native name="ej.bon.XMath.asin(double)double"/>
		<native name="ej.bon.XMath.atan(double)double"/>
		<native name="ej.bon.XMath.log(double)double"/>
		<native name="ej.bon.XMath.exp(double)double"/>
		<native name="ej.bon.XMath.pow(double,double)double"/>
		<native name="ej.bon.ByteArray.isBigEndian()boolean"/>
		<native name="ej.bon.ByteArray.clear(byte[],int,int)void"/>
		<native name="ej.bon.ByteArray.set(byte[],byte,int,int)void"/>
	</nativesPool>
	
	<nativeRequirements name="ej.bon.ImmutablesBlock.initialize()void">
		<type name="ej.bon.ImmutablesError"/>
	</nativeRequirements>
	<nativeRequirements name="ej.bon.ImmutablesBlock.erase(ej.bon.ImmutablesBlock[])void">
		<type name="ej.bon.ImmutablesError"/>
	</nativeRequirements>
	<nativeRequirements name="ej.bon.ImmutablesTable.writeBuffer(int,int,byte[])void">
		<type name="ej.bon.ImmutablesError"/>
	</nativeRequirements>
	
</nativesInterface>