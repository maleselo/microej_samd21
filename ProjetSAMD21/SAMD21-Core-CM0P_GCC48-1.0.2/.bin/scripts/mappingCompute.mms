# MMS
#
# Copyright 2009-2016 IS2T. All rights reserved.
# Modification and distribution is permitted under certain conditions.
# IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.


# This script remove symbols defined in several graphs in order that each symbol and section are defined
# in only one graph.

# "$Computed" graph contains all symbols that have already been added in another graph
union $Computed $Label_VMDebugger $Label_VMDebugger
union $Computed $Computed $Label_VMConsole
union $Computed $Computed $Label_ApplicationStrings
union $Computed $Computed $Label_Statics

# Java Runtime
# must be the first one to contain .bss.soar.* sections
substract $Label_JavaRuntime $Label_JavaRuntime $Computed
union $Computed $Computed $Label_JavaRuntime

# Logging
# must be before EDC_BON to contain java_util.* symbols
substract $Logging $Logging $Computed
union $Computed $Computed $Logging

# EDC
substract $Label_EDC $Label_EDC $Computed
union $Computed $Computed $Label_EDC

# B-ON
substract $Label_BON $Label_BON $Computed
union $Computed $Computed $Label_BON

# PAP
substract $Label_PAP $Label_PAP $Computed
union $Computed $Computed $Label_PAP

# KF
substract $Label_KF $Label_KF $Computed
union $Computed $Computed $Label_KF

# FS
substract $Label_FS $Label_FS $Computed
union $Computed $Computed $Label_FS

# NET
substract $Label_NET $Label_NET $Computed
union $Computed $Computed $Label_NET

# NET EXT
substract $Label_NETEXT $Label_NETEXT $Computed
union $Computed $Computed $Label_NETEXT

# HAL
substract $Label_HAL $Label_HAL $Computed
union $Computed $Computed $Label_HAL

# SSL
substract $Label_SSL $Label_SSL $Computed
union $Computed $Computed $Label_SSL

# ECOM
substract $Label_ECOM $Label_ECOM $Computed
union $Computed $Computed $Label_ECOM

# MicroUI
substract $Label_MicroUI $Label_MicroUI $Computed
union $Computed $Computed $Label_MicroUI

# Widgets
substract $Label_Widget $Label_Widget $Computed
union $Computed $Computed $Label_Widget

# MWT
substract $Label_MWT $Label_MWT $Computed
union $Computed $Computed $Label_MWT

# Domino
substract $Label_Domino $Label_Domino $Computed
union $Computed $Computed $Label_Domino

# NUM
substract $Label_NUM $Label_NUM $Computed
union $Computed $Computed $Label_NUM

# OSGiME
substract $Label_OSGiME $Label_OSGiME $Computed
union $Computed $Computed $Label_OSGiME

# NLS
substract $Label_NLS $Label_NLS $Computed
union $Computed $Computed $Label_NLS

# SP
substract $Label_SP $Label_SP $Computed
union $Computed $Computed $Label_SP

# StoryBoard
substract $Label_StoryBoard $Label_StoryBoard $Computed
union $Computed $Computed $Label_StoryBoard

# Internet Pack
substract $Label_Internet_Pack $Label_Internet_Pack $Computed
union $Computed $Computed $Label_Internet_Pack

# Components
substract $Components $Components $Computed
union $Computed $Computed $Components

# Motion
substract $Motion $Motion $Computed
union $Computed $Computed $Motion

# Gesture
substract $Gesture $Gesture $Computed
union $Computed $Computed $Gesture

# FlowMWT
# must be before Flow to contain its symbols
substract $FlowMWT $FlowMWT $Computed
union $Computed $Computed $FlowMWT

# Flow
substract $Flow $Flow $Computed
union $Computed $Computed $Flow

# JSON
substract $Label_JSON $Label_JSON $Computed
union $Computed $Computed $Label_JSON

# CBOR
substract $Label_CBOR $Label_CBOR $Computed
union $Computed $Computed $Label_CBOR

# MQTT
substract $Label_Paho $Label_Paho $Computed
union $Computed $Computed $Label_Paho

