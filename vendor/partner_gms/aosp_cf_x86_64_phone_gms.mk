$(call inherit-product, device/google/cuttlefish/vsoc_x86_64/phone/aosp_cf.mk)
$(call inherit-product, vendor/google/security/adb/vendor_key.mk)
# Includes only mandatory GMS packages if they exist.
$(call inherit-product-if-exists, vendor/partner_gms/products/gms.mk)

PRODUCT_ARTIFACT_PATH_REQUIREMENT_ALLOWED_LIST += \
    system/app/GoogleExtShared/GoogleExtShared.apk \
    system/app/GooglePrintRecommendationService/GooglePrintRecommendationService.apk \
    system/etc/permissions/privapp-permissions-google-system.xml \
    system/etc/sysconfig/google-hiddenapi-package-allowlist.xml \
        system/priv-app/GooglePackageInstaller/GooglePackageInstaller.apk \
    system/priv-app/TagGoogle/TagGoogle.apk

PRODUCT_NAME := aosp_cf_x86_64_phone_gms
