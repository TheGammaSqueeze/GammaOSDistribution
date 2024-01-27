/*
 * Copyright (C) 2022 Arm Limited. All rights reserved.
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

#include <vector>
#include <BufferAllocator/BufferAllocator.h>
#include <android-base/unique_fd.h>

#include "allocator/allocator.h"
#include "core/buffer_allocation.h"
#include "core/buffer_descriptor.h"
#include "usages.h"

enum class dma_buf_heap
{
	/* Upstream heaps */
	system,
	system_uncached,

	/* Custom heaps */
	physically_contiguous,
	protected_memory,
};

struct custom_heap
{
	const char *name;
	struct
	{
		const char *name;
		int flags;
	}
	ion_fallback;
};

const custom_heap physically_contiguous_heap =
{
	"linux,cma",
	{
		"linux,cma",
		0,
	},
};

const custom_heap protected_memory_heap =
{
	"protected",
	{
		"ion_protected_heap",
		0,
	},
};

const custom_heap custom_heaps[] =
{
	physically_contiguous_heap,
	protected_memory_heap,
};

static const char *get_dma_buf_heap_name(dma_buf_heap heap)
{
	switch (heap)
	{
	case dma_buf_heap::system:
		return kDmabufSystemHeapName;
	case dma_buf_heap::system_uncached:
		return kDmabufSystemUncachedHeapName;
	case dma_buf_heap::physically_contiguous:
		return physically_contiguous_heap.name;
	case dma_buf_heap::protected_memory:
		return protected_memory_heap.name;
	}
}

static BufferAllocator *get_global_buffer_allocator()
{
	static struct allocator_initialization
	{
		BufferAllocator allocator;
		allocator_initialization()
		{
			for (const auto &heap : custom_heaps)
			{
				allocator.MapNameToIonHeap(heap.name, heap.ion_fallback.name, heap.ion_fallback.flags);
			}
		}
	}
	instance;

	return &instance.allocator;
}

static dma_buf_heap pick_dma_buf_heap(uint64_t usage)
{
	if (usage & GRALLOC_USAGE_PROTECTED)
	{
		return dma_buf_heap::protected_memory;
	}
	else if (!(usage & GRALLOC_USAGE_HW_VIDEO_ENCODER) && (usage & GRALLOC_USAGE_HW_FB))
	{
#if defined(GRALLOC_USE_CONTIGUOUS_DISPLAY_MEMORY) && GRALLOC_USE_CONTIGUOUS_DISPLAY_MEMORY
		return dma_buf_heap::physically_contiguous;
#else
		return dma_buf_heap::system;
#endif
	}
	else if ((usage & GRALLOC_USAGE_SW_READ_MASK) == GRALLOC_USAGE_SW_READ_OFTEN)
	{
		return dma_buf_heap::system;
	}
	else
	{
		return dma_buf_heap::system_uncached;
	}
}

int allocator_allocate(const buffer_descriptor_t *descriptor, private_handle_t **out_handle)
{
	auto allocator = get_global_buffer_allocator();

	uint64_t usage = descriptor->consumer_usage | descriptor->producer_usage;
	auto heap = pick_dma_buf_heap(usage);
	auto heap_name = get_dma_buf_heap_name(heap);
	android::base::unique_fd fd{allocator->Alloc(heap_name, descriptor->size)};
	if (fd < 0)
	{
		MALI_GRALLOC_LOGE("libdmabufheap allocation failed for %s heap", heap_name);
		return -ENOMEM;
	}

	*out_handle = make_private_handle(
	    0, descriptor->size,
	    descriptor->consumer_usage, descriptor->producer_usage, std::move(fd), descriptor->hal_format,
	    descriptor->alloc_format, descriptor->width, descriptor->height, descriptor->size, descriptor->layer_count,
	    descriptor->plane_info, descriptor->pixel_stride);
	if (nullptr == *out_handle)
	{
		MALI_GRALLOC_LOGE("Private handle could not be created for descriptor");
		return -ENOMEM;
	}

	return 0;
}

void allocator_free(private_handle_t *handle)
{
	if (handle == nullptr)
	{
		return;
	}

	if (handle->base != nullptr)
	{
		munmap(handle->base, handle->size);
	}

	close(handle->share_fd);
	handle->share_fd = -1;
}

static SyncType make_sync_type(bool read, bool write)
{
	if (read && write)
	{
		return kSyncReadWrite;
	}
	else if (read)
	{
		return kSyncRead;
	}
	else if (write)
	{
		return kSyncWrite;
	}
	else
	{
		return static_cast<SyncType>(0);
	}
}

int allocator_sync_start(const private_handle_t *handle, bool read, bool write)
{
	auto allocator = get_global_buffer_allocator();
	return allocator->CpuSyncStart(static_cast<unsigned>(handle->share_fd), make_sync_type(read, write));
}

int allocator_sync_end(const private_handle_t *handle, bool read, bool write)
{
	auto allocator = get_global_buffer_allocator();
	return allocator->CpuSyncEnd(static_cast<unsigned>(handle->share_fd), make_sync_type(read, write));
}

int allocator_map(private_handle_t *handle)
{
	void *hint = nullptr;
	int protection = PROT_READ | PROT_WRITE, flags = MAP_SHARED;
	off_t page_offset = 0;
	void *mapping = mmap(hint, handle->size, protection, flags, handle->share_fd, page_offset);
	if (MAP_FAILED  == mapping)
	{
		MALI_GRALLOC_LOGE("mmap(share_fd = %d) failed: %s", handle->share_fd, strerror(errno));
		return -errno;
	}

	handle->base = static_cast<std::byte *>(mapping);

	return 0;
}

void allocator_unmap(private_handle_t *handle)
{
	void *base = static_cast<std::byte *>(handle->base);
	if (munmap(base, handle->size) < 0)
	{
		MALI_GRALLOC_LOGE("munmap(base = %p, size = %d) failed: %s", base, handle->size, strerror(errno));
	}

	handle->base = nullptr;
	handle->cpu_write = false;
	handle->lock_count = 0;
}

void allocator_close()
{
	/* nop */
}
