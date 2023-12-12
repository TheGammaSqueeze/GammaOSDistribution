/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/compiler/xla/pjrt/tpu_client.h"

#include <memory>
#include <vector>

#include "absl/container/inlined_vector.h"
#include "absl/memory/memory.h"
#include "absl/status/status.h"
#include "tensorflow/compiler/xla/client/client_library.h"
#include "tensorflow/compiler/xla/pjrt/local_device_state.h"
#include "tensorflow/compiler/xla/pjrt/pjrt_stream_executor_client.h"
#include "tensorflow/compiler/xla/pjrt/tracked_device_buffer.h"
#include "tensorflow/compiler/xla/service/shaped_buffer.h"
#include "tensorflow/compiler/xla/service/tpu_computation_placer.h"
#include "tensorflow/compiler/xla/shape.h"
#include "tensorflow/compiler/xla/shape_util.h"
#include "tensorflow/compiler/xla/status.h"
#include "tensorflow/compiler/xla/util.h"
#include "tensorflow/core/platform/casts.h"
#include "tensorflow/core/platform/errors.h"
#include "tensorflow/stream_executor/device_memory.h"
#include "tensorflow/stream_executor/lib/statusor.h"
#include "tensorflow/stream_executor/stream.h"
#include "tensorflow/stream_executor/tpu/tpu_executable_interface.h"
#include "tensorflow/stream_executor/tpu/tpu_executor_interface.h"
#include "tensorflow/stream_executor/tpu/tpu_platform_interface.h"
#include "tensorflow/stream_executor/tpu/tpu_stream.h"

namespace tf_tpu = tensorflow::tpu;

namespace xla {
namespace {

class TpuDeviceState : public LocalDeviceState {
 public:
  TpuDeviceState(se::StreamExecutor* executor, LocalClient* client,
                 bool asynchronous);

  Status ThenMemcpyDeviceToDevice(se::Stream* transfer_stream,
                                  se::Stream* dst_stream,
                                  se::DeviceMemoryBase src_buffer,
                                  se::DeviceMemoryBase dst_buffer) override;
};

TpuDeviceState::TpuDeviceState(se::StreamExecutor* executor,
                               LocalClient* client, bool asynchronous)
    : LocalDeviceState(executor, client, LocalDeviceState::kAsynchronous,
                       asynchronous,
                       /*allow_event_reuse=*/false) {}

Status TpuDeviceState::ThenMemcpyDeviceToDevice(
    se::Stream* transfer_stream, se::Stream* dst_stream,
    se::DeviceMemoryBase src_buffer, se::DeviceMemoryBase dst_buffer) {
  auto* transfer_tpu_stream = tensorflow::down_cast<tf_tpu::TpuStream*>(
      transfer_stream->implementation());
  TF_RETURN_IF_ERROR(transfer_tpu_stream->EnqueueOnTpuDeviceSendRecvLocal(
      src_buffer, dst_buffer));
  return Status::OK();
}

class PjRtTpuClient : public PjRtStreamExecutorClient {
 public:
  PjRtTpuClient(LocalClient* client,
                std::vector<std::unique_ptr<PjRtStreamExecutorDevice>> devices,
                int task_id);

  StatusOr<DeviceAssignment> GetDefaultDeviceAssignment(
      int num_replicas, int num_partitions) const override;

  bool EnqueueD2DTransfersOnSrcStream() const override { return false; }

