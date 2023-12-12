/*
 * Copyright (C) 2019 The Android Open Source Project
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

//#define LOG_NDEBUG 0
#define LOG_TAG "GCH_PendingRequestsTracker"
#define ATRACE_TAG ATRACE_TAG_CAMERA
#include <log/log.h>
#include <utils/Trace.h>

#include "pending_requests_tracker.h"

namespace android {
namespace google_camera_hal {

std::unique_ptr<PendingRequestsTracker> PendingRequestsTracker::Create(
    const std::vector<HalStream>& hal_configured_streams,
    const std::unordered_map<int32_t, int32_t>& grouped_stream_id_map) {
  auto tracker =
      std::unique_ptr<PendingRequestsTracker>(new PendingRequestsTracker());
  if (tracker == nullptr) {
    ALOGE("%s: Failed to create PendingRequestsTracker", __FUNCTION__);
    return nullptr;
  }

  status_t res =
      tracker->Initialize(hal_configured_streams, grouped_stream_id_map);
  if (res != OK) {
    ALOGE("%s: Initializing stream buffer tracker failed: %s(%d)", __FUNCTION__,
          strerror(-res), res);
    return nullptr;
  }

  return tracker;
}

status_t PendingRequestsTracker::Initialize(
    const std::vector<HalStream>& hal_configured_streams,
    const std::unordered_map<int32_t, int32_t>& grouped_stream_id_map) {
  grouped_stream_id_map_ = grouped_stream_id_map;
  for (auto& hal_stream : hal_configured_streams) {
    int hal_stream_id = OverrideStreamIdForGroup(hal_stream.id);
    // For grouped hal streams, only use one stream to represent the whole group
    if (hal_stream_id == hal_stream.id) {
      auto [max_buffer_it, max_buffer_inserted] =
          stream_max_buffers_.emplace(hal_stream_id, hal_stream.max_buffers);
      if (!max_buffer_inserted) {
        ALOGE("%s: There are duplicated stream id %d", __FUNCTION__,
              hal_stream_id);
        return BAD_VALUE;
      }

      stream_pending_buffers_.emplace(hal_stream_id, /*pending_buffers=*/0);
      stream_acquired_buffers_.emplace(hal_stream_id, /*pending_buffers=*/0);
    }
  }

  return OK;
}

bool PendingRequestsTracker::IsStreamConfigured(int32_t stream_id) const {
  return stream_max_buffers_.find(stream_id) != stream_max_buffers_.end();
}

int32_t PendingRequestsTracker::OverrideStreamIdForGroup(int32_t stream_id) const {
  if (grouped_stream_id_map_.count(stream_id) == 1) {
    return grouped_stream_id_map_.at(stream_id);
  } else {
    return stream_id;
  }
}

void PendingRequestsTracker::TrackRequestBuffersLocked(
    const std::vector<StreamBuffer>& requested_buffers) {
  ATRACE_CALL();

  for (auto& buffer : requested_buffers) {
    int32_t stream_id = OverrideStreamIdForGroup(buffer.stream_id);
    if (!IsStreamConfigured(stream_id)) {
      ALOGW("%s: stream %d was not configured.", __FUNCTION__, stream_id);
      // Continue to track other buffers.
      continue;
    }

    stream_pending_buffers_[stream_id]++;
  }
}

status_t PendingRequestsTracker::TrackReturnedResultBuffers(
    const std::vector<StreamBuffer>& returned_buffers) {
  ATRACE_CALL();

  {
    std::lock_guard<std::mutex> lock(pending_requests_mutex_);
    for (auto& buffer : returned_buffers) {
      int32_t stream_id = OverrideStreamIdForGroup(buffer.stream_id);
      if (!IsStreamConfigured(stream_id)) {
        ALOGW("%s: stream %d was not configured.", __FUNCTION__, stream_id);
        // Continue to track other buffers.
        continue;
      }

      if (stream_pending_buffers_[stream_id] == 0) {
        ALOGE("%s: stream %d should not have any pending quota buffers.",
              __FUNCTION__, stream_id);
        // Continue to track other buffers.
        continue;
      }

      stream_pending_buffers_[stream_id]--;
      if (stream_pending_buffers_[stream_id] == 0) {
        ALOGV("%s: stream %d all pending buffers have been returned.",
              __FUNCTION__, stream_id);
      }
    }
  }

  tracker_request_condition_.notify_one();
  return OK;
}

