#
# Copyright 2017 The Android Open-Source Project
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

#
# Common BoardConfig for all supported architectures.
#

# TODO(b/170639028): Back up TARGET_NO_BOOTLOADER
__TARGET_NO_BOOTLOADER := $(TARGET_NO_BOOTLOADER)
include build/make/target/board/BoardConfigMainlineCommon.mk
TARGET_NO_BOOTLOADER := $(__TARGET_NO_BOOTLOADER)

TARGET_BOOTLOADER_BOARD_NAME := cutf

BOARD_SYSTEMIMAGE_FILE_SYSTEM_TYPE := $(TARGET_RO_FILE_SYSTEM_TYPE)

# Boot partition size: 32M
# This is only used for OTA update packages. The image size on disk
# will not change (as is it not a filesystem.)
BOARD_BOOTIMAGE_PARTITION_SIZE := 67108864
ifdef TARGET_DEDICATED_RECOVERY
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 67108864
endif
BOARD_VENDOR_BOOTIMAGE_PARTITION_SIZE := 67108864

# Build a separate vendor.img partition
BOARD_USES_VENDORIMAGE := true
BOARD_VENDORIMAGE_FILE_SYSTEM_TYPE := $(TARGET_RO_FILE_SYSTEM_TYPE)

BOARD_USES_METADATA_PARTITION := true

# Build a separate product.img partition
BOARD_USES_PRODUCTIMAGE := true
BOARD_PRODUCTIMAGE_FILE_SYSTEM_TYPE := $(TARGET_RO_FILE_SYSTEM_TYPE)

# Build a separate system_ext.img partition
BOARD_USES_SYSTEM_EXTIMAGE := true
BOARD_SYSTEM_EXTIMAGE_FILE_SYSTEM_TYPE := $(TARGET_RO_FILE_SYSTEM_TYPE)
TARGET_COPY_OUT_SYSTEM_EXT := system_ext

# Build a separate odm.img partition
BOARD_USES_ODMIMAGE := true
BOARD_ODMIMAGE_FILE_SYSTEM_TYPE := $(TARGET_RO_FILE_SYSTEM_TYPE)
TARGET_COPY_OUT_ODM := odm

# Build a separate vendor_dlkm partition
BOARD_USES_VENDOR_DLKMIMAGE := true
BOARD_VENDOR_DLKMIMAGE_FILE_SYSTEM_TYPE := ext4
TARGET_COPY_OUT_VENDOR_DLKM := vendor_dlkm

# Build a separate odm_dlkm partition
BOARD_USES_ODM_DLKMIMAGE := true
BOARD_ODM_DLKMIMAGE_FILE_SYSTEM_TYPE := ext4
TARGET_COPY_OUT_ODM_DLKM := odm_dlkm

# FIXME: Remove this once we generate the vbmeta digest correctly
BOARD_AVB_MAKE_VBMETA_IMAGE_ARGS += --flag 2

# Enable chained vbmeta for system image mixing
BOARD_AVB_VBMETA_SYSTEM := product system system_ext
BOARD_AVB_VBMETA_SYSTEM_KEY_PATH := external/avb/test/data/testkey_rsa2048.pem
BOARD_AVB_VBMETA_SYSTEM_ALGORITHM := SHA256_RSA2048
BOARD_AVB_VBMETA_SYSTEM_ROLLBACK_INDEX := $(PLATFORM_SECURITY_PATCH_TIMESTAMP)
BOARD_AVB_VBMETA_SYSTEM_ROLLBACK_INDEX_LOCATION := 1

# Enable chained vbmeta for boot images
BOARD_AVB_BOOT_KEY_PATH := external/avb/test/data/testkey_rsa2048.pem
BOARD_AVB_BOOT_ALGORITHM := SHA256_RSA2048
BOARD_AVB_BOOT_ROLLBACK_INDEX := $(PLATFORM_SECURITY_PATCH_TIMESTAMP)
BOARD_AVB_BOOT_ROLLBACK_INDEX_LOCATION := 2

# Using sha256 for dm-verity partitions. b/178983355
# system, system_other, product.
TARGET_AVB_SYSTEM_HASHTREE_ALGORITHM ?= sha256
TARGET_AVB_SYSTEM_OTHER_HASHTREE_ALGORITHM ?= sha256
TARGET_AVB_PRODUCT_HASHTREE_ALGORITHM ?= sha256
# Using blake2b-256 for system_ext. This give us move coverage of the
# algorithms as we otherwise don't have a device using blake2b-256.
TARGET_AVB_SYSTEM_EXT_HASHTREE_ALGORITHM ?= blake2b-256