  StatusOr<absl::optional<std::string>> ExecutableFingerprint(
      const PjRtExecutable& executable) const override;
};

PjRtTpuClient::PjRtTpuClient(
    LocalClient* client,
    std::vector<std::unique_ptr<PjRtStreamExecutorDevice>> devices, int task_id)
    : PjRtStreamExecutorClient(kTpuName, client, std::move(devices), task_id,
                               /*allocator=*/nullptr,
                               /*host_memory_allocator=*/nullptr,
                               /*should_stage_host_to_device_transfers=*/false,
                               /*gpu_run_options=*/nullptr) {}

StatusOr<DeviceAssignment> PjRtTpuClient::GetDefaultDeviceAssignment(
    int num_replicas, int num_partitions) const {
  tf_tpu::TpuPlatformInterface* platform =
      tf_tpu::TpuPlatformInterface::GetRegisteredPlatform();
  tf_tpu::TpuHostLocationExternal host = platform->GetTpuHostLocation();
  int num_local_devices = host.Cores(kTensorCore).size();
  if (num_replicas * num_partitions <= num_local_devices) {
    return tf_tpu::TpuComputationPlacer::AssignLocalDevices(host, num_replicas,
                                                            num_partitions);
  }
  // Fallback to default global device assignment if we can't run locally.
  return PjRtStreamExecutorClient::GetDefaultDeviceAssignment(num_replicas,
                                                              num_partitions);
}

StatusOr<absl::optional<std::string>> PjRtTpuClient::ExecutableFingerprint(
    const PjRtExecutable& executable) const {
  if (executable.client() != this) {
    return InvalidArgument(
        "Passed executable from different client (platform '%s') to "
        "PjRtTpuClient::ExecutableFingerprint",
        executable.client()->platform_name());
  }
  if (executable.num_partitions() > 1) {
    LOG(INFO) << "ExecutableFingerprint not fully implemented for MPMD "
                 "executables, fingerprint may not be unique.";
  }
  xla::TpuExecutableInterface* tpu_executable =
      tensorflow::down_cast<xla::TpuExecutableInterface*>(
          tensorflow::down_cast<const PjRtStreamExecutorExecutable*>(
              &executable)
              ->executables()[0]
              ->executable());
  return absl::optional<std::string>(tpu_executable->fingerprint());
}

StatusOr<std::vector<std::unique_ptr<PjRtStreamExecutorDevice>>> GetTpuDevices(
    LocalClient* client,
    std::vector<std::unique_ptr<LocalDeviceState>> local_device_states) {
  std::vector<std::unique_ptr<PjRtStreamExecutorDevice>> devices;
  tf_tpu::TpuTopologyExternal topology =
      tf_tpu::TpuPlatformInterface::GetRegisteredPlatform()->topology();

  std::map<int, int> core_id_to_device_ordinal;
  for (int i = 0; i < client->device_count(); ++i) {
    se::StreamExecutor* executor =
        client->backend().stream_executor(i).ValueOrDie();
    tf_tpu::TpuExecutorInterface* tpu_executor =
        tensorflow::down_cast<tf_tpu::TpuExecutorInterface*>(
            executor->implementation());
    core_id_to_device_ordinal[tpu_executor->GetCoreLocationExternal().Id()] = i;
  }

  for (const tf_tpu::TpuCoreLocationExternal& core :
       topology.cores(TpuCoreTypeEnum::kTensorCore)) {
    auto it = core_id_to_device_ordinal.find(core.Id());
    int device_ordinal =
        (it != core_id_to_device_ordinal.end()) ? it->second : -1;
    int task_id = topology.IdForHost(core.host_coordinates());
    const tf_tpu::TpuDimensionsExternal coords = core.chip_coordinates();
    std::array<int, 3> coords_array = {coords.x, coords.y, coords.z};
    std::unique_ptr<LocalDeviceState> local_device_state;
    if (device_ordinal >= 0) {
      local_device_state = std::move(local_device_states[device_ordinal]);
    }
    auto device = absl::make_unique<PjRtTpuDevice>(
        core, std::move(local_device_state), task_id, coords_array,
        std::string(tf_tpu::TpuVersionEnumToString(topology.version())));
    devices.push_back(std::move(device));
  }
  return devices;
}

}  // namespace

StatusOr<std::shared_ptr<PjRtClient>> GetTpuClient(
    bool asynchronous, absl::Duration init_retry_timeout) {
  tf_tpu::TpuPlatformInterface* platform =
      tf_tpu::TpuPlatformInterface::GetRegisteredPlatform(
          /*initialize_platform=*/true, /*num_tries=*/1);
  if (platform == nullptr) {
    return InvalidArgument("TpuPlatform is not available.");
  }
  // NOTE: We retry in a loop since some pod failures are transient (e.g. some
  // RPCs may timeout waiting for other hosts to come up, but will succeed
  // at a later point if retried).
  auto start = absl::Now();
  // TODO(b/165870356): TpuPlatform::Initialized() always returns true!
  auto status = platform->Initialize({});
  while (!platform->Initialized()) {
    status = platform->Initialize({});
    if (!status.ok()) {
      LOG(ERROR) << "Platform initialization failed: " << status;
      if ((absl::Now() - start) >= init_retry_timeout) {
        return status;
      }
    }
  }
  if (platform->VisibleDeviceCount() <= 0) {
    return InvalidArgument("No TPU devices found.");
  }
  LocalClientOptions options;
  options.set_platform(platform);
  TF_ASSIGN_OR_RETURN(LocalClient * client,
                      ClientLibrary::GetOrCreateLocalClient(options));

  std::vector<std::unique_ptr<LocalDeviceState>> local_device_states;
  local_device_states.reserve(client->device_count());
  for (int i = 0; i < client->device_count(); ++i) {
    se::StreamExecutor* executor =
        client->backend().stream_executor(i).ValueOrDie();
    local_device_states.push_back(
        absl::make_unique<TpuDeviceState>(executor, client, asynchronous));
  }

  TF_ASSIGN_OR_RETURN(auto devices,
                      GetTpuDevices(client, std::move(local_device_states)));
  int task_id = platform->GetTpuHostLocation().Id();

  return std::shared_ptr<PjRtClient>(
      absl::make_unique<PjRtTpuClient>(client, std::move(devices), task_id));
}

}  // namespace xla
