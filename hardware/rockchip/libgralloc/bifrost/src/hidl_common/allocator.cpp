/*
 * Copyright (C) 2020-2022 ARM Limited. All rights reserved.
 *
 * Copyright 2016 The Android Open Source Project
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

// #define ENABLE_DEBUG_LOG
#include "../custom_log.h"

#include "allocator.h"
#include "shared_metadata.h"

#include "core/buffer_allocation.h"
#include "core/buffer_descriptor.h"
#include "core/format_info.h"
#include "allocator/allocator.h"
#include "allocator/shared_memory/shared_memory.h"
#include "mapper_metadata.h"
#include "gralloc_version.h"

namespace arm
{
namespace allocator
{
namespace common
{

using aidl::android::hardware::graphics::common::ExtendableType;

/* Get the default chroma siting to use based on the format. */
static void get_format_default_chroma_siting(internal_format_t format, ExtendableType *chroma_siting)
{
	*chroma_siting = android::gralloc4::ChromaSiting_Unknown;
	const auto *format_info = format.get_base_info();
	if (format_info == nullptr)
	{
		return;
	}

	if (format_info->is_yuv)
	{
	        /* Default chroma siting values based on format */
		switch (format.get_base())
		{
		case MALI_GRALLOC_FORMAT_INTERNAL_NV12:
		case MALI_GRALLOC_FORMAT_INTERNAL_NV15:
		case MALI_GRALLOC_FORMAT_INTERNAL_NV21:
		case MALI_GRALLOC_FORMAT_INTERNAL_P010:
		case MALI_GRALLOC_FORMAT_INTERNAL_YUV420_8BIT_I:
		case MALI_GRALLOC_FORMAT_INTERNAL_YUV420_10BIT_I:
		case MALI_GRALLOC_FORMAT_INTERNAL_Y0L2:
			*chroma_siting = android::gralloc4::ChromaSiting_SitedInterstitial;
			break;
		case MALI_GRALLOC_FORMAT_INTERNAL_Y210:
		case MALI_GRALLOC_FORMAT_INTERNAL_P210:
			*chroma_siting = android::gralloc4::ChromaSiting_CositedHorizontal;
			break;
		case MALI_GRALLOC_FORMAT_INTERNAL_NV16:
		case MALI_GRALLOC_FORMAT_INTERNAL_Y410:
		case MALI_GRALLOC_FORMAT_INTERNAL_YUV444:
		case MALI_GRALLOC_FORMAT_INTERNAL_Q410:
		case MALI_GRALLOC_FORMAT_INTERNAL_Q401:
		case MALI_GRALLOC_FORMAT_INTERNAL_YUV422_8BIT:
			*chroma_siting = arm::mapper::common::ChromaSiting_CositedBoth;
			break;
		default:
			MALI_GRALLOC_LOG(WARNING) << "No default Chroma Siting found for format " << format;
		}
	}
	else if (format_info->is_rgb)
	{
		*chroma_siting = android::gralloc4::ChromaSiting_None;
	}
}

