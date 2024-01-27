/*
 * Copyright (C) 2016-2022 ARM Limited. All rights reserved.
 *
 * Copyright (C) 2008 The Android Open Source Project
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

#define ENABLE_DEBUG_LOG
#include "../custom_log.h"

#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>

#include <log/log.h>
#include <cutils/atomic.h>

#include <ion/ion.h>
#include <linux/ion_4.12.h>
#include <linux/dma-buf.h>
#include <vector>
#include <sys/ioctl.h>

#include <hardware/hardware.h>
#include <hardware/gralloc1.h>

#include "private_interface_types.h"
#include "buffer.h"
#include "helper_functions.h"
#include "gralloc/formats.h"
#include "usages.h"
#include "core/buffer_descriptor.h"
#include "core/buffer_allocation.h"
#include "allocator/allocator.h"

#define INIT_ZERO(obj) (memset(&(obj), 0, sizeof((obj))))

#define HEAP_MASK_FROM_ID(id) (1 << id)
#define HEAP_MASK_FROM_TYPE(type) (1 << type)

static const enum ion_heap_type ION_HEAP_TYPE_INVALID = ((enum ion_heap_type)~0);
static const enum ion_heap_type ION_HEAP_TYPE_SECURE = (enum ion_heap_type)(((unsigned int)ION_HEAP_TYPE_CUSTOM) + 1);

#if defined(ION_HEAP_SECURE_MASK)
#if (HEAP_MASK_FROM_TYPE(ION_HEAP_TYPE_SECURE) != ION_HEAP_SECURE_MASK)
#error "ION_HEAP_TYPE_SECURE value is not compatible with ION_HEAP_SECURE_MASK"
#endif
#endif

struct ion_device
{
	int client()
	{
		return ion_client;
	}
	bool use_legacy()
	{
		return use_legacy_ion;
	}

	static void close()
	{
		ion_device &dev = get_inst();
		if (dev.ion_client >= 0)
		{
			ion_close(dev.ion_client);
			dev.ion_client = -1;
		}
	}

	static ion_device *get()
	{
		ion_device &dev = get_inst();
		if (dev.ion_client < 0)
		{
			if (dev.open_and_query_ion() != 0)
			{
				close();
			}
		}

		if (dev.ion_client < 0)
		{
			return nullptr;
		}
		return &dev;
	}

	/*
	 *  Identifies a heap and retrieves file descriptor from ION for allocation
	 *
	 * @param usage     [in]    Producer and consumer combined usage.
	 * @param size      [in]    Requested buffer size (in bytes).
	 * @param heap_type [in]    Requested heap type.
	 * @param flags     [in]    ION allocation attributes defined by ION_FLAG_*.
	 *
	 * @return File handle which can be used for allocation, on success
	 *         -1, otherwise.
	 */
	int alloc_from_ion_heap(size_t size, enum ion_heap_type heap_type, unsigned int flags);

	enum ion_heap_type pick_ion_heap(uint64_t usage);

private:
	int ion_client;
	bool use_legacy_ion;
	bool secure_heap_exists;
	/*
	* Cache the heap types / IDs information to avoid repeated IOCTL calls
	* Assumption: Heap types / IDs would not change after boot up.
	*/
	int heap_cnt;
	ion_heap_data heap_info[ION_NUM_HEAP_IDS];

	ion_device()
	    : ion_client(-1)
	    , use_legacy_ion(false)
	    , secure_heap_exists(false)
	    , heap_cnt(0)
	{
	}

	static ion_device& get_inst()
	{
		static ion_device dev;
		return dev;
	}

	/*
	 * Opens the ION module. Queries heap information and stores it for later use
	 *
	 * @return              0 in case of success
	 *                      -1 for all error cases
	 */
	int open_and_query_ion();
};

static void set_ion_flags(enum ion_heap_type heap_type, uint64_t usage,
                          unsigned int *priv_heap_flag, unsigned int *ion_flags)
{
#if !defined(GRALLOC_USE_ION_DMA_HEAP) || !GRALLOC_USE_ION_DMA_HEAP
	GRALLOC_UNUSED(heap_type);
#endif

	if (priv_heap_flag)
	{
#if defined(GRALLOC_USE_ION_DMA_HEAP) && GRALLOC_USE_ION_DMA_HEAP
		if (heap_type == ION_HEAP_TYPE_DMA)
		{
			*priv_heap_flag = private_handle_t::PRIV_FLAGS_USES_ION_DMA_HEAP;
		}
#endif
	}

	if (ion_flags)
	{
#if defined(GRALLOC_USE_ION_DMA_HEAP) && GRALLOC_USE_ION_DMA_HEAP
		if (heap_type != ION_HEAP_TYPE_DMA)
		{
#endif
			if ((usage & GRALLOC_USAGE_SW_READ_MASK) == GRALLOC_USAGE_SW_READ_OFTEN)
			{
				*ion_flags = ION_FLAG_CACHED | ION_FLAG_CACHED_NEEDS_SYNC;
			}
#if defined(GRALLOC_USE_ION_DMA_HEAP) && GRALLOC_USE_ION_DMA_HEAP
		}
#endif
	}
}

