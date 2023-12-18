#Huawei devices don't declare fingerprint and telephony hardware feature
#TODO: Proper detection
PRODUCT_COPY_FILES := \
	frameworks/native/data/etc/android.hardware.fingerprint.xml:system/etc/permissions/android.hardware.fingerprint.xml \
	frameworks/native/data/etc/android.hardware.telephony.gsm.xml:system/etc/permissions/android.hardware.telephony.gsm.xml \
	frameworks/native/data/etc/android.hardware.telephony.ims.xml:system/etc/permissions/android.hardware.telephony.ims.xml \
	frameworks/native/data/etc/android.hardware.bluetooth.xml:system/etc/permissions/android.hardware.bluetooth.xml \
	frameworks/native/data/etc/android.hardware.bluetooth_le.xml:system/etc/permissions/android.hardware.bluetooth_le.xml \
	frameworks/native/data/etc/android.hardware.usb.host.xml:system/etc/permissions/android.hardware.usb.host.xml \

BOARD_PLAT_PRIVATE_SEPOLICY_DIR += device/phh/treble/sepolicy

PRODUCT_PACKAGE_OVERLAYS += \
	device/phh/treble/overlay \
	device/phh/treble/overlay-lineage

PRODUCT_ENFORCE_RRO_EXCLUDED_OVERLAYS += \
	device/phh/treble/overlay-lineage/lineage-sdk

