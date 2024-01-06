TARGET_GAPPS_ARCH := arm64
$(call inherit-product, device/phh/treble/base-pre.mk)
include build/make/target/product/aosp_arm64.mk
$(call inherit-product, device/phh/treble/base.mk)

$(call inherit-product, device/phh/treble/gapps.mk)
$(call inherit-product, device/phh/treble/lineage.mk)

PRODUCT_NAME := lineage_arm64_bgN
PRODUCT_DEVICE := phhgsi_arm64_ab
PRODUCT_BRAND := google
PRODUCT_SYSTEM_BRAND := google
PRODUCT_MODEL := Anbernic RG505

# Overwrite the inherited "emulator" characteristics
PRODUCT_CHARACTERISTICS := device

PRODUCT_PACKAGES += 

