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

#include "Gralloc.h"

#include <aidl/android/hardware/graphics/common/PlaneLayoutComponent.h>
#include <aidl/android/hardware/graphics/common/PlaneLayoutComponentType.h>
#include <drm_fourcc.h>
#include <gralloctypes/Gralloc4.h>
#include <hidl/ServiceManagement.h>
#include <log/log.h>

#include <algorithm>

#include "Drm.h"

using aidl::android::hardware::graphics::common::PlaneLayout;
using aidl::android::hardware::graphics::common::PlaneLayoutComponent;
using aidl::android::hardware::graphics::common::PlaneLayoutComponentType;
using android::hardware::hidl_handle;
using android::hardware::hidl_vec;
using android::hardware::graphics::common::V1_2::BufferUsage;
using android::hardware::graphics::mapper::V4_0::Error;
using android::hardware::graphics::mapper::V4_0::IMapper;
using MetadataType =
    android::hardware::graphics::mapper::V4_0::IMapper::MetadataType;

namespace android {

Gralloc::Gralloc() {
  android::hardware::preloadPassthroughService<IMapper>();

  gralloc4_ = IMapper::getService();
  if (gralloc4_ != nullptr) {
    ALOGE("%s using Gralloc4.", __FUNCTION__);
    return;
  }
  ALOGE("%s Gralloc4 not available.", __FUNCTION__);

  ALOGE("%s No Grallocs available!", __FUNCTION__);
}

Error Gralloc::GetMetadata(buffer_handle_t buffer, MetadataType type,
                           hidl_vec<uint8_t>* metadata) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return Error::NO_RESOURCES;
  }

  if (metadata == nullptr) {
    return Error::BAD_VALUE;
  }

  Error error = Error::NONE;

  auto native_handle = const_cast<native_handle_t*>(buffer);

  auto ret =
      gralloc4_->get(native_handle, type,
                     [&](const auto& get_error, const auto& get_metadata) {
                       error = get_error;
                       *metadata = get_metadata;
                     });

  if (!ret.isOk()) {
    error = Error::NO_RESOURCES;
  }

  if (error != Error::NONE) {
    ALOGE("%s failed to get metadata %s", __FUNCTION__, type.name.c_str());
  }
  return error;
}

std::optional<uint32_t> Gralloc::GetWidth(buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return std::nullopt;
  }

  hidl_vec<uint8_t> encoded_width;

  Error error = GetMetadata(buffer, android::gralloc4::MetadataType_Width,
                            &encoded_width);
  if (error != Error::NONE) {
    return std::nullopt;
  }

  uint64_t width = 0;
  android::gralloc4::decodeWidth(encoded_width, &width);
  return static_cast<uint32_t>(width);
}

std::optional<uint32_t> Gralloc::GetHeight(buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return std::nullopt;
  }

  hidl_vec<uint8_t> encoded_height;

  Error error = GetMetadata(buffer, android::gralloc4::MetadataType_Height,
                            &encoded_height);
  if (error != Error::NONE) {
    return std::nullopt;
  }

  uint64_t height = 0;
  android::gralloc4::decodeHeight(encoded_height, &height);
  return static_cast<uint32_t>(height);
}

std::optional<uint32_t> Gralloc::GetDrmFormat(buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return std::nullopt;
  }

  hidl_vec<uint8_t> encoded_format;

  Error error =
      GetMetadata(buffer, android::gralloc4::MetadataType_PixelFormatFourCC,
                  &encoded_format);
  if (error != Error::NONE) {
    return std::nullopt;
  }

  uint32_t format = 0;
  android::gralloc4::decodePixelFormatFourCC(encoded_format, &format);
  return static_cast<uint32_t>(format);
}

std::optional<std::vector<PlaneLayout>> Gralloc::GetPlaneLayouts(
    buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return std::nullopt;
  }

  hidl_vec<uint8_t> encoded_layouts;

  Error error = GetMetadata(
      buffer, android::gralloc4::MetadataType_PlaneLayouts, &encoded_layouts);
  if (error != Error::NONE) {
    return std::nullopt;
  }

  std::vector<PlaneLayout> plane_layouts;
  android::gralloc4::decodePlaneLayouts(encoded_layouts, &plane_layouts);
  return plane_layouts;
}

std::optional<uint32_t> Gralloc::GetMonoPlanarStrideBytes(
    buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return std::nullopt;
  }

  auto plane_layouts_opt = GetPlaneLayouts(buffer);
  if (!plane_layouts_opt) {
    return std::nullopt;
  }

  std::vector<PlaneLayout>& plane_layouts = *plane_layouts_opt;
  if (plane_layouts.size() != 1) {
    return std::nullopt;
  }

  return static_cast<uint32_t>(plane_layouts[0].strideInBytes);
}

