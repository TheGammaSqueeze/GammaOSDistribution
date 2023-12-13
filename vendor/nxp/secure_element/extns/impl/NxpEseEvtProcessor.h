/******************************************************************************
 *
 *  Copyright 2019 NXP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/
#ifndef VENDOR_NXP_NXPESEEVTPROCESSOR_V1_0_NXPESENFCCNTC_H
#define VENDOR_NXP_NXPESEEVTPROCESSOR_V1_0_NXPESENFCCNTC_H

#include <hardware/hardware.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <vendor/nxp/eventprocessor/1.0/INxpEseEvtProcessor.h>
#include "hal_nxpese.h"
#include "utils/Log.h"

namespace vendor {
namespace nxp {
namespace eventprocessor {
namespace V1_0 {
namespace implementation {

using ::android::hidl::base::V1_0::DebugInfo;
using ::android::hidl::base::V1_0::IBase;
using ::vendor::nxp::eventprocessor::V1_0::INxpEseEvtProcessor;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;


struct NxpEseEvtProcessor : public INxpEseEvtProcessor {
  Return<void> nfccNtf(uint64_t ntfType, const hidl_vec<uint8_t> &ntfData);
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace eventprocessor
}  // namespace nxp
}  // namespace vendor

#endif  // VENDOR_NXP_NXPESEEVTPROCESSOR_V1_0_NXPESENFCCNTC_H
