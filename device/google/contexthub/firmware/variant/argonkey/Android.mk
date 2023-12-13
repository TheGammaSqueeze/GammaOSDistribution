#
# Copyright (C) 2016 The Android Open Source Project
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

LOCAL_PATH := $(call my-dir)

include $(CLEAR_NANO_VARS)

LOCAL_MODULE := libnanohub_os_argonkey
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/../../NOTICE
LOCAL_MODULE_TAGS := optional
LOCAL_AUX_OS_VARIANT := argonkey

LOCAL_SRC_FILES :=      \
    src/os/i2c.c        \
    src/os/led.c        \
    src/os/spi.c        \

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/inc \

LOCAL_EXPORT_C_INCLUDE_DIRS := \
    $(LOCAL_C_INCLUDES)

include $(BUILD_NANOHUB_OS_STATIC_LIBRARY)
