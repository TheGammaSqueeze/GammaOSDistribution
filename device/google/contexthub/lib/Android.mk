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

src_files := \
    nanohub/aes.c \
    nanohub/rsa.c \
    nanohub/sha2.c \

src_includes := \
    $(LOCAL_PATH)/include \

include $(CLEAR_NANO_VARS)

LOCAL_MODULE := libnanohub_common_bl
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := $(src_files)
LOCAL_C_INCLUDES := $(src_includes)
LOCAL_EXPORT_C_INCLUDE_DIRS := $(src_includes)

include $(BUILD_NANOHUB_BL_STATIC_LIBRARY)

include $(CLEAR_NANO_VARS)

LOCAL_MODULE := libnanohub_common_os
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := nanohub/softcrc.c
LOCAL_C_INCLUDES := $(src_includes)
LOCAL_EXPORT_C_INCLUDE_DIRS := $(src_includes)

include $(BUILD_NANOHUB_OS_STATIC_LIBRARY)

include $(call first-makefiles-under, $(LOCAL_PATH))

src_files :=
src_includes :=
