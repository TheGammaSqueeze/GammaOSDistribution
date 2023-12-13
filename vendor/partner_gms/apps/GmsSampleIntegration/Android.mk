###############################################################################
# Various GMS Sample Integration targets
LOCAL_PATH:= $(my-dir)

# GmsSampleIntegration
include $(CLEAR_VARS)
LOCAL_PACKAGE_NAME := GmsSampleIntegration
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_EXT_MODULE := true
LOCAL_CERTIFICATE := platform
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res_dhs_full $(LOCAL_PATH)/res
LOCAL_SDK_VERSION := current
include $(BUILD_PACKAGE)

# GmsSampleIntegrationGo
include $(CLEAR_VARS)
LOCAL_PACKAGE_NAME := GmsSampleIntegrationGo
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_EXT_MODULE := true
LOCAL_CERTIFICATE := platform
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res_dhs_go $(LOCAL_PATH)/res
LOCAL_SDK_VERSION := current
include $(BUILD_PACKAGE)

# GmsSampleIntegrationGo_2GB
include $(CLEAR_VARS)
LOCAL_PACKAGE_NAME := GmsSampleIntegrationGo_2GB
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_EXT_MODULE := true
LOCAL_CERTIFICATE := platform
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res_dhs_go_2gb $(LOCAL_PATH)/res
LOCAL_SDK_VERSION := current
include $(BUILD_PACKAGE)

# GmsEEAType4cIntegration (GSA, Chrome, search+chrome placement)
include $(CLEAR_VARS)
LOCAL_PACKAGE_NAME := GmsEEAType4cIntegration
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_EXT_MODULE := true
LOCAL_CERTIFICATE := platform
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res_dhs_full $(LOCAL_PATH)/res
LOCAL_SDK_VERSION := current
include $(BUILD_PACKAGE)

# GmsEEAType4cIntegrationGo (GSA, Chrome, search+chrome placement)
include $(CLEAR_VARS)
LOCAL_PACKAGE_NAME := GmsEEAType4cIntegrationGo
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_EXT_MODULE := true
LOCAL_CERTIFICATE := platform
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res_dhs_go $(LOCAL_PATH)/res
LOCAL_SDK_VERSION := current
include $(BUILD_PACKAGE)

# GmsEEAType4cIntegrationGo_2GB (GSA, Chrome, search+chrome placement)
include $(CLEAR_VARS)
LOCAL_PACKAGE_NAME := GmsEEAType4cIntegrationGo_2GB
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_EXT_MODULE := true
LOCAL_CERTIFICATE := platform
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res_dhs_go_2gb $(LOCAL_PATH)/res
LOCAL_SDK_VERSION := current
include $(BUILD_PACKAGE)

# GmsEEAType1Integration (No GSA, No Chrome)
include $(CLEAR_VARS)
LOCAL_PACKAGE_NAME := GmsEEAType1Integration
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_TAGS := optional
LOCAL_SYSTEM_EXT_MODULE := true
LOCAL_CERTIFICATE := platform
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res_dhs_min $(LOCAL_PATH)/res
LOCAL_SDK_VERSION := current
include $(BUILD_PACKAGE)
