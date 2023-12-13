/*
 * Copyright (c) 2017-2019, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <hardware/hardware.h>
#include <log/log.h>
#include "NqNfc.h"
#include "phNxpNciHal_Adaptation.h"

namespace vendor {
namespace nxp {
namespace hardware {
namespace nfc {
namespace V1_1 {
namespace implementation {

// Methods from ::vendor::nxp::hardware::nfc::V1_0::INqNfc follow.
Return<void> NqNfc::ioctl(uint64_t ioctlType, const hidl_vec<uint8_t>& inputData, ioctl_cb _hidl_cb) {
    uint32_t status;
    nfc_nci_IoctlInOutData_t inpOutData;
    V1_0::NfcData  outputData;

    nfc_nci_IoctlInOutData_t *pInOutData = (nfc_nci_IoctlInOutData_t*)&inputData[0];

    /*
     * data from proxy->stub is copied to local data which can be updated by
     * underlying HAL implementation since its an inout argument
     */
    memcpy(&inpOutData, pInOutData, sizeof(nfc_nci_IoctlInOutData_t));
    if (ioctlType == HAL_NFC_IOCTL_SET_TRANSIT_CONFIG) {
      /*As transit configurations are appended at the end of
      nfc_nci_IoctlInOutData_t, Assign appropriate pointer to TransitConfig*/
      if (inpOutData.inp.data.transitConfig.len == 0) {
        inpOutData.inp.data.transitConfig.val = NULL;
      } else {
        inpOutData.inp.data.transitConfig.val =
            ((char *)pInOutData) + sizeof(nfc_nci_IoctlInOutData_t);
      }
    }
    status = phNxpNciHal_ioctl(ioctlType, &inpOutData);

    /*
     * copy data and additional fields indicating status of ioctl operation
     * and context of the caller. Then invoke the corresponding proxy callback
     */
    inpOutData.out.ioctlType = ioctlType;
    inpOutData.out.context = pInOutData->inp.context;
    inpOutData.out.result = status;
    outputData.setToExternal((uint8_t*)&inpOutData.out, sizeof(nfc_nci_ExtnOutputData_t));
    _hidl_cb(outputData);
    return Void();
}

// Methods from ::vendor::nxp::hardware::nfc::V1_1::INqNfc follow.
Return<void> NqNfc::getNfcChipId(getNfcChipId_cb _hidl_cb) {
    std::string value = phNxpNciHal_getNfcChipId();
    _hidl_cb(value);
    return Void();
}

Return<void> NqNfc::getNfcFirmwareVersion(getNfcFirmwareVersion_cb _hidl_cb) {
    std::string value = phNxpNciHal_getNfcFirmwareVersion();
    _hidl_cb(value);
    return Void();
}


}  // namespace implementation
}  // namespace V1_1
}  // namespace nfc
}  // namespace hardware
}  // namespace nxp
}  // namespace vendor
