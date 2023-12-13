#
# Copyright (C) 2011 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

ifndef ART_ANDROID_COMMON_PATH_MK
ART_ANDROID_COMMON_PATH_MK := true

# We cannot build things that require host core images from prebuilts, because
# they aren't present there. Set up a variable to skip all build rules that
# relate to them, because `m checkbuild` complains on rules with nonexisting
# dependencies, even if they won't get called.
# TODO(b/172480617): Remove this when ART sources are no longer in platform manifests.
ifeq (true,$(SOONG_CONFIG_art_module_source_build))
  my_art_module_source_build := true
else ifeq (false,$(SOONG_CONFIG_art_module_source_build))
  my_art_module_source_build := false
else
  $(error SOONG_CONFIG_art_module_source_build is neither true nor false - mk file ordering problem?)
endif

ifeq (true,$(my_art_module_source_build))

include art/build/Android.common.mk
include art/build/Android.common_build.mk

# Directory used for dalvik-cache on device.
ART_TARGET_DALVIK_CACHE_DIR := /data/dalvik-cache

# Directory used for gtests on device.
# $(TARGET_OUT_DATA_NATIVE_TESTS) will evaluate to the nativetest directory in the target part on
# the host, so we can strip everything but the directory to find out whether it is "nativetest" or
# "nativetest64."
ART_TARGET_NATIVETEST_DIR := /data/$(notdir $(TARGET_OUT_DATA_NATIVE_TESTS))/art

ART_TARGET_NATIVETEST_OUT := $(TARGET_OUT_DATA_NATIVE_TESTS)/art

# Directory used for oat tests on device.
ART_TARGET_TEST_DIR := /data/art-test
ART_TARGET_TEST_OUT := $(TARGET_OUT_DATA)/art-test

# Modules to compile for core.art.
CORE_IMG_JARS := core-oj core-libart okhttp bouncycastle apache-xml
HOST_CORE_IMG_JARS   := $(addsuffix -hostdex,$(CORE_IMG_JARS))
TARGET_CORE_IMG_JARS := $(CORE_IMG_JARS)
HOST_CORE_IMG_DEX_LOCATIONS   := $(foreach jar,$(HOST_CORE_IMG_JARS),  $(HOST_OUT_JAVA_LIBRARIES)/$(jar).jar)
ifeq ($(ART_TEST_ANDROID_ROOT),)
TARGET_CORE_IMG_DEX_LOCATIONS := $(foreach jar,$(TARGET_CORE_IMG_JARS),/$(ART_DEXPREOPT_BOOT_JAR_DIR)/$(jar).jar)
else
TARGET_CORE_IMG_DEX_LOCATIONS := $(foreach jar,$(TARGET_CORE_IMG_JARS),$(ART_TEST_ANDROID_ROOT)/$(jar).jar)
endif
HOST_CORE_IMG_DEX_FILES   := $(foreach jar,$(HOST_CORE_IMG_JARS),  $(call intermediates-dir-for,JAVA_LIBRARIES,$(jar),t,COMMON)/javalib.jar)
TARGET_CORE_IMG_DEX_FILES := $(foreach jar,$(TARGET_CORE_IMG_JARS),$(call intermediates-dir-for,JAVA_LIBRARIES,$(jar).com.android.art.testing, ,COMMON)/javalib.jar)

# Also copy the jar files next to host boot.art image.
HOST_BOOT_IMAGE_JARS := $(foreach jar,$(CORE_IMG_JARS),$(HOST_OUT)/apex/com.android.art/javalib/$(jar).jar)
$(HOST_BOOT_IMAGE_JARS): $(HOST_OUT)/apex/com.android.art/javalib/%.jar : $(HOST_OUT_JAVA_LIBRARIES)/%-hostdex.jar
	$(copy-file-to-target)

HOST_BOOT_IMAGE_JARS += $(HOST_OUT)/apex/com.android.conscrypt/javalib/conscrypt.jar
$(HOST_OUT)/apex/com.android.conscrypt/javalib/conscrypt.jar : $(HOST_OUT_JAVA_LIBRARIES)/conscrypt-hostdex.jar
	$(copy-file-to-target)
HOST_BOOT_IMAGE_JARS += $(HOST_OUT)/apex/com.android.i18n/javalib/core-icu4j.jar
$(HOST_OUT)/apex/com.android.i18n/javalib/core-icu4j.jar : $(HOST_OUT_JAVA_LIBRARIES)/core-icu4j-hostdex.jar
	$(copy-file-to-target)

HOST_CORE_IMG_OUTS += $(HOST_BOOT_IMAGE_JARS) $(HOST_BOOT_IMAGE) $(2ND_HOST_BOOT_IMAGE)

HOST_TEST_CORE_JARS   := $(addsuffix -hostdex,$(CORE_IMG_JARS) core-icu4j conscrypt)
ART_HOST_DEX_DEPENDENCIES := $(foreach jar,$(HOST_TEST_CORE_JARS),$(HOST_OUT_JAVA_LIBRARIES)/$(jar).jar)
ART_TARGET_DEX_DEPENDENCIES := com.android.art.testing com.android.conscrypt com.android.i18n

