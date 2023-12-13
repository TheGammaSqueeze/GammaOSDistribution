/*
 * Copyright 2020 HIMSA II K/S - www.himsa.com.
 * Represented by EHIMA - www.ehima.com
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

#include <base/callback.h>
#include <gmock/gmock.h>

#include "hcimsgs.h"

namespace controller {
class ControllerInterface {
 public:
  virtual uint8_t GetIsoBufferCount(void) = 0;
  virtual uint16_t GetIsoDataSize(void) = 0;
  virtual uint16_t GetAclDataSizeBle(void) = 0;

  virtual ~ControllerInterface() = default;
};

class MockControllerInterface : public ControllerInterface {
 public:
  MOCK_METHOD((uint8_t), GetIsoBufferCount, (), (override));
  MOCK_METHOD((uint16_t), GetIsoDataSize, (), (override));
  MOCK_METHOD((uint16_t), GetAclDataSizeBle, (), (override));
};

void SetMockControllerInterface(
    MockControllerInterface* mock_controller_interface);
}  // namespace controller