# CoAP
substract $Label_Californium_Blockwise $Label_Californium_Blockwise $Computed
union $Computed $Computed $Label_Californium_Blockwise
substract $Label_Californium_Observe $Label_Californium_Observe $Computed
union $Computed $Computed $Label_Californium_Observe
substract $Label_Californium_Deduplication_Crop $Label_Californium_Deduplication_Crop $Computed
union $Computed $Computed $Label_Californium_Deduplication_Crop
substract $Label_Californium_Deduplication_Sweep $Label_Californium_Deduplication_Sweep $Computed
union $Computed $Computed $Label_Californium_Deduplication_Sweep
substract $Label_Californium_Connector_UDP $Label_Californium_Connector_UDP $Computed
union $Computed $Computed $Label_Californium_Connector_UDP
substract $Label_Californium $Label_Californium $Computed
union $Computed $Computed $Label_Californium

# LWM2M
substract $Label_Lwm2m_Californium $Label_Lwm2m_Californium $Computed
union $Computed $Computed $Label_Lwm2m_Californium
substract $Label_Lwm2m_Models $Label_Lwm2m_Models $Computed
union $Computed $Computed $Label_Lwm2m_Models
substract $Label_Lwm2m_API $Label_Lwm2m_API $Computed
union $Computed $Computed $Label_Lwm2m_API


substract LibAddonEclasspath_URLUTIL LibAddonEclasspath_URLUTIL $Computed
union $Computed $Computed LibAddonEclasspath_URLUTIL
substract LibAddonEclasspath_URL LibAddonEclasspath_URL $Computed
union $Computed $Computed LibAddonEclasspath_URL
substract LibAddonEclasspath_URI LibAddonEclasspath_URI $Computed
union $Computed $Computed LibAddonEclasspath_URI
substract LibAddonEclasspath_STRINGTOKENIZER LibAddonEclasspath_STRINGTOKENIZER $Computed
union $Computed $Computed LibAddonEclasspath_STRINGTOKENIZER
substract LibAddonEclasspath_SOCKETFACTORY LibAddonEclasspath_SOCKETFACTORY $Computed
union $Computed $Computed LibAddonEclasspath_SOCKETFACTORY
substract LibAddonEclasspath_QUEUES LibAddonEclasspath_QUEUES $Computed
union $Computed $Computed LibAddonEclasspath_QUEUES
substract LibAddonEclasspath_PROPERTIES LibAddonEclasspath_PROPERTIES $Computed
union $Computed $Computed LibAddonEclasspath_PROPERTIES
substract LibAddonEclasspath_PRINTWRITER LibAddonEclasspath_PRINTWRITER $Computed
union $Computed $Computed LibAddonEclasspath_PRINTWRITER
substract LibAddonEclasspath_PIPEDSTREAMS LibAddonEclasspath_PIPEDSTREAMS $Computed
union $Computed $Computed LibAddonEclasspath_PIPEDSTREAMS
substract LibAddonEclasspath_MAPS LibAddonEclasspath_MAPS $Computed
union $Computed $Computed LibAddonEclasspath_MAPS
substract LibAddonEclasspath_LOGGING LibAddonEclasspath_LOGGING $Computed
union $Computed $Computed LibAddonEclasspath_LOGGING
substract LibAddonEclasspath_LISTS LibAddonEclasspath_LISTS $Computed
union $Computed $Computed LibAddonEclasspath_LISTS
substract LibAddonEclasspath_HTTPSCLIENT LibAddonEclasspath_HTTPSCLIENT $Computed
union $Computed $Computed LibAddonEclasspath_HTTPSCLIENT
substract LibAddonEclasspath_HTTPCLIENT LibAddonEclasspath_HTTPCLIENT $Computed
union $Computed $Computed LibAddonEclasspath_HTTPCLIENT
substract LibAddonEclasspath_EXECUTOR LibAddonEclasspath_EXECUTOR $Computed
union $Computed $Computed LibAddonEclasspath_EXECUTOR
substract LibAddonEclasspath_COLLECTIONSUTIL LibAddonEclasspath_COLLECTIONSUTIL $Computed
union $Computed $Computed LibAddonEclasspath_COLLECTIONSUTIL
substract LibAddonEclasspath_COLLECTIONS LibAddonEclasspath_COLLECTIONS $Computed
union $Computed $Computed LibAddonEclasspath_COLLECTIONS
substract LibAddonEclasspath_BYTEBUFFER LibAddonEclasspath_BYTEBUFFER $Computed
union $Computed $Computed LibAddonEclasspath_BYTEBUFFER
substract LibAddonEclasspath_BUFFEREDSTREAMS LibAddonEclasspath_BUFFEREDSTREAMS $Computed
union $Computed $Computed LibAddonEclasspath_BUFFEREDSTREAMS
substract LibAddonEclasspath_BITSET LibAddonEclasspath_BITSET $Computed
union $Computed $Computed LibAddonEclasspath_BITSET



