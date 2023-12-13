/******************************************************************************
 *
 *  Copyright 2019 The Android Open Source Project
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
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

#include "hci/class_of_device.h"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "common/numbers.h"
#include "common/strings.h"
#include "os/log.h"

namespace bluetooth {
namespace hci {

// ClassOfDevice cannot initialize member variables as it is a POD type
// NOLINTNEXTLINE(cppcoreguidelines-pro-type-member-init)
ClassOfDevice::ClassOfDevice(const uint8_t (&class_of_device)[kLength]) {
  std::copy(class_of_device, class_of_device + kLength, cod.data());
};

std::string ClassOfDevice::ToString() const {
  char buffer[] = "000-0-00";
  std::snprintf(&buffer[0], sizeof(buffer), "%03x-%01x-%02x", (static_cast<uint16_t>(cod[2]) << 4) | cod[1] >> 4,
                cod[1] & 0x0f, cod[0]);
  std::string str(buffer);
  return str;
}

std::string ClassOfDevice::ToLegacyConfigString() const {
  return std::to_string(ToUint32Legacy());
}

std::optional<ClassOfDevice> ClassOfDevice::FromString(const std::string& str) {
  if (str.length() != 8) {
    return std::nullopt;
  }

  std::istringstream stream(str);
  std::string token;
  int index = 0;
  uint16_t values[3];

  ClassOfDevice new_cod{};
  while (getline(stream, token, '-')) {
    if (index >= 3) {
      return std::nullopt;
    }

    if (index == 0 && token.length() != 3) {
      return std::nullopt;
    } else if (index == 1 && token.length() != 1) {
      return std::nullopt;
    } else if (index == 2 && token.length() != 2) {
      return std::nullopt;
    }
    char* temp = nullptr;
    values[index] = std::strtol(token.c_str(), &temp, 16);
    if (*temp != '\0') {
      return std::nullopt;
    }

    index++;
  }

  if (index != 3) {
    return std::nullopt;
  }

  new_cod.cod[0] = values[2];
  new_cod.cod[1] = values[1] | ((values[0] & 0xf) << 4);
  new_cod.cod[2] = values[0] >> 4;

  return new_cod;
}

bool ClassOfDevice::FromString(const std::string& from, ClassOfDevice& to) {
  auto new_cod = FromString(from);
  if (!new_cod) {
    to = {};
    return false;
  }
  to = std::move(*new_cod);
  return true;
}

std::optional<ClassOfDevice> ClassOfDevice::FromUint32Legacy(uint32_t cod_int) {
  if (cod_int != 0 && (cod_int >> 24) != 0) {
    return std::nullopt;
  }
  ClassOfDevice result = {};
  result.cod[2] = static_cast<uint8_t>(cod_int);
  result.cod[1] = static_cast<uint8_t>(cod_int >> 8);
  result.cod[0] = static_cast<uint8_t>(cod_int >> 16);
  return result;
}

std::optional<ClassOfDevice> ClassOfDevice::FromLegacyConfigString(const std::string& str) {
  char* ptr = nullptr;
  auto num = std::strtoull(str.data(), &ptr, 10);
  if (num > 0xffffff) {
    return std::nullopt;
  }
  return FromUint32Legacy(static_cast<uint32_t>(num));
}

uint32_t ClassOfDevice::ToUint32Legacy() const {
  return (cod[2]) | (cod[1] << 8) | (cod[0] << 16);
}

size_t ClassOfDevice::FromOctets(const uint8_t* from) {
  std::copy(from, from + kLength, data());
  return kLength;
};

bool ClassOfDevice::IsValid(const std::string& cod) {
  return ClassOfDevice::FromString(cod).has_value();
}
}  // namespace hci
}  // namespace bluetooth
