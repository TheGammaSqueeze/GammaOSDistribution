###############################################################################
# Only use this makefile for the Google Fi devices
$(call inherit-product, vendor/partner_gms/products/gms.mk)

# GCS and Tycho apps are mandatory for Google Fi.
PRODUCT_PACKAGES += \
    Tycho \
    GCS \
    NovaBugreportWrapper \
    GmsConfigOverlayFi \
    sysconfig_google_fi \
    privapp_permissions_google_fi