status_t PendingRequestsTracker::TrackReturnedAcquiredBuffers(
    const std::vector<StreamBuffer>& returned_buffers) {
  ATRACE_CALL();

  {
    std::lock_guard<std::mutex> lock(pending_acquisition_mutex_);
    for (auto& buffer : returned_buffers) {
      int32_t stream_id = OverrideStreamIdForGroup(buffer.stream_id);
      if (!IsStreamConfigured(stream_id)) {
        ALOGW("%s: stream %d was not configured.", __FUNCTION__, stream_id);
        // Continue to track other buffers.
        continue;
      }

      if (stream_acquired_buffers_[stream_id] == 0) {
        if (buffer.status == BufferStatus::kOk) {
          ALOGE("%s: stream %d should not have any pending acquired buffers.",
                __FUNCTION__, stream_id);
        } else {
          // This may indicate that HAL doesn't intend to process a certain
          // buffer, so the buffer isn't sent to pipeline and it's not
          // explicitly allocated and recorded in buffer cache manager.
          // The buffer still needs to return to framework with an error status
          // if HAL doesn't process it.
          ALOGV(
              "%s: stream %d isn't acquired but returned with buffer status %u",
              __FUNCTION__, stream_id, buffer.status);
        }
        // Continue to track other buffers.
        continue;
      }

      stream_acquired_buffers_[stream_id]--;
    }
  }

  tracker_acquisition_condition_.notify_one();
  return OK;
}

void PendingRequestsTracker::OnBufferCacheFlushed() {
  std::unique_lock<std::mutex> lock(pending_requests_mutex_);
  requested_stream_ids_.clear();
}

bool PendingRequestsTracker::DoStreamsHaveEnoughBuffersLocked(
    const std::vector<StreamBuffer>& buffers) const {
  for (auto& buffer : buffers) {
    int32_t stream_id = OverrideStreamIdForGroup(buffer.stream_id);
    if (!IsStreamConfigured(stream_id)) {
      ALOGE("%s: stream %d was not configured.", __FUNCTION__, stream_id);
      return false;
    }

    if (stream_pending_buffers_.at(stream_id) >=
        stream_max_buffers_.at(stream_id)) {
      ALOGV("%s: stream %d is not ready. max_buffers=%u", __FUNCTION__,
            stream_id, stream_max_buffers_.at(stream_id));
      return false;
    }
  }

  return true;
}

bool PendingRequestsTracker::DoesStreamHaveEnoughBuffersToAcquireLocked(
    int32_t stream_id, uint32_t num_buffers) const {
  if (!IsStreamConfigured(stream_id)) {
    ALOGE("%s: stream %d was not configured.", __FUNCTION__, stream_id);
    return false;
  }

  if (stream_acquired_buffers_.at(stream_id) + num_buffers >
      stream_max_buffers_.at(stream_id)) {
    ALOGV("%s: stream %d is not ready. max_buffers=%u", __FUNCTION__, stream_id,
          stream_max_buffers_.at(stream_id));
    return false;
  }

  return true;
}

