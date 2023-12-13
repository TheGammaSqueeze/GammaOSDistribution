####################################
# dexpreopt support - typically used on user builds to run dexopt (for Dalvik) or dex2oat (for ART) ahead of time
#
####################################

include $(BUILD_SYSTEM)/dex_preopt_config.mk

# Method returning whether the install path $(1) should be for system_other.
# Under SANITIZE_LITE, we do not want system_other. Just put things under /data/asan.
ifeq ($(SANITIZE_LITE),true)
install-on-system-other =
else
install-on-system-other = $(filter-out $(PRODUCT_DEXPREOPT_SPEED_APPS) $(PRODUCT_SYSTEM_SERVER_APPS),$(basename $(notdir $(filter $(foreach f,$(SYSTEM_OTHER_ODEX_FILTER),$(TARGET_OUT)/$(f)),$(1)))))
endif

# We want to install the profile even if we are not using preopt since it is required to generate
# the image on the device.
ALL_DEFAULT_INSTALLED_MODULES += $(call copy-many-files,$(DEXPREOPT_IMAGE_PROFILE_BUILT_INSTALLED),$(PRODUCT_OUT))

# Install boot images. Note that there can be multiple.
my_boot_image_arch := TARGET_ARCH
my_boot_image_out := $(PRODUCT_OUT)
my_boot_image_syms := $(TARGET_OUT_UNSTRIPPED)
DEFAULT_DEX_PREOPT_INSTALLED_IMAGE_MODULE := \
  $(foreach my_boot_image_name,$(DEXPREOPT_IMAGE_NAMES),$(strip \
    $(eval include $(BUILD_SYSTEM)/dex_preopt_libart.mk) \
    $(my_boot_image_module)))
ifdef TARGET_2ND_ARCH
  my_boot_image_arch := TARGET_2ND_ARCH
  2ND_DEFAULT_DEX_PREOPT_INSTALLED_IMAGE_MODULE := \
    $(foreach my_boot_image_name,$(DEXPREOPT_IMAGE_NAMES),$(strip \
      $(eval include $(BUILD_SYSTEM)/dex_preopt_libart.mk) \
      $(my_boot_image_module)))
endif
# Install boot images for testing on host. We exclude framework image as it is not part of art manifest.
my_boot_image_arch := HOST_ARCH
my_boot_image_out := $(HOST_OUT)
my_boot_image_syms := $(HOST_OUT)/symbols
HOST_BOOT_IMAGE_MODULE := \
  $(foreach my_boot_image_name,art_host,$(strip \
    $(eval include $(BUILD_SYSTEM)/dex_preopt_libart.mk) \
    $(my_boot_image_module)))
HOST_BOOT_IMAGE := $(call module-installed-files,$(HOST_BOOT_IMAGE_MODULE))
ifdef HOST_2ND_ARCH
  my_boot_image_arch := HOST_2ND_ARCH
  2ND_HOST_BOOT_IMAGE_MODULE := \
    $(foreach my_boot_image_name,art_host,$(strip \
      $(eval include $(BUILD_SYSTEM)/dex_preopt_libart.mk) \
      $(my_boot_image_module)))
  2ND_HOST_BOOT_IMAGE := $(call module-installed-files,$(2ND_HOST_BOOT_IMAGE_MODULE))
endif
my_boot_image_arch :=
my_boot_image_out :=
my_boot_image_syms :=
my_boot_image_module :=

# Build the boot.zip which contains the boot jars and their compilation output
# We can do this only if preopt is enabled and if the product uses libart config (which sets the
# default properties for preopting).
ifeq ($(WITH_DEXPREOPT), true)
ifeq ($(PRODUCT_USES_DEFAULT_ART_CONFIG), true)

boot_zip := $(PRODUCT_OUT)/boot.zip
bootclasspath_jars := $(DEXPREOPT_BOOTCLASSPATH_DEX_FILES)
system_server_jars := \
  $(foreach m,$(PRODUCT_SYSTEM_SERVER_JARS),\
    $(PRODUCT_OUT)/system/framework/$(call word-colon,2,$(m)).jar)

$(boot_zip): PRIVATE_BOOTCLASSPATH_JARS := $(bootclasspath_jars)
$(boot_zip): PRIVATE_SYSTEM_SERVER_JARS := $(system_server_jars)
$(boot_zip): $(bootclasspath_jars) $(system_server_jars) $(SOONG_ZIP) $(MERGE_ZIPS) $(DEXPREOPT_IMAGE_ZIP_boot) $(DEXPREOPT_IMAGE_ZIP_art)
	@echo "Create boot package: $@"
	rm -f $@
	$(SOONG_ZIP) -o $@.tmp \
	  -C $(dir $(firstword $(PRIVATE_BOOTCLASSPATH_JARS)))/.. $(addprefix -f ,$(PRIVATE_BOOTCLASSPATH_JARS)) \
	  -C $(PRODUCT_OUT) $(addprefix -f ,$(PRIVATE_SYSTEM_SERVER_JARS))
	$(MERGE_ZIPS) $@ $@.tmp $(DEXPREOPT_IMAGE_ZIP_boot) $(DEXPREOPT_IMAGE_ZIP_art)
	rm -f $@.tmp

$(call dist-for-goals, droidcore, $(boot_zip))

endif  #PRODUCT_USES_DEFAULT_ART_CONFIG
endif  #WITH_DEXPREOPT
