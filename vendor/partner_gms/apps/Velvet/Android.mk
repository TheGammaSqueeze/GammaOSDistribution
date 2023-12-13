###############################################################################
# Velvet
LOCAL_PATH := $(my-dir)

my_archs := arm arm64 x86 x86_64
my_src_arch := $(call get-prebuilt-src-arch, $(my_archs))

OFFLINE_LANG_PACK_FILE_LIST := $(patsubst $(LOCAL_PATH)/OfflineVoiceRecognitionLanguagePacks/en-US/%,%,$(shell find $(LOCAL_PATH)/OfflineVoiceRecognitionLanguagePacks -type f))

define install-lang-pack-files
include $$(CLEAR_VARS)
LOCAL_MODULE := $(1)
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_TAGS := optional
LOCAL_PRODUCT_MODULE := true
LOCAL_MODULE_PATH := $$(TARGET_OUT_PRODUCT)/usr/srec/en-US
LOCAL_SRC_FILES := OfflineVoiceRecognitionLanguagePacks/en-US/$$(LOCAL_MODULE)
include $$(BUILD_PREBUILT)
endef

$(foreach fp, $(OFFLINE_LANG_PACK_FILE_LIST),\
  $(eval $(call install-lang-pack-files, $(fp))))

include $(CLEAR_VARS)
LOCAL_MODULE := Velvet
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)
LOCAL_PRIVILEGED_MODULE := true
LOCAL_PRODUCT_MODULE := true
LOCAL_CERTIFICATE := PRESIGNED
ifeq ($(my_src_arch),arm)
LOCAL_DPI_VARIANTS := xhdpi hdpi mdpi
LOCAL_DPI_FILE_STEM := $(LOCAL_MODULE)_$(my_src_arch)_%.apk
endif
LOCAL_SRC_FILES := $(LOCAL_MODULE)_$(my_src_arch).apk
LOCAL_OVERRIDES_PACKAGES := QuickSearchBox
LOCAL_OPTIONAL_USES_LIBRARIES := org.apache.http.legacy
LOCAL_REQUIRED_MODULES := GmsConfigOverlayGSA $(OFFLINE_LANG_PACK_FILE_LIST)
LOCAL_MODULE_TARGET_ARCH := $(my_src_arch)
include $(BUILD_PREBUILT)