std::optional<GrallocBuffer> Gralloc::Import(buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return std::nullopt;
  }

  buffer_handle_t imported_buffer;

  Error error;
  auto ret =
      gralloc4_->importBuffer(buffer, [&](const auto& err, const auto& buf) {
        error = err;
        if (err == Error::NONE) {
          imported_buffer = static_cast<buffer_handle_t>(buf);
        }
      });

  if (!ret.isOk() || error != Error::NONE) {
    ALOGE("%s failed to import buffer", __FUNCTION__);
    return std::nullopt;
  }
  return GrallocBuffer(this, imported_buffer);
}

void Gralloc::Release(buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return;
  }

  auto native_buffer = const_cast<native_handle_t*>(buffer);
  auto ret = gralloc4_->freeBuffer(native_buffer);

  if (!ret.isOk()) {
    ALOGE("%s failed to release buffer", __FUNCTION__);
  }
}

std::optional<void*> Gralloc::Lock(buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return std::nullopt;
  }

  auto native_buffer = const_cast<native_handle_t*>(buffer);

  const auto buffer_usage = static_cast<uint64_t>(BufferUsage::CPU_READ_OFTEN |
                                                  BufferUsage::CPU_WRITE_OFTEN);

  auto width_opt = GetWidth(buffer);
  if (!width_opt) {
    return std::nullopt;
  }

  auto height_opt = GetHeight(buffer);
  if (!height_opt) {
    return std::nullopt;
  }

  IMapper::Rect buffer_region;
  buffer_region.left = 0;
  buffer_region.top = 0;
  buffer_region.width = *width_opt;
  buffer_region.height = *height_opt;

  // Empty fence, lock immedietly.
  hidl_handle fence;

  Error error = Error::NONE;
  void* data = nullptr;

  auto ret =
      gralloc4_->lock(native_buffer, buffer_usage, buffer_region, fence,
                      [&](const auto& lock_error, const auto& lock_data) {
                        error = lock_error;
                        if (lock_error == Error::NONE) {
                          data = lock_data;
                        }
                      });

  if (!ret.isOk()) {
    error = Error::NO_RESOURCES;
  }

  if (error != Error::NONE) {
    ALOGE("%s failed to lock buffer", __FUNCTION__);
    return std::nullopt;
  }

  return data;
}

std::optional<android_ycbcr> Gralloc::LockYCbCr(buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return std::nullopt;
  }

  auto format_opt = GetDrmFormat(buffer);
  if (!format_opt) {
    ALOGE("%s failed to check format of buffer", __FUNCTION__);
    return std::nullopt;
  }

  if (*format_opt != DRM_FORMAT_NV12 && *format_opt != DRM_FORMAT_NV21 &&
      *format_opt != DRM_FORMAT_YVU420) {
    ALOGE("%s called on non-ycbcr buffer", __FUNCTION__);
    return std::nullopt;
  }

  auto lock_opt = Lock(buffer);
  if (!lock_opt) {
    ALOGE("%s failed to lock buffer", __FUNCTION__);
    return std::nullopt;
  }

  auto plane_layouts_opt = GetPlaneLayouts(buffer);
  if (!plane_layouts_opt) {
    ALOGE("%s failed to get plane layouts", __FUNCTION__);
    return std::nullopt;
  }

  android_ycbcr buffer_ycbcr;
  buffer_ycbcr.y = nullptr;
  buffer_ycbcr.cb = nullptr;
  buffer_ycbcr.cr = nullptr;
  buffer_ycbcr.ystride = 0;
  buffer_ycbcr.cstride = 0;
  buffer_ycbcr.chroma_step = 0;

  for (const auto& plane_layout : *plane_layouts_opt) {
    for (const auto& plane_layout_component : plane_layout.components) {
      const auto& type = plane_layout_component.type;

      if (!android::gralloc4::isStandardPlaneLayoutComponentType(type)) {
        continue;
      }

      auto* component_data = reinterpret_cast<uint8_t*>(*lock_opt) +
                             plane_layout.offsetInBytes +
                             plane_layout_component.offsetInBits / 8;

      switch (static_cast<PlaneLayoutComponentType>(type.value)) {
        case PlaneLayoutComponentType::Y:
          buffer_ycbcr.y = component_data;
          buffer_ycbcr.ystride = plane_layout.strideInBytes;
          break;
        case PlaneLayoutComponentType::CB:
          buffer_ycbcr.cb = component_data;
          buffer_ycbcr.cstride = plane_layout.strideInBytes;
          buffer_ycbcr.chroma_step = plane_layout.sampleIncrementInBits / 8;
          break;
        case PlaneLayoutComponentType::CR:
          buffer_ycbcr.cr = component_data;
          buffer_ycbcr.cstride = plane_layout.strideInBytes;
          buffer_ycbcr.chroma_step = plane_layout.sampleIncrementInBits / 8;
          break;
        default:
          break;
      }
    }
  }

  return buffer_ycbcr;
}

