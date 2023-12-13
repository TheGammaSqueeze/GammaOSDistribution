#
# Copyright (C) 2018-2019 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This file contains the definitions needed for a _really_ minimal system
# image to be run under emulation under upstream QEMU (www.qemu.org), once
# it supports a few Android virtual devices. Note that this is _not_ the
# same as running under the Android emulator.

PRODUCT_SOONG_NAMESPACES += device/generic/goldfish

PRODUCT_PACKAGES += \
    com.android.adbd \
    adbd_system_api \
    android.hardware.confirmationui@1.0-service.trusty \
    android.hidl.allocator@1.0-service \
    android.system.suspend@1.0-service \
    apexd \
    com.android.art \
    com.android.i18n \
    com.android.runtime \
    dhcpclient \
    gatekeeperd \
    hwservicemanager \
    init_system \
    init_vendor \
    init.environ.rc \
    keymaster_soft_wrapped_attestation_keys.xml \
    libandroid_servers \
    libc.bootstrap \
    libdl.bootstrap \
    libdl_android.bootstrap \
    libm.bootstrap \
    linker \
    linker64 \
    linkerconfig \
    logcat \
    logd \
    logwrapper \
    mediaserver \
    mdnsd \
    reboot \
    securedpud \
    servicemanager \
    sh \
    su \
    toolbox \
    toybox \
    vndservicemanager \
    vold \

# VINTF stuff for system and vendor (no product / odm / system_ext / etc.)
PRODUCT_PACKAGES += \
    system_compatibility_matrix.xml \
    system_manifest.xml \
    vendor_compatibility_matrix.xml \
    vendor_manifest.xml \

# Devices that inherit from build/make/target/product/base.mk always have
# /system/system_ext/etc/vintf/manifest.xml generated. And build-time VINTF
# checks assume that. Since we don't inherit from base.mk, add the dependency
# here manually.
PRODUCT_PACKAGES += \
    system_ext_manifest.xml \

# Skip VINTF checks for kernel configs
PRODUCT_OTA_ENFORCE_VINTF_KERNEL_REQUIREMENTS := false

# Ensure boringssl NIAP check won't reboot us
PRODUCT_PACKAGES += \
    com.android.conscrypt \
    boringssl_self_test \

# SELinux packages are added as dependencies of the selinux_policy
# phony package.
PRODUCT_PACKAGES += \
    selinux_policy \

PRODUCT_HOST_PACKAGES += \
    adb \
    e2fsdroid \
    make_f2fs \
    mdnsd \
    mke2fs \
    sload_f2fs \
    toybox \

PRODUCT_COPY_FILES += \
    system/core/rootdir/init.usb.rc:system/etc/init/hw/init.usb.rc \
    system/core/rootdir/init.usb.configfs.rc:system/etc/init/hw/init.usb.configfs.rc \
    system/core/rootdir/etc/hosts:system/etc/hosts \

PRODUCT_FULL_TREBLE_OVERRIDE := true

PRODUCT_COPY_FILES += \
    device/generic/trusty/fstab.ranchu:root/fstab.qemu_trusty \
    device/generic/trusty/init.qemu_trusty.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/hw/init.qemu_trusty.rc \
    device/generic/trusty/ueventd.qemu_trusty.rc:$(TARGET_COPY_OUT_VENDOR)/etc/ueventd.rc \

PRODUCT_COPY_FILES += \
    device/generic/goldfish/data/etc/config.ini:config.ini \
    device/generic/trusty/advancedFeatures.ini:advancedFeatures.ini \

# for Trusty
$(call inherit-product, system/core/trusty/trusty-base.mk)
$(call inherit-product, system/core/trusty/trusty-storage.mk)
$(call inherit-product, system/core/trusty/trusty-test.mk)

# Test Utilities
PRODUCT_PACKAGES += \
    tipc-test \
    libtrusty_metrics_test \
    trusty-ut-ctrl \
    VtsHalConfirmationUIV1_0TargetTest \
    VtsHalGatekeeperV1_0TargetTest \
    VtsHalKeymasterV3_0TargetTest \
    VtsHalKeymasterV4_0TargetTest \

PRODUCT_BOOT_JARS := \
    $(ART_APEX_JARS) \
    ext \
    com.android.i18n:core-icu4j \
    framework-minus-apex \
    telephony-common \
    voip-common \
    ims-common \

PRODUCT_UPDATABLE_BOOT_JARS := \
    com.android.conscrypt:conscrypt \
    com.android.os.statsd:framework-statsd \
    com.android.wifi:framework-wifi \
    com.android.tethering:framework-tethering \

