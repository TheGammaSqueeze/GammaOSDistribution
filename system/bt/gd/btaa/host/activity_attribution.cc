/*
 * Copyright 2020 The Android Open Source Project
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

#include "btaa/activity_attribution.h"

#include "module.h"

namespace bluetooth {
namespace activity_attribution {

struct ActivityAttribution::impl {};

void ActivityAttribution::OnWakelockAcquired() {}

void ActivityAttribution::OnWakelockReleased() {}

void ActivityAttribution::OnWakeup() {}

void ActivityAttribution::RegisterActivityAttributionCallback(ActivityAttributionCallback* callback) {}

std::string ActivityAttribution::ToString() const {
  return "Btaa Module";
}

void ActivityAttribution::ListDependencies(ModuleList* list) {}

void ActivityAttribution::Start() {}

void ActivityAttribution::Stop() {}

const ModuleFactory ActivityAttribution::Factory = ModuleFactory([]() { return new ActivityAttribution(); });

DumpsysDataFinisher EmptyDumpsysDataFinisher = [](DumpsysDataBuilder* dumpsys_data_builder) {};
DumpsysDataFinisher ActivityAttribution::GetDumpsysData(flatbuffers::FlatBufferBuilder* builder) const {
  return EmptyDumpsysDataFinisher;
}
}  // namespace activity_attribution
}  // namespace bluetooth
