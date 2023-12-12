# Copyright (C) 2012 The Android Open Source Project
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

# TODO(b/186905324): Switch soc_ver with TARGET_BOARD_PLATFORM
soc_ver := $(TARGET_BOARD_PLATFORM)

LOCAL_PATH:= $(call my-dir)
# HAL module implemenation, not prelinked and stored in
# hw/<COPYPIX_HARDWARE_MODULE_ID>.<ro.product.board>.so

include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := libcutils libdrm liblog libutils libhardware
LOCAL_HEADER_LIBRARIES += generated_kernel_headers

LOCAL_PROPRIETARY_MODULE := true

LOCAL_C_INCLUDES += \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libdrmresource/include

LOCAL_SRC_FILES := \
	libdrmresource/utils/worker.cpp \
	libdrmresource/drm/resourcemanager.cpp \
	libdrmresource/drm/drmdevice.cpp \
	libdrmresource/drm/drmconnector.cpp \
	libdrmresource/drm/drmcrtc.cpp \
	libdrmresource/drm/drmencoder.cpp \
	libdrmresource/drm/drmmode.cpp \
	libdrmresource/drm/drmplane.cpp \
	libdrmresource/drm/drmproperty.cpp \
	libdrmresource/drm/drmeventlistener.cpp \
	libdrmresource/drm/vsyncworker.cpp

LOCAL_CFLAGS := -DHLOG_CODE=0
LOCAL_CFLAGS += -Wno-unused-parameter
LOCAL_CFLAGS += -DSOC_VERSION=$(soc_ver)
LOCAL_EXPORT_SHARED_LIBRARY_HEADERS := libdrm

LOCAL_MODULE := libdrmresource
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/NOTICE
LOCAL_MODULE_TAGS := optional

include $(TOP)/hardware/google/graphics/common/BoardConfigCFlags.mk
include $(BUILD_SHARED_LIBRARY)

################################################################################
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := liblog libcutils libhardware \
	android.hardware.graphics.composer@2.4 \
	android.hardware.graphics.allocator@2.0 \
	android.hardware.graphics.mapper@2.0 \
	libhardware_legacy libutils \
	libsync libacryl libui libion_google libdrmresource libdrm \
	libvendorgraphicbuffer libbinder_ndk \
	android.hardware.power-V1-ndk_platform pixel-power-ext-V1-ndk_platform

LOCAL_SHARED_LIBRARIES += com.google.hardware.pixel.display-V4-ndk_platform \
                          libbinder_ndk \
                          libbase \
                          libpng \
                          libprocessgroup

LOCAL_HEADER_LIBRARIES := libhardware_legacy_headers libbinder_headers google_hal_headers
LOCAL_HEADER_LIBRARIES += libgralloc_headers
LOCAL_HEADER_LIBRARIES += generated_kernel_headers

LOCAL_STATIC_LIBRARIES += libVendorVideoApi
LOCAL_STATIC_LIBRARIES += libjsoncpp
LOCAL_STATIC_LIBRARIES += libaidlcommonsupport
LOCAL_PROPRIETARY_MODULE := true

LOCAL_C_INCLUDES += \
	$(TOP)/hardware/google/graphics/common/include \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libdevice \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libmaindisplay \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libexternaldisplay \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libvirtualdisplay \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libhwchelper \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libresource \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1 \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libmaindisplay \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libexternaldisplay \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libvirtualdisplay \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libresource \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libdevice \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libresource \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libdisplayinterface \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libhwcService \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libdisplayinterface \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libdrmresource/include

LOCAL_SRC_FILES := \
	libhwchelper/ExynosHWCHelper.cpp \
	ExynosHWCDebug.cpp \
	libdevice/ExynosDisplay.cpp \
	libdevice/ExynosDevice.cpp \
	libdevice/ExynosLayer.cpp \
	libmaindisplay/ExynosPrimaryDisplay.cpp \
	libresource/ExynosMPP.cpp \
	libresource/ExynosResourceManager.cpp \
	libexternaldisplay/ExynosExternalDisplay.cpp \
	libvirtualdisplay/ExynosVirtualDisplay.cpp \
	libdisplayinterface/ExynosDeviceInterface.cpp \
	libdisplayinterface/ExynosDisplayInterface.cpp \
	libdisplayinterface/ExynosDeviceDrmInterface.cpp \
	libdisplayinterface/ExynosDisplayDrmInterface.cpp \
	pixel-display.cpp

LOCAL_EXPORT_SHARED_LIBRARY_HEADERS += libacryl libdrm libui libvendorgraphicbuffer

LOCAL_VINTF_FRAGMENTS         += pixel-display-default.xml

