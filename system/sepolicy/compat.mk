version := $(version_under_treble_tests)

include $(CLEAR_VARS)
#################################
# build this target to ensure the compat permissions files all build against the current policy
#
LOCAL_MODULE := $(version)_compat_test
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0 legacy_unencumbered
LOCAL_LICENSE_CONDITIONS := notice unencumbered
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/NOTICE
LOCAL_REQUIRED_MODULES := $(version).compat.cil
LOCAL_MODULE_CLASS := FAKE
LOCAL_MODULE_TAGS := optional

include $(BUILD_SYSTEM)/base_rules.mk

all_cil_files := \
    $(built_plat_cil) \
    $(built_plat_mapping_cil) \
    $(built_pub_vers_cil) \
    $(ALL_MODULES.$(version).compat.cil.BUILT) \

ifdef HAS_SYSTEM_EXT_SEPOLICY
all_cil_files += $(built_system_ext_cil)
endif

ifdef HAS_SYSTEM_EXT_PUBLIC_SEPOLICY
all_cil_files += $(built_system_ext_mapping_cil)
endif

ifdef HAS_PRODUCT_SEPOLICY
all_cil_files += $(built_product_cil)
endif

ifdef HAS_PRODUCT_PUBLIC_SEPOLICY
all_cil_files += $(built_product_mapping_cil)
endif

ifneq ($(mixed_sepolicy_build),true)

all_cil_files += $(built_vendor_cil)

ifdef BOARD_ODM_SEPOLICY_DIRS
all_cil_files += $(built_odm_cil)
endif

endif # ifneq ($(mixed_sepolicy_build),true)

$(LOCAL_BUILT_MODULE): PRIVATE_CIL_FILES := $(all_cil_files)
$(LOCAL_BUILT_MODULE): $(HOST_OUT_EXECUTABLES)/secilc $(HOST_OUT_EXECUTABLES)/sepolicy-analyze $(all_cil_files)
	@mkdir -p $(dir $@)
	$(hide) $< -m -N -M true -G -c $(POLICYVERS) $(PRIVATE_CIL_FILES) -o $@ -f /dev/null

all_cil_files :=
version :=
version_under_treble_tests :=