$(call inherit-product, vendor/hardware_overlay/overlay.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

#Those overrides are here because Huawei's init read properties
#from /system/etc/prop.default, then /vendor/build.prop, then /system/build.prop
#So we need to set our props in prop.default
PRODUCT_SYSTEM_DEFAULT_PROPERTIES += \
	ro.build.version.sdk=$(PLATFORM_SDK_VERSION) \
	ro.build.version.codename=$(PLATFORM_VERSION_CODENAME) \
	ro.build.version.all_codenames=$(PLATFORM_VERSION_ALL_CODENAMES) \
	ro.build.version.release=$(PLATFORM_VERSION) \
	ro.build.version.security_patch=$(PLATFORM_SECURITY_PATCH) \
	ro.adb.secure=0 \
	ro.logd.auditd=true

#Huawei HiSuite (also other OEM custom programs I guess) it's of no use in AOSP builds
PRODUCT_SYSTEM_DEFAULT_PROPERTIES += \
	persist.sys.usb.config=adb \
	ro.cust.cdrom=/dev/null

#VNDK config files
PRODUCT_COPY_FILES += \
	device/phh/treble/vndk-detect:system/bin/vndk-detect \
	device/phh/treble/vndk.rc:system/etc/init/vndk.rc \

#USB Audio
PRODUCT_COPY_FILES += \
	frameworks/av/services/audiopolicy/config/usb_audio_policy_configuration.xml:system/etc/usb_audio_policy_configuration.xml \
	device/phh/treble/files/fake_audio_policy_volume.xml:system/etc/fake_audio_policy_volume.xml \

# NFC:
#   Provide default libnfc-nci.conf file for devices that does not have one in
#   vendor/etc
PRODUCT_COPY_FILES += \
	device/phh/treble/nfc/libnfc-nci.conf:system/phh/libnfc-nci-oreo.conf \
	device/phh/treble/nfc/libnfc-nci-huawei.conf:system/phh/libnfc-nci-huawei.conf

# LineageOS build may need this to make NFC work
PRODUCT_PACKAGES += \
        NfcNci \

PRODUCT_COPY_FILES += \
	device/phh/treble/rw-system.sh:system/bin/rw-system.sh \
	device/phh/treble/phh-on-data.sh:system/bin/phh-on-data.sh \
	device/phh/treble/phh-prop-handler.sh:system/bin/phh-prop-handler.sh \
	device/phh/treble/fixSPL/getSPL.arm:system/bin/getSPL

PRODUCT_COPY_FILES += \
	device/phh/treble/empty:system/phh/empty \
	device/phh/treble/phh-on-boot.sh:system/bin/phh-on-boot.sh


# GammaOS Customizations
PRODUCT_COPY_FILES += \
        device/phh/treble/gammaos/daijisho/399.apk:system/product/app/daijisho/399.apk \
        device/phh/treble/gammaos/daijisho/launcher3.tar.gz:system/etc/launcher3.tar.gz \
        device/phh/treble/gammaos/daijisho/launcherconfig.tar.gz:system/etc/launcherconfig.tar.gz \
        device/phh/treble/gammaos/customization.sh:system/bin/customization.sh \
        device/phh/treble/gammaos/aurora/AuroraStore_4.3.5.apk:system/etc/AuroraStore_4.3.5.apk \
        device/phh/treble/gammaos/firefox/Firefox_120.0.1.apk:system/etc/Firefox_120.0.1.apk \
        device/phh/treble/gammaos/magisk/magisk.apk:system/etc/magisk.apk \
        device/phh/treble/gammaos/magisk/magisk_user_de.tar.gz:system/etc/magisk_user_de.tar.gz \
        device/phh/treble/gammaos/magisk/magisk-data-adb.tar.gz:system/etc/magisk-data-adb.tar.gz \
        device/phh/treble/gammaos/retroarch/RetroArch_aarch64.apk:system/etc/RetroArch_aarch64.apk \
        device/phh/treble/gammaos/retroarch/retroarch64.tar.gz:system/etc/retroarch64.tar.gz \
        device/phh/treble/gammaos/retroarch/retroarch64sdcard.tar.gz:system/etc/retroarch64sdcard.tar.gz \
        device/phh/treble/gammaos/retroarch/retroarch64sdcard1-arc.tar.gz:system/etc/retroarch64sdcard1-arc.tar.gz \
        device/phh/treble/gammaos/retroarch/retroarch64sdcard2-405.tar.gz:system/etc/retroarch64sdcard2-405.tar.gz \
        device/phh/treble/gammaos/retroarch/retroarch64sdcard2.tar.gz:system/etc/retroarch64sdcard2.tar.gz \
        device/phh/treble/gammaos/retroarch/roms.tar.gz:system/etc/roms.tar.gz \
        device/phh/treble/gammaos/rgp2xbox/rgp2xbox:system/bin/rgp2xbox \
        device/phh/treble/gammaos/rgp2xbox/rgp2xbox.sh:system/bin/rgp2xbox.sh \
        device/phh/treble/gammaos/setclock/setclock_max.sh:system/bin/setclock_max.sh \
        device/phh/treble/gammaos/setclock/setclock_stock.sh:system/bin/setclock_stock.sh \
        device/phh/treble/gammaos/setclock/setclock_powersave.sh:system/bin/setclock_powersave.sh \
        device/phh/treble/gammaos/toast/Toast.apk:system/etc/Toast.apk \
        device/phh/treble/gammaos/aptx/lib/libaptXHD_encoder.so:system/aptx/lib/libaptXHD_encoder.so \
        device/phh/treble/gammaos/aptx/lib/libaptX_encoder.so:system/aptx/lib/libaptX_encoder.so \
        device/phh/treble/gammaos/aptx/lib64/libaptXHD_encoder.so:system/aptx/lib64/libaptXHD_encoder.so \
        device/phh/treble/gammaos/aptx/lib64/libaptX_encoder.so:system/aptx/lib64/libaptX_encoder.so

PRODUCT_PACKAGES += \
	treble-environ-rc \

PRODUCT_PACKAGES += \
	bootctl \
	vintf \

# Fix Offline Charging on Huawmeme
PRODUCT_PACKAGES += \
	huawei-charger
PRODUCT_COPY_FILES += \
	$(call find-copy-subdir-files,*,device/phh/treble/huawei_charger/files,system/etc/charger)

PRODUCT_COPY_FILES += \
	device/phh/treble/twrp/twrp.rc:system/etc/init/twrp.rc \
	device/phh/treble/twrp/twrp.sh:system/bin/twrp.sh \
	device/phh/treble/twrp/busybox-armv7l:system/bin/busybox_phh

PRODUCT_PACKAGES += \
    simg2img_simple \
    lptools

ifneq (,$(wildcard external/exfat))
PRODUCT_PACKAGES += \
	mkfs.exfat \
	fsck.exfat
endif

PRODUCT_PACKAGES += \
	android.hidl.manager-V1.0-java \
	android.hardware.wifi.hostapd-V1.0-java \
	vendor.huawei.hardware.biometrics.fingerprint-V2.1-java \
	vendor.huawei.hardware.tp-V1.0-java \
	vendor.qti.hardware.radio.am-V1.0-java \
	vendor.qti.qcril.am-V1.0-java \
	vendor.xiaomi.hardware.displayfeature-V1.0-java

PRODUCT_COPY_FILES += \
	device/phh/treble/interfaces.xml:system/etc/permissions/interfaces.xml

PRODUCT_COPY_FILES += \
	device/phh/treble/files/samsung-gpio_keys.kl:system/phh/samsung-gpio_keys.kl \
	device/phh/treble/files/samsung-sec_touchscreen.kl:system/phh/samsung-sec_touchscreen.kl \
	device/phh/treble/files/samsung-sec_touchkey.kl:system/phh/samsung-sec_touchkey.kl \
	device/phh/treble/files/oneplus6-synaptics_s3320.kl:system/phh/oneplus6-synaptics_s3320.kl \
	device/phh/treble/files/huawei-fingerprint.kl:system/phh/huawei/fingerprint.kl \
	device/phh/treble/files/samsung-sec_e-pen.idc:system/usr/idc/sec_e-pen.idc \
	device/phh/treble/files/samsung-9810-floating_feature.xml:system/ph/sam-9810-flo_feat.xml \
	device/phh/treble/files/mimix3-gpio-keys.kl:system/phh/mimix3-gpio-keys.kl \
	device/phh/treble/files/nokia-soc_gpio_keys.kl:system/phh/nokia-soc_gpio_keys.kl \
	device/phh/treble/files/lenovo-synaptics_dsx.kl:system/phh/lenovo-synaptics_dsx.kl \
	device/phh/treble/files/oppo-touchpanel.kl:system/phh/oppo-touchpanel.kl \
	device/phh/treble/files/google-uinput-fpc.kl:system/phh/google-uinput-fpc.kl \
	device/phh/treble/files/moto-uinput-egis.kl:system/phh/moto-uinput-egis.kl \
	device/phh/treble/files/daisy-buttonJack.kl:system/phh/daisy-buttonJack.kl \
	device/phh/treble/files/daisy-uinput-fpc.kl:system/phh/daisy-uinput-fpc.kl \
	device/phh/treble/files/daisy-uinput-goodix.kl:system/phh/daisy-uinput-goodix.kl \
	device/phh/treble/files/nubia-nubia_synaptics_dsx.kl:system/phh/nubia-nubia_synaptics_dsx.kl \
	device/phh/treble/files/unihertz-mtk-kpd.kl:system/phh/unihertz-mtk-kpd.kl \
	device/phh/treble/files/unihertz-mtk-tpd.kl:system/phh/unihertz-mtk-tpd.kl \
	device/phh/treble/files/unihertz-mtk-tpd-kpd.kl:system/phh/unihertz-mtk-tpd-kpd.kl \
	device/phh/treble/files/unihertz-fingerprint_key.kl:system/phh/unihertz-fingerprint_key.kl \
	device/phh/treble/files/zf6-goodixfp.kl:system/phh/zf6-goodixfp.kl \
	device/phh/treble/files/zf6-googlekey_input.kl:system/phh/zf6-googlekey_input.kl \
	device/phh/treble/files/teracube2e-mtk-kpd.kl:system/phh/teracube2e-mtk-kpd.kl \
	device/phh/treble/files/bv9500plus-mtk-kpd.kl:system/phh/bv9500plus-mtk-kpd.kl \
	device/phh/treble/files/moto-liber-gpio-keys.kl:system/phh/moto-liber-gpio-keys.kl \
	device/phh/treble/files/tecno-touchpanel.kl:system/phh/tecno-touchpanel.kl \
	device/phh/treble/files/rosemary-excluded-input-devices.xml:system/phh/rosemary-excluded-input-devices.xml

SELINUX_IGNORE_NEVERALLOWS := true

# Universal NoCutoutOverlay
PRODUCT_PACKAGES += \
    NoCutoutOverlay

PRODUCT_PACKAGES += \
    lightsctl \
    lightsctl-aidl \
    uevent

PRODUCT_COPY_FILES += \
	device/phh/treble/files/adbd.rc:system/etc/init/adbd.rc

#MTK incoming SMS fix
PRODUCT_PACKAGES += \
	mtk-sms-fwk-ready

# Helper to debug Xiaomi motorized camera
PRODUCT_PACKAGES += \
	xiaomi-motor \
	oneplus-motor

PRODUCT_PACKAGES += \
	Stk

PRODUCT_PACKAGES += \
	resetprop_phh

PRODUCT_COPY_FILES += \
	device/phh/treble/phh-securize.sh:system/bin/phh-securize.sh \
	device/phh/treble/files/ota.sh:system/bin/ota.sh \

PRODUCT_COPY_FILES += \
	device/phh/treble/remove-telephony.sh:system/bin/remove-telephony.sh \

PRODUCT_COPY_FILES += \
	frameworks/native/data/etc/android.software.secure_lock_screen.xml:system/etc/permissions/android.software.secure_lock_screen.xml \
	device/phh/treble/files/android.software.controls.xml:system/etc/permissions/android.software.controls.xml \

PRODUCT_COPY_FILES += \
        device/phh/treble/ld.config.26.txt:system/etc/ld.config.26.txt \

PRODUCT_PACKAGES += \
    asus-motor

# Privapp-permissions whitelist for PhhTrebleApp
PRODUCT_COPY_FILES += \
	device/phh/treble/privapp-permissions-me.phh.treble.app.xml:system/etc/permissions/privapp-permissions-me.phh.treble.app.xml

# Remote debugging
PRODUCT_COPY_FILES += \
	device/phh/treble/remote/dbclient:system/bin/dbclient \
	device/phh/treble/remote/phh-remotectl.rc:system/etc/init/phh-remotectl.rc \
	device/phh/treble/remote/phh-remotectl.sh:system/bin/phh-remotectl.sh \

PRODUCT_PACKAGES += \
	android.hardware.biometrics.fingerprint@2.1-service.oppo.compat \
	android.hardware.biometrics.fingerprint@2.1-service.oplus.compat \

PRODUCT_PACKAGES += \
	vr_hwc \
	curl \
	healthd \

PRODUCT_SYSTEM_DEFAULT_PROPERTIES += \
	debug.fdsan=warn_once \
	ro.apex.updatable=false \
	persist.sys.fflag.override.settings_provider_model=false \
	ro.setupwizard.mode=OPTIONAL \

PRODUCT_PRODUCT_PROPERTIES += \
	ro.setupwizard.mode=OPTIONAL \

# AOSP overlays
PRODUCT_PACKAGES += \
    NavigationBarMode2ButtonOverlay

PRODUCT_PACKAGES += \
	oplus-alert-slider

PRODUCT_COPY_FILES += \
	device/phh/treble/empty:system/etc/smartpa_params/empty \
	device/phh/treble/proprietary-files/gome/fs16xx_01s_left.preset:system/phh/gome/fs16xx_01s_left.preset \
	device/phh/treble/proprietary-files/gome/fs16xx_01s_mono.preset:system/phh/gome/fs16xx_01s_mono.preset \
	device/phh/treble/proprietary-files/gome/fs16xx_01s_right.preset:system/phh/gome/fs16xx_01s_right.preset \
	device/phh/treble/proprietary-files/umidigi/fs16xx_01s_mono.preset:system/phh/umidigi/fs16xx_01s_mono.preset

PRODUCT_PACKAGES += phh-ota

PRODUCT_PACKAGES += \
    xiaomi-touch

PRODUCT_COPY_FILES += \
	frameworks/av/services/audiopolicy/config/a2dp_audio_policy_configuration_7_0.xml:system/etc/a2dp_audio_policy_configuration_7_0.xml \
	frameworks/av/services/audiopolicy/config/a2dp_audio_policy_configuration.xml:system/etc/a2dp_audio_policy_configuration.xml \

include build/make/target/product/gsi_release.mk

# Protect deskclock from power save
PRODUCT_COPY_FILES += \
	device/phh/treble/files/com.android.deskclock_whitelist.xml:system/etc/sysconfig/com.android.deskclock_whitelist.xml
