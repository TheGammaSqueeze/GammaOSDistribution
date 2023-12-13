#############################################################################
# GoogleDialerGo
LOCAL_PATH := $(my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:= GoogleDialerGo
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)
LOCAL_PRIVILEGED_MODULE := true
LOCAL_PRODUCT_MODULE := true
LOCAL_CERTIFICATE := PRESIGNED
#LOCAL_DPI_VARIANTS := xxxhdpi xxhdpi xhdpi hdpi mdpi
#LOCAL_DPI_FILE_STEM := $(LOCAL_MODULE)_%.apk
LOCAL_SRC_FILES := $(LOCAL_MODULE).apk
LOCAL_OVERRIDES_PACKAGES := Dialer
LOCAL_OPTIONAL_USES_LIBRARIES := org.apache.http.legacy
LOCAL_REQUIRED_MODULES := googledialergo-sysconfig.xml
include $(BUILD_PREBUILT)
