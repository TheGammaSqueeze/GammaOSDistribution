$(call inherit-product, vendor/partner_gms/products/eea_common.mk)

PRODUCT_PACKAGES += \
    sysconfig_eea_v1 \
    GoogleActionsService \
    GmsEEAType1Integration \
    GmsConfigOverlayVAS \
    Launcher3QuickStep
