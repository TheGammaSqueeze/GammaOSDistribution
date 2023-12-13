//
// Copyright (C) 2019 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef UPDATE_ENGINE_COMMON_DYNAMIC_PARTITION_CONTROL_STUB_H_
#define UPDATE_ENGINE_COMMON_DYNAMIC_PARTITION_CONTROL_STUB_H_

#include <stdint.h>

#include <memory>
#include <string>
#include <vector>

#include "update_engine/common/dynamic_partition_control_interface.h"

namespace chromeos_update_engine {

class DynamicPartitionControlStub : public DynamicPartitionControlInterface {
 public:
  FeatureFlag GetDynamicPartitionsFeatureFlag() override;
  FeatureFlag GetVirtualAbFeatureFlag() override;
  FeatureFlag GetVirtualAbCompressionFeatureFlag() override;
  bool OptimizeOperation(const std::string& partition_name,
                         const InstallOperation& operation,
                         InstallOperation* optimized) override;
  void Cleanup() override;
  bool PreparePartitionsForUpdate(uint32_t source_slot,
                                  uint32_t target_slot,
                                  const DeltaArchiveManifest& manifest,
                                  bool update,
                                  uint64_t* required_size) override;

  bool FinishUpdate(bool powerwash_required) override;
  std::unique_ptr<AbstractAction> GetCleanupPreviousUpdateAction(
      BootControlInterface* boot_control,
      PrefsInterface* prefs,
      CleanupPreviousUpdateActionDelegateInterface* delegate) override;
  bool ResetUpdate(PrefsInterface* prefs) override;

  bool ListDynamicPartitionsForSlot(
      uint32_t slot,
      uint32_t current_slot,
      std::vector<std::string>* partitions) override;
  bool GetDeviceDir(std::string* path) override;

  bool VerifyExtentsForUntouchedPartitions(
      uint32_t source_slot,
      uint32_t target_slot,
      const std::vector<std::string>& partitions) override;

  std::unique_ptr<android::snapshot::ISnapshotWriter> OpenCowWriter(
      const std::string& unsuffixed_partition_name,
      const std::optional<std::string>&,
      bool is_append) override;

  FileDescriptorPtr OpenCowFd(const std::string& unsuffixed_partition_name,
                              const std::optional<std::string>&,
                              bool is_append = false) override {
    return nullptr;
  }

  bool MapAllPartitions() override;
  bool UnmapAllPartitions() override;

  bool IsDynamicPartition(const std::string& part_name, uint32_t slot) override;
  bool UpdateUsesSnapshotCompression() override;
};
}  // namespace chromeos_update_engine

#endif  // UPDATE_ENGINE_COMMON_DYNAMIC_PARTITION_CONTROL_STUB_H_