BOARD_AVB_SYSTEM_ADD_HASHTREE_FOOTER_ARGS += --hash_algorithm $(TARGET_AVB_SYSTEM_HASHTREE_ALGORITHM)
BOARD_AVB_SYSTEM_OTHER_ADD_HASHTREE_FOOTER_ARGS += --hash_algorithm $(TARGET_AVB_SYSTEM_OTHER_HASHTREE_ALGORITHM)
BOARD_AVB_SYSTEM_EXT_ADD_HASHTREE_FOOTER_ARGS += --hash_algorithm $(TARGET_AVB_SYSTEM_EXT_HASHTREE_ALGORITHM)
BOARD_AVB_PRODUCT_ADD_HASHTREE_FOOTER_ARGS += --hash_algorithm $(TARGET_AVB_PRODUCT_HASHTREE_ALGORITHM)

# vendor and odm.
BOARD_AVB_VENDOR_ADD_HASHTREE_FOOTER_ARGS += --hash_algorithm sha256
BOARD_AVB_ODM_ADD_HASHTREE_FOOTER_ARGS += --hash_algorithm sha256

# vendor_dlkm and odm_dlkm.
BOARD_AVB_VENDOR_DLKM_ADD_HASHTREE_FOOTER_ARGS += --hash_algorithm sha256
BOARD_AVB_ODM_DLKM_ADD_HASHTREE_FOOTER_ARGS += --hash_algorithm sha256

BOARD_USES_GENERIC_AUDIO := false
USE_CAMERA_STUB := true

# Hardware composer configuration
TARGET_USES_HWC2 := true

# The compiler will occasionally generate movaps, etc.
BOARD_MALLOC_ALIGNMENT := 16

# Disable sparse on all filesystem images
TARGET_USERIMAGES_SPARSE_EROFS_DISABLED ?= true
TARGET_USERIMAGES_SPARSE_EXT_DISABLED ?= true
TARGET_USERIMAGES_SPARSE_F2FS_DISABLED ?= true

# Make the userdata partition 6G to accommodate ASAN and CTS
BOARD_USERDATAIMAGE_PARTITION_SIZE := $(TARGET_USERDATAIMAGE_PARTITION_SIZE)
BOARD_USERDATAIMAGE_FILE_SYSTEM_TYPE := $(TARGET_USERDATAIMAGE_FILE_SYSTEM_TYPE)
TARGET_USERIMAGES_USE_F2FS := true

BOARD_GPU_DRIVERS := virgl

# Enable goldfish's encoder.
# TODO(b/113617962) Remove this if we decide to use
# device/generic/opengl-transport to generate the encoder
BUILD_EMULATOR_OPENGL_DRIVER := true
BUILD_EMULATOR_OPENGL := true

# Minimum size of the final bootable disk image: 10G
# GCE will pad disk images out to 10G. Our disk images should be at least as
# big to avoid warnings about partition table oddities.
BOARD_DISK_IMAGE_MINIMUM_SIZE := 10737418240

BOARD_BOOTIMAGE_MAX_SIZE := 8388608
BOARD_SYSLOADER_MAX_SIZE := 7340032
# TODO(san): See if we can get rid of this.
BOARD_FLASH_BLOCK_SIZE := 512

USE_OPENGL_RENDERER := true

# Wifi.
BOARD_WLAN_DEVICE           := wlan0
BOARD_HOSTAPD_DRIVER        := NL80211
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_simulated_cf
WPA_SUPPLICANT_VERSION      := VER_0_8_X
WIFI_DRIVER_FW_PATH_PARAM   := "/dev/null"
WIFI_DRIVER_FW_PATH_STA     := "/dev/null"
WIFI_DRIVER_FW_PATH_AP      := "/dev/null"

# vendor sepolicy
BOARD_VENDOR_SEPOLICY_DIRS += device/google/cuttlefish/shared/sepolicy/vendor
BOARD_VENDOR_SEPOLICY_DIRS += device/google/cuttlefish/shared/sepolicy/vendor/google

BOARD_SEPOLICY_DIRS += system/bt/vendor_libs/linux/sepolicy

# product sepolicy, allow other layers to append
PRODUCT_PRIVATE_SEPOLICY_DIRS += device/google/cuttlefish/shared/sepolicy/product/private
# PRODUCT_PUBLIC_SEPOLICY_DIRS += device/google/cuttlefish/shared/sepolicy/product/public
# system_ext sepolicy
SYSTEM_EXT_PRIVATE_SEPOLICY_DIRS += device/google/cuttlefish/shared/sepolicy/system_ext/private
# SYSTEM_EXT_PUBLIC_SEPOLICY_DIRS += device/google/cuttlefish/shared/sepolicy/system_ext/public

STAGEFRIGHT_AVCENC_CFLAGS := -DANDROID_GCE

INIT_BOOTCHART := true

# Settings for dhcpcd-6.8.2.
DHCPCD_USE_IPV6 := no
DHCPCD_USE_DBUS := no
DHCPCD_USE_SCRIPT := yes


TARGET_RECOVERY_PIXEL_FORMAT := ABGR_8888
TARGET_RECOVERY_UI_LIB := librecovery_ui_cuttlefish
TARGET_RECOVERY_FSTAB ?= device/google/cuttlefish/shared/config/fstab.f2fs

