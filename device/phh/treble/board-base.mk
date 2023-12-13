TARGET_SYSTEM_PROP := device/phh/treble/system.prop $(TARGET_SYSTEM_PROP)
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/phh/treble/bluetooth
TARGET_EXFAT_DRIVER := exfat
DEVICE_FRAMEWORK_MANIFEST_FILE := device/phh/treble/framework_manifest.xml

BOARD_ROOT_EXTRA_FOLDERS += bt_firmware sec_storage efs persist
BUILD_BROKEN_ELF_PREBUILT_PRODUCT_COPY_FILES := true

BOARD_ROOT_EXTRA_SYMLINKS := $(filter-out $(BOARD_ROOT_EXTRA_SYMLINKS),/mnt/vendor/persist:/persist)

BOARD_EXT4_SHARE_DUP_BLOCKS := true

TARGET_NO_KERNEL_OVERRIDE := true
