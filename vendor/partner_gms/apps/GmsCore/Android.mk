###############################################################################
# GmsCore
LOCAL_PATH := $(my-dir)

my_archs := arm arm64 x86 x86_64
my_src_arch := $(call get-prebuilt-src-arch, $(my_archs))

include $(CLEAR_VARS)
LOCAL_MODULE := GmsCore
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)
LOCAL_PRIVILEGED_MODULE := true
LOCAL_PRODUCT_MODULE := true
LOCAL_CERTIFICATE := PRESIGNED
ifeq ($(my_src_arch),arm)
LOCAL_DPI_VARIANTS := xxhdpi
LOCAL_DPI_FILE_STEM := $(LOCAL_MODULE)_$(my_src_arch)_%.apk
else ifeq ($(my_src_arch),arm64)
LOCAL_DPI_VARIANTS := xxhdpi
LOCAL_DPI_FILE_STEM := $(LOCAL_MODULE)_$(my_src_arch)_%.apk
endif
LOCAL_SRC_FILES := $(LOCAL_MODULE)_$(my_src_arch).apk
LOCAL_OVERRIDES_PACKAGES := NetworkRecommendation
LOCAL_OPTIONAL_USES_LIBRARIES := org.apache.http.legacy com.android.media.remotedisplay com.android.location.provider org.carconnectivity.android.digitalkey.secureelement org.carconnectivity.android.digitalkey.timesync com.google.android.ble samsung.uwb androidx.window.extensions androidx.window.sidecar com.google.android.wearable
#LOCAL_REQUIRED_MODULES :=
ifeq ($(my_src_arch),arm64)
LOCAL_MULTILIB := both
else ifeq ($(my_src_arch),x86_64)
LOCAL_MULTILIB := both
endif
include $(BUILD_PREBUILT)