void allocate(buffer_descriptor_t *bufferDescriptor, uint32_t count, IAllocator::allocate_cb hidl_cb)
{
	Error error = Error::NONE;
	int stride = 0;
	std::vector<hidl_handle> grallocBuffers;

	grallocBuffers.reserve(count);

	for (uint32_t i = 0; i < count; i++)
	{
		private_handle_t *hnd = nullptr;
		if (mali_gralloc_buffer_allocate(bufferDescriptor, &hnd) != 0)
		{
			MALI_GRALLOC_LOGE("%s, buffer allocation failed with %d", __func__, errno);
			error = Error::NO_RESOURCES;
			break;
		}

		hnd->imapper_version = HIDL_MAPPER_VERSION_SCALED;

		hnd->reserved_region_size = bufferDescriptor->reserved_size;
		hnd->attr_size = mapper::common::shared_metadata_size() + hnd->reserved_region_size;
		std::tie(hnd->share_attr_fd, hnd->attr_base) =
			gralloc_shared_memory_allocate("gralloc_shared_memory", hnd->attr_size);
		if (hnd->share_attr_fd < 0 || hnd->attr_base == MAP_FAILED)
		{
			MALI_GRALLOC_LOGE("%s, shared memory allocation failed with errno %d", __func__, errno);
			mali_gralloc_buffer_free(hnd);
			error = Error::UNSUPPORTED;
			break;
		}

		mapper::common::shared_metadata_init(hnd->attr_base, bufferDescriptor->name);
		const auto internal_format = bufferDescriptor->alloc_format;
		const uint64_t usage = bufferDescriptor->consumer_usage | bufferDescriptor->producer_usage;
		android_dataspace_t dataspace;
		const auto *format_info = internal_format.get_base_info();
		get_format_dataspace(format_info, usage, hnd->width, hnd->height, &dataspace, &hnd->yuv_info);

		ExtendableType chroma_siting;
		get_format_default_chroma_siting(internal_format, &chroma_siting);

		mapper::common::set_dataspace(hnd, static_cast<mapper::common::Dataspace>(dataspace));
		mapper::common::set_chroma_siting(hnd, chroma_siting);

		/*
		* We need to set attr_base to MAP_FAILED before the HIDL callback
		* to avoid sending an invalid pointer to the client process.
		*
		* hnd->attr_base = mmap(...);
		* hidl_callback(hnd); // client receives hnd->attr_base = <dangling pointer>
		*/
		munmap(hnd->attr_base, hnd->attr_size);
		hnd->attr_base = MAP_FAILED;

                {
			buffer_descriptor_t* bufDescriptor = bufferDescriptor;
			D("got new private_handle_t instance @%p for buffer '%s'. share_fd : %d, share_attr_fd : %d, "
				"flags : 0x%x, width : %d, height : %d, "
				"req_format : 0x%x, producer_usage : 0x%" PRIx64 ", consumer_usage : 0x%" PRIx64 ", "
				", stride : %d, "
				"alloc_format : 0x%" PRIx64 ", size : %d, layer_count : %u, backing_store_size : %d, "
				"backing_store_id : %" PRIu64 ", "
				"allocating_pid : %d, yuv_info : %d",
				hnd, (bufDescriptor->name).c_str() == nullptr ? "unset" : (bufDescriptor->name).c_str(),
			  hnd->share_fd, hnd->share_attr_fd,
			  hnd->flags, hnd->width, hnd->height,
			  hnd->req_format, hnd->producer_usage, hnd->consumer_usage,
			  hnd->stride,
			  hnd->alloc_format, hnd->size, hnd->layer_count, hnd->backing_store_size,
			  hnd->backing_store_id,
			  hnd->allocating_pid, hnd->yuv_info);
#ifdef ENABLE_DEBUG_LOG
			ALOGD("plane_info[0]: offset : %u, byte_stride : %u, alloc_width : %u, alloc_height : %u",
					(hnd->plane_info)[0].offset,
					(hnd->plane_info)[0].byte_stride,
					(hnd->plane_info)[0].alloc_width,
					(hnd->plane_info)[0].alloc_height);
			ALOGD("plane_info[1]: offset : %u, byte_stride : %u, alloc_width : %u, alloc_height : %u",
					(hnd->plane_info)[1].offset,
					(hnd->plane_info)[1].byte_stride,
					(hnd->plane_info)[1].alloc_width,
					(hnd->plane_info)[1].alloc_height);
#endif
		}

		int tmpStride = bufferDescriptor->pixel_stride;

		if (stride == 0)
		{
			stride = tmpStride;
		}
		else if (stride != tmpStride)
		{
			/* Stride must be the same for all allocations */
			mali_gralloc_buffer_free(hnd);
			stride = 0;
			error = Error::UNSUPPORTED;
			break;
		}

		grallocBuffers.emplace_back(hidl_handle(hnd));
	}

	/* Populate the array of buffers for application consumption */
	hidl_vec<hidl_handle> hidlBuffers;
	if (error == Error::NONE)
	{
		hidlBuffers.setToExternal(grallocBuffers.data(), grallocBuffers.size());
	}
	hidl_cb(error, stride, hidlBuffers);

	/* The application should import the Gralloc buffers using IMapper for
	 * further usage. Free the allocated buffers in IAllocator context
	 */
	for (auto &buffer : grallocBuffers)
	{
		const native_handle_t *native_handle = buffer.getNativeHandle();
		mali_gralloc_buffer_free(private_handle_t::downcast(native_handle));
		native_handle_delete(const_cast<native_handle_t *>(native_handle));
	}
}

} // namespace common
} // namespace allocator
} // namespace arm
