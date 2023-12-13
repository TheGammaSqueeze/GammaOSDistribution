/*
 * Copyright 2021 HIMSA II K/S - www.himsa.com.
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

#include <hardware/bt_vc.h>

class VolumeControl {
 public:
  virtual ~VolumeControl() = default;

  static void Initialize(bluetooth::vc::VolumeControlCallbacks* callbacks);
  static void CleanUp();
  static VolumeControl* Get();
  static void DebugDump(int fd);

  static void AddFromStorage(const RawAddress& address, bool auto_connect);

  static bool IsVolumeControlRunning();

  /* Volume Control Server (VCS) */
  virtual void Connect(const RawAddress& address) = 0;
  virtual void Disconnect(const RawAddress& address) = 0;
  virtual void SetVolume(std::variant<RawAddress, int> addr_or_group_id,
                         uint8_t volume) = 0;
};
