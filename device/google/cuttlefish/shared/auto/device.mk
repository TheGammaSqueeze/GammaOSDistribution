#
# Copyright (C) 2017 The Android Open Source Project
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
#

################################################
# Begin GCE specific configurations

DEVICE_MANIFEST_FILE += device/google/cuttlefish/shared/auto/manifest.xml

$(call inherit-product, device/google/cuttlefish/shared/device.mk)

# Extend cuttlefish common sepolicy with auto-specific functionality
BOARD_SEPOLICY_DIRS += device/google/cuttlefish/shared/auto/sepolicy/vendor

################################################
# Begin general Android Auto Embedded configurations

PRODUCT_COPY_FILES += \
    packages/services/Car/car_product/init/init.bootstat.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/hw//init.bootstat.rc \
    packages/services/Car/car_product/init/init.car.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/hw//init.car.rc

ifneq ($(LOCAL_SENSOR_FILE_OVERRIDES),true)
    PRODUCT_COPY_FILES += \
        frameworks/native/data/etc/android.hardware.sensor.accelerometer.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.accelerometer.xml \
        frameworks/native/data/etc/android.hardware.sensor.compass.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.compass.xml
endif

PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.bluetooth.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.bluetooth.xml \
    frameworks/native/data/etc/android.hardware.broadcastradio.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.broadcastradio.xml \
    frameworks/native/data/etc/android.hardware.faketouch.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.faketouch.xml \
    frameworks/native/data/etc/android.hardware.screen.landscape.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.screen.landscape.xml \
    frameworks/native/data/etc/android.software.activities_on_secondary_displays.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.software.activities_on_secondary_displays.xml \
    frameworks/native/data/etc/car_core_hardware.xml:system/etc/permissions/car_core_hardware.xml \

# Preinstalled packages per user type
PRODUCT_COPY_FILES += \
    device/google/cuttlefish/shared/auto/preinstalled-packages-product-car-cuttlefish.xml:$(TARGET_COPY_OUT_PRODUCT)/etc/sysconfig/preinstalled-packages-product-car-cuttlefish.xml

LOCAL_AUDIO_PRODUCT_COPY_FILES ?= \
    device/google/cuttlefish/shared/auto/car_audio_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/car_audio_configuration.xml \
    device/google/cuttlefish/shared/auto/audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_configuration.xml \
    frameworks/av/services/audiopolicy/config/a2dp_audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/a2dp_audio_policy_configuration.xml \
    frameworks/av/services/audiopolicy/config/usb_audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/usb_audio_policy_configuration.xml \

PRODUCT_VENDOR_PROPERTIES += \
    keyguard.no_require_sim=true \
    ro.cdma.home.operator.alpha=Android \
    ro.cdma.home.operator.numeric=302780 \
    ro.com.android.dataroaming=true \

# vehicle HAL
ifeq ($(LOCAL_VHAL_PRODUCT_PACKAGE),)
    LOCAL_VHAL_PRODUCT_PACKAGE := android.hardware.automotive.vehicle@2.0-service
    BOARD_SEPOLICY_DIRS += device/google/cuttlefish/shared/auto/sepolicy/vhal
endif
PRODUCT_PACKAGES += $(LOCAL_VHAL_PRODUCT_PACKAGE)

# Broadcast Radio
PRODUCT_PACKAGES += android.hardware.broadcastradio@2.0-service

# AudioControl HAL
ifeq ($(LOCAL_AUDIOCONTROL_HAL_PRODUCT_PACKAGE),)
    LOCAL_AUDIOCONTROL_HAL_PRODUCT_PACKAGE := android.hardware.automotive.audiocontrol-service.example
endif
PRODUCT_PACKAGES += $(LOCAL_AUDIOCONTROL_HAL_PRODUCT_PACKAGE)

# CAN bus HAL
PRODUCT_PACKAGES += android.hardware.automotive.can@1.0-service
PRODUCT_PACKAGES_DEBUG += canhalctrl \
    canhaldump \
    canhalsend

# Cuttlefish RIL support
TARGET_USES_CF_RILD ?= false
ifeq ($(TARGET_USES_CF_RILD),true)
    PRODUCT_PACKAGES += \
        libcuttlefish-ril-2 \
        libcuttlefish-rild
endif

# system_other support
PRODUCT_PACKAGES += \
    cppreopts.sh \

BOARD_IS_AUTOMOTIVE := true

$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base.mk)
$(call inherit-product, frameworks/native/build/phone-xhdpi-2048-dalvik-heap.mk)
$(call inherit-product, packages/services/Car/car_product/build/car.mk)

# Placed here due to b/110784510
PRODUCT_BRAND := generic

DEVICE_PACKAGE_OVERLAYS += device/google/cuttlefish/shared/auto/overlay

TARGET_BOARD_INFO_FILE ?= device/google/cuttlefish/shared/auto/android-info.txt

PRODUCT_ENFORCE_RRO_TARGETS := framework-res

TARGET_NO_TELEPHONY := true
