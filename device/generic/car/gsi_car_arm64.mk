#
# Copyright (C) 2021 The Android Open Source Project
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

$(call inherit-product, device/generic/car/gsi_car_base.mk)
$(call inherit-product, device/generic/common/gsi_arm64.mk)

# This option is specific to the phone GSI, so clear this option after
# gsi_arm64.mk is inherited.
PRODUCT_INSTALL_DEBUG_POLICY_TO_SYSTEM_EXT :=

PRODUCT_NAME := gsi_car_arm64
PRODUCT_DEVICE := generic_arm64
PRODUCT_BRAND := Android
PRODUCT_MODEL := Car GSI on arm64