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

#include "../MessageDefinition.h"

#include <linux/genetlink.h>

namespace android::nl::protocols::generic {

class GenericMessageBase : public MessageDefinition<genlmsghdr> {
  public:
    typedef std::map<uint8_t, std::string> GenericCommandNameMap;

    GenericMessageBase(
            nlmsgtype_t msgtype, const std::string&& msgname,
            const std::initializer_list<GenericCommandNameMap::value_type> commandNames = {},
            const std::initializer_list<AttributeMap::value_type> attrTypes = {});

    void toStream(std::stringstream& ss, const genlmsghdr& data) const override;

  private:
    const GenericCommandNameMap mCommandNames;
};

}  // namespace android::nl::protocols::generic