void Gralloc::Unlock(buffer_handle_t buffer) {
  if (gralloc4_ == nullptr) {
    ALOGE("%s Gralloc4 not available.", __FUNCTION__);
    return;
  }

  auto native_handle = const_cast<native_handle_t*>(buffer);

  Error error = Error::NONE;
  auto ret = gralloc4_->unlock(
      native_handle,
      [&](const auto& unlock_error, const auto&) { error = unlock_error; });

  if (!ret.isOk()) {
    error = Error::NO_RESOURCES;
  }

  if (error != Error::NONE) {
    ALOGE("%s failed to unlock buffer", __FUNCTION__);
  }
}

GrallocBuffer::GrallocBuffer(Gralloc* gralloc, buffer_handle_t buffer)
    : gralloc_(gralloc), buffer_(buffer) {}

GrallocBuffer::~GrallocBuffer() { Release(); }

GrallocBuffer::GrallocBuffer(GrallocBuffer&& rhs) { *this = std::move(rhs); }

GrallocBuffer& GrallocBuffer::operator=(GrallocBuffer&& rhs) {
  gralloc_ = rhs.gralloc_;
  buffer_ = rhs.buffer_;
  rhs.gralloc_ = nullptr;
  rhs.buffer_ = nullptr;
  return *this;
}

void GrallocBuffer::Release() {
  if (gralloc_ && buffer_) {
    gralloc_->Release(buffer_);
    gralloc_ = nullptr;
    buffer_ = nullptr;
  }
}

std::optional<GrallocBufferView> GrallocBuffer::Lock() {
  if (gralloc_ && buffer_) {
    auto format_opt = GetDrmFormat();
    if (!format_opt) {
      ALOGE("%s failed to check format of buffer", __FUNCTION__);
      return std::nullopt;
    }
    if (*format_opt != DRM_FORMAT_NV12 && *format_opt != DRM_FORMAT_NV21 &&
        *format_opt != DRM_FORMAT_YVU420) {
      auto locked_opt = gralloc_->Lock(buffer_);
      if (!locked_opt) {
        return std::nullopt;
      }
      return GrallocBufferView(this, *locked_opt);
    } else {
      auto locked_ycbcr_opt = gralloc_->LockYCbCr(buffer_);
      if (!locked_ycbcr_opt) {
        ALOGE("%s failed to lock ycbcr buffer", __FUNCTION__);
        return std::nullopt;
      }
      return GrallocBufferView(this, *locked_ycbcr_opt);
    }
  }
  return std::nullopt;
}

void GrallocBuffer::Unlock() {
  if (gralloc_ && buffer_) {
    gralloc_->Unlock(buffer_);
  }
}

std::optional<uint32_t> GrallocBuffer::GetWidth() {
  if (gralloc_ && buffer_) {
    return gralloc_->GetWidth(buffer_);
  }
  return std::nullopt;
}

std::optional<uint32_t> GrallocBuffer::GetHeight() {
  if (gralloc_ && buffer_) {
    return gralloc_->GetHeight(buffer_);
  }
  return std::nullopt;
}

std::optional<uint32_t> GrallocBuffer::GetDrmFormat() {
  if (gralloc_ && buffer_) {
    return gralloc_->GetDrmFormat(buffer_);
  }
  return std::nullopt;
}

std::optional<std::vector<PlaneLayout>> GrallocBuffer::GetPlaneLayouts() {
  if (gralloc_ && buffer_) {
    return gralloc_->GetPlaneLayouts(buffer_);
  }
  return std::nullopt;
}

std::optional<uint32_t> GrallocBuffer::GetMonoPlanarStrideBytes() {
  if (gralloc_ && buffer_) {
    return gralloc_->GetMonoPlanarStrideBytes(buffer_);
  }
  return std::nullopt;
}

GrallocBufferView::GrallocBufferView(GrallocBuffer* buffer, void* raw)
    : gralloc_buffer_(buffer), locked_(raw) {}

GrallocBufferView::GrallocBufferView(GrallocBuffer* buffer, android_ycbcr raw)
    : gralloc_buffer_(buffer), locked_ycbcr_(raw) {}

GrallocBufferView::~GrallocBufferView() {
  if (gralloc_buffer_) {
    gralloc_buffer_->Unlock();
  }
}

GrallocBufferView::GrallocBufferView(GrallocBufferView&& rhs) {
  *this = std::move(rhs);
}

GrallocBufferView& GrallocBufferView::operator=(GrallocBufferView&& rhs) {
  std::swap(gralloc_buffer_, rhs.gralloc_buffer_);
  std::swap(locked_, rhs.locked_);
  std::swap(locked_ycbcr_, rhs.locked_ycbcr_);
  return *this;
}

const std::optional<void*> GrallocBufferView::Get() const { return locked_; }

const std::optional<android_ycbcr>& GrallocBufferView::GetYCbCr() const {
  return locked_ycbcr_;
}

}  // namespace android