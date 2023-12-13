###############################################################################
# LatinImeGoogleGo
LOCAL_PATH := $(my-dir)

my_archs := arm arm64
my_src_arch := $(call get-prebuilt-src-arch,$(my_archs))

include $(CLEAR_VARS)
LOCAL_MODULE := LatinImeGoogleGo
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)
#LOCAL_PRIVILEGED_MODULE :=
LOCAL_PRODUCT_MODULE := true
LOCAL_CERTIFICATE := PRESIGNED
LOCAL_SRC_FILES := $(LOCAL_MODULE)_$(my_src_arch).apk
LOCAL_OVERRIDES_PACKAGES := LatinIME
LOCAL_REQUIRED_MODULES := en_us_d3_20180105.dict
LOCAL_MODULE_TARGET_ARCH := $(my_src_arch)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := en_us_d3_20180105.dict
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS := optional
LOCAL_PRODUCT_MODULE := true
LOCAL_MODULE_PATH := $(TARGET_OUT_PRODUCT)/usr/share/ime/google/d3_lms/
LOCAL_SRC_FILES := lms/main_en_us_d3_20180105.dict
include $(BUILD_PREBUILT)