int ion_device::alloc_from_ion_heap(size_t size, enum ion_heap_type heap_type, unsigned int flags)
{
	int shared_fd = -1;
	int ret = -1;

	if (ion_client < 0 ||
	    size <= 0 ||
	    heap_type == ION_HEAP_TYPE_INVALID)
	{
		return -1;
	}

	if (use_legacy_ion == false)
	{
		int i = 0;

		/* Attempt to allocate memory from each matching heap type (of
		 * enumerated heaps) until successful
		 */
		do
		{
			if (heap_type == heap_info[i].type)
			{
				ret = ion_alloc_fd(ion_client, size, 0,
				                   HEAP_MASK_FROM_ID(heap_info[i].heap_id),
				                   flags, &shared_fd);
			}

			i++;
		} while ((ret < 0) && (i < heap_cnt));
	}
	else
	{
		/* This assumes that when the heaps were defined, the heap ids were
		 * defined as (1 << type) and that ION interprets the heap_mask as
		 * (1 << type).
		 */
		unsigned int heap_mask = HEAP_MASK_FROM_TYPE(heap_type);

		ret = ion_alloc_fd(ion_client, size, 0, heap_mask, flags, &shared_fd);
	}

	if (ret < 0)
	{
		MALI_GRALLOC_LOGE("%s: Allocation failed.", __func__);
		return -1;
	}

	return shared_fd;
}

enum ion_heap_type ion_device::pick_ion_heap(uint64_t usage)
{
	enum ion_heap_type heap_type = ION_HEAP_TYPE_INVALID;

	if (usage & GRALLOC_USAGE_PROTECTED)
	{
		if (secure_heap_exists)
		{
			heap_type = ION_HEAP_TYPE_SECURE;
		}
		else
		{
			MALI_GRALLOC_LOGE("Protected ION memory is not supported on this platform.");
		}
	}
	else if (!(usage & GRALLOC_USAGE_HW_VIDEO_ENCODER) && (usage & GRALLOC_USAGE_HW_FB))
	{
#if defined(GRALLOC_USE_ION_DMA_HEAP) && GRALLOC_USE_ION_DMA_HEAP && \
    defined(GRALLOC_USE_CONTIGUOUS_DISPLAY_MEMORY) && GRALLOC_USE_CONTIGUOUS_DISPLAY_MEMORY
		heap_type = ION_HEAP_TYPE_DMA;
#else
		heap_type = ION_HEAP_TYPE_SYSTEM;
#endif
	}
	else
	{
		heap_type = ION_HEAP_TYPE_SYSTEM;
	}

	return heap_type;
}

int ion_device::open_and_query_ion()
{
	int ret = -1;

	if (ion_client >= 0)
	{
		MALI_GRALLOC_LOGW("ION device already open");
		return 0;
	}

	ion_client = ion_open();
	if (ion_client < 0)
	{
		MALI_GRALLOC_LOGE("ion_open failed with %s", strerror(errno));
		return -1;
	}

	INIT_ZERO(heap_info);
	heap_cnt = 0;
	use_legacy_ion = (ion_is_legacy(ion_client) != 0);

	if (use_legacy_ion == false)
	{
		int cnt;
		ret = ion_query_heap_cnt(ion_client, &cnt);
		if (ret == 0)
		{
			if (cnt > (int)ION_NUM_HEAP_IDS)
			{
				MALI_GRALLOC_LOGE("Retrieved heap count %d is more than maximun heaps %zu on ion",
				      cnt, ION_NUM_HEAP_IDS);
				return -1;
			}

			std::vector<struct ion_heap_data> heap_data(cnt);
			ret = ion_query_get_heaps(ion_client, cnt, heap_data.data());
			if (ret == 0)
			{
				int heap_info_idx = 0;
				for (std::vector<struct ion_heap_data>::iterator heap = heap_data.begin();
                                            heap != heap_data.end(); heap++)
				{
					if (heap_info_idx >= (int)ION_NUM_HEAP_IDS)
					{
						MALI_GRALLOC_LOGE("Iterator exceeding max index, cannot cache heap information");
						return -1;
					}

					if (strcmp(heap->name, "ion_protected_heap") == 0)
					{
						heap->type = ION_HEAP_TYPE_SECURE;
						secure_heap_exists = true;
					}

					heap_info[heap_info_idx] = *heap;
					heap_info_idx++;
				}
			}
		}
		if (ret < 0)
		{
			MALI_GRALLOC_LOGE("%s: Failed to query ION heaps.", __func__);
			return ret;
		}

		heap_cnt = cnt;
	}
	else
	{
		MALI_GRALLOC_LOGI("Using new ION API. Legacy ION ioctl is expected to fail.");
#if defined(ION_HEAP_SECURE_MASK)
		secure_heap_exists = true;
#endif
	}

	return 0;
}