BOARD_SUPER_PARTITION_SIZE := 7516192768  # 7GiB
BOARD_SUPER_PARTITION_GROUPS := google_system_dynamic_partitions google_vendor_dynamic_partitions
BOARD_GOOGLE_SYSTEM_DYNAMIC_PARTITIONS_PARTITION_LIST := product system system_ext
BOARD_GOOGLE_SYSTEM_DYNAMIC_PARTITIONS_SIZE := 5771362304  # 5.375GiB
BOARD_GOOGLE_VENDOR_DYNAMIC_PARTITIONS_PARTITION_LIST := odm vendor vendor_dlkm odm_dlkm
# 1404MiB, reserve 4MiB for dynamic partition metadata
BOARD_GOOGLE_VENDOR_DYNAMIC_PARTITIONS_SIZE := 1472200704
BOARD_BUILD_SUPER_IMAGE_BY_DEFAULT := true
BOARD_SUPER_IMAGE_IN_UPDATE_PACKAGE := true
TARGET_RELEASETOOLS_EXTENSIONS := device/google/cuttlefish/shared

# Generate a partial ota update package for partitions in vbmeta_system
BOARD_PARTIAL_OTA_UPDATE_PARTITIONS_LIST := product system system_ext vbmeta_system

BOARD_BOOTLOADER_IN_UPDATE_PACKAGE := true
BOARD_RAMDISK_USE_LZ4 := true

# To see full logs from init, disable ratelimiting.
# The default is 5 messages per second amortized, with a burst of up to 10.
BOARD_KERNEL_CMDLINE += printk.devkmsg=on
BOARD_KERNEL_CMDLINE += firmware_class.path=/vendor/etc/

BOARD_KERNEL_CMDLINE += init=/init
BOARD_BOOTCONFIG += androidboot.hardware=cutf_cvm

# TODO(b/179489292): Remove once kfence is enabled everywhere
BOARD_KERNEL_CMDLINE += kfence.sample_interval=500

BOARD_KERNEL_CMDLINE += loop.max_part=7

# TODO(b/182417593): Move all of these module options to modules.options
# TODO(b/176860479): Remove once goldfish and cuttlefish share a wifi implementation
BOARD_BOOTCONFIG += kernel.mac80211_hwsim.radios=0
# Reduce slab size usage from virtio vsock to reduce slab fragmentation
BOARD_BOOTCONFIG += \
    kernel.vmw_vsock_virtio_transport_common.virtio_transport_max_vsock_pkt_buf_size=16384

ifeq ($(TARGET_USERDATAIMAGE_FILE_SYSTEM_TYPE),f2fs)
BOARD_BOOTCONFIG += androidboot.fstab_suffix=f2fs
endif

ifeq ($(TARGET_USERDATAIMAGE_FILE_SYSTEM_TYPE),ext4)
BOARD_BOOTCONFIG += androidboot.fstab_suffix=ext4
endif

BOARD_INCLUDE_DTB_IN_BOOTIMG := true
BOARD_BOOT_HEADER_VERSION := 4
BOARD_MKBOOTIMG_ARGS += --header_version $(BOARD_BOOT_HEADER_VERSION)
PRODUCT_COPY_FILES += \
    device/google/cuttlefish/dtb.img:dtb.img \
    device/google/cuttlefish/required_images:required_images \

BOARD_BUILD_SYSTEM_ROOT_IMAGE := false

# Cuttlefish doesn't support ramdump feature yet, exclude the ramdump debug tool.
EXCLUDE_BUILD_RAMDUMP_UPLOADER_DEBUG_TOOL := true

# GKI-related variables.
BOARD_USES_GENERIC_KERNEL_IMAGE := true
ifdef TARGET_DEDICATED_RECOVERY
  BOARD_EXCLUDE_KERNEL_FROM_RECOVERY_IMAGE := true
else
  BOARD_MOVE_RECOVERY_RESOURCES_TO_VENDOR_BOOT := true
endif
BOARD_MOVE_GSI_AVB_KEYS_TO_VENDOR_BOOT := true

# TARGET_KERNEL_USE is defined in kernel.mk, if not defined in the environment variable.
# Keep in sync with GKI APEX in device.mk
ifneq (,$(TARGET_KERNEL_USE))
  ifneq (,$(filter 5.4, $(TARGET_KERNEL_USE)))
    BOARD_KERNEL_MODULE_INTERFACE_VERSIONS := 5.4-android12-0
  else
    BOARD_KERNEL_MODULE_INTERFACE_VERSIONS := $(TARGET_KERNEL_USE)-android12-unstable
  endif
endif

BOARD_GENERIC_RAMDISK_KERNEL_MODULES_LOAD := dm-user.ko

BOARD_HAVE_BLUETOOTH := true
