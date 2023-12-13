TARGET_GAPPS_ARCH := arm
$(call inherit-product, device/phh/treble/base-pre.mk)
include build/make/target/product/aosp_arm.mk
$(call inherit-product, device/phh/treble/base.mk)

$(call inherit-product, vendor/foss/foss.mk)
$(call inherit-product, device/phh/treble/lineage.mk)

PRODUCT_NAME := lineage_a64_bfS
PRODUCT_DEVICE := phhgsi_a64_ab
PRODUCT_BRAND := google
PRODUCT_SYSTEM_BRAND := google
PRODUCT_MODEL := Phh-Treble with FOSS apps

# Overwrite the inherited "emulator" characteristics
PRODUCT_CHARACTERISTICS := device

PRODUCT_PACKAGES +=  phh-su me.phh.superuser su

