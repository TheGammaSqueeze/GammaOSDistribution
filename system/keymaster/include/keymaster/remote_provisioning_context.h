/*
 * Copyright 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <array>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

#include <cppbor.h>
#include <keymaster/cppcose/cppcose.h>

namespace keymaster {

class RemoteProvisioningContext {
  public:
    RemoteProvisioningContext() {}
    virtual ~RemoteProvisioningContext(){};
    virtual std::vector<uint8_t> DeriveBytesFromHbk(const std::string& context,
                                                    size_t numBytes) const = 0;
    virtual std::unique_ptr<cppbor::Map> CreateDeviceInfo() const = 0;
    virtual std::pair<std::vector<uint8_t>, cppbor::Array> GenerateBcc(bool testMode) const = 0;

    // Generate an HMAC-SHA256 over the given input. This is used to verify a given
    // input hasn't changed across multiple calls to the remote provisioning HAL.
    virtual std::optional<cppcose::HmacSha256>
    GenerateHmacSha256(const cppcose::bytevec& input) const = 0;

    std::vector<uint8_t> devicePrivKey_;
    cppbor::Array bcc_;

  private:
    // Uncopyable.
    RemoteProvisioningContext(const RemoteProvisioningContext&);
    void operator=(const RemoteProvisioningContext&);
};

}  // namespace keymaster
