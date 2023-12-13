LOCAL_PATH := $(call my-dir)

#
# Prebuilt Launcher client library Libraries
#
include $(CLEAR_VARS)
LOCAL_MODULE := lib_launcherClient
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0 SPDX-license-identifier-BSD SPDX-license-identifier-GPL SPDX-license-identifier-MIT
LOCAL_LICENSE_CONDITIONS := notice restricted
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := JAVA_LIBRARIES
LOCAL_SRC_FILES := libs/launcher_client.jar
LOCAL_UNINSTALLABLE_MODULE := true
LOCAL_SDK_VERSION := 28
include $(BUILD_PREBUILT)

#
# Search Launcher build rule
#
include $(CLEAR_VARS)

# Relative path for Launcher3 directory
LAUNCHER_PATH := ../../../../packages/apps/Trebuchet

LOCAL_STATIC_ANDROID_LIBRARIES := Launcher3CommonDepsLib
LOCAL_STATIC_JAVA_LIBRARIES := lib_launcherClient

LOCAL_SRC_FILES := \
    $(call all-java-files-under, $(LAUNCHER_PATH)/src_shortcuts_overrides) \
    $(call all-java-files-under, $(LAUNCHER_PATH)/src_ui_overrides) \
    $(call all-java-files-under, src) \
    $(call all-java-files-under, src_base) \
    $(call all-java-files-under, $(LAUNCHER_PATH)/src)

LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res

LOCAL_PROGUARD_FLAG_FILES := $(LAUNCHER_PATH)/proguard.flags

LOCAL_MIN_SDK_VERSION := 28
LOCAL_SDK_VERSION := current
LOCAL_PACKAGE_NAME := SearchLauncher

LOCAL_MODULE_TAGS := optional
LOCAL_USE_AAPT2 := true
LOCAL_AAPT2_ONLY := true
LOCAL_PRIVILEGED_MODULE := true
LOCAL_SYSTEM_EXT_MODULE := true
LOCAL_OVERRIDES_PACKAGES := Home Launcher2 Launcher3 Launcher3QuickStep
LOCAL_REQUIRED_MODULES := privapp_whitelist_com.android.launcher3
LOCAL_JACK_COVERAGE_INCLUDE_FILTER := com.android.launcher3.*

LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0 SPDX-license-identifier-BSD SPDX-license-identifier-GPL SPDX-license-identifier-MIT
LOCAL_LICENSE_CONDITIONS := notice restricted
include $(BUILD_PACKAGE)

#
# Search Launcher QuickStep build rule
#
include $(CLEAR_VARS)

# Relative path for Launcher3 directory
LAUNCHER_PATH := ../../../../packages/apps/Trebuchet

LOCAL_STATIC_ANDROID_LIBRARIES := \
    Launcher3CommonDepsLib \
    Launcher3QuickStepLib \
    QuickstepResLib
LOCAL_STATIC_JAVA_LIBRARIES := \
    lib_launcherClient \
    SystemUISharedLib \
    SystemUI-statsd

ifneq (,$(wildcard frameworks/base))
  LOCAL_PRIVATE_PLATFORM_APIS := true
else
  LOCAL_SDK_VERSION := system_current
  LOCAL_MIN_SDK_VERSION := 28
endif

LOCAL_SRC_FILES := \
    $(call all-java-files-under, quickstep/src) \
    $(call all-java-files-under, $(LAUNCHER_PATH)/quickstep/src) \
    $(call all-java-files-under, $(LAUNCHER_PATH)/src_shortcuts_overrides) \
    $(call all-java-files-under, src) \
    $(call all-java-files-under, $(LAUNCHER_PATH)/src)

LOCAL_RESOURCE_DIR := \
    $(LOCAL_PATH)/quickstep/res \
    $(LOCAL_PATH)/res \
    $(LOCAL_PATH)/$(LAUNCHER_PATH)/quickstep/res

LOCAL_PROGUARD_ENABLED := disabled

LOCAL_MODULE_TAGS := optional
LOCAL_USE_AAPT2 := true
LOCAL_AAPT2_ONLY := true
LOCAL_PACKAGE_NAME := SearchLauncherQuickStep
LOCAL_PRIVILEGED_MODULE := true
LOCAL_SYSTEM_EXT_MODULE := true
LOCAL_OVERRIDES_PACKAGES := Home Launcher2 Launcher3 Launcher3QuickStep
LOCAL_REQUIRED_MODULES := privapp_whitelist_com.android.launcher3 GmsConfigOverlaySearchLauncherQuickStep
LOCAL_JACK_COVERAGE_INCLUDE_FILTER := com.android.launcher3.*

LOCAL_FULL_LIBS_MANIFEST_FILES := $(LOCAL_PATH)/$(LAUNCHER_PATH)/quickstep/AndroidManifest.xml

LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0 SPDX-license-identifier-BSD SPDX-license-identifier-GPL SPDX-license-identifier-MIT
LOCAL_LICENSE_CONDITIONS := notice restricted
include $(BUILD_PACKAGE)

# ==================================================
include $(call all-makefiles-under,$(LOCAL_PATH))
