/*
 * Copyright 2020, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "android.hardware.security.keymint-impl"
#include <log/log.h>

#include "AndroidKeyMintOperation.h"

#include <aidl/android/hardware/security/keymint/ErrorCode.h>
#include <aidl/android/hardware/security/secureclock/ISecureClock.h>

#include <keymaster/android_keymaster.h>

#include "KeyMintUtils.h"

namespace aidl::android::hardware::security::keymint {

using ::keymaster::AbortOperationRequest;
using ::keymaster::AbortOperationResponse;
using ::keymaster::FinishOperationRequest;
using ::keymaster::FinishOperationResponse;
using ::keymaster::TAG_ASSOCIATED_DATA;
using ::keymaster::UpdateOperationRequest;
using ::keymaster::UpdateOperationResponse;
using secureclock::TimeStampToken;
using namespace km_utils;  // NOLINT(google-build-using-namespace)

AndroidKeyMintOperation::AndroidKeyMintOperation(
    shared_ptr<::keymaster::AndroidKeymaster> implementation, keymaster_operation_handle_t opHandle)
    : impl_(std::move(implementation)), opHandle_(opHandle) {}

AndroidKeyMintOperation::~AndroidKeyMintOperation() {
    if (opHandle_ != 0) {
        abort();
    }
}

ScopedAStatus
AndroidKeyMintOperation::updateAad(const vector<uint8_t>& input,
                                   const optional<HardwareAuthToken>& /* authToken */,
                                   const optional<TimeStampToken>& /* timestampToken */) {
    UpdateOperationRequest request(impl_->message_version());
    request.op_handle = opHandle_;
    request.additional_params.push_back(TAG_ASSOCIATED_DATA, input.data(), input.size());

    UpdateOperationResponse response(impl_->message_version());
    impl_->UpdateOperation(request, &response);

    return kmError2ScopedAStatus(response.error);
}

ScopedAStatus AndroidKeyMintOperation::update(const vector<uint8_t>& input,
                                              const optional<HardwareAuthToken>& /* authToken */,
                                              const optional<TimeStampToken>&
                                              /* timestampToken */,
                                              vector<uint8_t>* output) {
    if (!output) return kmError2ScopedAStatus(KM_ERROR_OUTPUT_PARAMETER_NULL);

    UpdateOperationRequest request(impl_->message_version());
    request.op_handle = opHandle_;
    request.input.Reinitialize(input.data(), input.size());

    UpdateOperationResponse response(impl_->message_version());
    impl_->UpdateOperation(request, &response);

    if (response.error != KM_ERROR_OK) return kmError2ScopedAStatus(response.error);
    if (response.input_consumed != request.input.buffer_size()) {
        return kmError2ScopedAStatus(KM_ERROR_UNKNOWN_ERROR);
    }

    *output = kmBuffer2vector(response.output);
    return ScopedAStatus::ok();
}

ScopedAStatus
AndroidKeyMintOperation::finish(const optional<vector<uint8_t>>& input,      //
                                const optional<vector<uint8_t>>& signature,  //
                                const optional<HardwareAuthToken>& /* authToken */,
                                const optional<TimeStampToken>& /* timestampToken */,
                                const optional<vector<uint8_t>>& /* confirmationToken */,
                                vector<uint8_t>* output) {

    if (!output) {
        return ScopedAStatus(AStatus_fromServiceSpecificError(
            static_cast<int32_t>(ErrorCode::OUTPUT_PARAMETER_NULL)));
    }

    FinishOperationRequest request(impl_->message_version());
    request.op_handle = opHandle_;
    if (input) request.input.Reinitialize(input->data(), input->size());
    if (signature) request.signature.Reinitialize(signature->data(), signature->size());

    FinishOperationResponse response(impl_->message_version());
    impl_->FinishOperation(request, &response);
    opHandle_ = 0;

    if (response.error != KM_ERROR_OK) return kmError2ScopedAStatus(response.error);

    *output = kmBuffer2vector(response.output);
    return ScopedAStatus::ok();
}

ScopedAStatus AndroidKeyMintOperation::abort() {
    AbortOperationRequest request(impl_->message_version());
    request.op_handle = opHandle_;

    AbortOperationResponse response(impl_->message_version());
    impl_->AbortOperation(request, &response);
    opHandle_ = 0;

    return kmError2ScopedAStatus(response.error);
}

}  // namespace aidl::android::hardware::security::keymint
