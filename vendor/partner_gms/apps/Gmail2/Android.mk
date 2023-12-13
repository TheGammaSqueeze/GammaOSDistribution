###############################################################################
# Gmail2
LOCAL_PATH := $(my-dir)

my_archs := arm arm64 x86 x86_64
my_src_arch := $(call get-prebuilt-src-arch, $(my_archs))

include $(CLEAR_VARS)
LOCAL_MODULE := Gmail2
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)
#LOCAL_PRIVILEGED_MODULE :=
LOCAL_PRODUCT_MODULE := true
LOCAL_CERTIFICATE := PRESIGNED
LOCAL_SRC_FILES := $(LOCAL_MODULE)_$(my_src_arch).apk
LOCAL_MODULE_TARGET_ARCH := $(my_src_arch)
LOCAL_OVERRIDES_PACKAGES := Email Exchange2
LOCAL_OPTIONAL_USES_LIBRARIES := org.apache.http.legacy
#LOCAL_REQUIRED_MODULES :=
include $(BUILD_PREBUILT)
