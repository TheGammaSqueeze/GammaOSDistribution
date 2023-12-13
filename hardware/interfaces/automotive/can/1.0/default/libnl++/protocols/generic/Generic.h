/*
 * Copyright (C) 2020 The Android Open Source Project
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

#include "../NetlinkProtocol.h"

namespace android::nl::protocols::generic {

/**
 * Definition of NETLINK_GENERIC protocol.
 */
class Generic : public NetlinkProtocol {
  public:
    typedef std::map<nlmsgtype_t, std::shared_ptr<MessageDescriptor>> FamilyRegister;

    Generic();

    const std::optional<std::reference_wrapper<MessageDescriptor>> getMessageDescriptor(
            nlmsgtype_t nlmsg_type);

  private:
    FamilyRegister mFamilyRegister;
};

}  // namespace android::nl::protocols::generic