static int call_dma_buf_sync_ioctl(int fd, uint64_t operation, bool read, bool write)
{
	ion_device *dev = ion_device::get();
	if (dev == nullptr)
	{
		return -ENODEV;
	}

	if (dev->use_legacy())
	{
		ion_sync_fd(dev->client(), fd);
	}
	else
	{
		/* Either DMA_BUF_SYNC_START or DMA_BUF_SYNC_END. */
		dma_buf_sync sync_args = { operation };

		if (read)
		{
			sync_args.flags |= DMA_BUF_SYNC_READ;
		}

		if (write)
		{
			sync_args.flags |= DMA_BUF_SYNC_WRITE;
		}

		int ret, retry = 5;
		do
		{
			ret = ioctl(fd, DMA_BUF_IOCTL_SYNC, &sync_args);
			retry--;
		} while ((ret == -EAGAIN || ret == -EINTR) && retry);

		if (ret < 0)
		{
			MALI_GRALLOC_LOGE("ioctl: %#" PRIx64 ", flags: %#" PRIx64 "failed with code %d: %s",
			     (uint64_t)DMA_BUF_IOCTL_SYNC, (uint64_t)sync_args.flags, ret, strerror(errno));
			return -errno;
		}
	}

	return 0;
}

int allocator_sync_start(const private_handle_t *handle, bool read, bool write)
{
	if (handle == nullptr)
	{
		return -EINVAL;
	}

	return call_dma_buf_sync_ioctl(handle->share_fd, DMA_BUF_SYNC_START, read, write);
}

int allocator_sync_end(const private_handle_t *handle, bool read, bool write)
{
	if (handle == nullptr)
	{
		return -EINVAL;
	}

	return call_dma_buf_sync_ioctl(handle->share_fd, DMA_BUF_SYNC_END, read, write);
}

void allocator_free(private_handle_t *handle)
{
	if (handle == nullptr)
	{
		return;
	}

	/* Buffer might be unregistered already so we need to assure we have a valid handle */
	if (handle->base != 0)
	{
		if (munmap(handle->base, handle->size) != 0)
		{
			MALI_GRALLOC_LOGE("Failed to munmap handle %p", handle);
		}
	}

	close(handle->share_fd);
	handle->share_fd = -1;
}

int allocator_allocate(const buffer_descriptor_t *descriptor, private_handle_t **out_handle)
{
	int ret = 0;

	ion_device *dev = ion_device::get();
	if (!dev)
	{
		MALI_GRALLOC_LOGE("Failed to obtain ion device");
		return -ENODEV;
	}

	uint64_t usage = descriptor->consumer_usage | descriptor->producer_usage;
	enum ion_heap_type heap_type = dev->pick_ion_heap(usage);
	if (heap_type == ION_HEAP_TYPE_INVALID)
	{
		MALI_GRALLOC_LOGE("Failed to find an appropriate ion heap");
		return -ENOMEM;
	}

	unsigned int priv_heap_flag = 0;
	unsigned int ion_flags = 0;
	set_ion_flags(heap_type, usage, &priv_heap_flag, &ion_flags);

	android::base::unique_fd shared_fd{
		dev->alloc_from_ion_heap(descriptor->size, heap_type, ion_flags)};
	if (shared_fd < 0)
	{
		MALI_GRALLOC_LOGE("ion_alloc failed from client with pid %d", dev->client());
		return -ENOMEM;
	}

	private_handle_t *handle = make_private_handle(
	    priv_heap_flag, descriptor->size, descriptor->consumer_usage,
	    descriptor->producer_usage, std::move(shared_fd), descriptor->hal_format, descriptor->alloc_format,
	    descriptor->width, descriptor->height, descriptor->size, descriptor->layer_count,
	    descriptor->plane_info, descriptor->pixel_stride);
	if (nullptr == handle)
	{
		MALI_GRALLOC_LOGE("Private handle could not be created for descriptor");
		return -ENOMEM;
	}

	*out_handle = handle;
	return 0;
}

int allocator_map(private_handle_t *handle)
{
	if (handle == nullptr)
	{
		return -EINVAL;
	}

	void *hint = nullptr;
	int protection = PROT_READ | PROT_WRITE;
	int flags = MAP_SHARED;
	off_t page_offset = 0;
	void *mapping = mmap(hint, handle->size, protection, flags, handle->share_fd, page_offset);
	if (MAP_FAILED == mapping)
	{
		MALI_GRALLOC_LOGE("mmap(share_fd = %d) failed: %s", handle->share_fd, strerror(errno));
		return -errno;
	}

	handle->base = static_cast<std::byte *>(mapping);

	return 0;
}

void allocator_unmap(private_handle_t *handle)
{
	if (handle == nullptr)
	{
		return;
	}

	void *base = static_cast<std::byte *>(handle->base);
	if (munmap(base, handle->size) < 0)
	{
		MALI_GRALLOC_LOGE("Could not munmap base:%p size:%d '%s'", base, handle->size, strerror(errno));
	}
	else
	{
		handle->base = 0;
		handle->lock_count = 0;
		handle->cpu_write = 0;
	}
}

void allocator_close(void)
{
	ion_device::close();
}