include $(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/Android.mk

LOCAL_CFLAGS += -DHLOG_CODE=0
LOCAL_CFLAGS += -DLOG_TAG=\"display\"
LOCAL_CFLAGS += -Wno-unused-parameter
LOCAL_CFLAGS += -DSOC_VERSION=$(soc_ver)

LOCAL_MODULE := libexynosdisplay
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/NOTICE
LOCAL_MODULE_TAGS := optional

include $(TOP)/hardware/google/graphics/common/BoardConfigCFlags.mk
include $(BUILD_SHARED_LIBRARY)

################################################################################

ifeq ($(BOARD_USES_HWC_SERVICES),true)

include $(CLEAR_VARS)

LOCAL_HEADER_LIBRARIES := libhardware_legacy_headers libbinder_headers google_hal_headers
LOCAL_HEADER_LIBRARIES += libgralloc_headers
LOCAL_SHARED_LIBRARIES := liblog libcutils libutils libbinder libexynosdisplay libacryl \
	android.hardware.graphics.composer@2.4 \
	android.hardware.graphics.allocator@2.0 \
	android.hardware.graphics.mapper@2.0

LOCAL_SHARED_LIBRARIES += com.google.hardware.pixel.display-V4-ndk_platform \
                          libbinder_ndk \
                          libbase

LOCAL_STATIC_LIBRARIES += libVendorVideoApi
LOCAL_PROPRIETARY_MODULE := true

LOCAL_C_INCLUDES += \
	$(TOP)/hardware/google/graphics/common/include \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libdevice \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libmaindisplay \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libexternaldisplay \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libvirtualdisplay \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libhwchelper \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libresource \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1 \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libmaindisplay \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libexternaldisplay \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libvirtualdisplay \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libresource \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libdevice \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libresource \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libhwcService \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libdisplayinterface \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libdrmresource/include

LOCAL_EXPORT_SHARED_LIBRARY_HEADERS += libdrm
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_C_INCLUDES)

LOCAL_CFLAGS := -DHLOG_CODE=0
LOCAL_CFLAGS += -DLOG_TAG=\"hwcservice\"
LOCAL_CFLAGS += -DSOC_VERSION=$(soc_ver)

LOCAL_SRC_FILES := \
	libhwcService/IExynosHWC.cpp \
	libhwcService/ExynosHWCService.cpp

LOCAL_MODULE := libExynosHWCService
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/NOTICE
LOCAL_MODULE_TAGS := optional

include $(TOP)/hardware/google/graphics/common/BoardConfigCFlags.mk
include $(BUILD_SHARED_LIBRARY)

endif

################################################################################

include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_SHARED_LIBRARIES := liblog libcutils libutils libexynosdisplay libacryl \
	android.hardware.graphics.composer@2.4 \
	android.hardware.graphics.allocator@2.0 \
	android.hardware.graphics.mapper@2.0 \
	libui

LOCAL_SHARED_LIBRARIES += com.google.hardware.pixel.display-V4-ndk_platform \
                          libbinder_ndk \
                          libbase

LOCAL_PROPRIETARY_MODULE := true
LOCAL_HEADER_LIBRARIES := libhardware_legacy_headers libbinder_headers google_hal_headers
LOCAL_HEADER_LIBRARIES += libgralloc_headers

LOCAL_CFLAGS := -DHLOG_CODE=0
LOCAL_CFLAGS += -DLOG_TAG=\"hwcomposer\"
LOCAL_CFLAGS += -DSOC_VERSION=$(soc_ver)

ifeq ($(BOARD_USES_HWC_SERVICES),true)
LOCAL_CFLAGS += -DUSES_HWC_SERVICES
LOCAL_SHARED_LIBRARIES += libExynosHWCService
endif
LOCAL_STATIC_LIBRARIES += libVendorVideoApi

LOCAL_C_INCLUDES += \
	$(TOP)/hardware/google/graphics/common/include \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libdevice \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libmaindisplay \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libexternaldisplay \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libvirtualdisplay \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libhwchelper \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libresource \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1 \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libmaindisplay \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libexternaldisplay \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libvirtualdisplay \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libresource \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libdevice \
	$(TOP)/hardware/google/graphics/$(soc_ver)/libhwc2.1/libresource \
	$(TOP)/hardware/google/graphics/$(soc_ver)/include \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libhwcService \
	$(TOP)/hardware/google/graphics/common/libhwc2.1/libdisplayinterface

LOCAL_SRC_FILES := \
	ExynosHWC.cpp

LOCAL_MODULE := hwcomposer.$(TARGET_BOARD_PLATFORM)
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/NOTICE
LOCAL_MODULE_TAGS := optional

include $(TOP)/hardware/google/graphics/common/BoardConfigCFlags.mk
include $(BUILD_SHARED_LIBRARY)
