#
# Copyright (C) 2019 The Android Open Source Project
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

# Order of this and the following statements is important.
# Putting this first in the list takes precedence over the one inherited from
# aosp_cf.
OVERRIDE_TARGET_FLATTEN_APEX := true

$(call inherit-product, device/google/cuttlefish/vsoc_x86/phone/aosp_cf.mk)

PRODUCT_NAME := aosp_cf_x86_phone_noapex
PRODUCT_DEVICE := vsoc_x86_noapex
PRODUCT_MANUFACTURER := Google
PRODUCT_MODEL := Cuttlefish x86 phone without APEX support

PRODUCT_VENDOR_PROPERTIES += \
    ro.soc.manufacturer=$(PRODUCT_MANUFACTURER) \
    ro.soc.model=$(PRODUCT_DEVICE)
