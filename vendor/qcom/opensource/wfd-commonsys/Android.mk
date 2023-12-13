LOCAL_PATH := $(call my-dir)

ifneq ($(filter $(QSSI_SUPPORTED_PLATFORMS),$(TARGET_BOARD_PLATFORM)),)

#Disable WFD for selected 32-bit targets
ifeq ($(call is-board-platform,bengal),true)
ifeq ($(TARGET_BOARD_SUFFIX),_32)
WFD_DISABLE_PLATFORM_LIST := bengal
endif
endif

# ------------------------------------------------------------------------------
# Guard compilation of vendor projects from qssi/qssi_32 as these modules
# would be scanned during initial stages of qssi/qssi_32 compilation.
# non-src shippable deps of such such modules would raise compilation issues
# in qssi/qssi_32 customer variant compilation.
ifneq ($(call is-product-in-list, qssi qssi_32),true)
ifneq ($(call is-board-platform-in-list,$(WFD_DISABLE_PLATFORM_LIST)),true)
ifneq ($(TARGET_HAS_LOW_RAM), true)
include $(call all-makefiles-under, $(LOCAL_PATH))
endif
endif
endif

endif