# TestSuite
substract $TestSuite $TestSuite $Computed
union $Computed $Computed $TestSuite

# PNG
substract $Label_LIBPNG $Label_LIBPNG $Computed
union $Computed $Computed $Label_LIBPNG 

# BMPM
substract $Label_LIBBMPM $Label_LIBBMPM $Computed
union $Computed $Computed $Label_LIBBMPM

# DISPLAY
substract $Label_LIBDisplay $Label_LIBDisplay $Computed
union $Computed $Computed $Label_LIBDisplay 

# LIBInput
substract $Label_LIBInput $Label_LIBInput $Computed
union $Computed $Computed $Label_LIBInput 

# OS
substract $Label_OS $Label_OS $Computed
union $Computed $Computed $Label_OS 
 
# VMALLOCATOR
substract $Label_VMAllocator $Label_VMAllocator $Computed
union $Computed $Computed $Label_VMAllocator

# VMCORE
substract $Label_VMCore $Label_VMCore $Computed
union $Computed $Computed $Label_VMCore

# DRIVER
substract $Label_Drivers $Label_Drivers $Computed
union $Computed $Computed $Label_Drivers

# ICETEA STRINGS
substract $Label_IceteaString $Label_IceteaString $Computed
union $Computed $Computed $Label_IceteaString 

# ICETEART
substract $Label_IceteaRuntime $Label_IceteaRuntime $Computed
union $Computed $Computed $Label_IceteaRuntime 

# Math Float
substract $Label_LIBFloat $Label_LIBFloat $Computed
union $Computed $Computed $Label_LIBFloat
 
# Math Int
substract $Label_LIBInt $Label_LIBInt $Computed
union $Computed $Computed $Label_LIBInt

# PrintfScanf
substract $Label_PrintfScanf $Label_PrintfScanf $Computed
union $Computed $Computed $Label_PrintfScanf

# USB
substract $Label_Usb $Label_Usb $Computed
union $Computed $Computed $Label_Usb

# InstalledFeatures
substract $Label_InstalledFeatures $Label_InstalledFeatures $Computed
union $Computed $Computed $Label_InstalledFeatures
 
# Application Fonts
substract $Label_ApplicationFonts $Label_ApplicationFonts $Computed
union $Computed $Computed $Label_ApplicationFonts
 
# Application Images
substract $Label_ApplicationImages $Label_ApplicationImages $Computed
union $Computed $Computed $Label_ApplicationImages
 
# Application Resources
substract $Label_ApplicationResources $Label_ApplicationResources $Computed
union $Computed $Computed $Label_ApplicationResources

# Application Immutables
substract $Label_ApplicationImmutables $Label_ApplicationImmutables $Computed
union $Computed $Computed $Label_ApplicationImmutables

# ClassesNames (Must be before JavaApplication because $TotalSoar include $Label_ClassesNames)
substract $Label_ClassesNames $Label_ClassesNames $Computed
union $Computed $Computed $Label_ClassesNames
 
# JavaApplication (without libraries)
substract $Label_JavaApplication $TotalSoar $Computed
union $Computed $Computed $Label_JavaApplication

# SSL Stack
substract $Label_NativeStackSSL $Label_NativeStackSSL $Computed
union $Computed $Computed $Label_NativeStackSSL

# NET Stack
substract $Label_NativeStackNET $Label_NativeStackNET $Computed
union $Computed $Computed $Label_NativeStackNET

# WIFI Stack
substract $Label_NativeStackWifi $Label_NativeStackWifi $Computed
union $Computed $Computed $Label_NativeStackWifi

# WIFI Stack TI CC3100
substract $Label_NativeStackWifiTICC3100 $Label_NativeStackWifiTICC3100 $Computed
union $Computed $Computed $Label_NativeStackWifiTICC3100

# MODEM 3G Stack
substract $Label_NativeStackModem3G $Label_NativeStackModem3G $Computed
union $Computed $Computed $Label_NativeStackModem3G

# FS Stack
substract $Label_NativeStackFS $Label_NativeStackFS $Computed
union $Computed $Computed $Label_NativeStackFS

# BSP Malloc
substract $Label_BSP_Malloc $Label_BSP_Malloc $Computed
union $Computed $Computed $Label_BSP_Malloc

# Remaining Data
substract $Remaining All $Computed
union $Computed $Computed $Remaining

