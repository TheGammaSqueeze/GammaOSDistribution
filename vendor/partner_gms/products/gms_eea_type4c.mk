$(call inherit-product, vendor/partner_gms/products/eea_common.mk)

PRODUCT_PACKAGES += \
    sysconfig_eea_v1_search_chrome \
    GmsConfigOverlayGSA \
    Velvet \
    Chrome \
    GmsEEAType4cIntegration \
    SearchLauncherQuickStep
