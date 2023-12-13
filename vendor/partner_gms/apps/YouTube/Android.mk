###############################################################################
# YouTube
LOCAL_PATH := $(my-dir)

my_archs := arm arm64 x86 x86_64
my_src_arch := $(call get-prebuilt-src-arch, $(my_archs))

include $(CLEAR_VARS)
LOCAL_MODULE := YouTube
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)
#LOCAL_PRIVILEGED_MODULE :=
LOCAL_PRODUCT_MODULE := true
LOCAL_CERTIFICATE := PRESIGNED
LOCAL_DPI_VARIANTS := xxhdpi xhdpi hdpi mdpi
LOCAL_DPI_FILE_STEM := YouTube_$(my_src_arch)_%.apk
LOCAL_SRC_FILES := YouTube_$(my_src_arch)_xxhdpi.apk
#LOCAL_OVERRIDES_PACKAGES :=
LOCAL_OPTIONAL_USES_LIBRARIES := org.apache.http.legacy androidx.window.extensions androidx.window.sidecar
#LOCAL_REQUIRED_MODULES :=
LOCAL_MULTILIB := both
include $(BUILD_PREBUILT)
