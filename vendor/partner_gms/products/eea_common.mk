###############################################################################
# GMS home folder location
# Note: we cannot use $(my-dir) in this makefile
ANDROID_PARTNER_GMS_HOME := vendor/partner_gms

# Android Build system uncompresses DEX files (classes*.dex) in the privileged
# apps by default, which breaks APK v2/v3 signature. Because some privileged
# GMS apps are still shipped with compressed DEX, we need to disable
# uncompression feature to make them work correctly.
DONT_UNCOMPRESS_PRIV_APPS_DEXS := true

# GMS mandatory core packages
PRODUCT_PACKAGES := \
    AndroidAutoStub \
    AndroidPlatformServices \
    ConfigUpdater \
    GoogleExtShared \
    GoogleFeedback \
    GoogleLocationHistory \
    GoogleOneTimeInitializer \
    GooglePackageInstaller \
    GooglePartnerSetup \
    GooglePrintRecommendationService \
    GoogleRestore \
    GoogleServicesFramework \
    GoogleCalendarSyncAdapter \
    GoogleContactsSyncAdapter \
    SpeechServicesByGoogle \
    GmsCore \
    Phonesky \
    SetupWizard \
    WebViewGoogle \
    Wellbeing

# GMS common RRO packages
PRODUCT_PACKAGES += GmsConfigOverlayCommon

# GMS optional RRO packages
PRODUCT_PACKAGES += GmsConfigOverlayGeotz

# GMS common configuration files
PRODUCT_PACKAGES += \
    play_store_fsi_cert \
    gms_fsverity_cert \
    default_permissions_allowlist_google \
    privapp_permissions_google_system \
    privapp_permissions_google_product \
    privapp_permissions_google_system_ext \
    split_permissions_google \
    preferred_apps_google \
    sysconfig_google \
    sysconfig_wellbeing \
    sysconfig_d2d_cable_migration_feature \
    google_hiddenapi_package_allowlist

# Overlay for GMS devices: default backup transport in SettingsProvider
PRODUCT_PACKAGE_OVERLAYS += $(ANDROID_PARTNER_GMS_HOME)/overlay/gms_overlay

# GMS mandatory application packages
PRODUCT_PACKAGES += \
    Drive \
    Gmail2 \
    Duo \
    Maps \
    YTMusic \
    Photos \
    Videos \
    YouTube

# GMS comms suite
$(call inherit-product, $(ANDROID_PARTNER_GMS_HOME)/products/google_comms_suite.mk)

# GMS optional application packages
PRODUCT_PACKAGES += \
    CalendarGoogle \
    DeskClockGoogle \
    LatinImeGoogle \
    TagGoogle \
    talkback \
    Keep \
    CalculatorGoogle

PRODUCT_PRODUCT_PROPERTIES += \
    ro.setupwizard.rotation_locked=true \
    setupwizard.theme=glif_v3_light \
    ro.opa.eligible_device=true \
    ro.com.google.gmsversion=12_202110