ART_CORE_SHARED_LIBRARIES := libjavacore libopenjdk libopenjdkjvm libopenjdkjvmti
ART_CORE_SHARED_DEBUG_LIBRARIES := libopenjdkd libopenjdkjvmd libopenjdkjvmtid
ART_HOST_CORE_SHARED_LIBRARIES := $(ART_CORE_SHARED_LIBRARIES) libicuuc-host libicui18n-host libicu_jni
ART_HOST_SHARED_LIBRARY_DEPENDENCIES := $(foreach lib,$(ART_HOST_CORE_SHARED_LIBRARIES), $(ART_HOST_OUT_SHARED_LIBRARIES)/$(lib)$(ART_HOST_SHLIB_EXTENSION))
ART_HOST_SHARED_LIBRARY_DEBUG_DEPENDENCIES := $(foreach lib,$(ART_CORE_SHARED_DEBUG_LIBRARIES), $(ART_HOST_OUT_SHARED_LIBRARIES)/$(lib)$(ART_HOST_SHLIB_EXTENSION))
ifdef HOST_2ND_ARCH
ART_HOST_SHARED_LIBRARY_DEPENDENCIES += $(foreach lib,$(ART_HOST_CORE_SHARED_LIBRARIES), $(2ND_HOST_OUT_SHARED_LIBRARIES)/$(lib).so)
ART_HOST_SHARED_LIBRARY_DEBUG_DEPENDENCIES += $(foreach lib,$(ART_CORE_SHARED_DEBUG_LIBRARIES), $(2ND_HOST_OUT_SHARED_LIBRARIES)/$(lib).so)
endif

# Both the primary and the secondary arches of the libs are built by depending
# on the module name.
ART_DEBUG_TARGET_SHARED_LIBRARY_DEPENDENCIES := $(foreach lib,$(ART_CORE_SHARED_LIBRARIES), $(lib).com.android.art.debug)
ART_TARGET_SHARED_LIBRARY_DEBUG_DEPENDENCIES := $(foreach lib,$(ART_CORE_SHARED_DEBUG_LIBRARIES), $(TARGET_OUT_SHARED_LIBRARIES)/$(lib).so)
ifdef TARGET_2ND_ARCH
ART_TARGET_SHARED_LIBRARY_DEBUG_DEPENDENCIES += $(foreach lib,$(ART_CORE_SHARED_DEBUG_LIBRARIES), $(2ND_TARGET_OUT_SHARED_LIBRARIES)/$(lib).so)
endif

ART_CORE_DEBUGGABLE_EXECUTABLES := \
    dex2oat \
    dexoptanalyzer \
    imgdiag \
    oatdump \
    odrefresh \
    profman \

ART_CORE_EXECUTABLES := \
    dalvikvm \
    dexlist \

# Depend on the -target or -host phony targets generated by the build system
# for each module
ART_TARGET_EXECUTABLES :=
ifneq ($(ART_BUILD_TARGET_NDEBUG),false)
ART_TARGET_EXECUTABLES += $(foreach name,$(ART_CORE_EXECUTABLES) $(ART_CORE_DEBUGGABLE_EXECUTABLES),$(name)-target)
endif
ifneq ($(ART_BUILD_TARGET_DEBUG),false)
ART_TARGET_EXECUTABLES += $(foreach name,$(ART_CORE_DEBUGGABLE_EXECUTABLES),$(name)d-target)
endif

ART_HOST_EXECUTABLES :=
ifneq ($(ART_BUILD_HOST_NDEBUG),false)
ART_HOST_EXECUTABLES += $(foreach name,$(ART_CORE_EXECUTABLES) $(ART_CORE_DEBUGGABLE_EXECUTABLES),$(name)-host)
endif
ifneq ($(ART_BUILD_HOST_DEBUG),false)
ART_HOST_EXECUTABLES += $(foreach name,$(ART_CORE_DEBUGGABLE_EXECUTABLES),$(name)d-host)
endif

# Release ART APEX, included by default in "user" builds.
RELEASE_ART_APEX := com.android.art
# Debug ART APEX, included by default in "userdebug" and "eng"
# builds and used in ART device benchmarking.
DEBUG_ART_APEX := com.android.art.debug
# Testing ART APEX, used in ART device testing.
TESTING_ART_APEX := com.android.art.testing

RUNTIME_APEX := com.android.runtime
CONSCRYPT_APEX := com.android.conscrypt
I18N_APEX := com.android.i18n
STATSD_APEX := com.android.os.statsd
TZDATA_APEX := com.android.tzdata

# A phony file to create the ICU data file for host.
HOST_I18N_DATA := $(HOST_OUT)/$(I18N_APEX)/timestamp
# A phony file to create the tz data file for host.
HOST_TZDATA_DATA := $(HOST_OUT)/$(TZDATA_APEX)/timestamp

endif # ifeq (true,$(my_art_module_source_build))

endif # ART_ANDROID_COMMON_PATH_MK
