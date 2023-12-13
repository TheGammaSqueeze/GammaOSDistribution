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

########################################################
# COMMON OS & BL defs
########################################################

include $(CLEAR_NANO_VARS)

LOCAL_MODULE := libnanohub_os_x86
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/../../../NOTICE
LOCAL_AUX_CPU := x86

LOCAL_SRC_FILES := \
    atomic.c \
    atomicBitset.c \
    cpu.c \

include $(BUILD_NANOHUB_OS_STATIC_LIBRARY)
