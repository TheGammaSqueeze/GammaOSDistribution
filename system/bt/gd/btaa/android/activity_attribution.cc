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

#define LOG_TAG "btaa"

#include "btaa/activity_attribution.h"
#include "activity_attribution_generated.h"

#include <aidl/android/system/suspend/BnSuspendCallback.h>
#include <aidl/android/system/suspend/BnWakelockCallback.h>
#include <aidl/android/system/suspend/ISuspendControlService.h>
#include <android/binder_manager.h>

#include "btaa/attribution_processor.h"
#include "btaa/hci_processor.h"
#include "btaa/wakelock_processor.h"
#include "module.h"
#include "os/log.h"

using aidl::android::system::suspend::BnSuspendCallback;
using aidl::android::system::suspend::BnWakelockCallback;
using aidl::android::system::suspend::ISuspendCallback;
using aidl::android::system::suspend::ISuspendControlService;
using Status = ::ndk::ScopedAStatus;
using namespace ndk;

namespace bluetooth {
namespace activity_attribution {

const ModuleFactory ActivityAttribution::Factory = ModuleFactory([]() { return new ActivityAttribution(); });

static const std::string kBtWakelockName("hal_bluetooth_lock");
static const std::string kBtWakeupReason("hs_uart_wakeup");
static const size_t kHciAclHeaderSize = 4;

struct wakelock_callback : public BnWakelockCallback {
  wakelock_callback(ActivityAttribution* module) : module_(module) {}

  Status notifyAcquired() override {
    module_->OnWakelockAcquired();
    return Status::ok();
  }
  Status notifyReleased() override {
    module_->OnWakelockReleased();
    return Status::ok();
  }

  ActivityAttribution* module_;
};

struct wakeup_callback : public BnSuspendCallback {
  wakeup_callback(ActivityAttribution* module) : module_(module) {}

  Status notifyWakeup(bool success, const std::vector<std::string>& wakeup_reasons) override {
    for (auto& wakeup_reason : wakeup_reasons) {
      if (wakeup_reason.find(kBtWakeupReason) != std::string::npos) {
        module_->OnWakeup();
        break;
      }
    }
    return Status::ok();
  }

  ActivityAttribution* module_;
};

struct ActivityAttribution::impl {
  impl(ActivityAttribution* module) {
    bool is_registered = false;

    auto control_service =
        ISuspendControlService::fromBinder(SpAIBinder(AServiceManager_getService("suspend_control")));
    if (!control_service) {
      LOG_ERROR("Fail to obtain suspend_control");
      return;
    }

    Status register_callback_status =
        control_service->registerCallback(SharedRefBase::make<wakeup_callback>(module), &is_registered);
    if (!is_registered || !register_callback_status.isOk()) {
      LOG_ERROR("Fail to register wakeup callback");
      return;
    }

    register_callback_status = control_service->registerWakelockCallback(
        SharedRefBase::make<wakelock_callback>(module), kBtWakelockName, &is_registered);
    if (!is_registered || !register_callback_status.isOk()) {
      LOG_ERROR("Fail to register wakelock callback");
      return;
    }
  }

  void on_hci_packet(hal::HciPacket packet, hal::SnoopLogger::PacketType type, uint16_t length) {
    attribution_processor_.OnBtaaPackets(std::move(hci_processor_.OnHciPacket(std::move(packet), type, length)));
  }

  void on_wakelock_acquired() {
    wakelock_processor_.OnWakelockAcquired();
  }

  void on_wakelock_released() {
    uint32_t wakelock_duration_ms = 0;

    wakelock_duration_ms = wakelock_processor_.OnWakelockReleased();
    if (wakelock_duration_ms != 0) {
      attribution_processor_.OnWakelockReleased(wakelock_duration_ms);
    }
  }

  void on_wakeup() {
    attribution_processor_.OnWakeup();
  }

  void register_callback(ActivityAttributionCallback* callback) {
    callback_ = callback;
  }

  void Dump(
      std::promise<flatbuffers::Offset<ActivityAttributionData>> promise, flatbuffers::FlatBufferBuilder* fb_builder) {
    attribution_processor_.Dump(std::move(promise), fb_builder);
  }

  ActivityAttributionCallback* callback_;
  AttributionProcessor attribution_processor_;
  HciProcessor hci_processor_;
  WakelockProcessor wakelock_processor_;
};

void ActivityAttribution::Capture(const hal::HciPacket& packet, hal::SnoopLogger::PacketType type) {
  uint16_t original_length = packet.size();
  uint16_t truncate_length;

  switch (type) {
    case hal::SnoopLogger::PacketType::CMD:
    case hal::SnoopLogger::PacketType::EVT:
      truncate_length = packet.size();
      break;
    case hal::SnoopLogger::PacketType::ACL:
    case hal::SnoopLogger::PacketType::SCO:
    case hal::SnoopLogger::PacketType::ISO:
      truncate_length = kHciAclHeaderSize;
      break;
  }

  if (!truncate_length) {
    return;
  }

  hal::HciPacket truncate_packet(packet.begin(), packet.begin() + truncate_length);
  CallOn(pimpl_.get(), &impl::on_hci_packet, truncate_packet, type, original_length);
}

void ActivityAttribution::OnWakelockAcquired() {
  CallOn(pimpl_.get(), &impl::on_wakelock_acquired);
}

void ActivityAttribution::OnWakelockReleased() {
  CallOn(pimpl_.get(), &impl::on_wakelock_released);
}

void ActivityAttribution::OnWakeup() {
  CallOn(pimpl_.get(), &impl::on_wakeup);
}

void ActivityAttribution::RegisterActivityAttributionCallback(ActivityAttributionCallback* callback) {
  CallOn(pimpl_.get(), &impl::register_callback, callback);
}

std::string ActivityAttribution::ToString() const {
  return "Btaa Module";
}

void ActivityAttribution::ListDependencies(ModuleList* list) {}

void ActivityAttribution::Start() {
  pimpl_ = std::make_unique<impl>(this);
}

void ActivityAttribution::Stop() {
  pimpl_.reset();
}

DumpsysDataFinisher ActivityAttribution::GetDumpsysData(flatbuffers::FlatBufferBuilder* fb_builder) const {
  ASSERT(fb_builder != nullptr);

  std::promise<flatbuffers::Offset<ActivityAttributionData>> promise;
  auto future = promise.get_future();
  pimpl_->Dump(std::move(promise), fb_builder);

  auto dumpsys_data = future.get();

  return [dumpsys_data](DumpsysDataBuilder* dumpsys_builder) {
    dumpsys_builder->add_activity_attribution_dumpsys_data(dumpsys_data);
  };
}

}  // namespace activity_attribution
}  // namespace bluetooth
