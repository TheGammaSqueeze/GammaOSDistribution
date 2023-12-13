#
# Copyright (C) 2015 The Android Open Source Project
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

include $(CLEAR_VARS)
LOCAL_STATIC_JAVA_LIBRARIES := androidx.test.rules collector-device-lib
LOCAL_JAVA_LIBRARIES := android.test.runner.stubs android.test.base.stubs

LOCAL_MODULE_TAGS := tests
LOCAL_COMPATIBILITY_SUITE += device-tests

LOCAL_SRC_FILES := $(call all-java-files-under, src/com/android/nn/benchmark)
LOCAL_JNI_SHARED_LIBRARIES := libnnbenchmark_jni

# need fread_unlocked in version 28
LOCAL_SDK_VERSION := 28
LOCAL_ASSET_DIR := $(LOCAL_PATH)/../models/assets

GOOGLE_TEST_MODELS_DIR := vendor/google/tests/mlts/models/assets
ifneq ($(wildcard $(GOOGLE_TEST_MODELS_DIR)),)
LOCAL_ASSET_DIR += $(GOOGLE_TEST_MODELS_DIR)
endif

LOCAL_PACKAGE_NAME := NeuralNetworksApiBenchmark
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0 SPDX-license-identifier-MIT
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/LICENSE
include $(BUILD_PACKAGE)

include $(CLEAR_VARS)

LOCAL_STATIC_JAVA_LIBRARIES := androidx.test.rules
LOCAL_JAVA_LIBRARIES := android.test.runner.stubs android.test.base.stubs

LOCAL_MODULE_TAGS := tests
LOCAL_COMPATIBILITY_SUITE += device-tests

LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_JNI_SHARED_LIBRARIES := libnnbenchmark_jni librandom_graph_test_jni

# need fread_unlocked in version 28
LOCAL_SDK_VERSION := 28
LOCAL_ASSET_DIR := $(LOCAL_PATH)/../models/assets

GOOGLE_TEST_MODELS_DIR := vendor/google/tests/mlts/models/assets
ifneq ($(wildcard $(GOOGLE_TEST_MODELS_DIR)),)
LOCAL_ASSET_DIR += $(GOOGLE_TEST_MODELS_DIR)
endif

LOCAL_PACKAGE_NAME := NeuralNetworksApiCrashTest
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0 SPDX-license-identifier-MIT
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/LICENSE
include $(BUILD_PACKAGE)

include $(CLEAR_VARS)
LOCAL_SDK_VERSION := 28
LOCAL_SRC_FILES := $(call all-java-files-under, src/com/android/nn/benchmark/core) \
    $(call all-java-files-under, src/com/android/nn/benchmark/evaluators) \
    $(call all-java-files-under, src/com/android/nn/benchmark/imageprocessors) \
    $(call all-java-files-under, src/com/android/nn/benchmark/util)
LOCAL_JNI_SHARED_LIBRARIES := libnnbenchmark_jni
LOCAL_MODULE := NeuralNetworksApiBenchmark_Lib
LOCAL_LICENSE_KINDS := SPDX-license-identifier-Apache-2.0
LOCAL_LICENSE_CONDITIONS := notice
LOCAL_NOTICE_FILE := $(LOCAL_PATH)/LICENSE
include $(BUILD_JAVA_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))