status_t PendingRequestsTracker::UpdateRequestedStreamIdsLocked(
    const std::vector<StreamBuffer>& requested_buffers,
    std::vector<int32_t>* first_requested_stream_ids) {
  if (first_requested_stream_ids == nullptr) {
    ALOGE("%s: first_requested_stream_ids is nullptr", __FUNCTION__);
    return BAD_VALUE;
  }

  for (auto& buffer : requested_buffers) {
    int32_t stream_id = OverrideStreamIdForGroup(buffer.stream_id);
    auto stream_id_iter = requested_stream_ids_.find(stream_id);
    if (stream_id_iter == requested_stream_ids_.end()) {
      first_requested_stream_ids->push_back(stream_id);

      // Include all stream IDs in the same group in first_requested_stream_ids
      for (auto& [id_in_group, group_stream_id] : grouped_stream_id_map_) {
        if (group_stream_id == stream_id) {
          first_requested_stream_ids->push_back(id_in_group);
        }
      }
      requested_stream_ids_.emplace(stream_id);
    }
  }

  return OK;
}

status_t PendingRequestsTracker::WaitAndTrackRequestBuffers(
    const CaptureRequest& request,
    std::vector<int32_t>* first_requested_stream_ids) {
  ATRACE_CALL();

  if (first_requested_stream_ids == nullptr) {
    ALOGE("%s: first_requested_stream_ids is nullptr", __FUNCTION__);
    return BAD_VALUE;
  }

  std::unique_lock<std::mutex> lock(pending_requests_mutex_);
  if (!tracker_request_condition_.wait_for(
          lock, std::chrono::milliseconds(kTrackerTimeoutMs), [this, &request] {
            return DoStreamsHaveEnoughBuffersLocked(request.output_buffers);
          })) {
    ALOGE("%s: Waiting for buffer ready timed out.", __FUNCTION__);
    return TIMED_OUT;
  }

  ALOGV("%s: all streams are ready", __FUNCTION__);

  TrackRequestBuffersLocked(request.output_buffers);

  first_requested_stream_ids->clear();
  status_t res = UpdateRequestedStreamIdsLocked(request.output_buffers,
                                                first_requested_stream_ids);
  if (res != OK) {
    ALOGE("%s: Updating requested stream ID for output buffers failed: %s(%d)",
          __FUNCTION__, strerror(-res), res);
    return res;
  }

  return OK;
}

status_t PendingRequestsTracker::WaitAndTrackAcquiredBuffers(
    int32_t stream_id, uint32_t num_buffers) {
  ATRACE_CALL();

  int32_t overridden_stream_id = OverrideStreamIdForGroup(stream_id);

  if (!IsStreamConfigured(overridden_stream_id)) {
    ALOGW("%s: stream %d was not configured.", __FUNCTION__,
          overridden_stream_id);
    // Continue to track other buffers.
    return BAD_VALUE;
  }

  std::unique_lock<std::mutex> lock(pending_acquisition_mutex_);
  if (!tracker_acquisition_condition_.wait_for(
          lock, std::chrono::milliseconds(kAcquireBufferTimeoutMs),
          [this, overridden_stream_id, num_buffers] {
            return DoesStreamHaveEnoughBuffersToAcquireLocked(
                overridden_stream_id, num_buffers);
          })) {
    ALOGW("%s: Waiting to acquire buffer timed out.", __FUNCTION__);
    return TIMED_OUT;
  }

  stream_acquired_buffers_[overridden_stream_id] += num_buffers;

  return OK;
}

void PendingRequestsTracker::TrackBufferAcquisitionFailure(int32_t stream_id,
                                                           uint32_t num_buffers) {
  int32_t overridden_stream_id = OverrideStreamIdForGroup(stream_id);
  if (!IsStreamConfigured(overridden_stream_id)) {
    ALOGW("%s: stream %d was not configured.", __FUNCTION__,
          overridden_stream_id);
    // Continue to track other buffers.
    return;
  }

  std::unique_lock<std::mutex> lock(pending_acquisition_mutex_);
  stream_acquired_buffers_[overridden_stream_id] -= num_buffers;
}

}  // namespace google_camera_hal
}  // namespace android
