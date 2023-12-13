$(call inherit-product, vendor/partner_gms/products/eea_common.mk)

PRODUCT_PACKAGES += \
    sysconfig_eea_v2_search_chrome \
    GmsConfigOverlayGSA \
    Velvet \
    Chrome \
    SearchSelector \
    GmsEEAType4cIntegration \
    SearchLauncherQuickStep
