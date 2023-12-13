$(call inherit-product, vendor/partner_gms/products/eea_go_common.mk)

PRODUCT_PACKAGES += \
    sysconfig_eea_v2_search_chrome \
    GmsConfigOverlaySearchGo \
    AssistantGo \
    GoogleSearchGo \
    Chrome \
    SearchSelector \
    GmsEEAType4cIntegrationGo \
    Launcher3Go \
    GMailGo
