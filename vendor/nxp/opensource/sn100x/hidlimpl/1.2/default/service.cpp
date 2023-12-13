/*
 * Copyright (c) 2018-2019, The Linux Foundation. All rights reserved.
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

#define LOG_TAG "vendor.nxp.hardware.nfc@1.2-service"

#include <android/hardware/nfc/1.1/INfc.h>
#include <vendor/nxp/hardware/nfc/1.1/INqNfc.h>

#include <hidl/LegacySupport.h>
#include "Nfc.h"
#include "NqNfc.h"

using android::hardware::nfc::V1_2::INfc;
using android::hardware::nfc::V1_2::implementation::Nfc;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using vendor::nxp::hardware::nfc::V1_1::INqNfc;
using vendor::nxp::hardware::nfc::V1_1::implementation::NqNfc;
using android::OK;
using android::sp;
using android::status_t;

int main() {
    configureRpcThreadpool(1, true /*callerWillJoin*/);
    status_t status;

    sp<INfc> nfc_service = new Nfc();
    status = nfc_service->registerAsService();
    LOG_ALWAYS_FATAL_IF(status != OK, "Error while registering nfc AOSP service: %d", status);

    sp<INqNfc> nq_nfc_service = new NqNfc();
    status = nq_nfc_service->registerAsService();
    LOG_ALWAYS_FATAL_IF(status != OK, "Error while registering nqnfc vendor service: %d", status);

    joinRpcThreadpool();
    return status;
}
