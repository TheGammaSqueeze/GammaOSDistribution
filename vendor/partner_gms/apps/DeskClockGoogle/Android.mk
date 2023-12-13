###############################################################################
# DeskClockGoogle
LOCAL_PATH := $(my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := DeskClockGoogle
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)
#LOCAL_PRIVILEGED_MODULE :=
LOCAL_PRODUCT_MODULE := true
LOCAL_CERTIFICATE := PRESIGNED
LOCAL_SRC_FILES := $(LOCAL_MODULE).apk
LOCAL_OVERRIDES_PACKAGES := AlarmClock DeskClock
LOCAL_OPTIONAL_USES_LIBRARIES := org.apache.http.legacy
#LOCAL_REQUIRED_MODULES :=
include $(BUILD_PREBUILT)
