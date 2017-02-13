# MMS
#
# Copyright 2013-2016 IS2T. All rights reserved.
# Modification and distribution is permitted under certain conditions.
# IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.


# merge some sections
union $Label_MiscRuntime $Label_JavaRuntime $Label_JavaRuntime
union $Label_VMCore $Label_VMCore $Label_IceteaRuntime
union $Label_MicroUI $Label_MicroUI $Label_LIBDisplay
union $Label_MicroUI $Label_MicroUI $Label_LIBInput
union $Label_MicroUI $Label_MicroUI $Label_LIBPNG
union $Label_MicroUI $Label_MicroUI $Label_LIBBMPM


# Fix labels 
union VMDebugger $Label_VMDebugger $Label_VMDebugger
union VMConsole $Label_VMConsole $Label_VMConsole
union ApplicationStrings $Label_ApplicationStrings $Label_ApplicationStrings
union Statics $Label_Statics $Label_Statics
union LibFoundationEDC $Label_EDC $Label_EDC
union LibFoundationBON $Label_BON $Label_BON
union LibFoundationKF $Label_KF $Label_KF
union LibFoundationFS $Label_FS $Label_FS
union LibFoundationHAL $Label_HAL $Label_HAL
union LibFoundationSSL $Label_SSL $Label_SSL
union LibFoundationNET $Label_NET $Label_NET
union LibFoundationPAP $Label_PAP $Label_PAP
union LibFoundationECOM $Label_ECOM $Label_ECOM
union LibFoundationMicroUI $Label_MicroUI $Label_MicroUI
union LibFoundationMWT $Label_MWT $Label_MWT
union Domino $Label_Domino $Label_Domino
union LibFoundationNUM $Label_NUM $Label_NUM
union LibAddonNETExt $Label_NETEXT $Label_NETEXT
union LibAddonWidget $Label_Widget $Label_Widget
union LibAddonOSGiME $Label_OSGiME $Label_OSGiME
union LibFoundationNLS $Label_NLS $Label_NLS
union LibFoundationSP $Label_SP $Label_SP
union LibAddonStoryBoard $Label_StoryBoard $Label_StoryBoard
union Internet_Pack $Label_Internet_Pack $Label_Internet_Pack
union LibAddonLogging $Logging $Logging
union LibAddonComponents $Components $Components
union LibAddonMotion $Motion $Motion
union LibAddonGesture $Gesture $Gesture
union LibAddonFlowMWT $FlowMWT $FlowMWT
union LibAddonFlow $Flow $Flow
union LibAddonJSON $Label_JSON $Label_JSON
union LibAddonCBOR $Label_CBOR $Label_CBOR
union LibAddonMQTT $Label_Paho $Label_Paho
union LibAddonCoAP_Core $Label_Californium $Label_Californium
union LibAddonCoAP_Core_Connector_UDP $Label_Californium_Connector_UDP $Label_Californium_Connector_UDP
union LibAddonCoAP_Blockwise $Label_Californium_Blockwise $Label_Californium_Blockwise
union LibAddonCoAP_Observe $Label_Californium_Observe $Label_Californium_Observe
union LibAddonCoAP_Deduplication_Crop $Label_Californium_Deduplication_Crop $Label_Californium_Deduplication_Crop
union LibAddonCoAP_Deduplication_Sweep $Label_Californium_Deduplication_Sweep $Label_Californium_Deduplication_Sweep
union LibAddonLWM2M_Models $Label_Lwm2m_Models $Label_Lwm2m_Models
union LibAddonLWM2M_Impl_Californium $Label_Lwm2m_Californium $Label_Lwm2m_Californium
union LibAddonLWM2M_API $Label_Lwm2m_API $Label_Lwm2m_API
#union LibAddonHTTP $Label_HTTPClient $Label_HTTPClient
union TestSuite $TestSuite $TestSuite
union Drivers $Label_Drivers $Label_Drivers
union CoreEngineAllocator $Label_VMAllocator $Label_VMAllocator
union CoreEngine $Label_VMCore $Label_VMCore
union InstalledFeatures $Label_InstalledFeatures $Label_InstalledFeatures
union ApplicationFonts $Label_ApplicationFonts $Label_ApplicationFonts
union ApplicationImages $Label_ApplicationImages $Label_ApplicationImages
union ApplicationResources $Label_ApplicationResources $Label_ApplicationResources
union ApplicationImmutables $Label_ApplicationImmutables $Label_ApplicationImmutables
union ApplicationCode $Label_JavaApplication $Label_JavaApplication
union MiscRuntime $Label_MiscRuntime $Label_MiscRuntime
union BSP $Remaining $Remaining
union NativeMathFloatDouble $Label_LIBFloat $Label_LIBFloat
union NativeMathIntLong $Label_LIBInt $Label_LIBInt
union NativePrintfScanf $Label_PrintfScanf $Label_IceteaString
union NativeStackSSL $Label_NativeStackSSL $Label_NativeStackSSL
union NativeStackNET $Label_NativeStackNET $Label_NativeStackNET
union NativeStackFS $Label_NativeStackFS $Label_NativeStackFS
union NativeStackWIFI $Label_NativeStackWifi $Label_NativeStackWifi
union NativeStackWifiTICC3100 $Label_NativeStackWifiTICC3100 $Label_NativeStackWifiTICC3100
union NativeStackModem3G $Label_NativeStackModem3G $Label_NativeStackModem3G
union NativeStackUSB $Label_Usb $Label_Usb

union ClassesNames $Label_ClassesNames $Label_ClassesNames
union RTOS $Label_OS $Label_OS
union BSPMalloc $Label_BSP_Malloc $Label_BSP_Malloc

# Print results
totalImageSize All

echo
echo APPLICATION:
totalImageSize ApplicationCode
totalImageSize ApplicationFonts
totalImageSize ApplicationImages
totalImageSize ApplicationResources
totalImageSize ApplicationImmutables
totalImageSize ApplicationStrings
totalImageSize ClassesNames

echo
echo Java LIBRARIES:
totalImageSize LibFoundationEDC
totalImageSize LibFoundationBON
totalImageSize LibFoundationKF
totalImageSize LibFoundationFS
totalImageSize LibFoundationHAL
totalImageSize LibFoundationSSL
totalImageSize LibFoundationPAP
totalImageSize LibFoundationECOM
totalImageSize LibFoundationNET
totalImageSize LibFoundationMicroUI
totalImageSize LibFoundationMWT
totalImageSize LibFoundationNUM
totalImageSize LibAddonOSGiME
totalImageSize LibFoundationNLS
totalImageSize LibFoundationSP
totalImageSize LibAddonStoryBoard
totalImageSize LibAddonWidget
totalImageSize LibAddonLogging
totalImageSize LibAddonComponents
totalImageSize LibAddonMotion
totalImageSize LibAddonGesture
totalImageSize LibAddonFlowMWT
totalImageSize LibAddonFlow
totalImageSize TestSuite
totalImageSize InstalledFeatures


echo
echo MicroJvm LIBRARIES & RUNTIME:
totalImageSize CoreEngine
totalImageSize CoreEngineAllocator
totalImageSize VMConsole
totalImageSize VMDebugger
totalImageSize Drivers

echo
echo BSP
totalImageSize BSP
totalImageSize NativeStackSSL
totalImageSize NativeStackNET
totalImageSize NativeStackFS
totalImageSize NativeMathFloatDouble
totalImageSize NativeMathIntLong
totalImageSize NativePrintfScanf
totalImageSize RTOS

