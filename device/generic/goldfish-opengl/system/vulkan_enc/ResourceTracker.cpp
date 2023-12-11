// Copyright (C) 2018 The Android Open Source Project
// Copyright (C) 2018 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "ResourceTracker.h"

#include "Resources.h"
#include "CommandBufferStagingStream.h"
#include "DescriptorSetVirtualization.h"

#include "android/base/Optional.h"
#include "android/base/threads/AndroidWorkPool.h"

#include "goldfish_vk_private_defs.h"

#include "../OpenglSystemCommon/EmulatorFeatureInfo.h"
#include "../OpenglSystemCommon/HostConnection.h"

#ifdef VK_USE_PLATFORM_ANDROID_KHR

#include "../egl/goldfish_sync.h"

typedef uint32_t zx_handle_t;
typedef uint64_t zx_koid_t;
#define ZX_HANDLE_INVALID         ((zx_handle_t)0)
#define ZX_KOID_INVALID ((zx_koid_t)0)
void zx_handle_close(zx_handle_t) { }
void zx_event_create(int, zx_handle_t*) { }

#include "AndroidHardwareBuffer.h"

#ifndef HOST_BUILD
#include <drm/virtgpu_drm.h>
#include <xf86drm.h>
#endif

#include "VirtioGpuNext.h"

#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_FUCHSIA

#include <cutils/native_handle.h>
#include <fuchsia/hardware/goldfish/llcpp/fidl.h>
#include <fuchsia/sysmem/llcpp/fidl.h>
#include <lib/zx/channel.h>
#include <lib/zx/vmo.h>
#include <zircon/errors.h>
#include <zircon/process.h>
#include <zircon/rights.h>
#include <zircon/syscalls.h>
#include <zircon/syscalls/object.h>

#include "services/service_connector.h"

#ifndef FUCHSIA_NO_TRACE
#include <lib/trace/event.h>
#endif

#define GET_STATUS_SAFE(result, member) \
    ((result).ok() ? ((result).Unwrap()->member) : ZX_OK)

struct AHardwareBuffer;

void AHardwareBuffer_release(AHardwareBuffer*) { }

native_handle_t *AHardwareBuffer_getNativeHandle(AHardwareBuffer*) { return NULL; }

uint64_t getAndroidHardwareBufferUsageFromVkUsage(
    const VkImageCreateFlags vk_create,
    const VkImageUsageFlags vk_usage) {
  return AHARDWAREBUFFER_USAGE_GPU_SAMPLED_IMAGE;
}

VkResult importAndroidHardwareBuffer(
    Gralloc *grallocHelper,
    const VkImportAndroidHardwareBufferInfoANDROID* info,
    struct AHardwareBuffer **importOut) {
  return VK_SUCCESS;
}

VkResult createAndroidHardwareBuffer(
    bool hasDedicatedImage,
    bool hasDedicatedBuffer,
    const VkExtent3D& imageExtent,
    uint32_t imageLayers,
    VkFormat imageFormat,
    VkImageUsageFlags imageUsage,
    VkImageCreateFlags imageCreateFlags,
    VkDeviceSize bufferSize,
    VkDeviceSize allocationInfoAllocSize,
    struct AHardwareBuffer **out) {
  return VK_SUCCESS;
}

namespace goldfish_vk {
struct HostVisibleMemoryVirtualizationInfo;
}

VkResult getAndroidHardwareBufferPropertiesANDROID(
    Gralloc *grallocHelper,
    const goldfish_vk::HostVisibleMemoryVirtualizationInfo*,
    VkDevice,
    const AHardwareBuffer*,
    VkAndroidHardwareBufferPropertiesANDROID*) { return VK_SUCCESS; }

VkResult getMemoryAndroidHardwareBufferANDROID(struct AHardwareBuffer **) { return VK_SUCCESS; }

#endif // VK_USE_PLATFORM_FUCHSIA

#include "HostVisibleMemoryVirtualization.h"
#include "Resources.h"
#include "VkEncoder.h"

#include "android/base/AlignedBuf.h"
#include "android/base/synchronization/AndroidLock.h"

#include "goldfish_address_space.h"
#include "goldfish_vk_private_defs.h"
#include "vk_format_info.h"
#include "vk_struct_id.h"
#include "vk_util.h"

#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <vndk/hardware_buffer.h>
#include <log/log.h>
#include <stdlib.h>
#include <sync/sync.h>

#ifdef VK_USE_PLATFORM_ANDROID_KHR

#include <sys/mman.h>
#include <sys/syscall.h>

#ifdef HOST_BUILD
#include "android/utils/tempfile.h"
#endif

static inline int
inline_memfd_create(const char *name, unsigned int flags) {
#ifdef HOST_BUILD
    TempFile* tmpFile = tempfile_create();
    return open(tempfile_path(tmpFile), O_RDWR);
    // TODO: Windows is not suppose to support VkSemaphoreGetFdInfoKHR
#else
    return syscall(SYS_memfd_create, name, flags);
#endif
}
#define memfd_create inline_memfd_create
#endif // !VK_USE_PLATFORM_ANDROID_KHR

#define RESOURCE_TRACKER_DEBUG 0

#if RESOURCE_TRACKER_DEBUG
#undef D
#define D(fmt,...) ALOGD("%s: " fmt, __func__, ##__VA_ARGS__);
#else
#ifndef D
#define D(fmt,...)
#endif
#endif

using android::aligned_buf_alloc;
using android::aligned_buf_free;
using android::base::Optional;
using android::base::guest::AutoLock;
using android::base::guest::RecursiveLock;
using android::base::guest::Lock;
using android::base::guest::WorkPool;

namespace goldfish_vk {

#define MAKE_HANDLE_MAPPING_FOREACH(type_name, map_impl, map_to_u64_impl, map_from_u64_impl) \
    void mapHandles_##type_name(type_name* handles, size_t count) override { \
        for (size_t i = 0; i < count; ++i) { \
            map_impl; \
        } \
    } \
    void mapHandles_##type_name##_u64(const type_name* handles, uint64_t* handle_u64s, size_t count) override { \
        for (size_t i = 0; i < count; ++i) { \
            map_to_u64_impl; \
        } \
    } \
    void mapHandles_u64_##type_name(const uint64_t* handle_u64s, type_name* handles, size_t count) override { \
        for (size_t i = 0; i < count; ++i) { \
            map_from_u64_impl; \
        } \
    } \

#define DEFINE_RESOURCE_TRACKING_CLASS(class_name, impl) \
class class_name : public VulkanHandleMapping { \
public: \
    virtual ~class_name() { } \
    GOLDFISH_VK_LIST_HANDLE_TYPES(impl) \
}; \

#define CREATE_MAPPING_IMPL_FOR_TYPE(type_name) \
    MAKE_HANDLE_MAPPING_FOREACH(type_name, \
        handles[i] = new_from_host_##type_name(handles[i]); ResourceTracker::get()->register_##type_name(handles[i]);, \
        handle_u64s[i] = (uint64_t)new_from_host_##type_name(handles[i]), \
        handles[i] = (type_name)new_from_host_u64_##type_name(handle_u64s[i]); ResourceTracker::get()->register_##type_name(handles[i]);)

#define UNWRAP_MAPPING_IMPL_FOR_TYPE(type_name) \
    MAKE_HANDLE_MAPPING_FOREACH(type_name, \
        handles[i] = get_host_##type_name(handles[i]), \
        handle_u64s[i] = (uint64_t)get_host_u64_##type_name(handles[i]), \
        handles[i] = (type_name)get_host_##type_name((type_name)handle_u64s[i]))

#define DESTROY_MAPPING_IMPL_FOR_TYPE(type_name) \
    MAKE_HANDLE_MAPPING_FOREACH(type_name, \
        ResourceTracker::get()->unregister_##type_name(handles[i]); delete_goldfish_##type_name(handles[i]), \
        (void)handle_u64s[i]; delete_goldfish_##type_name(handles[i]), \
        (void)handles[i]; delete_goldfish_##type_name((type_name)handle_u64s[i]))

DEFINE_RESOURCE_TRACKING_CLASS(CreateMapping, CREATE_MAPPING_IMPL_FOR_TYPE)
DEFINE_RESOURCE_TRACKING_CLASS(UnwrapMapping, UNWRAP_MAPPING_IMPL_FOR_TYPE)
DEFINE_RESOURCE_TRACKING_CLASS(DestroyMapping, DESTROY_MAPPING_IMPL_FOR_TYPE)

static uint32_t* sSeqnoPtr = nullptr;

// static
uint32_t ResourceTracker::streamFeatureBits = 0;
ResourceTracker::ThreadingCallbacks ResourceTracker::threadingCallbacks;

struct StagingInfo {
    Lock mLock;
    std::vector<CommandBufferStagingStream*> streams;
    std::vector<VkEncoder*> encoders;

    ~StagingInfo() {
        for (auto stream : streams) {
            delete stream;
        }

        for (auto encoder : encoders) {
            delete encoder;
        }
    }

    void pushStaging(CommandBufferStagingStream* stream, VkEncoder* encoder) {
        AutoLock lock(mLock);
        stream->reset();
        streams.push_back(stream);
        encoders.push_back(encoder);
    }

    void popStaging(CommandBufferStagingStream** streamOut, VkEncoder** encoderOut) {
        AutoLock lock(mLock);
        CommandBufferStagingStream* stream;
        VkEncoder* encoder;
        if (streams.empty()) {
            stream = new CommandBufferStagingStream;
            encoder = new VkEncoder(stream);
        } else {
            stream = streams.back();
            encoder = encoders.back();
            streams.pop_back();
            encoders.pop_back();
        }
        *streamOut = stream;
        *encoderOut = encoder;
    }
};

static StagingInfo sStaging;

class ResourceTracker::Impl {
public:
    Impl() = default;
    CreateMapping createMapping;
    UnwrapMapping unwrapMapping;
    DestroyMapping destroyMapping;
    DefaultHandleMapping defaultMapping;

#define HANDLE_DEFINE_TRIVIAL_INFO_STRUCT(type) \
    struct type##_Info { \
        uint32_t unused; \
    }; \

    GOLDFISH_VK_LIST_TRIVIAL_HANDLE_TYPES(HANDLE_DEFINE_TRIVIAL_INFO_STRUCT)

    struct VkInstance_Info {
        uint32_t highestApiVersion;
        std::set<std::string> enabledExtensions;
        // Fodder for vkEnumeratePhysicalDevices.
        std::vector<VkPhysicalDevice> physicalDevices;
    };

    using HostMemBlocks = std::vector<HostMemAlloc>;
    using HostMemBlockIndex = size_t;

#define INVALID_HOST_MEM_BLOCK (-1)

    struct VkDevice_Info {
        VkPhysicalDevice physdev;
        VkPhysicalDeviceProperties props;
        VkPhysicalDeviceMemoryProperties memProps;
        std::vector<HostMemBlocks> hostMemBlocks { VK_MAX_MEMORY_TYPES };
        uint32_t apiVersion;
        std::set<std::string> enabledExtensions;
        std::vector<std::pair<PFN_vkDeviceMemoryReportCallbackEXT, void *>> deviceMemoryReportCallbacks;
    };

    struct VirtioGpuHostmemResourceInfo {
        uint32_t resourceId = 0;
        int primeFd = -1;
    };

    struct VkDeviceMemory_Info {
        VkDeviceSize allocationSize = 0;
        VkDeviceSize mappedSize = 0;
        uint8_t* mappedPtr = nullptr;
        uint32_t memoryTypeIndex = 0;
        bool virtualHostVisibleBacking = false;
        bool directMapped = false;
        GoldfishAddressSpaceBlock*
            goldfishAddressSpaceBlock = nullptr;
        VirtioGpuHostmemResourceInfo resInfo;
        SubAlloc subAlloc;
        AHardwareBuffer* ahw = nullptr;
        bool imported = false;
        zx_handle_t vmoHandle = ZX_HANDLE_INVALID;
    };

    struct VkCommandBuffer_Info {
        uint32_t placeholder;
    };

    struct VkQueue_Info {
        VkDevice device;
    };

    // custom guest-side structs for images/buffers because of AHardwareBuffer :((
    struct VkImage_Info {
        VkDevice device;
        VkImageCreateInfo createInfo;
        bool external = false;
        VkExternalMemoryImageCreateInfo externalCreateInfo;
        VkDeviceMemory currentBacking = VK_NULL_HANDLE;
        VkDeviceSize currentBackingOffset = 0;
        VkDeviceSize currentBackingSize = 0;
        bool baseRequirementsKnown = false;
        VkMemoryRequirements baseRequirements;
#ifdef VK_USE_PLATFORM_FUCHSIA
        bool isSysmemBackedMemory = false;
#endif
    };

    struct VkBuffer_Info {
        VkDevice device;
        VkBufferCreateInfo createInfo;
        bool external = false;
        VkExternalMemoryBufferCreateInfo externalCreateInfo;
        VkDeviceMemory currentBacking = VK_NULL_HANDLE;
        VkDeviceSize currentBackingOffset = 0;
        VkDeviceSize currentBackingSize = 0;
        bool baseRequirementsKnown = false;
        VkMemoryRequirements baseRequirements;
#ifdef VK_USE_PLATFORM_FUCHSIA
        bool isSysmemBackedMemory = false;
#endif
    };

    struct VkSemaphore_Info {
        VkDevice device;
        zx_handle_t eventHandle = ZX_HANDLE_INVALID;
        zx_koid_t eventKoid = ZX_KOID_INVALID;
        int syncFd = -1;
    };

    struct VkDescriptorUpdateTemplate_Info {
        uint32_t templateEntryCount = 0;
        VkDescriptorUpdateTemplateEntry* templateEntries;

        uint32_t imageInfoCount = 0;
        uint32_t bufferInfoCount = 0;
        uint32_t bufferViewCount = 0;
        uint32_t* imageInfoIndices;
        uint32_t* bufferInfoIndices;
        uint32_t* bufferViewIndices;
        VkDescriptorImageInfo* imageInfos;
        VkDescriptorBufferInfo* bufferInfos;
        VkBufferView* bufferViews;
    };

    struct VkFence_Info {
        VkDevice device;
        bool external = false;
        VkExportFenceCreateInfo exportFenceCreateInfo;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        int syncFd = -1;
#endif
    };

    struct VkDescriptorPool_Info {
        uint32_t unused;
    };

    struct VkDescriptorSet_Info {
        uint32_t unused;
    };

    struct VkDescriptorSetLayout_Info {
        uint32_t unused;
    };

    struct VkCommandPool_Info {
        uint32_t unused;
    };

    struct VkSampler_Info {
        uint32_t unused;
    };

    struct VkBufferCollectionFUCHSIA_Info {
#ifdef VK_USE_PLATFORM_FUCHSIA
        android::base::Optional<
            fuchsia_sysmem::wire::BufferCollectionConstraints>
            constraints;
        android::base::Optional<VkBufferCollectionProperties2FUCHSIA>
            properties;

        // the index of corresponding createInfo for each image format
        // constraints in |constraints|.
        std::vector<uint32_t> createInfoIndex;
#endif  // VK_USE_PLATFORM_FUCHSIA
    };

#define HANDLE_REGISTER_IMPL_IMPL(type) \
    std::unordered_map<type, type##_Info> info_##type; \
    void register_##type(type obj) { \
        AutoLock lock(mLock); \
        info_##type[obj] = type##_Info(); \
    } \

#define HANDLE_UNREGISTER_IMPL_IMPL(type) \
    void unregister_##type(type obj) { \
        AutoLock lock(mLock); \
        info_##type.erase(obj); \
    } \

    GOLDFISH_VK_LIST_HANDLE_TYPES(HANDLE_REGISTER_IMPL_IMPL)
    GOLDFISH_VK_LIST_TRIVIAL_HANDLE_TYPES(HANDLE_UNREGISTER_IMPL_IMPL)

    void unregister_VkInstance(VkInstance instance) {
        AutoLock lock(mLock);

        auto it = info_VkInstance.find(instance);
        if (it == info_VkInstance.end()) return;
        auto info = it->second;
        info_VkInstance.erase(instance);
        lock.unlock();
    }

    void unregister_VkDevice(VkDevice device) {
        AutoLock lock(mLock);

        auto it = info_VkDevice.find(device);
        if (it == info_VkDevice.end()) return;
        auto info = it->second;
        info_VkDevice.erase(device);
        lock.unlock();
    }

    void unregister_VkCommandPool(VkCommandPool pool) {
        if (!pool) return;

        clearCommandPool(pool);

        AutoLock lock(mLock);
        info_VkCommandPool.erase(pool);
    }

    void unregister_VkSampler(VkSampler sampler) {
        if (!sampler) return;

        AutoLock lock(mLock);
        info_VkSampler.erase(sampler);
    }

    void unregister_VkCommandBuffer(VkCommandBuffer commandBuffer) {
        resetCommandBufferStagingInfo(commandBuffer, true /* also reset primaries */, true /* also clear pending descriptor sets */);

        struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(commandBuffer);
        if (!cb) return;
        if (cb->lastUsedEncoder) { cb->lastUsedEncoder->decRef(); }
        eraseObjects(&cb->subObjects);
        forAllObjects(cb->poolObjects, [cb](void* commandPool) {
            struct goldfish_VkCommandPool* p = as_goldfish_VkCommandPool((VkCommandPool)commandPool);
            eraseObject(&p->subObjects, (void*)cb);
        });
        eraseObjects(&cb->poolObjects);

        if (cb->userPtr) {
            CommandBufferPendingDescriptorSets* pendingSets = (CommandBufferPendingDescriptorSets*)cb->userPtr;
            delete pendingSets;
        }

        AutoLock lock(mLock);
        info_VkCommandBuffer.erase(commandBuffer);
    }

    void unregister_VkQueue(VkQueue queue) {
        struct goldfish_VkQueue* q = as_goldfish_VkQueue(queue);
        if (!q) return;
        if (q->lastUsedEncoder) { q->lastUsedEncoder->decRef(); }

        AutoLock lock(mLock);
        info_VkQueue.erase(queue);
    }

    void unregister_VkDeviceMemory(VkDeviceMemory mem) {
        AutoLock lock(mLock);

        auto it = info_VkDeviceMemory.find(mem);
        if (it == info_VkDeviceMemory.end()) return;

        auto& memInfo = it->second;

        if (memInfo.ahw) {
            AHardwareBuffer_release(memInfo.ahw);
        }

        if (memInfo.vmoHandle != ZX_HANDLE_INVALID) {
            zx_handle_close(memInfo.vmoHandle);
        }

        if (memInfo.mappedPtr &&
            !memInfo.virtualHostVisibleBacking &&
            !memInfo.directMapped) {
            aligned_buf_free(memInfo.mappedPtr);
        }

        if (memInfo.directMapped) {
            ALOGE("%s: warning: direct mapped memory never goes to unregister!\n", __func__);
            subFreeHostMemory(&memInfo.subAlloc);
        }

        delete memInfo.goldfishAddressSpaceBlock;

        info_VkDeviceMemory.erase(mem);
    }

    void unregister_VkImage(VkImage img) {
        AutoLock lock(mLock);

        auto it = info_VkImage.find(img);
        if (it == info_VkImage.end()) return;

        auto& imageInfo = it->second;

        info_VkImage.erase(img);
    }

    void unregister_VkBuffer(VkBuffer buf) {
        AutoLock lock(mLock);

        auto it = info_VkBuffer.find(buf);
        if (it == info_VkBuffer.end()) return;

        info_VkBuffer.erase(buf);
    }

    void unregister_VkSemaphore(VkSemaphore sem) {
        AutoLock lock(mLock);

        auto it = info_VkSemaphore.find(sem);
        if (it == info_VkSemaphore.end()) return;

        auto& semInfo = it->second;

        if (semInfo.eventHandle != ZX_HANDLE_INVALID) {
            zx_handle_close(semInfo.eventHandle);
        }

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        if (semInfo.syncFd >= 0) {
            close(semInfo.syncFd);
        }
#endif

        info_VkSemaphore.erase(sem);
    }

    void unregister_VkDescriptorUpdateTemplate(VkDescriptorUpdateTemplate templ) {

        AutoLock lock(mLock);
        auto it = info_VkDescriptorUpdateTemplate.find(templ);
        if (it == info_VkDescriptorUpdateTemplate.end())
            return;

        auto& info = it->second;
        if (info.templateEntryCount) delete [] info.templateEntries;
        if (info.imageInfoCount) {
            delete [] info.imageInfoIndices;
            delete [] info.imageInfos;
        }
        if (info.bufferInfoCount) {
            delete [] info.bufferInfoIndices;
            delete [] info.bufferInfos;
        }
        if (info.bufferViewCount) {
            delete [] info.bufferViewIndices;
            delete [] info.bufferViews;
        }
        info_VkDescriptorUpdateTemplate.erase(it);
    }

    void unregister_VkFence(VkFence fence) {
        AutoLock lock(mLock);
        auto it = info_VkFence.find(fence);
        if (it == info_VkFence.end()) return;

        auto& fenceInfo = it->second;
        (void)fenceInfo;

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        if (fenceInfo.syncFd >= 0) {
            close(fenceInfo.syncFd);
        }
#endif

        info_VkFence.erase(fence);
    }

#ifdef VK_USE_PLATFORM_FUCHSIA
    void unregister_VkBufferCollectionFUCHSIA(
        VkBufferCollectionFUCHSIA collection) {
        AutoLock lock(mLock);
        info_VkBufferCollectionFUCHSIA.erase(collection);
    }
#endif

    void unregister_VkDescriptorSet_locked(VkDescriptorSet set) {
        struct goldfish_VkDescriptorSet* ds = as_goldfish_VkDescriptorSet(set);
        delete ds->reified;
        info_VkDescriptorSet.erase(set);
    }

    void unregister_VkDescriptorSet(VkDescriptorSet set) {
        if (!set) return;

        AutoLock lock(mLock);
        unregister_VkDescriptorSet_locked(set);
    }

    void unregister_VkDescriptorSetLayout(VkDescriptorSetLayout setLayout) {
        if (!setLayout) return;

        AutoLock lock(mLock);
        delete as_goldfish_VkDescriptorSetLayout(setLayout)->layoutInfo;
        info_VkDescriptorSetLayout.erase(setLayout);
    }

    VkResult allocAndInitializeDescriptorSets(
        void* context,
        VkDevice device,
        const VkDescriptorSetAllocateInfo* ci,
        VkDescriptorSet* sets) {

        if (mFeatureInfo->hasVulkanBatchedDescriptorSetUpdate) {
            // Using the pool ID's we collected earlier from the host
            VkResult poolAllocResult = validateAndApplyVirtualDescriptorSetAllocation(ci, sets);

            if (poolAllocResult != VK_SUCCESS) return poolAllocResult;

            for (uint32_t i = 0; i < ci->descriptorSetCount; ++i) {
                register_VkDescriptorSet(sets[i]);
                VkDescriptorSetLayout setLayout = as_goldfish_VkDescriptorSet(sets[i])->reified->setLayout;

                // Need to add ref to the set layout in the virtual case
                // because the set itself might not be realized on host at the
                // same time
                struct goldfish_VkDescriptorSetLayout* dsl = as_goldfish_VkDescriptorSetLayout(setLayout);
                ++dsl->layoutInfo->refcount;
            }
        } else {
            // Pass through and use host allocation
            VkEncoder* enc = (VkEncoder*)context;
            VkResult allocRes = enc->vkAllocateDescriptorSets(device, ci, sets, true /* do lock */);

            if (allocRes != VK_SUCCESS) return allocRes;

            for (uint32_t i = 0; i < ci->descriptorSetCount; ++i) {
                applyDescriptorSetAllocation(ci->descriptorPool, ci->pSetLayouts[i]);
                fillDescriptorSetInfoForPool(ci->descriptorPool, ci->pSetLayouts[i], sets[i]);
            }
        }

        return VK_SUCCESS;
    }

    VkDescriptorImageInfo createImmutableSamplersFilteredImageInfo(
        VkDescriptorType descType,
        VkDescriptorSet descSet,
        uint32_t binding,
        const VkDescriptorImageInfo* pImageInfo) {

        VkDescriptorImageInfo res = *pImageInfo;

        if (descType != VK_DESCRIPTOR_TYPE_SAMPLER &&
            descType != VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) return res;

        bool immutableSampler = as_goldfish_VkDescriptorSet(descSet)->reified->bindingIsImmutableSampler[binding];

        if (!immutableSampler) return res;

        res.sampler = 0;

        return res;
    }

    bool descriptorBindingIsImmutableSampler(
        VkDescriptorSet dstSet,
        uint32_t dstBinding) {

        return as_goldfish_VkDescriptorSet(dstSet)->reified->bindingIsImmutableSampler[dstBinding];
    }

    VkDescriptorImageInfo
    filterNonexistentSampler(
        const VkDescriptorImageInfo& inputInfo) {

        VkSampler sampler =
            inputInfo.sampler;

        VkDescriptorImageInfo res = inputInfo;

        if (sampler) {
            auto it = info_VkSampler.find(sampler);
            bool samplerExists = it != info_VkSampler.end();
            if (!samplerExists) res.sampler = 0;
        }

        return res;
    }


    void freeDescriptorSetsIfHostAllocated(VkEncoder* enc, VkDevice device, uint32_t descriptorSetCount, const VkDescriptorSet* sets) {
        for (uint32_t i = 0; i < descriptorSetCount; ++i) {
            struct goldfish_VkDescriptorSet* ds = as_goldfish_VkDescriptorSet(sets[i]);
            if (ds->reified->allocationPending) {
                unregister_VkDescriptorSet(sets[i]);
                delete_goldfish_VkDescriptorSet(sets[i]);
            } else {
                enc->vkFreeDescriptorSets(device, ds->reified->pool, 1, &sets[i], false /* no lock */);
            }
        }
    }

    void clearDescriptorPoolAndUnregisterDescriptorSets(void* context, VkDevice device, VkDescriptorPool pool) {

        std::vector<VkDescriptorSet> toClear =
            clearDescriptorPool(pool, mFeatureInfo->hasVulkanBatchedDescriptorSetUpdate);

        for (auto set : toClear) {
            if (mFeatureInfo->hasVulkanBatchedDescriptorSetUpdate) {
                VkDescriptorSetLayout setLayout = as_goldfish_VkDescriptorSet(set)->reified->setLayout;
                decDescriptorSetLayoutRef(context, device, setLayout, nullptr);
            }
            unregister_VkDescriptorSet(set);
            delete_goldfish_VkDescriptorSet(set);
        }
    }

    void unregister_VkDescriptorPool(VkDescriptorPool pool) {
        if (!pool) return;

        AutoLock lock(mLock);

        struct goldfish_VkDescriptorPool* dp = as_goldfish_VkDescriptorPool(pool);
        delete dp->allocInfo;

        info_VkDescriptorPool.erase(pool);
    }

    bool descriptorPoolSupportsIndividualFreeLocked(VkDescriptorPool pool) {
        return as_goldfish_VkDescriptorPool(pool)->allocInfo->createFlags &
            VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
    }

    static constexpr uint32_t kDefaultApiVersion = VK_MAKE_VERSION(1, 1, 0);

    void setInstanceInfo(VkInstance instance,
                         uint32_t enabledExtensionCount,
                         const char* const* ppEnabledExtensionNames,
                         uint32_t apiVersion) {
        AutoLock lock(mLock);
        auto& info = info_VkInstance[instance];
        info.highestApiVersion = apiVersion;

        if (!ppEnabledExtensionNames) return;

        for (uint32_t i = 0; i < enabledExtensionCount; ++i) {
            info.enabledExtensions.insert(ppEnabledExtensionNames[i]);
        }
    }

    void setDeviceInfo(VkDevice device,
                       VkPhysicalDevice physdev,
                       VkPhysicalDeviceProperties props,
                       VkPhysicalDeviceMemoryProperties memProps,
                       uint32_t enabledExtensionCount,
                       const char* const* ppEnabledExtensionNames,
                       const void* pNext) {
        AutoLock lock(mLock);
        auto& info = info_VkDevice[device];
        info.physdev = physdev;
        info.props = props;
        info.memProps = memProps;
        initHostVisibleMemoryVirtualizationInfo(
            physdev, &memProps,
            mFeatureInfo.get(),
            &mHostVisibleMemoryVirtInfo);
        info.apiVersion = props.apiVersion;

        const VkBaseInStructure *extensionCreateInfo =
            reinterpret_cast<const VkBaseInStructure *>(pNext);
        while(extensionCreateInfo) {
            if(extensionCreateInfo->sType
                == VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT) {
                auto deviceMemoryReportCreateInfo =
                    reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT *>(
                        extensionCreateInfo);
                if(deviceMemoryReportCreateInfo->pfnUserCallback != nullptr) {
                    info.deviceMemoryReportCallbacks.emplace_back(
                        deviceMemoryReportCreateInfo->pfnUserCallback,
                        deviceMemoryReportCreateInfo->pUserData);
                }
            }
            extensionCreateInfo = extensionCreateInfo->pNext;
        }

        if (!ppEnabledExtensionNames) return;

        for (uint32_t i = 0; i < enabledExtensionCount; ++i) {
            info.enabledExtensions.insert(ppEnabledExtensionNames[i]);
        }
    }

    void emitDeviceMemoryReport(VkDevice_Info info,
                                VkDeviceMemoryReportEventTypeEXT type,
                                uint64_t memoryObjectId,
                                VkDeviceSize size,
                                VkObjectType objectType,
                                uint64_t objectHandle,
                                uint32_t heapIndex = 0) {
        if(info.deviceMemoryReportCallbacks.empty()) return;

        const VkDeviceMemoryReportCallbackDataEXT callbackData = {
            VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT,  // sType
            nullptr,                                                   // pNext
            0,                                                         // flags
            type,                                                      // type
            memoryObjectId,                                            // memoryObjectId
            size,                                                      // size
            objectType,                                                // objectType
            objectHandle,                                              // objectHandle
            heapIndex,                                                 // heapIndex
        };
        for(const auto &callback : info.deviceMemoryReportCallbacks) {
            callback.first(&callbackData, callback.second);
        }
    }

    void setDeviceMemoryInfo(VkDevice device,
                             VkDeviceMemory memory,
                             VkDeviceSize allocationSize,
                             VkDeviceSize mappedSize,
                             uint8_t* ptr,
                             uint32_t memoryTypeIndex,
                             AHardwareBuffer* ahw = nullptr,
                             bool imported = false,
                             zx_handle_t vmoHandle = ZX_HANDLE_INVALID) {
        AutoLock lock(mLock);
        auto& deviceInfo = info_VkDevice[device];
        auto& info = info_VkDeviceMemory[memory];

        info.allocationSize = allocationSize;
        info.mappedSize = mappedSize;
        info.mappedPtr = ptr;
        info.memoryTypeIndex = memoryTypeIndex;
        info.ahw = ahw;
        info.imported = imported;
        info.vmoHandle = vmoHandle;
    }

    void setImageInfo(VkImage image,
                      VkDevice device,
                      const VkImageCreateInfo *pCreateInfo) {
        AutoLock lock(mLock);
        auto& info = info_VkImage[image];

        info.device = device;
        info.createInfo = *pCreateInfo;
    }

    bool isMemoryTypeHostVisible(VkDevice device, uint32_t typeIndex) const {
        AutoLock lock(mLock);
        const auto it = info_VkDevice.find(device);

        if (it == info_VkDevice.end()) return false;

        const auto& info = it->second;
        return info.memProps.memoryTypes[typeIndex].propertyFlags &
               VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT;
    }

    uint8_t* getMappedPointer(VkDeviceMemory memory) {
        AutoLock lock(mLock);
        const auto it = info_VkDeviceMemory.find(memory);
        if (it == info_VkDeviceMemory.end()) return nullptr;

        const auto& info = it->second;
        return info.mappedPtr;
    }

    VkDeviceSize getMappedSize(VkDeviceMemory memory) {
        AutoLock lock(mLock);
        const auto it = info_VkDeviceMemory.find(memory);
        if (it == info_VkDeviceMemory.end()) return 0;

        const auto& info = it->second;
        return info.mappedSize;
    }

    VkDeviceSize getNonCoherentExtendedSize(VkDevice device, VkDeviceSize basicSize) const {
        AutoLock lock(mLock);
        const auto it = info_VkDevice.find(device);
        if (it == info_VkDevice.end()) return basicSize;
        const auto& info = it->second;

        VkDeviceSize nonCoherentAtomSize =
            info.props.limits.nonCoherentAtomSize;
        VkDeviceSize atoms =
            (basicSize + nonCoherentAtomSize - 1) / nonCoherentAtomSize;
        return atoms * nonCoherentAtomSize;
    }

    bool isValidMemoryRange(const VkMappedMemoryRange& range) const {
        AutoLock lock(mLock);
        const auto it = info_VkDeviceMemory.find(range.memory);
        if (it == info_VkDeviceMemory.end()) return false;
        const auto& info = it->second;

        if (!info.mappedPtr) return false;

        VkDeviceSize offset = range.offset;
        VkDeviceSize size = range.size;

        if (size == VK_WHOLE_SIZE) {
            return offset <= info.mappedSize;
        }

        return offset + size <= info.mappedSize;
    }

    void setupFeatures(const EmulatorFeatureInfo* features) {
        if (!features || mFeatureInfo) return;
        mFeatureInfo.reset(new EmulatorFeatureInfo);
        *mFeatureInfo = *features;

        if (mFeatureInfo->hasDirectMem) {
            mGoldfishAddressSpaceBlockProvider.reset(
                new GoldfishAddressSpaceBlockProvider(
                    GoldfishAddressSpaceSubdeviceType::NoSubdevice));
        }

#ifdef VK_USE_PLATFORM_FUCHSIA
        if (mFeatureInfo->hasVulkan) {
            fidl::ClientEnd<fuchsia_hardware_goldfish::ControlDevice> channel{
                zx::channel(GetConnectToServiceFunction()("/dev/class/goldfish-control/000"))};
            if (!channel) {
                ALOGE("failed to open control device");
                abort();
            }
            mControlDevice = std::make_unique<
                fidl::WireSyncClient<fuchsia_hardware_goldfish::ControlDevice>>(
                std::move(channel));

            fidl::ClientEnd<fuchsia_sysmem::Allocator> sysmem_channel{
                zx::channel(GetConnectToServiceFunction()("/svc/fuchsia.sysmem.Allocator"))};
            if (!sysmem_channel) {
                ALOGE("failed to open sysmem connection");
            }
            mSysmemAllocator =
                std::make_unique<fidl::WireSyncClient<fuchsia_sysmem::Allocator>>(
                    std::move(sysmem_channel));
            char name[ZX_MAX_NAME_LEN] = {};
            zx_object_get_property(zx_process_self(), ZX_PROP_NAME, name, sizeof(name));
            std::string client_name(name);
            client_name += "-goldfish";
            zx_info_handle_basic_t info;
            zx_object_get_info(zx_process_self(), ZX_INFO_HANDLE_BASIC, &info, sizeof(info),
                               nullptr, nullptr);
            mSysmemAllocator->SetDebugClientInfo(fidl::StringView::FromExternal(client_name),
                                                 info.koid);
        }
#endif

        if (mFeatureInfo->hasVulkanNullOptionalStrings) {
            ResourceTracker::streamFeatureBits |= VULKAN_STREAM_FEATURE_NULL_OPTIONAL_STRINGS_BIT;
        }
        if (mFeatureInfo->hasVulkanIgnoredHandles) {
            ResourceTracker::streamFeatureBits |= VULKAN_STREAM_FEATURE_IGNORED_HANDLES_BIT;
        }
        if (mFeatureInfo->hasVulkanShaderFloat16Int8) {
            ResourceTracker::streamFeatureBits |= VULKAN_STREAM_FEATURE_SHADER_FLOAT16_INT8_BIT;
        }
        if (mFeatureInfo->hasVulkanQueueSubmitWithCommands) {
            ResourceTracker::streamFeatureBits |= VULKAN_STREAM_FEATURE_QUEUE_SUBMIT_WITH_COMMANDS_BIT;
        }
#if !defined(HOST_BUILD) && defined(VK_USE_PLATFORM_ANDROID_KHR)
       if (mFeatureInfo->hasVirtioGpuNext) {
           ALOGD("%s: has virtio-gpu-next; create hostmem rendernode\n", __func__);
           mRendernodeFd = drmOpenRender(128 /* RENDERNODE_MINOR */);
       }
#endif
    }

    void setThreadingCallbacks(const ResourceTracker::ThreadingCallbacks& callbacks) {
        ResourceTracker::threadingCallbacks = callbacks;
    }

    bool hostSupportsVulkan() const {
        if (!mFeatureInfo) return false;

        return mFeatureInfo->hasVulkan;
    }

    bool usingDirectMapping() const {
        return mHostVisibleMemoryVirtInfo.virtualizationSupported;
    }

    uint32_t getStreamFeatures() const {
        return ResourceTracker::streamFeatureBits;
    }

    bool supportsDeferredCommands() const {
        if (!mFeatureInfo) return false;
        return mFeatureInfo->hasDeferredVulkanCommands;
    }

    bool supportsAsyncQueueSubmit() const {
        if (!mFeatureInfo) return false;
        return mFeatureInfo->hasVulkanAsyncQueueSubmit;
    }

    bool supportsCreateResourcesWithRequirements() const {
        if (!mFeatureInfo) return false;
        return mFeatureInfo->hasVulkanCreateResourcesWithRequirements;
    }

    int getHostInstanceExtensionIndex(const std::string& extName) const {
        int i = 0;
        for (const auto& prop : mHostInstanceExtensions) {
            if (extName == std::string(prop.extensionName)) {
                return i;
            }
            ++i;
        }
        return -1;
    }

    int getHostDeviceExtensionIndex(const std::string& extName) const {
        int i = 0;
        for (const auto& prop : mHostDeviceExtensions) {
            if (extName == std::string(prop.extensionName)) {
                return i;
            }
            ++i;
        }
        return -1;
    }

    void deviceMemoryTransform_tohost(
        VkDeviceMemory* memory, uint32_t memoryCount,
        VkDeviceSize* offset, uint32_t offsetCount,
        VkDeviceSize* size, uint32_t sizeCount,
        uint32_t* typeIndex, uint32_t typeIndexCount,
        uint32_t* typeBits, uint32_t typeBitsCount) {

        (void)memoryCount;
        (void)offsetCount;
        (void)sizeCount;

        const auto& hostVirt =
            mHostVisibleMemoryVirtInfo;

        if (!hostVirt.virtualizationSupported) return;

        if (memory) {
            AutoLock lock (mLock);

            for (uint32_t i = 0; i < memoryCount; ++i) {
                VkDeviceMemory mem = memory[i];

                auto it = info_VkDeviceMemory.find(mem);
                if (it == info_VkDeviceMemory.end()) return;

                const auto& info = it->second;

                if (!info.directMapped) continue;

                memory[i] = info.subAlloc.baseMemory;

                if (offset) {
                    offset[i] = info.subAlloc.baseOffset + offset[i];
                }

                if (size) {
                    if (size[i] == VK_WHOLE_SIZE) {
                        size[i] = info.subAlloc.subMappedSize;
                    }
                }

                // TODO
                (void)memory;
                (void)offset;
                (void)size;
            }
        }

        for (uint32_t i = 0; i < typeIndexCount; ++i) {
            typeIndex[i] =
                hostVirt.memoryTypeIndexMappingToHost[typeIndex[i]];
        }

        for (uint32_t i = 0; i < typeBitsCount; ++i) {
            uint32_t bits = 0;
            for (uint32_t j = 0; j < VK_MAX_MEMORY_TYPES; ++j) {
                bool guestHas = typeBits[i] & (1 << j);
                uint32_t hostIndex =
                    hostVirt.memoryTypeIndexMappingToHost[j];
                bits |= guestHas ? (1 << hostIndex) : 0;
            }
            typeBits[i] = bits;
        }
    }

    void deviceMemoryTransform_fromhost(
        VkDeviceMemory* memory, uint32_t memoryCount,
        VkDeviceSize* offset, uint32_t offsetCount,
        VkDeviceSize* size, uint32_t sizeCount,
        uint32_t* typeIndex, uint32_t typeIndexCount,
        uint32_t* typeBits, uint32_t typeBitsCount) {

        (void)memoryCount;
        (void)offsetCount;
        (void)sizeCount;

        const auto& hostVirt =
            mHostVisibleMemoryVirtInfo;

        if (!hostVirt.virtualizationSupported) return;

        AutoLock lock (mLock);

        for (uint32_t i = 0; i < memoryCount; ++i) {
            // TODO
            (void)memory;
            (void)offset;
            (void)size;
        }

        for (uint32_t i = 0; i < typeIndexCount; ++i) {
            typeIndex[i] =
                hostVirt.memoryTypeIndexMappingFromHost[typeIndex[i]];
        }

        for (uint32_t i = 0; i < typeBitsCount; ++i) {
            uint32_t bits = 0;
            for (uint32_t j = 0; j < VK_MAX_MEMORY_TYPES; ++j) {
                bool hostHas = typeBits[i] & (1 << j);
                uint32_t guestIndex =
                    hostVirt.memoryTypeIndexMappingFromHost[j];
                bits |= hostHas ? (1 << guestIndex) : 0;

                if (hostVirt.memoryTypeBitsShouldAdvertiseBoth[j]) {
                    bits |= hostHas ? (1 << j) : 0;
                }
            }
            typeBits[i] = bits;
        }
    }

    void transformImpl_VkExternalMemoryProperties_fromhost(
        VkExternalMemoryProperties* pProperties,
        uint32_t) {
        VkExternalMemoryHandleTypeFlags supportedHandleType = 0u;
#ifdef VK_USE_PLATFORM_FUCHSIA
        supportedHandleType |=
            VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA |
            VK_EXTERNAL_MEMORY_HANDLE_TYPE_TEMP_ZIRCON_VMO_BIT_FUCHSIA;
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        supportedHandleType |=
            VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT |
            VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID;
#endif  // VK_USE_PLATFORM_ANDROID_KHR
        if (supportedHandleType) {
            pProperties->compatibleHandleTypes &= supportedHandleType;
            pProperties->exportFromImportedHandleTypes &= supportedHandleType;
        }
    }

    VkResult on_vkEnumerateInstanceExtensionProperties(
        void* context,
        VkResult,
        const char*,
        uint32_t* pPropertyCount,
        VkExtensionProperties* pProperties) {
        std::vector<const char*> allowedExtensionNames = {
            "VK_KHR_get_physical_device_properties2",
            "VK_KHR_sampler_ycbcr_conversion",
#ifdef VK_USE_PLATFORM_ANDROID_KHR
            "VK_KHR_external_semaphore_capabilities",
            "VK_KHR_external_memory_capabilities",
            "VK_KHR_external_fence_capabilities",
#endif
        };

        VkEncoder* enc = (VkEncoder*)context;

        // Only advertise a select set of extensions.
        if (mHostInstanceExtensions.empty()) {
            uint32_t hostPropCount = 0;
            enc->vkEnumerateInstanceExtensionProperties(nullptr, &hostPropCount, nullptr, true /* do lock */);
            mHostInstanceExtensions.resize(hostPropCount);

            VkResult hostRes =
                enc->vkEnumerateInstanceExtensionProperties(
                    nullptr, &hostPropCount, mHostInstanceExtensions.data(), true /* do lock */);

            if (hostRes != VK_SUCCESS) {
                return hostRes;
            }
        }

        std::vector<VkExtensionProperties> filteredExts;

        for (size_t i = 0; i < allowedExtensionNames.size(); ++i) {
            auto extIndex = getHostInstanceExtensionIndex(allowedExtensionNames[i]);
            if (extIndex != -1) {
                filteredExts.push_back(mHostInstanceExtensions[extIndex]);
            }
        }

        VkExtensionProperties anbExtProps[] = {
#ifdef VK_USE_PLATFORM_FUCHSIA
            { "VK_KHR_external_memory_capabilities", 1},
            { "VK_KHR_external_semaphore_capabilities", 1},
#endif
        };

        for (auto& anbExtProp: anbExtProps) {
            filteredExts.push_back(anbExtProp);
        }

        // Spec:
        //
        // https://www.khronos.org/registry/vulkan/specs/1.1-extensions/man/html/vkEnumerateInstanceExtensionProperties.html
        //
        // If pProperties is NULL, then the number of extensions properties
        // available is returned in pPropertyCount. Otherwise, pPropertyCount
        // must point to a variable set by the user to the number of elements
        // in the pProperties array, and on return the variable is overwritten
        // with the number of structures actually written to pProperties. If
        // pPropertyCount is less than the number of extension properties
        // available, at most pPropertyCount structures will be written. If
        // pPropertyCount is smaller than the number of extensions available,
        // VK_INCOMPLETE will be returned instead of VK_SUCCESS, to indicate
        // that not all the available properties were returned.
        //
        // pPropertyCount must be a valid pointer to a uint32_t value
        if (!pPropertyCount) return VK_ERROR_INITIALIZATION_FAILED;

        if (!pProperties) {
            *pPropertyCount = (uint32_t)filteredExts.size();
            return VK_SUCCESS;
        } else {
            auto actualExtensionCount = (uint32_t)filteredExts.size();
            if (*pPropertyCount > actualExtensionCount) {
              *pPropertyCount = actualExtensionCount;
            }

            for (uint32_t i = 0; i < *pPropertyCount; ++i) {
                pProperties[i] = filteredExts[i];
            }

            if (actualExtensionCount > *pPropertyCount) {
                return VK_INCOMPLETE;
            }

            return VK_SUCCESS;
        }
    }

    VkResult on_vkEnumerateDeviceExtensionProperties(
        void* context,
        VkResult,
        VkPhysicalDevice physdev,
        const char*,
        uint32_t* pPropertyCount,
        VkExtensionProperties* pProperties) {

        std::vector<const char*> allowedExtensionNames = {
            "VK_KHR_vulkan_memory_model",
            "VK_KHR_buffer_device_address",
            "VK_KHR_maintenance1",
            "VK_KHR_maintenance2",
            "VK_KHR_maintenance3",
            "VK_KHR_bind_memory2",
            "VK_KHR_dedicated_allocation",
            "VK_KHR_get_memory_requirements2",
            "VK_KHR_image_format_list",
            "VK_KHR_sampler_ycbcr_conversion",
            "VK_KHR_shader_float16_int8",
            // Timeline semaphores buggy in newer NVIDIA drivers
            // (vkWaitSemaphoresKHR causes further vkCommandBuffer dispatches to deadlock)
#ifndef VK_USE_PLATFORM_ANDROID_KHR
            "VK_KHR_timeline_semaphore",
#endif
            "VK_AMD_gpu_shader_half_float",
            "VK_NV_shader_subgroup_partitioned",
            "VK_KHR_shader_subgroup_extended_types",
            "VK_EXT_subgroup_size_control",
            "VK_KHR_pipeline_executable_properties",
#ifdef VK_USE_PLATFORM_ANDROID_KHR
            "VK_KHR_external_semaphore",
            "VK_KHR_external_semaphore_fd",
            // "VK_KHR_external_semaphore_win32", not exposed because it's translated to fd
            "VK_KHR_external_memory",
            "VK_KHR_external_fence",
            "VK_KHR_external_fence_fd",
            "VK_EXT_device_memory_report",
#endif
        };

        VkEncoder* enc = (VkEncoder*)context;

        if (mHostDeviceExtensions.empty()) {
            uint32_t hostPropCount = 0;
            enc->vkEnumerateDeviceExtensionProperties(physdev, nullptr, &hostPropCount, nullptr, true /* do lock */);
            mHostDeviceExtensions.resize(hostPropCount);

            VkResult hostRes =
                enc->vkEnumerateDeviceExtensionProperties(
                    physdev, nullptr, &hostPropCount, mHostDeviceExtensions.data(), true /* do lock */);

            if (hostRes != VK_SUCCESS) {
                return hostRes;
            }
        }

        bool hostHasWin32ExternalSemaphore =
            getHostDeviceExtensionIndex(
                "VK_KHR_external_semaphore_win32") != -1;

        bool hostHasPosixExternalSemaphore =
            getHostDeviceExtensionIndex(
                "VK_KHR_external_semaphore_fd") != -1;

        ALOGD("%s: host has ext semaphore? win32 %d posix %d\n", __func__,
                hostHasWin32ExternalSemaphore,
                hostHasPosixExternalSemaphore);

        bool hostSupportsExternalSemaphore =
            hostHasWin32ExternalSemaphore ||
            hostHasPosixExternalSemaphore;

        std::vector<VkExtensionProperties> filteredExts;

        for (size_t i = 0; i < allowedExtensionNames.size(); ++i) {
            auto extIndex = getHostDeviceExtensionIndex(allowedExtensionNames[i]);
            if (extIndex != -1) {
                filteredExts.push_back(mHostDeviceExtensions[extIndex]);
            }
        }

        VkExtensionProperties anbExtProps[] = {
#ifdef VK_USE_PLATFORM_ANDROID_KHR
            { "VK_ANDROID_native_buffer", 7 },
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
            { "VK_KHR_external_memory", 1 },
            { "VK_KHR_external_semaphore", 1 },
            { "VK_FUCHSIA_external_semaphore", 1 },
#endif
        };

        for (auto& anbExtProp: anbExtProps) {
            filteredExts.push_back(anbExtProp);
        }

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        bool hostSupportsExternalFenceFd =
            getHostDeviceExtensionIndex(
                "VK_KHR_external_fence_fd") != -1;
        if (!hostSupportsExternalFenceFd) {
            filteredExts.push_back({ "VK_KHR_external_fence_fd", 1});
        }
#endif

#ifndef VK_USE_PLATFORM_FUCHSIA
        if (hostSupportsExternalSemaphore &&
            !hostHasPosixExternalSemaphore) {
            filteredExts.push_back(
                { "VK_KHR_external_semaphore_fd", 1});
        }
#endif

        bool win32ExtMemAvailable =
            getHostDeviceExtensionIndex(
                "VK_KHR_external_memory_win32") != -1;
        bool posixExtMemAvailable =
            getHostDeviceExtensionIndex(
                "VK_KHR_external_memory_fd") != -1;
        bool moltenVkExtAvailable =
            getHostDeviceExtensionIndex(
                "VK_MVK_moltenvk") != -1;

        bool hostHasExternalMemorySupport =
            win32ExtMemAvailable || posixExtMemAvailable || moltenVkExtAvailable;

        if (hostHasExternalMemorySupport) {
#ifdef VK_USE_PLATFORM_ANDROID_KHR
            filteredExts.push_back({
                "VK_ANDROID_external_memory_android_hardware_buffer", 7
            });
            filteredExts.push_back({
                "VK_EXT_queue_family_foreign", 1
            });
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
            filteredExts.push_back({
                "VK_FUCHSIA_external_memory", 1
            });
            filteredExts.push_back({
                "VK_FUCHSIA_buffer_collection", 1
            });
#endif
        }

        // Spec:
        //
        // https://www.khronos.org/registry/vulkan/specs/1.1-extensions/man/html/vkEnumerateDeviceExtensionProperties.html
        //
        // pPropertyCount is a pointer to an integer related to the number of
        // extension properties available or queried, and is treated in the
        // same fashion as the
        // vkEnumerateInstanceExtensionProperties::pPropertyCount parameter.
        //
        // https://www.khronos.org/registry/vulkan/specs/1.1-extensions/man/html/vkEnumerateInstanceExtensionProperties.html
        //
        // If pProperties is NULL, then the number of extensions properties
        // available is returned in pPropertyCount. Otherwise, pPropertyCount
        // must point to a variable set by the user to the number of elements
        // in the pProperties array, and on return the variable is overwritten
        // with the number of structures actually written to pProperties. If
        // pPropertyCount is less than the number of extension properties
        // available, at most pPropertyCount structures will be written. If
        // pPropertyCount is smaller than the number of extensions available,
        // VK_INCOMPLETE will be returned instead of VK_SUCCESS, to indicate
        // that not all the available properties were returned.
        //
        // pPropertyCount must be a valid pointer to a uint32_t value

        if (!pPropertyCount) return VK_ERROR_INITIALIZATION_FAILED;

        if (!pProperties) {
            *pPropertyCount = (uint32_t)filteredExts.size();
            return VK_SUCCESS;
        } else {
            auto actualExtensionCount = (uint32_t)filteredExts.size();
            if (*pPropertyCount > actualExtensionCount) {
              *pPropertyCount = actualExtensionCount;
            }

            for (uint32_t i = 0; i < *pPropertyCount; ++i) {
                pProperties[i] = filteredExts[i];
            }

            if (actualExtensionCount > *pPropertyCount) {
                return VK_INCOMPLETE;
            }

            return VK_SUCCESS;
        }
    }

    VkResult on_vkEnumeratePhysicalDevices(
        void* context, VkResult,
        VkInstance instance, uint32_t* pPhysicalDeviceCount,
        VkPhysicalDevice* pPhysicalDevices) {

        VkEncoder* enc = (VkEncoder*)context;

        if (!instance) return VK_ERROR_INITIALIZATION_FAILED;

        if (!pPhysicalDeviceCount) return VK_ERROR_INITIALIZATION_FAILED;

        AutoLock lock(mLock);

        // When this function is called, we actually need to do two things:
        // - Get full information about physical devices from the host,
        // even if the guest did not ask for it
        // - Serve the guest query according to the spec:
        //
        // https://www.khronos.org/registry/vulkan/specs/1.1-extensions/man/html/vkEnumeratePhysicalDevices.html

        auto it = info_VkInstance.find(instance);

        if (it == info_VkInstance.end()) return VK_ERROR_INITIALIZATION_FAILED;

        auto& info = it->second;

        // Get the full host information here if it doesn't exist already.
        if (info.physicalDevices.empty()) {
            uint32_t hostPhysicalDeviceCount = 0;

            lock.unlock();
            VkResult countRes = enc->vkEnumeratePhysicalDevices(
                instance, &hostPhysicalDeviceCount, nullptr, false /* no lock */);
            lock.lock();

            if (countRes != VK_SUCCESS) {
                ALOGE("%s: failed: could not count host physical devices. "
                      "Error %d\n", __func__, countRes);
                return countRes;
            }

            info.physicalDevices.resize(hostPhysicalDeviceCount);

            lock.unlock();
            VkResult enumRes = enc->vkEnumeratePhysicalDevices(
                instance, &hostPhysicalDeviceCount, info.physicalDevices.data(), false /* no lock */);
            lock.lock();

            if (enumRes != VK_SUCCESS) {
                ALOGE("%s: failed: could not retrieve host physical devices. "
                      "Error %d\n", __func__, enumRes);
                return enumRes;
            }
        }

        // Serve the guest query according to the spec.
        //
        // https://www.khronos.org/registry/vulkan/specs/1.1-extensions/man/html/vkEnumeratePhysicalDevices.html
        //
        // If pPhysicalDevices is NULL, then the number of physical devices
        // available is returned in pPhysicalDeviceCount. Otherwise,
        // pPhysicalDeviceCount must point to a variable set by the user to the
        // number of elements in the pPhysicalDevices array, and on return the
        // variable is overwritten with the number of handles actually written
        // to pPhysicalDevices. If pPhysicalDeviceCount is less than the number
        // of physical devices available, at most pPhysicalDeviceCount
        // structures will be written.  If pPhysicalDeviceCount is smaller than
        // the number of physical devices available, VK_INCOMPLETE will be
        // returned instead of VK_SUCCESS, to indicate that not all the
        // available physical devices were returned.

        if (!pPhysicalDevices) {
            *pPhysicalDeviceCount = (uint32_t)info.physicalDevices.size();
            return VK_SUCCESS;
        } else {
            uint32_t actualDeviceCount = (uint32_t)info.physicalDevices.size();
            uint32_t toWrite = actualDeviceCount < *pPhysicalDeviceCount ? actualDeviceCount : *pPhysicalDeviceCount;

            for (uint32_t i = 0; i < toWrite; ++i) {
                pPhysicalDevices[i] = info.physicalDevices[i];
            }

            *pPhysicalDeviceCount = toWrite;

            if (actualDeviceCount > *pPhysicalDeviceCount) {
                return VK_INCOMPLETE;
            }

            return VK_SUCCESS;
        }
    }

    void on_vkGetPhysicalDeviceProperties(
        void*,
        VkPhysicalDevice,
        VkPhysicalDeviceProperties* pProperties) {
        // We have host properties at this point
        if (pProperties) {
            // We need this to ignore some cts tests when using Swiftshader Vk
            if (pProperties->deviceType != VK_PHYSICAL_DEVICE_TYPE_CPU) {
                // Otherwise, if not CPU type, mark as virtual type
                pProperties->deviceType = VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU;
            }
        }
    }

    void on_vkGetPhysicalDeviceProperties2(
        void*,
        VkPhysicalDevice,
        VkPhysicalDeviceProperties2* pProperties) {
        if (pProperties) {
            // We need this to ignore some cts tests when using Swiftshader Vk
            if (pProperties->properties.deviceType != VK_PHYSICAL_DEVICE_TYPE_CPU) {
                // Otherwise, if not CPU type, mark as virtual type
                pProperties->properties.deviceType = VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU;
            }

            VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* memoryReportFeaturesEXT =
                vk_find_struct<VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>(pProperties);
            if (memoryReportFeaturesEXT) {
                memoryReportFeaturesEXT->deviceMemoryReport = VK_TRUE;
            }
        }
    }

    void on_vkGetPhysicalDeviceMemoryProperties(
        void*,
        VkPhysicalDevice physdev,
        VkPhysicalDeviceMemoryProperties* out) {

        initHostVisibleMemoryVirtualizationInfo(
            physdev,
            out,
            mFeatureInfo.get(),
            &mHostVisibleMemoryVirtInfo);

        if (mHostVisibleMemoryVirtInfo.virtualizationSupported) {
            *out = mHostVisibleMemoryVirtInfo.guestMemoryProperties;
        }
    }

    void on_vkGetPhysicalDeviceMemoryProperties2(
        void*,
        VkPhysicalDevice physdev,
        VkPhysicalDeviceMemoryProperties2* out) {

        initHostVisibleMemoryVirtualizationInfo(
            physdev,
            &out->memoryProperties,
            mFeatureInfo.get(),
            &mHostVisibleMemoryVirtInfo);

        if (mHostVisibleMemoryVirtInfo.virtualizationSupported) {
            out->memoryProperties = mHostVisibleMemoryVirtInfo.guestMemoryProperties;
        }
    }

    void on_vkGetDeviceQueue(void*,
                             VkDevice device,
                             uint32_t,
                             uint32_t,
                             VkQueue* pQueue) {
        AutoLock lock(mLock);
        info_VkQueue[*pQueue].device = device;
    }

    void on_vkGetDeviceQueue2(void*,
                              VkDevice device,
                              const VkDeviceQueueInfo2*,
                              VkQueue* pQueue) {
        AutoLock lock(mLock);
        info_VkQueue[*pQueue].device = device;
    }

    VkResult on_vkCreateInstance(
        void* context,
        VkResult input_result,
        const VkInstanceCreateInfo* createInfo,
        const VkAllocationCallbacks*,
        VkInstance* pInstance) {

        if (input_result != VK_SUCCESS) return input_result;

        VkEncoder* enc = (VkEncoder*)context;

        uint32_t apiVersion;
        VkResult enumInstanceVersionRes =
            enc->vkEnumerateInstanceVersion(&apiVersion, false /* no lock */);

        setInstanceInfo(
            *pInstance,
            createInfo->enabledExtensionCount,
            createInfo->ppEnabledExtensionNames,
            apiVersion);

        return input_result;
    }

    VkResult on_vkCreateDevice(
        void* context,
        VkResult input_result,
        VkPhysicalDevice physicalDevice,
        const VkDeviceCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*,
        VkDevice* pDevice) {

        if (input_result != VK_SUCCESS) return input_result;

        VkEncoder* enc = (VkEncoder*)context;

        VkPhysicalDeviceProperties props;
        VkPhysicalDeviceMemoryProperties memProps;
        enc->vkGetPhysicalDeviceProperties(physicalDevice, &props, false /* no lock */);
        enc->vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProps, false /* no lock */);

        setDeviceInfo(
            *pDevice, physicalDevice, props, memProps,
            pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames,
            pCreateInfo->pNext);

        return input_result;
    }

    void on_vkDestroyDevice_pre(
        void* context,
        VkDevice device,
        const VkAllocationCallbacks*) {

        AutoLock lock(mLock);

        auto it = info_VkDevice.find(device);
        if (it == info_VkDevice.end()) return;
        auto info = it->second;

        lock.unlock();

        VkEncoder* enc = (VkEncoder*)context;

        bool freeMemorySyncSupported =
            mFeatureInfo->hasVulkanFreeMemorySync;
        for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; ++i) {
            for (auto& block : info.hostMemBlocks[i]) {
                destroyHostMemAlloc(
                    freeMemorySyncSupported,
                    enc, device, &block);
            }
        }
    }

    VkResult on_vkGetAndroidHardwareBufferPropertiesANDROID(
        void*, VkResult,
        VkDevice device,
        const AHardwareBuffer* buffer,
        VkAndroidHardwareBufferPropertiesANDROID* pProperties) {
        auto grallocHelper =
            ResourceTracker::threadingCallbacks.hostConnectionGetFunc()->grallocHelper();
        return getAndroidHardwareBufferPropertiesANDROID(
            grallocHelper,
            &mHostVisibleMemoryVirtInfo,
            device, buffer, pProperties);
    }

    VkResult on_vkGetMemoryAndroidHardwareBufferANDROID(
        void*, VkResult,
        VkDevice device,
        const VkMemoryGetAndroidHardwareBufferInfoANDROID *pInfo,
        struct AHardwareBuffer** pBuffer) {

        if (!pInfo) return VK_ERROR_INITIALIZATION_FAILED;
        if (!pInfo->memory) return VK_ERROR_INITIALIZATION_FAILED;

        AutoLock lock(mLock);

        auto deviceIt = info_VkDevice.find(device);

        if (deviceIt == info_VkDevice.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto memoryIt = info_VkDeviceMemory.find(pInfo->memory);

        if (memoryIt == info_VkDeviceMemory.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto& info = memoryIt->second;

        VkResult queryRes =
            getMemoryAndroidHardwareBufferANDROID(&info.ahw);

        if (queryRes != VK_SUCCESS) return queryRes;

        *pBuffer = info.ahw;

        return queryRes;
    }

#ifdef VK_USE_PLATFORM_FUCHSIA
    VkResult on_vkGetMemoryZirconHandleFUCHSIA(
        void*, VkResult,
        VkDevice device,
        const VkMemoryGetZirconHandleInfoFUCHSIA* pInfo,
        uint32_t* pHandle) {

        if (!pInfo) return VK_ERROR_INITIALIZATION_FAILED;
        if (!pInfo->memory) return VK_ERROR_INITIALIZATION_FAILED;

        AutoLock lock(mLock);

        auto deviceIt = info_VkDevice.find(device);

        if (deviceIt == info_VkDevice.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto memoryIt = info_VkDeviceMemory.find(pInfo->memory);

        if (memoryIt == info_VkDeviceMemory.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto& info = memoryIt->second;

        if (info.vmoHandle == ZX_HANDLE_INVALID) {
            ALOGE("%s: memory cannot be exported", __func__);
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        *pHandle = ZX_HANDLE_INVALID;
        zx_handle_duplicate(info.vmoHandle, ZX_RIGHT_SAME_RIGHTS, pHandle);
        return VK_SUCCESS;
    }

    VkResult on_vkGetMemoryZirconHandlePropertiesFUCHSIA(
        void*, VkResult,
        VkDevice device,
        VkExternalMemoryHandleTypeFlagBits handleType,
        uint32_t handle,
        VkMemoryZirconHandlePropertiesFUCHSIA* pProperties) {
        using fuchsia_hardware_goldfish::wire::kMemoryPropertyDeviceLocal;
        using fuchsia_hardware_goldfish::wire::kMemoryPropertyHostVisible;

        if (handleType != VK_EXTERNAL_MEMORY_HANDLE_TYPE_TEMP_ZIRCON_VMO_BIT_FUCHSIA &&
            handleType != VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        zx_info_handle_basic_t handleInfo;
        zx_status_t status = zx::unowned_vmo(handle)->get_info(
            ZX_INFO_HANDLE_BASIC, &handleInfo, sizeof(handleInfo), nullptr,
            nullptr);
        if (status != ZX_OK || handleInfo.type != ZX_OBJ_TYPE_VMO) {
            return VK_ERROR_INVALID_EXTERNAL_HANDLE;
        }

        AutoLock lock(mLock);

        auto deviceIt = info_VkDevice.find(device);

        if (deviceIt == info_VkDevice.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto& info = deviceIt->second;

        zx::vmo vmo_dup;
        status =
            zx::unowned_vmo(handle)->duplicate(ZX_RIGHT_SAME_RIGHTS, &vmo_dup);
        if (status != ZX_OK) {
            ALOGE("zx_handle_duplicate() error: %d", status);
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        uint32_t memoryProperty = 0u;

        auto result = mControlDevice->GetBufferHandleInfo(std::move(vmo_dup));
        if (!result.ok()) {
            ALOGE(
                "mControlDevice->GetBufferHandleInfo fatal error: epitaph: %d",
                result.status());
            return VK_ERROR_INITIALIZATION_FAILED;
        }
        if (result->result.is_response()) {
            memoryProperty = result->result.response().info.memory_property();
        } else if (result->result.err() == ZX_ERR_NOT_FOUND) {
            // If an VMO is allocated while ColorBuffer/Buffer is not created,
            // it must be a device-local buffer, since for host-visible buffers,
            // ColorBuffer/Buffer is created at sysmem allocation time.
            memoryProperty = kMemoryPropertyDeviceLocal;
        } else {
            // Importing read-only host memory into the Vulkan driver should not
            // work, but it is not an error to try to do so. Returning a
            // VkMemoryZirconHandlePropertiesFUCHSIA with no available
            // memoryType bits should be enough for clients. See fxbug.dev/24225
            // for other issues this this flow.
            ALOGW("GetBufferHandleInfo failed: %d", result->result.err());
            pProperties->memoryTypeBits = 0;
            return VK_SUCCESS;
        }

        pProperties->memoryTypeBits = 0;
        for (uint32_t i = 0; i < info.memProps.memoryTypeCount; ++i) {
            if (((memoryProperty & kMemoryPropertyDeviceLocal) &&
                 (info.memProps.memoryTypes[i].propertyFlags &
                  VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)) ||
                ((memoryProperty & kMemoryPropertyHostVisible) &&
                 (info.memProps.memoryTypes[i].propertyFlags &
                  VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT))) {
                pProperties->memoryTypeBits |= 1ull << i;
            }
        }
        return VK_SUCCESS;
    }

    zx_koid_t getEventKoid(zx_handle_t eventHandle) {
        if (eventHandle == ZX_HANDLE_INVALID) {
            return ZX_KOID_INVALID;
        }

        zx_info_handle_basic_t info;
        zx_status_t status =
            zx_object_get_info(eventHandle, ZX_INFO_HANDLE_BASIC, &info,
                               sizeof(info), nullptr, nullptr);
        if (status != ZX_OK) {
            ALOGE("Cannot get object info of handle %u: %d", eventHandle,
                  status);
            return ZX_KOID_INVALID;
        }
        return info.koid;
    }

    VkResult on_vkImportSemaphoreZirconHandleFUCHSIA(
        void*, VkResult,
        VkDevice device,
        const VkImportSemaphoreZirconHandleInfoFUCHSIA* pInfo) {

        if (!pInfo) return VK_ERROR_INITIALIZATION_FAILED;
        if (!pInfo->semaphore) return VK_ERROR_INITIALIZATION_FAILED;

        AutoLock lock(mLock);

        auto deviceIt = info_VkDevice.find(device);

        if (deviceIt == info_VkDevice.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto semaphoreIt = info_VkSemaphore.find(pInfo->semaphore);

        if (semaphoreIt == info_VkSemaphore.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto& info = semaphoreIt->second;

        if (info.eventHandle != ZX_HANDLE_INVALID) {
            zx_handle_close(info.eventHandle);
        }
#if VK_HEADER_VERSION < 174
        info.eventHandle = pInfo->handle;
#else // VK_HEADER_VERSION >= 174
        info.eventHandle = pInfo->zirconHandle;
#endif // VK_HEADER_VERSION < 174
        if (info.eventHandle != ZX_HANDLE_INVALID) {
            info.eventKoid = getEventKoid(info.eventHandle);
        }

        return VK_SUCCESS;
    }

    VkResult on_vkGetSemaphoreZirconHandleFUCHSIA(
        void*, VkResult,
        VkDevice device,
        const VkSemaphoreGetZirconHandleInfoFUCHSIA* pInfo,
        uint32_t* pHandle) {

        if (!pInfo) return VK_ERROR_INITIALIZATION_FAILED;
        if (!pInfo->semaphore) return VK_ERROR_INITIALIZATION_FAILED;

        AutoLock lock(mLock);

        auto deviceIt = info_VkDevice.find(device);

        if (deviceIt == info_VkDevice.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto semaphoreIt = info_VkSemaphore.find(pInfo->semaphore);

        if (semaphoreIt == info_VkSemaphore.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto& info = semaphoreIt->second;

        if (info.eventHandle == ZX_HANDLE_INVALID) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        *pHandle = ZX_HANDLE_INVALID;
        zx_handle_duplicate(info.eventHandle, ZX_RIGHT_SAME_RIGHTS, pHandle);
        return VK_SUCCESS;
    }

    VkResult on_vkCreateBufferCollectionFUCHSIA(
        void*, VkResult, VkDevice,
        const VkBufferCollectionCreateInfoFUCHSIA* pInfo,
        const VkAllocationCallbacks*,
        VkBufferCollectionFUCHSIA* pCollection) {
        fidl::ClientEnd<::fuchsia_sysmem::BufferCollectionToken> token_client;

        if (pInfo->collectionToken) {
            token_client = fidl::ClientEnd<::fuchsia_sysmem::BufferCollectionToken>(
                zx::channel(pInfo->collectionToken));
        } else {
            auto endpoints =
                fidl::CreateEndpoints<::fuchsia_sysmem::BufferCollectionToken>();
            if (!endpoints.is_ok()) {
                ALOGE("zx_channel_create failed: %d", endpoints.status_value());
                return VK_ERROR_INITIALIZATION_FAILED;
            }

            auto result = mSysmemAllocator->AllocateSharedCollection(
                std::move(endpoints->server));
            if (!result.ok()) {
                ALOGE("AllocateSharedCollection failed: %d", result.status());
                return VK_ERROR_INITIALIZATION_FAILED;
            }
            token_client = std::move(endpoints->client);
        }

        auto endpoints = fidl::CreateEndpoints<::fuchsia_sysmem::BufferCollection>();
        if (!endpoints.is_ok()) {
            ALOGE("zx_channel_create failed: %d", endpoints.status_value());
            return VK_ERROR_INITIALIZATION_FAILED;
        }
        auto [collection_client, collection_server] = std::move(endpoints.value());

        auto result = mSysmemAllocator->BindSharedCollection(
            std::move(token_client), std::move(collection_server));
        if (!result.ok()) {
            ALOGE("BindSharedCollection failed: %d", result.status());
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto* sysmem_collection =
            new fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>(
                std::move(collection_client));
        *pCollection = reinterpret_cast<VkBufferCollectionFUCHSIA>(sysmem_collection);

        register_VkBufferCollectionFUCHSIA(*pCollection);
        return VK_SUCCESS;
    }

    void on_vkDestroyBufferCollectionFUCHSIA(
        void*, VkResult, VkDevice,
        VkBufferCollectionFUCHSIA collection,
        const VkAllocationCallbacks*) {
        auto sysmem_collection = reinterpret_cast<
            fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>*>(collection);
        if (sysmem_collection) {
            sysmem_collection->Close();
        }
        delete sysmem_collection;

        unregister_VkBufferCollectionFUCHSIA(collection);
    }

    inline fuchsia_sysmem::wire::BufferCollectionConstraints
    defaultBufferCollectionConstraints(
        size_t minSizeBytes,
        size_t minBufferCount,
        size_t maxBufferCount = 0u,
        size_t minBufferCountForCamping = 0u,
        size_t minBufferCountForDedicatedSlack = 0u,
        size_t minBufferCountForSharedSlack = 0u) {
        fuchsia_sysmem::wire::BufferCollectionConstraints constraints = {};
        constraints.min_buffer_count = minBufferCount;
        if (maxBufferCount > 0) {
            constraints.max_buffer_count = maxBufferCount;
        }
        if (minBufferCountForCamping) {
            constraints.min_buffer_count_for_camping = minBufferCountForCamping;
        }
        if (minBufferCountForSharedSlack) {
            constraints.min_buffer_count_for_shared_slack =
                minBufferCountForSharedSlack;
        }
        constraints.has_buffer_memory_constraints = true;
        fuchsia_sysmem::wire::BufferMemoryConstraints& buffer_constraints =
            constraints.buffer_memory_constraints;

        buffer_constraints.min_size_bytes = minSizeBytes;
        buffer_constraints.max_size_bytes = 0xffffffff;
        buffer_constraints.physically_contiguous_required = false;
        buffer_constraints.secure_required = false;

        // No restrictions on coherency domain or Heaps.
        buffer_constraints.ram_domain_supported = true;
        buffer_constraints.cpu_domain_supported = true;
        buffer_constraints.inaccessible_domain_supported = true;
        buffer_constraints.heap_permitted_count = 2;
        buffer_constraints.heap_permitted[0] =
            fuchsia_sysmem::wire::HeapType::kGoldfishDeviceLocal;
        buffer_constraints.heap_permitted[1] =
            fuchsia_sysmem::wire::HeapType::kGoldfishHostVisible;

        return constraints;
    }

    uint32_t getBufferCollectionConstraintsVulkanImageUsage(
        const VkImageCreateInfo* pImageInfo) {
        uint32_t usage = 0u;
        VkImageUsageFlags imageUsage = pImageInfo->usage;

#define SetUsageBit(BIT, VALUE)                                           \
    if (imageUsage & VK_IMAGE_USAGE_##BIT##_BIT) {                 \
        usage |= fuchsia_sysmem::wire::kVulkanImageUsage##VALUE; \
    }

        SetUsageBit(COLOR_ATTACHMENT, ColorAttachment);
        SetUsageBit(TRANSFER_SRC, TransferSrc);
        SetUsageBit(TRANSFER_DST, TransferDst);
        SetUsageBit(SAMPLED, Sampled);

#undef SetUsageBit
        return usage;
    }

    uint32_t getBufferCollectionConstraintsVulkanBufferUsage(
        const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) {
        uint32_t usage = 0u;
        VkBufferUsageFlags bufferUsage =
            pBufferConstraintsInfo->pBufferCreateInfo->usage;

#define SetUsageBit(BIT, VALUE)                                            \
    if (bufferUsage & VK_BUFFER_USAGE_##BIT##_BIT) {                \
        usage |= fuchsia_sysmem::wire::kVulkanBufferUsage##VALUE; \
    }

        SetUsageBit(TRANSFER_SRC, TransferSrc);
        SetUsageBit(TRANSFER_DST, TransferDst);
        SetUsageBit(UNIFORM_TEXEL_BUFFER, UniformTexelBuffer);
        SetUsageBit(STORAGE_TEXEL_BUFFER, StorageTexelBuffer);
        SetUsageBit(UNIFORM_BUFFER, UniformBuffer);
        SetUsageBit(STORAGE_BUFFER, StorageBuffer);
        SetUsageBit(INDEX_BUFFER, IndexBuffer);
        SetUsageBit(VERTEX_BUFFER, VertexBuffer);
        SetUsageBit(INDIRECT_BUFFER, IndirectBuffer);

#undef SetUsageBit
        return usage;
    }

    static fuchsia_sysmem::wire::PixelFormatType vkFormatTypeToSysmem(
        VkFormat format) {
        switch (format) {
            case VK_FORMAT_B8G8R8A8_SINT:
            case VK_FORMAT_B8G8R8A8_UNORM:
            case VK_FORMAT_B8G8R8A8_SRGB:
            case VK_FORMAT_B8G8R8A8_SNORM:
            case VK_FORMAT_B8G8R8A8_SSCALED:
            case VK_FORMAT_B8G8R8A8_USCALED:
                return fuchsia_sysmem::wire::PixelFormatType::kBgra32;
            case VK_FORMAT_R8G8B8A8_SINT:
            case VK_FORMAT_R8G8B8A8_UNORM:
            case VK_FORMAT_R8G8B8A8_SRGB:
            case VK_FORMAT_R8G8B8A8_SNORM:
            case VK_FORMAT_R8G8B8A8_SSCALED:
            case VK_FORMAT_R8G8B8A8_USCALED:
                return fuchsia_sysmem::wire::PixelFormatType::kR8G8B8A8;
            case VK_FORMAT_R8_UNORM:
            case VK_FORMAT_R8_UINT:
            case VK_FORMAT_R8_USCALED:
            case VK_FORMAT_R8_SNORM:
            case VK_FORMAT_R8_SINT:
            case VK_FORMAT_R8_SSCALED:
            case VK_FORMAT_R8_SRGB:
                return fuchsia_sysmem::wire::PixelFormatType::kR8;
            case VK_FORMAT_R8G8_UNORM:
            case VK_FORMAT_R8G8_UINT:
            case VK_FORMAT_R8G8_USCALED:
            case VK_FORMAT_R8G8_SNORM:
            case VK_FORMAT_R8G8_SINT:
            case VK_FORMAT_R8G8_SSCALED:
            case VK_FORMAT_R8G8_SRGB:
                return fuchsia_sysmem::wire::PixelFormatType::kR8G8;
            default:
                return fuchsia_sysmem::wire::PixelFormatType::kInvalid;
        }
    }

    static bool vkFormatMatchesSysmemFormat(
        VkFormat vkFormat,
        fuchsia_sysmem::wire::PixelFormatType sysmemFormat) {
        switch (vkFormat) {
            case VK_FORMAT_B8G8R8A8_SINT:
            case VK_FORMAT_B8G8R8A8_UNORM:
            case VK_FORMAT_B8G8R8A8_SRGB:
            case VK_FORMAT_B8G8R8A8_SNORM:
            case VK_FORMAT_B8G8R8A8_SSCALED:
            case VK_FORMAT_B8G8R8A8_USCALED:
                return sysmemFormat ==
                       fuchsia_sysmem::wire::PixelFormatType::kBgra32;
            case VK_FORMAT_R8G8B8A8_SINT:
            case VK_FORMAT_R8G8B8A8_UNORM:
            case VK_FORMAT_R8G8B8A8_SRGB:
            case VK_FORMAT_R8G8B8A8_SNORM:
            case VK_FORMAT_R8G8B8A8_SSCALED:
            case VK_FORMAT_R8G8B8A8_USCALED:
                return sysmemFormat ==
                       fuchsia_sysmem::wire::PixelFormatType::kR8G8B8A8;
            case VK_FORMAT_R8_UNORM:
            case VK_FORMAT_R8_UINT:
            case VK_FORMAT_R8_USCALED:
            case VK_FORMAT_R8_SNORM:
            case VK_FORMAT_R8_SINT:
            case VK_FORMAT_R8_SSCALED:
            case VK_FORMAT_R8_SRGB:
                return sysmemFormat ==
                           fuchsia_sysmem::wire::PixelFormatType::kR8 ||
                       sysmemFormat ==
                           fuchsia_sysmem::wire::PixelFormatType::kL8;
            case VK_FORMAT_R8G8_UNORM:
            case VK_FORMAT_R8G8_UINT:
            case VK_FORMAT_R8G8_USCALED:
            case VK_FORMAT_R8G8_SNORM:
            case VK_FORMAT_R8G8_SINT:
            case VK_FORMAT_R8G8_SSCALED:
            case VK_FORMAT_R8G8_SRGB:
                return sysmemFormat ==
                       fuchsia_sysmem::wire::PixelFormatType::kR8G8;
            default:
                return false;
        }
    }

    static VkFormat sysmemPixelFormatTypeToVk(
        fuchsia_sysmem::wire::PixelFormatType format) {
        switch (format) {
            case fuchsia_sysmem::wire::PixelFormatType::kBgra32:
                return VK_FORMAT_B8G8R8A8_SRGB;
            case fuchsia_sysmem::wire::PixelFormatType::kR8G8B8A8:
                return VK_FORMAT_R8G8B8A8_SRGB;
            case fuchsia_sysmem::wire::PixelFormatType::kL8:
            case fuchsia_sysmem::wire::PixelFormatType::kR8:
                return VK_FORMAT_R8_UNORM;
            case fuchsia_sysmem::wire::PixelFormatType::kR8G8:
                return VK_FORMAT_R8G8_UNORM;
            default:
                return VK_FORMAT_UNDEFINED;
        }
    }

    VkResult setBufferCollectionConstraints(
        VkEncoder* enc, VkDevice device,
        fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>* collection,
        const VkImageCreateInfo* pImageInfo) {
        if (pImageInfo == nullptr) {
            ALOGE("setBufferCollectionConstraints: pImageInfo cannot be null.");
            return VK_ERROR_OUT_OF_DEVICE_MEMORY;
        }

        std::vector<VkImageCreateInfo> createInfos;
        if (pImageInfo->format == VK_FORMAT_UNDEFINED) {
            const auto kFormats = {
                VK_FORMAT_B8G8R8A8_SRGB,
                VK_FORMAT_R8G8B8A8_SRGB,
            };
            for (auto format : kFormats) {
                // shallow copy, using pNext from pImageInfo directly.
                auto createInfo = *pImageInfo;
                createInfo.format = format;
                createInfos.push_back(createInfo);
            }
        } else {
            createInfos.push_back(*pImageInfo);
        }

        VkImageConstraintsInfoFUCHSIA imageConstraints;
        imageConstraints.sType =
            VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA;
        imageConstraints.pNext = nullptr;
        imageConstraints.createInfoCount = createInfos.size();
        imageConstraints.pCreateInfos = createInfos.data();
        imageConstraints.pFormatConstraints = nullptr;
        imageConstraints.maxBufferCount = 0;
        imageConstraints.minBufferCount = 1;
        imageConstraints.minBufferCountForCamping = 0;
        imageConstraints.minBufferCountForDedicatedSlack = 0;
        imageConstraints.minBufferCountForSharedSlack = 0;
        imageConstraints.flags = 0u;

        return setBufferCollectionImageConstraints(enc, device, collection,
                                                   &imageConstraints);
    }

    VkResult addImageBufferCollectionConstraints(
        VkEncoder* enc,
        VkDevice device,
        VkPhysicalDevice physicalDevice,
        const VkImageCreateInfo* createInfo,
        const VkImageFormatConstraintsInfoFUCHSIA* formatConstraints,
        VkImageTiling tiling,
        fuchsia_sysmem::wire::BufferCollectionConstraints* constraints) {
        // First check if the format, tiling and usage is supported on host.
        VkImageFormatProperties imageFormatProperties;
        auto result = enc->vkGetPhysicalDeviceImageFormatProperties(
            physicalDevice, createInfo->format, createInfo->imageType, tiling,
            createInfo->usage, createInfo->flags, &imageFormatProperties,
            true /* do lock */);
        if (result != VK_SUCCESS) {
            ALOGW(
                "%s: Image format (%u) type (%u) tiling (%u) "
                "usage (%u) flags (%u) not supported by physical "
                "device",
                __func__, static_cast<uint32_t>(createInfo->format),
                static_cast<uint32_t>(createInfo->imageType),
                static_cast<uint32_t>(tiling),
                static_cast<uint32_t>(createInfo->usage),
                static_cast<uint32_t>(createInfo->flags));
            return VK_ERROR_FORMAT_NOT_SUPPORTED;
        }

        // Check if format constraints contains unsupported format features.
        if (formatConstraints) {
            VkFormatProperties formatProperties;
            enc->vkGetPhysicalDeviceFormatProperties(
                physicalDevice, createInfo->format, &formatProperties,
                true /* do lock */);

            auto supportedFeatures =
                (tiling == VK_IMAGE_TILING_LINEAR)
                    ? formatProperties.linearTilingFeatures
                    : formatProperties.optimalTilingFeatures;
            auto requiredFeatures = formatConstraints->requiredFormatFeatures;
            if ((~supportedFeatures) & requiredFeatures) {
                ALOGW(
                    "%s: Host device support features for %s tiling: %08x, "
                    "required features: %08x, feature bits %08x missing",
                    __func__,
                    tiling == VK_IMAGE_TILING_LINEAR ? "LINEAR" : "OPTIMAL",
                    static_cast<uint32_t>(requiredFeatures),
                    static_cast<uint32_t>(supportedFeatures),
                    static_cast<uint32_t>((~supportedFeatures) &
                                          requiredFeatures));
                return VK_ERROR_FORMAT_NOT_SUPPORTED;
            }
        }

        fuchsia_sysmem::wire::ImageFormatConstraints imageConstraints;
        if (formatConstraints && formatConstraints->sysmemFormat != 0) {
            auto pixelFormat =
                static_cast<fuchsia_sysmem::wire::PixelFormatType>(
                    formatConstraints->sysmemFormat);
            if (createInfo->format != VK_FORMAT_UNDEFINED &&
                !vkFormatMatchesSysmemFormat(createInfo->format, pixelFormat)) {
                ALOGW("%s: VkFormat %u doesn't match sysmem pixelFormat %lu",
                      __func__, static_cast<uint32_t>(createInfo->format),
                      formatConstraints->sysmemFormat);
                return VK_ERROR_FORMAT_NOT_SUPPORTED;
            }
            imageConstraints.pixel_format.type = pixelFormat;
        } else {
            auto pixel_format = vkFormatTypeToSysmem(createInfo->format);
            if (pixel_format ==
                fuchsia_sysmem::wire::PixelFormatType::kInvalid) {
                ALOGW("%s: Unsupported VkFormat %u", __func__,
                      static_cast<uint32_t>(createInfo->format));
                return VK_ERROR_FORMAT_NOT_SUPPORTED;
            }
            imageConstraints.pixel_format.type = pixel_format;
        }

        if (!formatConstraints || formatConstraints->colorSpaceCount == 0u) {
            imageConstraints.color_spaces_count = 1;
            imageConstraints.color_space[0].type =
                fuchsia_sysmem::wire::ColorSpaceType::kSrgb;
        } else {
            imageConstraints.color_spaces_count =
                formatConstraints->colorSpaceCount;
            for (size_t i = 0; i < formatConstraints->colorSpaceCount; i++) {
                imageConstraints.color_space[0].type =
                    static_cast<fuchsia_sysmem::wire::ColorSpaceType>(
                        formatConstraints->pColorSpaces[i].colorSpace);
            }
        }

        // Get row alignment from host GPU.
        VkDeviceSize offset;
        VkDeviceSize rowPitchAlignment;
        enc->vkGetLinearImageLayoutGOOGLE(device, createInfo->format, &offset,
                                          &rowPitchAlignment,
                                          true /* do lock */);
        ALOGD(
            "vkGetLinearImageLayoutGOOGLE: format %d offset %lu "
            "rowPitchAlignment = %lu",
            (int)createInfo->format, offset, rowPitchAlignment);

        imageConstraints.min_coded_width = createInfo->extent.width;
        imageConstraints.max_coded_width = 0xfffffff;
        imageConstraints.min_coded_height = createInfo->extent.height;
        imageConstraints.max_coded_height = 0xffffffff;
        // The min_bytes_per_row can be calculated by sysmem using
        // |min_coded_width|, |bytes_per_row_divisor| and color format.
        imageConstraints.min_bytes_per_row = 0;
        imageConstraints.max_bytes_per_row = 0xffffffff;
        imageConstraints.max_coded_width_times_coded_height = 0xffffffff;

        imageConstraints.layers = 1;
        imageConstraints.coded_width_divisor = 1;
        imageConstraints.coded_height_divisor = 1;
        imageConstraints.bytes_per_row_divisor = rowPitchAlignment;
        imageConstraints.start_offset_divisor = 1;
        imageConstraints.display_width_divisor = 1;
        imageConstraints.display_height_divisor = 1;
        imageConstraints.pixel_format.has_format_modifier = true;
        imageConstraints.pixel_format.format_modifier.value =
            (tiling == VK_IMAGE_TILING_LINEAR)
                ? fuchsia_sysmem::wire::kFormatModifierLinear
                : fuchsia_sysmem::wire::kFormatModifierGoogleGoldfishOptimal;

        constraints->image_format_constraints
            [constraints->image_format_constraints_count++] =
            std::move(imageConstraints);
        return VK_SUCCESS;
    }

    VkResult setBufferCollectionImageConstraints(
        VkEncoder* enc,
        VkDevice device,
        fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>* collection,
        const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) {
        if (!pImageConstraintsInfo ||
            pImageConstraintsInfo->sType !=
                VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA) {
            ALOGE("%s: invalid pImageConstraintsInfo", __func__);
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        if (pImageConstraintsInfo->createInfoCount == 0) {
            ALOGE("%s: createInfoCount must be greater than 0", __func__);
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        fuchsia_sysmem::wire::BufferCollectionConstraints constraints =
            defaultBufferCollectionConstraints(
                /* min_size_bytes */ 0, pImageConstraintsInfo->minBufferCount,
                pImageConstraintsInfo->maxBufferCount,
                pImageConstraintsInfo->minBufferCountForCamping,
                pImageConstraintsInfo->minBufferCountForDedicatedSlack,
                pImageConstraintsInfo->minBufferCountForSharedSlack);

        std::vector<fuchsia_sysmem::wire::ImageFormatConstraints>
            format_constraints;

        VkPhysicalDevice physicalDevice;
        {
            AutoLock lock(mLock);
            auto deviceIt = info_VkDevice.find(device);
            if (deviceIt == info_VkDevice.end()) {
                return VK_ERROR_INITIALIZATION_FAILED;
            }
            physicalDevice = deviceIt->second.physdev;
        }

        std::vector<uint32_t> createInfoIndex;

        bool hasOptimalTiling = false;
        for (uint32_t i = 0; i < pImageConstraintsInfo->createInfoCount; i++) {
            const VkImageCreateInfo* createInfo =
                &pImageConstraintsInfo->pCreateInfos[i];
            const VkImageFormatConstraintsInfoFUCHSIA* formatConstraints =
                pImageConstraintsInfo->pFormatConstraints
                    ? &pImageConstraintsInfo->pFormatConstraints[i]
                    : nullptr;

            // add ImageFormatConstraints for *optimal* tiling
            VkResult optimalResult = VK_ERROR_FORMAT_NOT_SUPPORTED;
            if (createInfo->tiling == VK_IMAGE_TILING_OPTIMAL) {
                optimalResult = addImageBufferCollectionConstraints(
                    enc, device, physicalDevice, createInfo, formatConstraints,
                    VK_IMAGE_TILING_OPTIMAL, &constraints);
                if (optimalResult == VK_SUCCESS) {
                    createInfoIndex.push_back(i);
                    hasOptimalTiling = true;
                }
            }

            // Add ImageFormatConstraints for *linear* tiling
            VkResult linearResult = addImageBufferCollectionConstraints(
                enc, device, physicalDevice, createInfo, formatConstraints,
                VK_IMAGE_TILING_LINEAR, &constraints);
            if (linearResult == VK_SUCCESS) {
                createInfoIndex.push_back(i);
            }

            // Update usage and BufferMemoryConstraints
            if (linearResult == VK_SUCCESS || optimalResult == VK_SUCCESS) {
                constraints.usage.vulkan |=
                    getBufferCollectionConstraintsVulkanImageUsage(createInfo);

                if (formatConstraints && formatConstraints->flags) {
                    ALOGW(
                        "%s: Non-zero flags (%08x) in image format "
                        "constraints; this is currently not supported, see "
                        "fxbug.dev/68833.",
                        __func__, formatConstraints->flags);
                }
            }
        }

        // Set buffer memory constraints based on optimal/linear tiling support
        // and flags.
        VkImageConstraintsInfoFlagsFUCHSIA flags = pImageConstraintsInfo->flags;
        if (flags & VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_RARELY_FUCHSIA)
            constraints.usage.cpu |= fuchsia_sysmem::wire::kCpuUsageRead;
        if (flags & VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_OFTEN_FUCHSIA)
            constraints.usage.cpu |= fuchsia_sysmem::wire::kCpuUsageReadOften;
        if (flags & VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_RARELY_FUCHSIA)
            constraints.usage.cpu |= fuchsia_sysmem::wire::kCpuUsageWrite;
        if (flags & VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_OFTEN_FUCHSIA)
            constraints.usage.cpu |= fuchsia_sysmem::wire::kCpuUsageWriteOften;

        constraints.has_buffer_memory_constraints = true;
        auto& memory_constraints = constraints.buffer_memory_constraints;
        memory_constraints.cpu_domain_supported = true;
        memory_constraints.ram_domain_supported = true;
        memory_constraints.inaccessible_domain_supported =
            hasOptimalTiling &&
            !(flags & (VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_RARELY_FUCHSIA |
                       VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_OFTEN_FUCHSIA |
                       VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_RARELY_FUCHSIA |
                       VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_OFTEN_FUCHSIA));

        if (memory_constraints.inaccessible_domain_supported) {
            memory_constraints.heap_permitted_count = 2;
            memory_constraints.heap_permitted[0] =
                fuchsia_sysmem::wire::HeapType::kGoldfishDeviceLocal;
            memory_constraints.heap_permitted[1] =
                fuchsia_sysmem::wire::HeapType::kGoldfishHostVisible;
        } else {
            memory_constraints.heap_permitted_count = 1;
            memory_constraints.heap_permitted[0] =
                fuchsia_sysmem::wire::HeapType::kGoldfishHostVisible;
        }

        if (constraints.image_format_constraints_count == 0) {
            ALOGE("%s: none of the specified formats is supported by device",
                  __func__);
            return VK_ERROR_FORMAT_NOT_SUPPORTED;
        }

        constexpr uint32_t kVulkanPriority = 5;
        const char kName[] = "GoldfishSysmemShared";
        collection->SetName(kVulkanPriority, fidl::StringView(kName));

        auto result = collection->SetConstraints(true, constraints);
        if (!result.ok()) {
            ALOGE("setBufferCollectionConstraints: SetConstraints failed: %d",
                  result.status());
            return VK_ERROR_OUT_OF_DEVICE_MEMORY;
        }

        // copy constraints to info_VkBufferCollectionFUCHSIA if
        // |collection| is a valid VkBufferCollectionFUCHSIA handle.
        AutoLock lock(mLock);
        VkBufferCollectionFUCHSIA buffer_collection =
            reinterpret_cast<VkBufferCollectionFUCHSIA>(collection);
        if (info_VkBufferCollectionFUCHSIA.find(buffer_collection) !=
            info_VkBufferCollectionFUCHSIA.end()) {
            info_VkBufferCollectionFUCHSIA[buffer_collection].constraints =
                android::base::makeOptional(std::move(constraints));
            info_VkBufferCollectionFUCHSIA[buffer_collection].createInfoIndex =
                std::move(createInfoIndex);
        }

        return VK_SUCCESS;
    }

    VkResult setBufferCollectionBufferConstraints(
        fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>* collection,
        const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) {
        if (pBufferConstraintsInfo == nullptr) {
            ALOGE(
                "setBufferCollectionBufferConstraints: "
                "pBufferConstraintsInfo cannot be null.");
            return VK_ERROR_OUT_OF_DEVICE_MEMORY;
        }

        fuchsia_sysmem::wire::BufferCollectionConstraints constraints =
            defaultBufferCollectionConstraints(
                /* min_size_bytes */ pBufferConstraintsInfo->pBufferCreateInfo->size,
                /* buffer_count */ pBufferConstraintsInfo->minCount);
        constraints.usage.vulkan =
            getBufferCollectionConstraintsVulkanBufferUsage(
                pBufferConstraintsInfo);

        constexpr uint32_t kVulkanPriority = 5;
        const char kName[] = "GoldfishBufferSysmemShared";
        collection->SetName(kVulkanPriority, fidl::StringView(kName));

        auto result = collection->SetConstraints(true, constraints);
        if (!result.ok()) {
            ALOGE("setBufferCollectionConstraints: SetConstraints failed: %d",
                  result.status());
            return VK_ERROR_OUT_OF_DEVICE_MEMORY;
        }

        // copy constraints to info_VkBufferCollectionFUCHSIA if
        // |collection| is a valid VkBufferCollectionFUCHSIA handle.
        AutoLock lock(mLock);
        VkBufferCollectionFUCHSIA buffer_collection =
            reinterpret_cast<VkBufferCollectionFUCHSIA>(collection);
        if (info_VkBufferCollectionFUCHSIA.find(buffer_collection) !=
            info_VkBufferCollectionFUCHSIA.end()) {
            info_VkBufferCollectionFUCHSIA[buffer_collection].constraints =
                android::base::makeOptional(std::move(constraints));
        }

        return VK_SUCCESS;
    }

    VkResult on_vkSetBufferCollectionConstraintsFUCHSIA(
        void* context, VkResult, VkDevice device,
        VkBufferCollectionFUCHSIA collection,
        const VkImageCreateInfo* pImageInfo) {
        VkEncoder* enc = (VkEncoder*)context;
        auto sysmem_collection = reinterpret_cast<
            fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>*>(collection);
        return setBufferCollectionConstraints(enc, device, sysmem_collection, pImageInfo);
    }

    VkResult on_vkSetBufferCollectionImageConstraintsFUCHSIA(
        void* context,
        VkResult,
        VkDevice device,
        VkBufferCollectionFUCHSIA collection,
        const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) {
        VkEncoder* enc = (VkEncoder*)context;
        auto sysmem_collection = reinterpret_cast<
            fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>*>(collection);
        return setBufferCollectionImageConstraints(
            enc, device, sysmem_collection, pImageConstraintsInfo);
    }

    VkResult on_vkSetBufferCollectionBufferConstraintsFUCHSIA(
        void*,
        VkResult,
        VkDevice,
        VkBufferCollectionFUCHSIA collection,
        const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) {
        auto sysmem_collection = reinterpret_cast<
            fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>*>(collection);
        return setBufferCollectionBufferConstraints(sysmem_collection,
                                                    pBufferConstraintsInfo);
    }

    VkResult on_vkGetBufferCollectionPropertiesFUCHSIA(
        void* context,
        VkResult,
        VkDevice device,
        VkBufferCollectionFUCHSIA collection,
        VkBufferCollectionPropertiesFUCHSIA* pProperties) {
        VkBufferCollectionProperties2FUCHSIA properties2 = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES2_FUCHSIA,
            .pNext = nullptr};
        auto result = on_vkGetBufferCollectionProperties2FUCHSIA(
            context, VK_SUCCESS, device, collection, &properties2);
        if (result != VK_SUCCESS) {
            return result;
        }

        pProperties->count = properties2.bufferCount;
        pProperties->memoryTypeBits = properties2.memoryTypeBits;
        return VK_SUCCESS;
    }

    VkResult getBufferCollectionImageCreateInfoIndexLocked(
        VkBufferCollectionFUCHSIA collection,
        fuchsia_sysmem::wire::BufferCollectionInfo2& info,
        uint32_t* outCreateInfoIndex) {
        if (!info_VkBufferCollectionFUCHSIA[collection]
                 .constraints.hasValue()) {
            ALOGE("%s: constraints not set", __func__);
            return VK_ERROR_OUT_OF_DEVICE_MEMORY;
        }

        if (!info.settings.has_image_format_constraints) {
            // no image format constraints, skip getting createInfoIndex.
            return VK_SUCCESS;
        }

        const auto& constraints =
            *info_VkBufferCollectionFUCHSIA[collection].constraints;
        const auto& createInfoIndices =
            info_VkBufferCollectionFUCHSIA[collection].createInfoIndex;
        const auto& out = info.settings.image_format_constraints;
        bool foundCreateInfo = false;

        for (size_t imageFormatIndex = 0;
             imageFormatIndex < constraints.image_format_constraints_count;
             imageFormatIndex++) {
            const auto& in =
                constraints.image_format_constraints[imageFormatIndex];
            // These checks are sorted in order of how often they're expected to
            // mismatch, from most likely to least likely. They aren't always
            // equality comparisons, since sysmem may change some values in
            // compatible ways on behalf of the other participants.
            if ((out.pixel_format.type != in.pixel_format.type) ||
                (out.pixel_format.has_format_modifier !=
                 in.pixel_format.has_format_modifier) ||
                (out.pixel_format.format_modifier.value !=
                 in.pixel_format.format_modifier.value) ||
                (out.min_bytes_per_row < in.min_bytes_per_row) ||
                (out.required_max_coded_width < in.required_max_coded_width) ||
                (out.required_max_coded_height <
                 in.required_max_coded_height) ||
                (out.bytes_per_row_divisor % in.bytes_per_row_divisor != 0)) {
                continue;
            }
            // Check if the out colorspaces are a subset of the in color spaces.
            bool all_color_spaces_found = true;
            for (uint32_t j = 0; j < out.color_spaces_count; j++) {
                bool found_matching_color_space = false;
                for (uint32_t k = 0; k < in.color_spaces_count; k++) {
                    if (out.color_space[j].type == in.color_space[k].type) {
                        found_matching_color_space = true;
                        break;
                    }
                }
                if (!found_matching_color_space) {
                    all_color_spaces_found = false;
                    break;
                }
            }
            if (!all_color_spaces_found) {
                continue;
            }

            // Choose the first valid format for now.
            *outCreateInfoIndex = createInfoIndices[imageFormatIndex];
            return VK_SUCCESS;
        }

        ALOGE("%s: cannot find a valid image format in constraints", __func__);
        return VK_ERROR_OUT_OF_DEVICE_MEMORY;
    }

    VkResult on_vkGetBufferCollectionProperties2FUCHSIA(
        void* context,
        VkResult,
        VkDevice device,
        VkBufferCollectionFUCHSIA collection,
        VkBufferCollectionProperties2FUCHSIA* pProperties) {
        VkEncoder* enc = (VkEncoder*)context;
        auto sysmem_collection = reinterpret_cast<
            fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>*>(collection);

        auto result = sysmem_collection->WaitForBuffersAllocated();
        if (!result.ok() || result.Unwrap()->status != ZX_OK) {
            ALOGE("Failed wait for allocation: %d %d", result.status(),
                  GET_STATUS_SAFE(result, status));
            return VK_ERROR_INITIALIZATION_FAILED;
        }
        fuchsia_sysmem::wire::BufferCollectionInfo2 info =
            std::move(result.Unwrap()->buffer_collection_info);

        bool is_host_visible = info.settings.buffer_settings.heap ==
                               fuchsia_sysmem::wire::HeapType::kGoldfishHostVisible;
        bool is_device_local = info.settings.buffer_settings.heap ==
                               fuchsia_sysmem::wire::HeapType::kGoldfishDeviceLocal;
        if (!is_host_visible && !is_device_local) {
            ALOGE("buffer collection uses a non-goldfish heap (type 0x%lu)",
                static_cast<uint64_t>(info.settings.buffer_settings.heap));
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        // memoryTypeBits
        // ====================================================================
        {
            AutoLock lock(mLock);
            auto deviceIt = info_VkDevice.find(device);
            if (deviceIt == info_VkDevice.end()) {
                return VK_ERROR_INITIALIZATION_FAILED;
            }
            auto& deviceInfo = deviceIt->second;

            // Device local memory type supported.
            pProperties->memoryTypeBits = 0;
            for (uint32_t i = 0; i < deviceInfo.memProps.memoryTypeCount; ++i) {
                if ((is_device_local &&
                     (deviceInfo.memProps.memoryTypes[i].propertyFlags &
                      VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT)) ||
                    (is_host_visible &&
                     (deviceInfo.memProps.memoryTypes[i].propertyFlags &
                      VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT))) {
                    pProperties->memoryTypeBits |= 1ull << i;
                }
            }
        }

        // bufferCount
        // ====================================================================
        pProperties->bufferCount = info.buffer_count;

        auto storeProperties = [this, collection, pProperties]() -> VkResult {
            // store properties to storage
            AutoLock lock(mLock);
            if (info_VkBufferCollectionFUCHSIA.find(collection) ==
                info_VkBufferCollectionFUCHSIA.end()) {
                return VK_ERROR_OUT_OF_DEVICE_MEMORY;
            }

            info_VkBufferCollectionFUCHSIA[collection].properties =
                android::base::makeOptional(*pProperties);

            // We only do a shallow copy so we should remove all pNext pointers.
            info_VkBufferCollectionFUCHSIA[collection].properties->pNext =
                nullptr;
            info_VkBufferCollectionFUCHSIA[collection]
                .properties->colorSpace.pNext = nullptr;
            return VK_SUCCESS;
        };

        // The fields below only apply to buffer collections with image formats.
        if (!info.settings.has_image_format_constraints) {
            ALOGD("%s: buffer collection doesn't have image format constraints",
                  __func__);
            return storeProperties();
        }

        // sysmemFormat
        // ====================================================================

        pProperties->sysmemFormat = static_cast<uint64_t>(
            info.settings.image_format_constraints.pixel_format.type);

        // colorSpace
        // ====================================================================
        if (info.settings.image_format_constraints.color_spaces_count == 0) {
            ALOGE(
                "%s: color space missing from allocated buffer collection "
                "constraints",
                __func__);
            return VK_ERROR_OUT_OF_DEVICE_MEMORY;
        }
        // Only report first colorspace for now.
        pProperties->colorSpace.colorSpace = static_cast<uint32_t>(
            info.settings.image_format_constraints.color_space[0].type);

        // createInfoIndex
        // ====================================================================
        {
            AutoLock lock(mLock);
            auto getIndexResult = getBufferCollectionImageCreateInfoIndexLocked(
                collection, info, &pProperties->createInfoIndex);
            if (getIndexResult != VK_SUCCESS) {
                return getIndexResult;
            }
        }

        // formatFeatures
        // ====================================================================
        VkPhysicalDevice physicalDevice;
        {
            AutoLock lock(mLock);
            auto deviceIt = info_VkDevice.find(device);
            if (deviceIt == info_VkDevice.end()) {
                return VK_ERROR_INITIALIZATION_FAILED;
            }
            physicalDevice = deviceIt->second.physdev;
        }

        VkFormat vkFormat = sysmemPixelFormatTypeToVk(
            info.settings.image_format_constraints.pixel_format.type);
        VkFormatProperties formatProperties;
        enc->vkGetPhysicalDeviceFormatProperties(
            physicalDevice, vkFormat, &formatProperties, true /* do lock */);
        if (is_device_local) {
            pProperties->formatFeatures =
                formatProperties.optimalTilingFeatures;
        }
        if (is_host_visible) {
            pProperties->formatFeatures = formatProperties.linearTilingFeatures;
        }

        // YCbCr properties
        // ====================================================================
        // TODO(59804): Implement this correctly when we support YUV pixel
        // formats in goldfish ICD.
        pProperties->samplerYcbcrConversionComponents.r =
            VK_COMPONENT_SWIZZLE_IDENTITY;
        pProperties->samplerYcbcrConversionComponents.g =
            VK_COMPONENT_SWIZZLE_IDENTITY;
        pProperties->samplerYcbcrConversionComponents.b =
            VK_COMPONENT_SWIZZLE_IDENTITY;
        pProperties->samplerYcbcrConversionComponents.a =
            VK_COMPONENT_SWIZZLE_IDENTITY;
        pProperties->suggestedYcbcrModel =
            VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY;
        pProperties->suggestedYcbcrRange = VK_SAMPLER_YCBCR_RANGE_ITU_FULL;
        pProperties->suggestedXChromaOffset = VK_CHROMA_LOCATION_MIDPOINT;
        pProperties->suggestedYChromaOffset = VK_CHROMA_LOCATION_MIDPOINT;

        return storeProperties();
    }
#endif

    HostMemBlockIndex getOrAllocateHostMemBlockLocked(
        HostMemBlocks& blocks,
        const VkMemoryAllocateInfo* pAllocateInfo,
        VkEncoder* enc,
        VkDevice device,
        const VkDevice_Info& deviceInfo) {

        HostMemBlockIndex res = 0;
        bool found = false;

        VkMemoryAllocateFlagsInfo allocFlagsInfo;
        VkMemoryOpaqueCaptureAddressAllocateInfo opaqueCaptureAddressAllocInfo;

        // Add buffer device address capture structs
        const VkMemoryAllocateFlagsInfo* allocFlagsInfoPtr =
            vk_find_struct<VkMemoryAllocateFlagsInfo>(pAllocateInfo);
        const VkMemoryOpaqueCaptureAddressAllocateInfo* opaqueCaptureAddressAllocInfoPtr =
            vk_find_struct<VkMemoryOpaqueCaptureAddressAllocateInfo>(pAllocateInfo);

        bool isDeviceAddressMemoryAllocation =
            allocFlagsInfoPtr && ((allocFlagsInfoPtr->flags & VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT) ||
               (allocFlagsInfoPtr->flags & VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT));
        bool isDedicated = isDeviceAddressMemoryAllocation;

        while (!found) {
            // If we need a dedicated host mapping, found = true necessarily
            if (isDedicated) {
                found = true;
            } else {
                for (HostMemBlockIndex i = 0; i < blocks.size(); ++i) {
                    if (blocks[i].initialized &&
                        blocks[i].initResult == VK_SUCCESS &&
                        !blocks[i].isDedicated &&
                        blocks[i].isDeviceAddressMemoryAllocation == isDeviceAddressMemoryAllocation &&
                        canSubAlloc(
                            blocks[i].subAlloc,
                            pAllocateInfo->allocationSize)) {
                        res = i;
                        found = true;
                        return res;
                    }
                }
            }

            blocks.push_back({});

            auto& hostMemAlloc = blocks.back();

            hostMemAlloc.isDedicated = isDedicated;

            // Uninitialized block; allocate on host.
            static constexpr VkDeviceSize oneMb = 1048576;
            // This needs to be a power of 2 that is at least the min alignment needed in HostVisibleMemoryVirtualization.cpp.
            static constexpr VkDeviceSize biggestPage = 65536;
            static constexpr VkDeviceSize kDefaultHostMemBlockSize =
                16 * oneMb; // 16 mb
            VkDeviceSize roundedUpAllocSize =
                oneMb * ((pAllocateInfo->allocationSize + oneMb - 1) / oneMb);

            // If dedicated, use a smaller "page rounded alloc size".
            VkDeviceSize pageRoundedAllocSize =
                biggestPage * ((pAllocateInfo->allocationSize + biggestPage - 1) / biggestPage);

            VkDeviceSize virtualHeapSize = VIRTUAL_HOST_VISIBLE_HEAP_SIZE;

            VkDeviceSize blockSizeNeeded =
                std::max(roundedUpAllocSize,
                    std::min(virtualHeapSize,
                             kDefaultHostMemBlockSize));

            VkMemoryAllocateInfo allocInfoForHost = vk_make_orphan_copy(*pAllocateInfo);
            vk_struct_chain_iterator structChainIter = vk_make_chain_iterator(&allocInfoForHost);

            allocInfoForHost.allocationSize = blockSizeNeeded;

            if (isDedicated) {
                allocInfoForHost.allocationSize = pageRoundedAllocSize;
            }

            // TODO: Support dedicated/external host visible allocation

            // Support device address capture/replay allocations
            if (isDeviceAddressMemoryAllocation) {
                hostMemAlloc.isDeviceAddressMemoryAllocation = true;
                if (allocFlagsInfoPtr) {
                    ALOGV("%s: has alloc flags\n", __func__);
                    allocFlagsInfo = *allocFlagsInfoPtr;
                    vk_append_struct(&structChainIter, &allocFlagsInfo);
                }

                if (opaqueCaptureAddressAllocInfoPtr) {
                    ALOGV("%s: has opaque capture address\n", __func__);
                    opaqueCaptureAddressAllocInfo = *opaqueCaptureAddressAllocInfoPtr;
                    vk_append_struct(&structChainIter, &opaqueCaptureAddressAllocInfo);
                }
            }

            mLock.unlock();
            VkResult host_res =
                enc->vkAllocateMemory(
                    device,
                    &allocInfoForHost,
                    nullptr,
                    &hostMemAlloc.memory, true /* do lock */);
            mLock.lock();

            if (host_res != VK_SUCCESS) {
                ALOGE("Could not allocate backing for virtual host visible memory: %d",
                      host_res);
                hostMemAlloc.initialized = true;
                hostMemAlloc.initResult = host_res;
                return INVALID_HOST_MEM_BLOCK;
            }

            auto& hostMemInfo = info_VkDeviceMemory[hostMemAlloc.memory];
            hostMemInfo.allocationSize = allocInfoForHost.allocationSize;
            VkDeviceSize nonCoherentAtomSize =
                deviceInfo.props.limits.nonCoherentAtomSize;
            hostMemInfo.mappedSize = hostMemInfo.allocationSize;
            hostMemInfo.memoryTypeIndex =
                pAllocateInfo->memoryTypeIndex;
            hostMemAlloc.nonCoherentAtomSize = nonCoherentAtomSize;

            uint64_t directMappedAddr = 0;

            VkResult directMapResult = VK_SUCCESS;
            if (mFeatureInfo->hasDirectMem) {
                mLock.unlock();
                directMapResult =
                    enc->vkMapMemoryIntoAddressSpaceGOOGLE(
                            device, hostMemAlloc.memory, &directMappedAddr, true /* do lock */);
                ALOGV("%s: direct mapped addr 0x%llx\n", __func__,
                      (unsigned long long)directMappedAddr);
                mLock.lock();
            } else if (mFeatureInfo->hasVirtioGpuNext) {
#if !defined(HOST_BUILD) && defined(VK_USE_PLATFORM_ANDROID_KHR)
                uint64_t hvaSizeId[3];

                int rendernodeFdForMem = drmOpenRender(128 /* RENDERNODE_MINOR */);
                ALOGE("%s: render fd = %d\n", __func__, rendernodeFdForMem);

                mLock.unlock();
                enc->vkGetMemoryHostAddressInfoGOOGLE(
                        device, hostMemAlloc.memory,
                        &hvaSizeId[0], &hvaSizeId[1], &hvaSizeId[2], true /* do lock */);
                ALOGD("%s: hvaOff, size: 0x%llx 0x%llx id: 0x%llx\n", __func__,
                        (unsigned long long)hvaSizeId[0],
                        (unsigned long long)hvaSizeId[1],
                        (unsigned long long)hvaSizeId[2]);
                mLock.lock();

                struct drm_virtgpu_resource_create_blob drm_rc_blob = { 0 };
                drm_rc_blob.blob_mem = VIRTGPU_BLOB_MEM_HOST;
                drm_rc_blob.blob_flags = VIRTGPU_BLOB_FLAG_MAPPABLE;
                drm_rc_blob.blob_id = hvaSizeId[2];
                drm_rc_blob.size = hvaSizeId[1];

                int res = drmIoctl(
                    rendernodeFdForMem, DRM_IOCTL_VIRTGPU_RESOURCE_CREATE_BLOB, &drm_rc_blob);

                if (res) {
                    ALOGE("%s: Failed to resource create v2: sterror: %s errno: %d\n", __func__,
                            strerror(errno), errno);
                    abort();
                }

                drm_virtgpu_map map_info;
                memset(&map_info, 0, sizeof(map_info));
                map_info.handle = drm_rc_blob.bo_handle;

                res = drmIoctl(rendernodeFdForMem, DRM_IOCTL_VIRTGPU_MAP, &map_info);
                if (res) {
                    ALOGE("%s: Failed to virtgpu map: sterror: %s errno: %d\n", __func__,
                            strerror(errno), errno);
                    abort();
                }

                directMappedAddr = (uint64_t)(uintptr_t)
                    mmap64(0, hvaSizeId[1], PROT_WRITE, MAP_SHARED, rendernodeFdForMem, map_info.offset);

                if (!directMappedAddr) {
                    ALOGE("%s: mmap of virtio gpu resource failed\n", __func__);
                    abort();
                }

                hostMemAlloc.memoryAddr = directMappedAddr;
                hostMemAlloc.memorySize = hvaSizeId[1];

                // add the host's page offset
                directMappedAddr += (uint64_t)(uintptr_t)(hvaSizeId[0]) & (PAGE_SIZE - 1);
				directMapResult = VK_SUCCESS;

                hostMemAlloc.fd = rendernodeFdForMem;
#endif // VK_USE_PLATFORM_ANDROID_KHR
            }

            if (directMapResult != VK_SUCCESS) {
                ALOGE("%s: error: directMapResult != VK_SUCCESS\n", __func__);
                hostMemAlloc.initialized = true;
                hostMemAlloc.initResult = directMapResult;
                mLock.unlock();
                enc->vkFreeMemory(device, hostMemAlloc.memory, nullptr, true /* do lock */);
                mLock.lock();
                return INVALID_HOST_MEM_BLOCK;
            }

            hostMemInfo.mappedPtr =
                (uint8_t*)(uintptr_t)directMappedAddr;
            hostMemInfo.virtualHostVisibleBacking = true;
            ALOGV("%s: Set mapped ptr to %p\n", __func__, hostMemInfo.mappedPtr);

            VkResult hostMemAllocRes =
                finishHostMemAllocInit(
                    enc,
                    device,
                    pAllocateInfo->memoryTypeIndex,
                    nonCoherentAtomSize,
                    hostMemInfo.allocationSize,
                    hostMemInfo.mappedSize,
                    hostMemInfo.mappedPtr,
                    &hostMemAlloc);

            if (hostMemAllocRes != VK_SUCCESS) {
                return INVALID_HOST_MEM_BLOCK;
            }

            if (isDedicated) {
                ALOGV("%s: New dedicated block at %zu\n", __func__, blocks.size() - 1);
                return blocks.size() - 1;
            }
        }

        // unreacheable, but we need to make Werror happy
        return INVALID_HOST_MEM_BLOCK;
    }

    uint64_t getAHardwareBufferId(AHardwareBuffer* ahw) {
        uint64_t id = 0;
#if defined(PLATFORM_SDK_VERSION) && PLATFORM_SDK_VERSION >= 31
        AHardwareBuffer_getId(ahw, &id);
#else
        (void)ahw;
#endif
        return id;
    }

    VkResult on_vkAllocateMemory(
        void* context,
        VkResult input_result,
        VkDevice device,
        const VkMemoryAllocateInfo* pAllocateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDeviceMemory* pMemory) {

#define _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(result) \
        { \
            auto it = info_VkDevice.find(device); \
            if (it == info_VkDevice.end()) return result; \
            emitDeviceMemoryReport( \
                it->second, \
                VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT, \
                0, \
                pAllocateInfo->allocationSize, \
                VK_OBJECT_TYPE_DEVICE_MEMORY, \
                0, \
                pAllocateInfo->memoryTypeIndex); \
            return result; \
        }

#define _RETURN_SCUCCESS_WITH_DEVICE_MEMORY_REPORT \
        { \
            uint64_t memoryObjectId = (uint64_t)(void*)*pMemory; \
            if (ahw) { \
                memoryObjectId = getAHardwareBufferId(ahw); \
            } \
            emitDeviceMemoryReport( \
                info_VkDevice[device], \
                isImport ? VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT : VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT, \
                memoryObjectId, \
                pAllocateInfo->allocationSize, \
                VK_OBJECT_TYPE_DEVICE_MEMORY, \
                (uint64_t)(void*)*pMemory, \
                pAllocateInfo->memoryTypeIndex); \
            return VK_SUCCESS; \
        }


        if (input_result != VK_SUCCESS) _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(input_result);

        VkEncoder* enc = (VkEncoder*)context;

        VkMemoryAllocateInfo finalAllocInfo = vk_make_orphan_copy(*pAllocateInfo);
        vk_struct_chain_iterator structChainIter = vk_make_chain_iterator(&finalAllocInfo);

        VkMemoryAllocateFlagsInfo allocFlagsInfo;
        VkMemoryOpaqueCaptureAddressAllocateInfo opaqueCaptureAddressAllocInfo;

        // Add buffer device address capture structs
        const VkMemoryAllocateFlagsInfo* allocFlagsInfoPtr =
            vk_find_struct<VkMemoryAllocateFlagsInfo>(pAllocateInfo);
        const VkMemoryOpaqueCaptureAddressAllocateInfo* opaqueCaptureAddressAllocInfoPtr =
            vk_find_struct<VkMemoryOpaqueCaptureAddressAllocateInfo>(pAllocateInfo);

        if (allocFlagsInfoPtr) {
            ALOGV("%s: has alloc flags\n", __func__);
            allocFlagsInfo = *allocFlagsInfoPtr;
            vk_append_struct(&structChainIter, &allocFlagsInfo);
        }

        if (opaqueCaptureAddressAllocInfoPtr) {
            ALOGV("%s: has opaque capture address\n", __func__);
            opaqueCaptureAddressAllocInfo = *opaqueCaptureAddressAllocInfoPtr;
            vk_append_struct(&structChainIter, &opaqueCaptureAddressAllocInfo);
        }

        VkMemoryDedicatedAllocateInfo dedicatedAllocInfo;
        VkImportColorBufferGOOGLE importCbInfo = {
            VK_STRUCTURE_TYPE_IMPORT_COLOR_BUFFER_GOOGLE, 0,
        };
        VkImportBufferGOOGLE importBufferInfo = {
                VK_STRUCTURE_TYPE_IMPORT_BUFFER_GOOGLE,
                0,
        };
        // VkImportPhysicalAddressGOOGLE importPhysAddrInfo = {
        //     VK_STRUCTURE_TYPE_IMPORT_PHYSICAL_ADDRESS_GOOGLE, 0,
        // };

        const VkExportMemoryAllocateInfo* exportAllocateInfoPtr =
            vk_find_struct<VkExportMemoryAllocateInfo>(pAllocateInfo);

        const VkImportAndroidHardwareBufferInfoANDROID* importAhbInfoPtr =
            vk_find_struct<VkImportAndroidHardwareBufferInfoANDROID>(pAllocateInfo);

        const VkImportMemoryBufferCollectionFUCHSIA* importBufferCollectionInfoPtr =
            vk_find_struct<VkImportMemoryBufferCollectionFUCHSIA>(pAllocateInfo);

        const VkImportMemoryZirconHandleInfoFUCHSIA* importVmoInfoPtr =
            vk_find_struct<VkImportMemoryZirconHandleInfoFUCHSIA>(pAllocateInfo);
        if (!importVmoInfoPtr) {
            importVmoInfoPtr = reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(
                __vk_find_struct(const_cast<void*>(pAllocateInfo->pNext),
                    VK_STRUCTURE_TYPE_TEMP_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA));
        }

        const VkMemoryDedicatedAllocateInfo* dedicatedAllocInfoPtr =
            vk_find_struct<VkMemoryDedicatedAllocateInfo>(pAllocateInfo);

        bool shouldPassThroughDedicatedAllocInfo =
            !exportAllocateInfoPtr && !importAhbInfoPtr &&
            !importBufferCollectionInfoPtr && !importVmoInfoPtr;

#ifndef VK_USE_PLATFORM_FUCHSIA
        shouldPassThroughDedicatedAllocInfo &=
            !isHostVisibleMemoryTypeIndexForGuest(
                &mHostVisibleMemoryVirtInfo, pAllocateInfo->memoryTypeIndex);

        if (!exportAllocateInfoPtr &&
            (importAhbInfoPtr || importBufferCollectionInfoPtr ||
             importVmoInfoPtr) &&
            dedicatedAllocInfoPtr &&
            isHostVisibleMemoryTypeIndexForGuest(
                &mHostVisibleMemoryVirtInfo, pAllocateInfo->memoryTypeIndex)) {
            ALOGE(
                "FATAL: It is not yet supported to import-allocate "
                "external memory that is both host visible and dedicated.");
            abort();
        }
#endif  // VK_USE_PLATFORM_FUCHSIA

        if (shouldPassThroughDedicatedAllocInfo &&
            dedicatedAllocInfoPtr) {
            dedicatedAllocInfo = vk_make_orphan_copy(*dedicatedAllocInfoPtr);
            vk_append_struct(&structChainIter, &dedicatedAllocInfo);
        }

        // State needed for import/export.
        bool exportAhb = false;
        bool exportVmo = false;
        bool importAhb = false;
        bool importBufferCollection = false;
        bool importVmo = false;
        (void)exportVmo;

        // Even if we export allocate, the underlying operation
        // for the host is always going to be an import operation.
        // This is also how Intel's implementation works,
        // and is generally simpler;
        // even in an export allocation,
        // we perform AHardwareBuffer allocation
        // on the guest side, at this layer,
        // and then we attach a new VkDeviceMemory
        // to the AHardwareBuffer on the host via an "import" operation.
        AHardwareBuffer* ahw = nullptr;

        if (exportAllocateInfoPtr) {
            exportAhb =
                exportAllocateInfoPtr->handleTypes &
                VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID;
            exportVmo =
                (exportAllocateInfoPtr->handleTypes &
                    VK_EXTERNAL_MEMORY_HANDLE_TYPE_TEMP_ZIRCON_VMO_BIT_FUCHSIA) ||
                (exportAllocateInfoPtr->handleTypes &
                    VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA);
        } else if (importAhbInfoPtr) {
            importAhb = true;
        } else if (importBufferCollectionInfoPtr) {
            importBufferCollection = true;
        } else if (importVmoInfoPtr) {
            importVmo = true;
        }
        bool isImport = importAhb || importBufferCollection || importVmo;

        if (exportAhb) {
            bool hasDedicatedImage = dedicatedAllocInfoPtr &&
                (dedicatedAllocInfoPtr->image != VK_NULL_HANDLE);
            bool hasDedicatedBuffer = dedicatedAllocInfoPtr &&
                (dedicatedAllocInfoPtr->buffer != VK_NULL_HANDLE);
            VkExtent3D imageExtent = { 0, 0, 0 };
            uint32_t imageLayers = 0;
            VkFormat imageFormat = VK_FORMAT_UNDEFINED;
            VkImageUsageFlags imageUsage = 0;
            VkImageCreateFlags imageCreateFlags = 0;
            VkDeviceSize bufferSize = 0;
            VkDeviceSize allocationInfoAllocSize =
                finalAllocInfo.allocationSize;

            if (hasDedicatedImage) {
                AutoLock lock(mLock);

                auto it = info_VkImage.find(
                    dedicatedAllocInfoPtr->image);
                if (it == info_VkImage.end()) _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(VK_ERROR_INITIALIZATION_FAILED);
                const auto& info = it->second;
                const auto& imgCi = info.createInfo;

                imageExtent = imgCi.extent;
                imageLayers = imgCi.arrayLayers;
                imageFormat = imgCi.format;
                imageUsage = imgCi.usage;
                imageCreateFlags = imgCi.flags;
            }

            if (hasDedicatedBuffer) {
                AutoLock lock(mLock);

                auto it = info_VkBuffer.find(
                    dedicatedAllocInfoPtr->buffer);
                if (it == info_VkBuffer.end()) _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(VK_ERROR_INITIALIZATION_FAILED);
                const auto& info = it->second;
                const auto& bufCi = info.createInfo;

                bufferSize = bufCi.size;
            }

            VkResult ahbCreateRes =
                createAndroidHardwareBuffer(
                    hasDedicatedImage,
                    hasDedicatedBuffer,
                    imageExtent,
                    imageLayers,
                    imageFormat,
                    imageUsage,
                    imageCreateFlags,
                    bufferSize,
                    allocationInfoAllocSize,
                    &ahw);

            if (ahbCreateRes != VK_SUCCESS) {
                _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(ahbCreateRes);
            }
        }

        if (importAhb) {
            ahw = importAhbInfoPtr->buffer;
            // We still need to acquire the AHardwareBuffer.
            importAndroidHardwareBuffer(
                ResourceTracker::threadingCallbacks.hostConnectionGetFunc()->grallocHelper(),
                importAhbInfoPtr, nullptr);
        }

        if (ahw) {
            ALOGD("%s: Import AHardwareBuffer", __func__);
            importCbInfo.colorBuffer =
                ResourceTracker::threadingCallbacks.hostConnectionGetFunc()->grallocHelper()->
                    getHostHandle(AHardwareBuffer_getNativeHandle(ahw));
            vk_append_struct(&structChainIter, &importCbInfo);
        }

        zx_handle_t vmo_handle = ZX_HANDLE_INVALID;

        if (importBufferCollection) {

#ifdef VK_USE_PLATFORM_FUCHSIA
            auto collection = reinterpret_cast<
                fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>*>(
                importBufferCollectionInfoPtr->collection);
            auto result = collection->WaitForBuffersAllocated();
            if (!result.ok() || result.Unwrap()->status != ZX_OK) {
                ALOGE("WaitForBuffersAllocated failed: %d %d", result.status(),
                      GET_STATUS_SAFE(result, status));
                _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(VK_ERROR_INITIALIZATION_FAILED);
            }
            fuchsia_sysmem::wire::BufferCollectionInfo2& info =
                result.Unwrap()->buffer_collection_info;
            uint32_t index = importBufferCollectionInfoPtr->index;
            if (info.buffer_count < index) {
                ALOGE("Invalid buffer index: %d %d", index);
                _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(VK_ERROR_INITIALIZATION_FAILED);
            }
            vmo_handle = info.buffers[index].vmo.release();
#endif

        }

        if (importVmo) {
            vmo_handle = importVmoInfoPtr->handle;
        }

#ifdef VK_USE_PLATFORM_FUCHSIA
        if (exportVmo) {
            bool hasDedicatedImage = dedicatedAllocInfoPtr &&
                (dedicatedAllocInfoPtr->image != VK_NULL_HANDLE);
            bool hasDedicatedBuffer =
                dedicatedAllocInfoPtr &&
                (dedicatedAllocInfoPtr->buffer != VK_NULL_HANDLE);

            if (hasDedicatedImage && hasDedicatedBuffer) {
                ALOGE(
                    "Invalid VkMemoryDedicatedAllocationInfo: At least one "
                    "of image and buffer must be VK_NULL_HANDLE.");
                return VK_ERROR_OUT_OF_DEVICE_MEMORY;
            }

            const VkImageCreateInfo* pImageCreateInfo = nullptr;

            VkBufferConstraintsInfoFUCHSIA bufferConstraintsInfo = {
                .sType =
                    VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA,
                .pNext = nullptr,
                .pBufferCreateInfo = nullptr,
                .requiredFormatFeatures = 0,
                .minCount = 1,
            };
            const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo =
                nullptr;

            if (hasDedicatedImage) {
                AutoLock lock(mLock);

                auto it = info_VkImage.find(dedicatedAllocInfoPtr->image);
                if (it == info_VkImage.end()) return VK_ERROR_INITIALIZATION_FAILED;
                const auto& imageInfo = it->second;

                pImageCreateInfo = &imageInfo.createInfo;
            }

            if (hasDedicatedBuffer) {
                AutoLock lock(mLock);

                auto it = info_VkBuffer.find(dedicatedAllocInfoPtr->buffer);
                if (it == info_VkBuffer.end())
                    return VK_ERROR_INITIALIZATION_FAILED;
                const auto& bufferInfo = it->second;

                bufferConstraintsInfo.pBufferCreateInfo =
                    &bufferInfo.createInfo;
                pBufferConstraintsInfo = &bufferConstraintsInfo;
            }

            hasDedicatedImage = hasDedicatedImage &&
                                getBufferCollectionConstraintsVulkanImageUsage(
                                    pImageCreateInfo);
            hasDedicatedBuffer =
                hasDedicatedBuffer &&
                getBufferCollectionConstraintsVulkanBufferUsage(
                    pBufferConstraintsInfo);

            if (hasDedicatedImage || hasDedicatedBuffer) {
                auto token_ends =
                    fidl::CreateEndpoints<::fuchsia_sysmem::BufferCollectionToken>();
                if (!token_ends.is_ok()) {
                    ALOGE("zx_channel_create failed: %d", token_ends.status_value());
                    abort();
                }

                {
                    auto result = mSysmemAllocator->AllocateSharedCollection(
                        std::move(token_ends->server));
                    if (!result.ok()) {
                        ALOGE("AllocateSharedCollection failed: %d",
                              result.status());
                        abort();
                    }
                }

                auto collection_ends =
                    fidl::CreateEndpoints<::fuchsia_sysmem::BufferCollection>();
                if (!collection_ends.is_ok()) {
                    ALOGE("zx_channel_create failed: %d", collection_ends.status_value());
                    abort();
                }

                {
                    auto result = mSysmemAllocator->BindSharedCollection(
                        std::move(token_ends->client), std::move(collection_ends->server));
                    if (!result.ok()) {
                        ALOGE("BindSharedCollection failed: %d",
                              result.status());
                        abort();
                    }
                }

                fidl::WireSyncClient<fuchsia_sysmem::BufferCollection> collection(
                    std::move(collection_ends->client));
                if (hasDedicatedImage) {
                    VkResult res = setBufferCollectionConstraints(
                        enc, device, &collection, pImageCreateInfo);
                    if (res == VK_ERROR_FORMAT_NOT_SUPPORTED) {
                      ALOGE("setBufferCollectionConstraints failed: format %u is not supported",
                            pImageCreateInfo->format);
                      return VK_ERROR_OUT_OF_DEVICE_MEMORY;
                    }
                    if (res != VK_SUCCESS) {
                        ALOGE("setBufferCollectionConstraints failed: %d", res);
                        abort();
                    }
                }

                if (hasDedicatedBuffer) {
                    VkResult res = setBufferCollectionBufferConstraints(
                        &collection, pBufferConstraintsInfo);
                    if (res != VK_SUCCESS) {
                        ALOGE("setBufferCollectionBufferConstraints failed: %d",
                              res);
                        abort();
                    }
                }

                {
                    auto result = collection.WaitForBuffersAllocated();
                    if (result.ok() && result.Unwrap()->status == ZX_OK) {
                        fuchsia_sysmem::wire::BufferCollectionInfo2& info =
                            result.Unwrap()->buffer_collection_info;
                        if (!info.buffer_count) {
                            ALOGE(
                                "WaitForBuffersAllocated returned "
                                "invalid count: %d",
                                info.buffer_count);
                            abort();
                        }
                        vmo_handle = info.buffers[0].vmo.release();
                    } else {
                        ALOGE("WaitForBuffersAllocated failed: %d %d",
                              result.status(), GET_STATUS_SAFE(result, status));
                        abort();
                    }
                }

                collection.Close();

                zx::vmo vmo_copy;
                zx_status_t status = zx_handle_duplicate(vmo_handle, ZX_RIGHT_SAME_RIGHTS,
                                                         vmo_copy.reset_and_get_address());
                if (status != ZX_OK) {
                    ALOGE("Failed to duplicate VMO: %d", status);
                    abort();
                }

                bool isHostVisible = isHostVisibleMemoryTypeIndexForGuest(
                    &mHostVisibleMemoryVirtInfo,
                    pAllocateInfo->memoryTypeIndex);

                // Only device-local images need to create color buffer; for
                // host-visible images, the color buffer is already created when
                // sysmem allocates memory.
                if (!isHostVisible) {
                    if (pImageCreateInfo) {
                        fuchsia_hardware_goldfish::wire::
                            ColorBufferFormatType format;
                        switch (pImageCreateInfo->format) {
                            case VK_FORMAT_B8G8R8A8_SINT:
                            case VK_FORMAT_B8G8R8A8_UNORM:
                            case VK_FORMAT_B8G8R8A8_SRGB:
                            case VK_FORMAT_B8G8R8A8_SNORM:
                            case VK_FORMAT_B8G8R8A8_SSCALED:
                            case VK_FORMAT_B8G8R8A8_USCALED:
                                format = fuchsia_hardware_goldfish::wire::
                                    ColorBufferFormatType::kBgra;
                                break;
                            case VK_FORMAT_R8G8B8A8_SINT:
                            case VK_FORMAT_R8G8B8A8_UNORM:
                            case VK_FORMAT_R8G8B8A8_SRGB:
                            case VK_FORMAT_R8G8B8A8_SNORM:
                            case VK_FORMAT_R8G8B8A8_SSCALED:
                            case VK_FORMAT_R8G8B8A8_USCALED:
                                format = fuchsia_hardware_goldfish::wire::
                                    ColorBufferFormatType::kRgba;
                                break;
                            case VK_FORMAT_R8_UNORM:
                            case VK_FORMAT_R8_UINT:
                            case VK_FORMAT_R8_USCALED:
                            case VK_FORMAT_R8_SNORM:
                            case VK_FORMAT_R8_SINT:
                            case VK_FORMAT_R8_SSCALED:
                            case VK_FORMAT_R8_SRGB:
                                format = fuchsia_hardware_goldfish::wire::
                                    ColorBufferFormatType::kLuminance;
                                break;
                            case VK_FORMAT_R8G8_UNORM:
                            case VK_FORMAT_R8G8_UINT:
                            case VK_FORMAT_R8G8_USCALED:
                            case VK_FORMAT_R8G8_SNORM:
                            case VK_FORMAT_R8G8_SINT:
                            case VK_FORMAT_R8G8_SSCALED:
                            case VK_FORMAT_R8G8_SRGB:
                                format = fuchsia_hardware_goldfish::wire::
                                    ColorBufferFormatType::kRg;
                                break;
                            default:
                                ALOGE("Unsupported format: %d",
                                      pImageCreateInfo->format);
                                abort();
                        }

                        fidl::FidlAllocator allocator;
                        fuchsia_hardware_goldfish::wire::CreateColorBuffer2Params createParams(
                            allocator);
                        createParams.set_width(allocator, pImageCreateInfo->extent.width)
                            .set_height(allocator, pImageCreateInfo->extent.height)
                            .set_format(allocator, format)
                            .set_memory_property(allocator,
                                fuchsia_hardware_goldfish::wire::kMemoryPropertyDeviceLocal);

                        auto result = mControlDevice->CreateColorBuffer2(
                            std::move(vmo_copy), std::move(createParams));
                        if (!result.ok() || result.Unwrap()->res != ZX_OK) {
                            if (result.ok() &&
                                result.Unwrap()->res == ZX_ERR_ALREADY_EXISTS) {
                                ALOGD(
                                    "CreateColorBuffer: color buffer already "
                                    "exists\n");
                            } else {
                                ALOGE("CreateColorBuffer failed: %d:%d",
                                      result.status(),
                                      GET_STATUS_SAFE(result, res));
                                abort();
                            }
                        }
                    }
                }

                if (pBufferConstraintsInfo) {
                    fidl::FidlAllocator allocator;
                    fuchsia_hardware_goldfish::wire::CreateBuffer2Params createParams(allocator);
                    createParams.set_size(allocator,
                            pBufferConstraintsInfo->pBufferCreateInfo->size)
                        .set_memory_property(allocator,
                            fuchsia_hardware_goldfish::wire::kMemoryPropertyDeviceLocal);

                    auto result =
                        mControlDevice->CreateBuffer2(std::move(vmo_copy), std::move(createParams));
                    if (!result.ok() || result.Unwrap()->result.is_err()) {
                        ALOGE("CreateBuffer2 failed: %d:%d", result.status(),
                              GET_STATUS_SAFE(result, result.err()));
                        abort();
                    }
                }
            }
        }

        if (vmo_handle != ZX_HANDLE_INVALID) {
            zx::vmo vmo_copy;
            zx_status_t status = zx_handle_duplicate(vmo_handle,
                                                     ZX_RIGHT_SAME_RIGHTS,
                                                     vmo_copy.reset_and_get_address());
            if (status != ZX_OK) {
                ALOGE("Failed to duplicate VMO: %d", status);
                abort();
            }
            zx_status_t status2 = ZX_OK;

            auto result = mControlDevice->GetBufferHandle(std::move(vmo_copy));
            if (!result.ok() || result.Unwrap()->res != ZX_OK) {
                ALOGE("GetBufferHandle failed: %d:%d", result.status(),
                      GET_STATUS_SAFE(result, res));
            } else {
                fuchsia_hardware_goldfish::wire::BufferHandleType
                    handle_type = result.Unwrap()->type;
                uint32_t buffer_handle = result.Unwrap()->id;

                if (handle_type == fuchsia_hardware_goldfish::wire::
                                       BufferHandleType::kBuffer) {
                    importBufferInfo.buffer = buffer_handle;
                    vk_append_struct(&structChainIter, &importBufferInfo);
                } else {
                    importCbInfo.colorBuffer = buffer_handle;
                    vk_append_struct(&structChainIter, &importCbInfo);
                }
            }
        }
#endif

        if (!isHostVisibleMemoryTypeIndexForGuest(
                &mHostVisibleMemoryVirtInfo,
                finalAllocInfo.memoryTypeIndex)) {
            input_result =
                enc->vkAllocateMemory(
                    device, &finalAllocInfo, pAllocator, pMemory, true /* do lock */);

            if (input_result != VK_SUCCESS) _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(input_result);

            VkDeviceSize allocationSize = finalAllocInfo.allocationSize;
            setDeviceMemoryInfo(
                device, *pMemory,
                finalAllocInfo.allocationSize,
                0, nullptr,
                finalAllocInfo.memoryTypeIndex,
                ahw,
                isImport,
                vmo_handle);

            _RETURN_SCUCCESS_WITH_DEVICE_MEMORY_REPORT;
        }

        // Device-local memory dealing is over. What follows:
        // host-visible memory.

        if (ahw) {
            ALOGE("%s: Host visible export/import allocation "
                  "of Android hardware buffers is not supported.",
                  __func__);
            abort();
        }

#ifdef VK_USE_PLATFORM_FUCHSIA
        if (vmo_handle != ZX_HANDLE_INVALID) {
            input_result = enc->vkAllocateMemory(device, &finalAllocInfo, pAllocator, pMemory, true /* do lock */);

            // Get VMO handle rights, and only use allowed rights to map the
            // host memory.
            zx_info_handle_basic handle_info;
            zx_status_t status = zx_object_get_info(vmo_handle, ZX_INFO_HANDLE_BASIC, &handle_info,
                                        sizeof(handle_info), nullptr, nullptr);
            if (status != ZX_OK) {
                ALOGE("%s: cannot get vmo object info: vmo = %u status: %d.", __func__, vmo_handle,
                      status);
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }

            zx_vm_option_t vm_permission = 0u;
            vm_permission |= (handle_info.rights & ZX_RIGHT_READ) ? ZX_VM_PERM_READ : 0;
            vm_permission |= (handle_info.rights & ZX_RIGHT_WRITE) ? ZX_VM_PERM_WRITE : 0;

            zx_paddr_t addr;
            status = zx_vmar_map(zx_vmar_root_self(), vm_permission, 0, vmo_handle, 0,
                finalAllocInfo.allocationSize, &addr);
            if (status != ZX_OK) {
                ALOGE("%s: cannot map vmar: status %d.", __func__, status);
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }

            D("host visible alloc (external): "
              "size 0x%llx host ptr %p mapped size 0x%llx",
              (unsigned long long)finalAllocInfo.allocationSize, mappedPtr,
              (unsigned long long)mappedSize);
            setDeviceMemoryInfo(device, *pMemory,
                finalAllocInfo.allocationSize, finalAllocInfo.allocationSize,
                reinterpret_cast<uint8_t*>(addr), finalAllocInfo.memoryTypeIndex,
                /*ahw=*/nullptr, isImport, vmo_handle);
            return VK_SUCCESS;
        }
#endif

        // Host visible memory, non external
        bool directMappingSupported = usingDirectMapping();
        if (!directMappingSupported) {
            input_result =
                enc->vkAllocateMemory(
                    device, &finalAllocInfo, pAllocator, pMemory, true /* do lock */);

            if (input_result != VK_SUCCESS) return input_result;

            VkDeviceSize mappedSize =
                getNonCoherentExtendedSize(device,
                    finalAllocInfo.allocationSize);
            uint8_t* mappedPtr = (uint8_t*)aligned_buf_alloc(4096, mappedSize);
            D("host visible alloc (non-direct): "
              "size 0x%llx host ptr %p mapped size 0x%llx",
              (unsigned long long)finalAllocInfo.allocationSize, mappedPtr,
              (unsigned long long)mappedSize);
            setDeviceMemoryInfo(
                device, *pMemory,
                finalAllocInfo.allocationSize,
                mappedSize, mappedPtr,
                finalAllocInfo.memoryTypeIndex);
            _RETURN_SCUCCESS_WITH_DEVICE_MEMORY_REPORT;
        }

        // Host visible memory with direct mapping via
        // VkImportPhysicalAddressGOOGLE
        // if (importPhysAddr) {
            // vkAllocateMemory(device, &finalAllocInfo, pAllocator, pMemory);
            //    host maps the host pointer to the guest physical address
            // TODO: the host side page offset of the
            // host pointer needs to be returned somehow.
        // }

        // Host visible memory with direct mapping
        AutoLock lock(mLock);

        auto it = info_VkDevice.find(device);
        if (it == info_VkDevice.end()) _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(VK_ERROR_DEVICE_LOST);
        auto& deviceInfo = it->second;

        auto& hostMemBlocksForTypeIndex =
            deviceInfo.hostMemBlocks[finalAllocInfo.memoryTypeIndex];

        HostMemBlockIndex blockIndex =
            getOrAllocateHostMemBlockLocked(
                hostMemBlocksForTypeIndex,
                &finalAllocInfo,
                enc,
                device,
                deviceInfo);

        if (blockIndex == (HostMemBlockIndex) INVALID_HOST_MEM_BLOCK) {
            _RETURN_FAILURE_WITH_DEVICE_MEMORY_REPORT(VK_ERROR_OUT_OF_HOST_MEMORY);
        }

        VkDeviceMemory_Info virtualMemInfo;

        subAllocHostMemory(
            &hostMemBlocksForTypeIndex[blockIndex],
            &finalAllocInfo,
            &virtualMemInfo.subAlloc);

        virtualMemInfo.allocationSize = virtualMemInfo.subAlloc.subAllocSize;
        virtualMemInfo.mappedSize = virtualMemInfo.subAlloc.subMappedSize;
        virtualMemInfo.mappedPtr = virtualMemInfo.subAlloc.mappedPtr;
        virtualMemInfo.memoryTypeIndex = finalAllocInfo.memoryTypeIndex;
        virtualMemInfo.directMapped = true;

        D("host visible alloc (direct, suballoc): "
          "size 0x%llx ptr %p mapped size 0x%llx",
          (unsigned long long)virtualMemInfo.allocationSize, virtualMemInfo.mappedPtr,
          (unsigned long long)virtualMemInfo.mappedSize);

        info_VkDeviceMemory[
            virtualMemInfo.subAlloc.subMemory] = virtualMemInfo;

        *pMemory = virtualMemInfo.subAlloc.subMemory;

        _RETURN_SCUCCESS_WITH_DEVICE_MEMORY_REPORT;
    }

    void on_vkFreeMemory(
        void* context,
        VkDevice device,
        VkDeviceMemory memory,
        const VkAllocationCallbacks* pAllocateInfo) {

        AutoLock lock(mLock);

        auto it = info_VkDeviceMemory.find(memory);
        if (it == info_VkDeviceMemory.end()) return;
        auto& info = it->second;
        uint64_t memoryObjectId = (uint64_t)(void*)memory;
        if (info.ahw) {
            memoryObjectId = getAHardwareBufferId(info.ahw);
        }
        emitDeviceMemoryReport(
            info_VkDevice[device],
            info.imported ? VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT
                          : VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT,
            memoryObjectId,
            0 /* size */,
            VK_OBJECT_TYPE_DEVICE_MEMORY,
            (uint64_t)(void*)memory
        );

#ifdef VK_USE_PLATFORM_FUCHSIA
        if (info.vmoHandle && info.mappedPtr) {
            zx_status_t status = zx_vmar_unmap(
                zx_vmar_root_self(), reinterpret_cast<zx_paddr_t>(info.mappedPtr), info.mappedSize);
            if (status != ZX_OK) {
                ALOGE("%s: Cannot unmap mappedPtr: status %d", status);
            }
            info.mappedPtr = nullptr;
        }
#endif

        if (!info.directMapped) {
            lock.unlock();
            VkEncoder* enc = (VkEncoder*)context;
            enc->vkFreeMemory(device, memory, pAllocateInfo, true /* do lock */);
            return;
        }

        VkDeviceMemory baseMemory = info.subAlloc.baseMemory;
        uint32_t memoryTypeIndex = info.subAlloc.memoryTypeIndex;
        bool isDeviceAddressMemoryAllocation = info.subAlloc.isDeviceAddressMemoryAllocation;
        // If this was a device address memory allocation,
        // free it right away.
        // TODO: Retest with eagerly freeing other kinds of host visible
        // allocs as well
        if (subFreeHostMemory(&info.subAlloc) && isDeviceAddressMemoryAllocation) {
            ALOGV("%s: Last free for this device-address block, "
                  "free on host and clear block contents\n", __func__);
            ALOGV("%s: baseMem 0x%llx this mem 0x%llx\n", __func__,
                    (unsigned long long)baseMemory,
                    (unsigned long long)memory);
            VkEncoder* enc = (VkEncoder*)context;
            bool freeMemorySyncSupported =
                mFeatureInfo->hasVulkanFreeMemorySync;

            auto it = info_VkDevice.find(device);
            if (it == info_VkDevice.end()) {
                ALOGE("%s: Last free: could not find device\n", __func__);
                return;
            }

            auto& deviceInfo = it->second;

            auto& hostMemBlocksForTypeIndex =
                deviceInfo.hostMemBlocks[memoryTypeIndex];

            size_t indexToRemove = 0;
            bool found = false;
            for (const auto& allocInfo : hostMemBlocksForTypeIndex) {
                if (baseMemory == allocInfo.memory) {
                    found = true;
                    break;
                }
                ++indexToRemove;
            }

            if (!found) {
                ALOGE("%s: Last free: could not find original block\n", __func__);
                return;
            }

            ALOGV("%s: Destroying host mem alloc block at index %zu\n", __func__, indexToRemove);

            destroyHostMemAlloc(
                freeMemorySyncSupported,
                enc, device,
                hostMemBlocksForTypeIndex.data() + indexToRemove);

            ALOGV("%s: Destroying host mem alloc block at index %zu (done)\n", __func__, indexToRemove);

            hostMemBlocksForTypeIndex.erase(hostMemBlocksForTypeIndex.begin() + indexToRemove);
        }
    }

    VkResult on_vkMapMemory(
        void*,
        VkResult host_result,
        VkDevice,
        VkDeviceMemory memory,
        VkDeviceSize offset,
        VkDeviceSize size,
        VkMemoryMapFlags,
        void** ppData) {

        if (host_result != VK_SUCCESS) {
            ALOGE("%s: Host failed to map\n", __func__);
            return host_result;
        }

        AutoLock lock(mLock);

        auto it = info_VkDeviceMemory.find(memory);
        if (it == info_VkDeviceMemory.end()) {
            ALOGE("%s: Could not find this device memory\n", __func__);
            return VK_ERROR_MEMORY_MAP_FAILED;
        }

        auto& info = it->second;

        if (!info.mappedPtr) {
            ALOGE("%s: mappedPtr null\n", __func__);
            return VK_ERROR_MEMORY_MAP_FAILED;
        }

        if (size != VK_WHOLE_SIZE &&
            (info.mappedPtr + offset + size > info.mappedPtr + info.allocationSize)) {
            ALOGE("%s: size is too big. alloc size 0x%llx while we wanted offset 0x%llx size 0x%llx total 0x%llx\n", __func__,
                    (unsigned long long)info.allocationSize,
                    (unsigned long long)offset,
                    (unsigned long long)size,
                    (unsigned long long)offset);
            return VK_ERROR_MEMORY_MAP_FAILED;
        }

        *ppData = info.mappedPtr + offset;

        return host_result;
    }

    void on_vkUnmapMemory(
        void*,
        VkDevice,
        VkDeviceMemory) {
        // no-op
    }

    uint32_t transformNonExternalResourceMemoryTypeBitsForGuest(
        uint32_t hostBits) {
        uint32_t res = 0;
        for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; ++i) {
            if (hostBits & (1 << i)) {
                res |= (1 << i);
            }
        }
        return res;
    }

    uint32_t transformExternalResourceMemoryTypeBitsForGuest(
        uint32_t normalBits) {
        uint32_t res = 0;
        for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; ++i) {
            bool shouldAcceptMemoryIndex = normalBits & (1 << i);
#ifndef VK_USE_PLATFORM_FUCHSIA
            shouldAcceptMemoryIndex &= !isHostVisibleMemoryTypeIndexForGuest(
                &mHostVisibleMemoryVirtInfo, i);
#endif  // VK_USE_PLATFORM_FUCHSIA

            if (shouldAcceptMemoryIndex) {
                res |= (1 << i);
            }
        }
        return res;
    }

    void transformNonExternalResourceMemoryRequirementsForGuest(
        VkMemoryRequirements* reqs) {
        reqs->memoryTypeBits =
            transformNonExternalResourceMemoryTypeBitsForGuest(
                reqs->memoryTypeBits);
    }

    void transformExternalResourceMemoryRequirementsForGuest(
        VkMemoryRequirements* reqs) {
        reqs->memoryTypeBits =
            transformExternalResourceMemoryTypeBitsForGuest(
                reqs->memoryTypeBits);
    }

    void transformExternalResourceMemoryDedicatedRequirementsForGuest(
        VkMemoryDedicatedRequirements* dedicatedReqs) {
        dedicatedReqs->prefersDedicatedAllocation = VK_TRUE;
        dedicatedReqs->requiresDedicatedAllocation = VK_TRUE;
    }

    void transformImageMemoryRequirementsForGuestLocked(
        VkImage image,
        VkMemoryRequirements* reqs) {

        auto it = info_VkImage.find(image);
        if (it == info_VkImage.end()) return;

        auto& info = it->second;

        if (!info.external ||
            !info.externalCreateInfo.handleTypes) {
            transformNonExternalResourceMemoryRequirementsForGuest(reqs);
        } else {
            transformExternalResourceMemoryRequirementsForGuest(reqs);
        }
        setMemoryRequirementsForSysmemBackedImage(image, reqs);
    }

    void transformBufferMemoryRequirementsForGuestLocked(
        VkBuffer buffer,
        VkMemoryRequirements* reqs) {

        auto it = info_VkBuffer.find(buffer);
        if (it == info_VkBuffer.end()) return;

        auto& info = it->second;

        if (!info.external ||
            !info.externalCreateInfo.handleTypes) {
            transformNonExternalResourceMemoryRequirementsForGuest(reqs);
            return;
        }

        transformExternalResourceMemoryRequirementsForGuest(reqs);
    }

    void transformImageMemoryRequirements2ForGuest(
        VkImage image,
        VkMemoryRequirements2* reqs2) {

        AutoLock lock(mLock);

        auto it = info_VkImage.find(image);
        if (it == info_VkImage.end()) return;

        auto& info = it->second;

        if (!info.external ||
            !info.externalCreateInfo.handleTypes) {
            transformNonExternalResourceMemoryRequirementsForGuest(
                &reqs2->memoryRequirements);
            setMemoryRequirementsForSysmemBackedImage(image, &reqs2->memoryRequirements);
            return;
        }

        transformExternalResourceMemoryRequirementsForGuest(&reqs2->memoryRequirements);

        setMemoryRequirementsForSysmemBackedImage(image, &reqs2->memoryRequirements);

        VkMemoryDedicatedRequirements* dedicatedReqs =
            vk_find_struct<VkMemoryDedicatedRequirements>(reqs2);

        if (!dedicatedReqs) return;

        transformExternalResourceMemoryDedicatedRequirementsForGuest(
            dedicatedReqs);
    }

    void transformBufferMemoryRequirements2ForGuest(
        VkBuffer buffer,
        VkMemoryRequirements2* reqs2) {

        AutoLock lock(mLock);

        auto it = info_VkBuffer.find(buffer);
        if (it == info_VkBuffer.end()) return;

        auto& info = it->second;

        if (!info.external ||
            !info.externalCreateInfo.handleTypes) {
            transformNonExternalResourceMemoryRequirementsForGuest(
                &reqs2->memoryRequirements);
            return;
        }

        transformExternalResourceMemoryRequirementsForGuest(&reqs2->memoryRequirements);

        VkMemoryDedicatedRequirements* dedicatedReqs =
            vk_find_struct<VkMemoryDedicatedRequirements>(reqs2);

        if (!dedicatedReqs) return;

        transformExternalResourceMemoryDedicatedRequirementsForGuest(
            dedicatedReqs);
    }

    VkResult on_vkCreateImage(
        void* context, VkResult,
        VkDevice device, const VkImageCreateInfo *pCreateInfo,
        const VkAllocationCallbacks *pAllocator,
        VkImage *pImage) {
        VkEncoder* enc = (VkEncoder*)context;

        VkImageCreateInfo localCreateInfo = vk_make_orphan_copy(*pCreateInfo);
        vk_struct_chain_iterator structChainIter = vk_make_chain_iterator(&localCreateInfo);
        VkExternalMemoryImageCreateInfo localExtImgCi;

        const VkExternalMemoryImageCreateInfo* extImgCiPtr =
            vk_find_struct<VkExternalMemoryImageCreateInfo>(pCreateInfo);
        if (extImgCiPtr) {
            localExtImgCi = vk_make_orphan_copy(*extImgCiPtr);
            vk_append_struct(&structChainIter, &localExtImgCi);
        }

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        VkNativeBufferANDROID localAnb;
        const VkNativeBufferANDROID* anbInfoPtr =
            vk_find_struct<VkNativeBufferANDROID>(pCreateInfo);
        if (anbInfoPtr) {
            localAnb = vk_make_orphan_copy(*anbInfoPtr);
            vk_append_struct(&structChainIter, &localAnb);
        }

        VkExternalFormatANDROID localExtFormatAndroid;
        const VkExternalFormatANDROID* extFormatAndroidPtr =
            vk_find_struct<VkExternalFormatANDROID>(pCreateInfo);
        if (extFormatAndroidPtr) {
            localExtFormatAndroid = vk_make_orphan_copy(*extFormatAndroidPtr);

            // Do not append external format android;
            // instead, replace the local image localCreateInfo format
            // with the corresponding Vulkan format
            if (extFormatAndroidPtr->externalFormat) {
                localCreateInfo.format =
                    vk_format_from_android(extFormatAndroidPtr->externalFormat);
                if (localCreateInfo.format == VK_FORMAT_UNDEFINED)
                    return VK_ERROR_VALIDATION_FAILED_EXT;
            }
        }
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
        const VkBufferCollectionImageCreateInfoFUCHSIA* extBufferCollectionPtr =
            vk_find_struct<VkBufferCollectionImageCreateInfoFUCHSIA>(pCreateInfo);
        bool isSysmemBackedMemory = false;

        if (extImgCiPtr &&
            ((extImgCiPtr->handleTypes &
                VK_EXTERNAL_MEMORY_HANDLE_TYPE_TEMP_ZIRCON_VMO_BIT_FUCHSIA) ||
            (extImgCiPtr->handleTypes &
                VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA))) {
            isSysmemBackedMemory = true;
        }

        if (extBufferCollectionPtr) {
            auto collection = reinterpret_cast<
                fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>*>(
                extBufferCollectionPtr->collection);
            uint32_t index = extBufferCollectionPtr->index;
            zx::vmo vmo;

            fuchsia_sysmem::wire::BufferCollectionInfo2 info;

            auto result = collection->WaitForBuffersAllocated();
            if (result.ok() && result.Unwrap()->status == ZX_OK) {
                info = std::move(result.Unwrap()->buffer_collection_info);
                if (index < info.buffer_count && info.settings.has_image_format_constraints) {
                    vmo = std::move(info.buffers[index].vmo);
                }
            } else {
                ALOGE("WaitForBuffersAllocated failed: %d %d", result.status(),
                      GET_STATUS_SAFE(result, status));
            }

            if (vmo.is_valid()) {
                zx::vmo vmo_dup;
                if (zx_status_t status = vmo.duplicate(ZX_RIGHT_SAME_RIGHTS, &vmo_dup);
                    status != ZX_OK) {
                    ALOGE("%s: zx_vmo_duplicate failed: %d", __func__, status);
                    abort();
                }

                auto buffer_handle_result = mControlDevice->GetBufferHandle(std::move(vmo_dup));
                if (!buffer_handle_result.ok()) {
                    ALOGE("%s: GetBufferHandle FIDL error: %d", __func__,
                          buffer_handle_result.status());
                    abort();
                }
                if (buffer_handle_result.value().res == ZX_OK) {
                    // Buffer handle already exists.
                    // If it is a ColorBuffer, no-op; Otherwise return error.
                    if (buffer_handle_result.value().type !=
                        fuchsia_hardware_goldfish::wire::BufferHandleType::kColorBuffer) {
                        ALOGE("%s: BufferHandle %u is not a ColorBuffer", __func__,
                              buffer_handle_result.value().id);
                        return VK_ERROR_OUT_OF_HOST_MEMORY;
                    }
                } else if (buffer_handle_result.value().res == ZX_ERR_NOT_FOUND) {
                    // Buffer handle not found. Create ColorBuffer based on buffer settings.
                    auto format =
                        info.settings.image_format_constraints.pixel_format.type ==
                                fuchsia_sysmem::wire::PixelFormatType::kR8G8B8A8
                            ? fuchsia_hardware_goldfish::wire::ColorBufferFormatType::kRgba
                            : fuchsia_hardware_goldfish::wire::ColorBufferFormatType::kBgra;

                    uint32_t memory_property =
                        info.settings.buffer_settings.heap ==
                                fuchsia_sysmem::wire::HeapType::kGoldfishDeviceLocal
                            ? fuchsia_hardware_goldfish::wire::kMemoryPropertyDeviceLocal
                            : fuchsia_hardware_goldfish::wire::kMemoryPropertyHostVisible;

                    fidl::FidlAllocator allocator;
                    fuchsia_hardware_goldfish::wire::CreateColorBuffer2Params createParams(
                        allocator);
                    createParams.set_width(allocator,
                            info.settings.image_format_constraints.min_coded_width)
                        .set_height(allocator,
                            info.settings.image_format_constraints.min_coded_height)
                        .set_format(allocator, format)
                        .set_memory_property(allocator, memory_property);

                    auto result =
                        mControlDevice->CreateColorBuffer2(std::move(vmo), std::move(createParams));
                    if (!result.ok() || result.Unwrap()->res != ZX_OK) {
                        ALOGE("CreateColorBuffer failed: %d:%d", result.status(),
                              GET_STATUS_SAFE(result, res));
                    }
                }

                if (info.settings.buffer_settings.heap ==
                    fuchsia_sysmem::wire::HeapType::kGoldfishHostVisible) {
                    ALOGD(
                        "%s: Image uses host visible memory heap; set tiling "
                        "to linear to match host ImageCreateInfo",
                        __func__);
                    localCreateInfo.tiling = VK_IMAGE_TILING_LINEAR;
                }
            }
            isSysmemBackedMemory = true;
        }

        if (isSysmemBackedMemory) {
            localCreateInfo.flags |= VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
        }
#endif

        VkResult res;
        VkMemoryRequirements memReqs;

        if (supportsCreateResourcesWithRequirements()) {
            res = enc->vkCreateImageWithRequirementsGOOGLE(device, &localCreateInfo, pAllocator, pImage, &memReqs, true /* do lock */);
        } else {
            res = enc->vkCreateImage(device, &localCreateInfo, pAllocator, pImage, true /* do lock */);
        }

        if (res != VK_SUCCESS) return res;

        AutoLock lock(mLock);

        auto it = info_VkImage.find(*pImage);
        if (it == info_VkImage.end()) return VK_ERROR_INITIALIZATION_FAILED;

        auto& info = it->second;

        info.device = device;
        info.createInfo = *pCreateInfo;
        info.createInfo.pNext = nullptr;

        if (supportsCreateResourcesWithRequirements()) {
            info.baseRequirementsKnown = true;
        }

        if (extImgCiPtr) {
            info.external = true;
            info.externalCreateInfo = *extImgCiPtr;
        }

#ifdef VK_USE_PLATFORM_FUCHSIA
        if (isSysmemBackedMemory) {
            info.isSysmemBackedMemory = true;
        }
#endif

        if (info.baseRequirementsKnown) {
            transformImageMemoryRequirementsForGuestLocked(*pImage, &memReqs);
            info.baseRequirements = memReqs;
        }
        return res;
    }

    VkResult on_vkCreateSamplerYcbcrConversion(
        void* context, VkResult,
        VkDevice device,
        const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSamplerYcbcrConversion* pYcbcrConversion) {

        VkSamplerYcbcrConversionCreateInfo localCreateInfo = vk_make_orphan_copy(*pCreateInfo);

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        const VkExternalFormatANDROID* extFormatAndroidPtr =
            vk_find_struct<VkExternalFormatANDROID>(pCreateInfo);
        if (extFormatAndroidPtr) {
            if (extFormatAndroidPtr->externalFormat == AHARDWAREBUFFER_FORMAT_R5G6B5_UNORM) {
                // We don't support external formats on host and it causes RGB565
                // to fail in CtsGraphicsTestCases android.graphics.cts.BasicVulkanGpuTest
                // when passed as an external format.
                // We may consider doing this for all external formats.
                // See b/134771579.
                *pYcbcrConversion = VK_YCBCR_CONVERSION_DO_NOTHING;
                return VK_SUCCESS;
            } else if (extFormatAndroidPtr->externalFormat) {
                localCreateInfo.format =
                    vk_format_from_android(extFormatAndroidPtr->externalFormat);
            }
        }
#endif

        VkEncoder* enc = (VkEncoder*)context;
        VkResult res = enc->vkCreateSamplerYcbcrConversion(
            device, &localCreateInfo, pAllocator, pYcbcrConversion, true /* do lock */);

        if (*pYcbcrConversion == VK_YCBCR_CONVERSION_DO_NOTHING) {
            ALOGE("FATAL: vkCreateSamplerYcbcrConversion returned a reserved value (VK_YCBCR_CONVERSION_DO_NOTHING)");
            abort();
        }
        return res;
    }

    void on_vkDestroySamplerYcbcrConversion(
        void* context,
        VkDevice device,
        VkSamplerYcbcrConversion ycbcrConversion,
        const VkAllocationCallbacks* pAllocator) {
        VkEncoder* enc = (VkEncoder*)context;
        if (ycbcrConversion != VK_YCBCR_CONVERSION_DO_NOTHING) {
            enc->vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator, true /* do lock */);
        }
    }

    VkResult on_vkCreateSamplerYcbcrConversionKHR(
        void* context, VkResult,
        VkDevice device,
        const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSamplerYcbcrConversion* pYcbcrConversion) {

        VkSamplerYcbcrConversionCreateInfo localCreateInfo = vk_make_orphan_copy(*pCreateInfo);

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        const VkExternalFormatANDROID* extFormatAndroidPtr =
            vk_find_struct<VkExternalFormatANDROID>(pCreateInfo);
        if (extFormatAndroidPtr) {
            if (extFormatAndroidPtr->externalFormat == AHARDWAREBUFFER_FORMAT_R5G6B5_UNORM) {
                // We don't support external formats on host and it causes RGB565
                // to fail in CtsGraphicsTestCases android.graphics.cts.BasicVulkanGpuTest
                // when passed as an external format.
                // We may consider doing this for all external formats.
                // See b/134771579.
                *pYcbcrConversion = VK_YCBCR_CONVERSION_DO_NOTHING;
                return VK_SUCCESS;
            } else if (extFormatAndroidPtr->externalFormat) {
                localCreateInfo.format =
                    vk_format_from_android(extFormatAndroidPtr->externalFormat);
            }
        }
#endif

        VkEncoder* enc = (VkEncoder*)context;
        VkResult res = enc->vkCreateSamplerYcbcrConversionKHR(
            device, &localCreateInfo, pAllocator, pYcbcrConversion, true /* do lock */);

        if (*pYcbcrConversion == VK_YCBCR_CONVERSION_DO_NOTHING) {
            ALOGE("FATAL: vkCreateSamplerYcbcrConversionKHR returned a reserved value (VK_YCBCR_CONVERSION_DO_NOTHING)");
            abort();
        }
        return res;
    }

    void on_vkDestroySamplerYcbcrConversionKHR(
        void* context,
        VkDevice device,
        VkSamplerYcbcrConversion ycbcrConversion,
        const VkAllocationCallbacks* pAllocator) {
        VkEncoder* enc = (VkEncoder*)context;
        if (ycbcrConversion != VK_YCBCR_CONVERSION_DO_NOTHING) {
            enc->vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator, true /* do lock */);
        }
    }

    VkResult on_vkCreateSampler(
        void* context, VkResult,
        VkDevice device,
        const VkSamplerCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSampler* pSampler) {

        VkSamplerCreateInfo localCreateInfo = vk_make_orphan_copy(*pCreateInfo);
        vk_struct_chain_iterator structChainIter = vk_make_chain_iterator(&localCreateInfo);

#if defined(VK_USE_PLATFORM_ANDROID_KHR) || defined(VK_USE_PLATFORM_FUCHSIA)
        VkSamplerYcbcrConversionInfo localVkSamplerYcbcrConversionInfo;
        const VkSamplerYcbcrConversionInfo* samplerYcbcrConversionInfo =
            vk_find_struct<VkSamplerYcbcrConversionInfo>(pCreateInfo);
        if (samplerYcbcrConversionInfo) {
            if (samplerYcbcrConversionInfo->conversion != VK_YCBCR_CONVERSION_DO_NOTHING) {
                localVkSamplerYcbcrConversionInfo = vk_make_orphan_copy(*samplerYcbcrConversionInfo);
                vk_append_struct(&structChainIter, &localVkSamplerYcbcrConversionInfo);
            }
        }
#endif

        VkEncoder* enc = (VkEncoder*)context;
        return enc->vkCreateSampler(device, &localCreateInfo, pAllocator, pSampler, true /* do lock */);
    }

    void on_vkGetPhysicalDeviceExternalFenceProperties(
        void* context,
        VkPhysicalDevice physicalDevice,
        const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
        VkExternalFenceProperties* pExternalFenceProperties) {

        (void)context;
        (void)physicalDevice;

        pExternalFenceProperties->exportFromImportedHandleTypes = 0;
        pExternalFenceProperties->compatibleHandleTypes = 0;
        pExternalFenceProperties->externalFenceFeatures = 0;

        bool syncFd =
            pExternalFenceInfo->handleType &
            VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT;

        if (!syncFd) {
            return;
        }

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        pExternalFenceProperties->exportFromImportedHandleTypes =
            VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT;
        pExternalFenceProperties->compatibleHandleTypes =
            VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT;
        pExternalFenceProperties->externalFenceFeatures =
            VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT |
            VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT;

        ALOGD("%s: asked for sync fd, set the features\n", __func__);
#endif
    }

    VkResult on_vkCreateFence(
        void* context,
        VkResult input_result,
        VkDevice device,
        const VkFenceCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator, VkFence* pFence) {

        VkEncoder* enc = (VkEncoder*)context;
        VkFenceCreateInfo finalCreateInfo = *pCreateInfo;

        const VkExportFenceCreateInfo* exportFenceInfoPtr =
            vk_find_struct<VkExportFenceCreateInfo>(pCreateInfo);

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        bool exportSyncFd =
            exportFenceInfoPtr &&
            (exportFenceInfoPtr->handleTypes &
             VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT);

        if (exportSyncFd) {
            ALOGV("%s: exporting sync fd, do not send pNext to host\n", __func__);
            finalCreateInfo.pNext = nullptr;
        }
#endif

        input_result = enc->vkCreateFence(
            device, &finalCreateInfo, pAllocator, pFence, true /* do lock */);

        if (input_result != VK_SUCCESS) return input_result;

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        if (exportSyncFd) {
            if (!mFeatureInfo->hasVirtioGpuNativeSync) {
                ALOGV("%s: ensure sync device\n", __func__);
                ensureSyncDeviceFd();
            }

            ALOGV("%s: getting fence info\n", __func__);
            AutoLock lock(mLock);
            auto it = info_VkFence.find(*pFence);

            if (it == info_VkFence.end())
                return VK_ERROR_INITIALIZATION_FAILED;

            auto& info = it->second;

            info.external = true;
            info.exportFenceCreateInfo = *exportFenceInfoPtr;
            ALOGV("%s: info set (fence still -1). fence: %p\n", __func__, (void*)(*pFence));
            // syncFd is still -1 because we expect user to explicitly
            // export it via vkGetFenceFdKHR
        }
#endif

        return input_result;
    }

    void on_vkDestroyFence(
        void* context,
        VkDevice device,
        VkFence fence,
        const VkAllocationCallbacks* pAllocator) {
        VkEncoder* enc = (VkEncoder*)context;
        enc->vkDestroyFence(device, fence, pAllocator, true /* do lock */);
    }

    VkResult on_vkResetFences(
        void* context,
        VkResult,
        VkDevice device,
        uint32_t fenceCount,
        const VkFence* pFences) {

        VkEncoder* enc = (VkEncoder*)context;
        VkResult res = enc->vkResetFences(device, fenceCount, pFences, true /* do lock */);

        if (res != VK_SUCCESS) return res;

        if (!fenceCount) return res;

        // Permanence: temporary
        // on fence reset, close the fence fd
        // and act like we need to GetFenceFdKHR/ImportFenceFdKHR again
        AutoLock lock(mLock);
        for (uint32_t i = 0; i < fenceCount; ++i) {
            VkFence fence = pFences[i];
            auto it = info_VkFence.find(fence);
            auto& info = it->second;
            if (!info.external) continue;

#ifdef VK_USE_PLATFORM_ANDROID_KHR
            if (info.syncFd >= 0) {
                ALOGV("%s: resetting fence. make fd -1\n", __func__);
                goldfish_sync_signal(info.syncFd);
                close(info.syncFd);
                info.syncFd = -1;
            }
#endif
        }

        return res;
    }

    VkResult on_vkImportFenceFdKHR(
        void* context,
        VkResult,
        VkDevice device,
        const VkImportFenceFdInfoKHR* pImportFenceFdInfo) {

        (void)context;
        (void)device;
        (void)pImportFenceFdInfo;

        // Transference: copy
        // meaning dup() the incoming fd

        VkEncoder* enc = (VkEncoder*)context;

        bool hasFence = pImportFenceFdInfo->fence != VK_NULL_HANDLE;

        if (!hasFence) return VK_ERROR_OUT_OF_HOST_MEMORY;

#ifdef VK_USE_PLATFORM_ANDROID_KHR

        bool syncFdImport =
            pImportFenceFdInfo->handleType & VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT;

        if (!syncFdImport) {
            ALOGV("%s: VK_ERROR_OUT_OF_HOST_MEMORY: no sync fd import\n", __func__);
            return VK_ERROR_OUT_OF_HOST_MEMORY;
        }

        AutoLock lock(mLock);
        auto it = info_VkFence.find(pImportFenceFdInfo->fence);
        if (it == info_VkFence.end()) {
            ALOGV("%s: VK_ERROR_OUT_OF_HOST_MEMORY: no fence info\n", __func__);
            return VK_ERROR_OUT_OF_HOST_MEMORY;
        }

        auto& info = it->second;

        if (info.syncFd >= 0) {
            ALOGV("%s: previous sync fd exists, close it\n", __func__);
            goldfish_sync_signal(info.syncFd);
            close(info.syncFd);
        }

        if (pImportFenceFdInfo->fd < 0) {
            ALOGV("%s: import -1, set to -1 and exit\n", __func__);
            info.syncFd = -1;
        } else {
            ALOGV("%s: import actual fd, dup and close()\n", __func__);
            info.syncFd = dup(pImportFenceFdInfo->fd);
            close(pImportFenceFdInfo->fd);
        }
        return VK_SUCCESS;
#else
        return VK_ERROR_OUT_OF_HOST_MEMORY;
#endif
    }

    VkResult on_vkGetFenceFdKHR(
        void* context,
        VkResult,
        VkDevice device,
        const VkFenceGetFdInfoKHR* pGetFdInfo,
        int* pFd) {

        // export operation.
        // first check if fence is signaled
        // then if so, return -1
        // else, queue work

        VkEncoder* enc = (VkEncoder*)context;

        bool hasFence = pGetFdInfo->fence != VK_NULL_HANDLE;

        if (!hasFence) {
            ALOGV("%s: VK_ERROR_OUT_OF_HOST_MEMORY: no fence\n", __func__);
            return VK_ERROR_OUT_OF_HOST_MEMORY;
        }

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        bool syncFdExport =
            pGetFdInfo->handleType & VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT;

        if (!syncFdExport) {
            ALOGV("%s: VK_ERROR_OUT_OF_HOST_MEMORY: no sync fd fence\n", __func__);
            return VK_ERROR_OUT_OF_HOST_MEMORY;
        }

        VkResult currentFenceStatus = enc->vkGetFenceStatus(device, pGetFdInfo->fence, true /* do lock */);

        if (VK_SUCCESS == currentFenceStatus) { // Fence already signaled
            ALOGV("%s: VK_SUCCESS: already signaled\n", __func__);
            *pFd = -1;
            return VK_SUCCESS;
        }

        if (VK_ERROR_DEVICE_LOST == currentFenceStatus) { // Other error
            ALOGV("%s: VK_ERROR_DEVICE_LOST: Other error\n", __func__);
            *pFd = -1;
            return VK_ERROR_DEVICE_LOST;
        }

        if (VK_NOT_READY == currentFenceStatus) { // Fence unsignaled; create fd here
            AutoLock lock(mLock);

            auto it = info_VkFence.find(pGetFdInfo->fence);
            if (it == info_VkFence.end()) {
                ALOGV("%s: VK_ERROR_OUT_OF_HOST_MEMORY: no fence info\n", __func__);
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }

            auto& info = it->second;

            bool syncFdCreated =
                info.external &&
                (info.exportFenceCreateInfo.handleTypes &
                 VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT);

            if (!syncFdCreated) {
                ALOGV("%s: VK_ERROR_OUT_OF_HOST_MEMORY: no sync fd created\n", __func__);
                return VK_ERROR_OUT_OF_HOST_MEMORY;
            }

            if (mFeatureInfo->hasVirtioGpuNativeSync) {
#if !defined(HOST_BUILD) && defined(VK_USE_PLATFORM_ANDROID_KHR)
                uint64_t hostFenceHandle = get_host_u64_VkFence(pGetFdInfo->fence);
                uint32_t hostFenceHandleLo = (uint32_t)hostFenceHandle;
                uint32_t hostFenceHandleHi = (uint32_t)(hostFenceHandle >> 32);

                uint64_t hostDeviceHandle = get_host_u64_VkDevice(device);
                uint32_t hostDeviceHandleLo = (uint32_t)hostDeviceHandle;
                uint32_t hostDeviceHandleHi = (uint32_t)(hostFenceHandle >> 32);

                #define VIRTIO_GPU_NATIVE_SYNC_VULKAN_CREATE_EXPORT_FD 0xa000

                uint32_t cmdDwords[5] = {
                    VIRTIO_GPU_NATIVE_SYNC_VULKAN_CREATE_EXPORT_FD,
                    hostDeviceHandleLo,
                    hostDeviceHandleHi,
                    hostFenceHandleLo,
                    hostFenceHandleHi,
                };

                drm_virtgpu_execbuffer execbuffer = {
                    .flags = VIRTGPU_EXECBUF_FENCE_FD_OUT,
                    .size = 5 * sizeof(uint32_t),
                    .command = (uint64_t)(cmdDwords),
                    .bo_handles = 0,
                    .num_bo_handles = 0,
                    .fence_fd = -1,
                };

                int res = drmIoctl(mRendernodeFd, DRM_IOCTL_VIRTGPU_EXECBUFFER, &execbuffer);
                if (res) {
                    ALOGE("%s: Failed to virtgpu execbuffer: sterror: %s errno: %d\n", __func__,
                            strerror(errno), errno);
                    abort();
                }

                *pFd = execbuffer.fence_fd;
#endif
            } else {
                goldfish_sync_queue_work(
                    mSyncDeviceFd,
                    get_host_u64_VkFence(pGetFdInfo->fence) /* the handle */,
                    GOLDFISH_SYNC_VULKAN_SEMAPHORE_SYNC /* thread handle (doubling as type field) */,
                    pFd);
            }

            // relinquish ownership
            info.syncFd = -1;
            ALOGV("%s: got fd: %d\n", __func__, *pFd);
            return VK_SUCCESS;
        }
        return VK_ERROR_DEVICE_LOST;
#else
        return VK_ERROR_OUT_OF_HOST_MEMORY;
#endif
    }

    VkResult on_vkWaitForFences(
        void* context,
        VkResult,
        VkDevice device,
        uint32_t fenceCount,
        const VkFence* pFences,
        VkBool32 waitAll,
        uint64_t timeout) {

        VkEncoder* enc = (VkEncoder*)context;

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        std::vector<VkFence> fencesExternal;
        std::vector<int> fencesExternalWaitFds;
        std::vector<VkFence> fencesNonExternal;

        AutoLock lock(mLock);

        for (uint32_t i = 0; i < fenceCount; ++i) {
            auto it = info_VkFence.find(pFences[i]);
            if (it == info_VkFence.end()) continue;
            const auto& info = it->second;
            if (info.syncFd >= 0) {
                fencesExternal.push_back(pFences[i]);
                fencesExternalWaitFds.push_back(info.syncFd);
            } else {
                fencesNonExternal.push_back(pFences[i]);
            }
        }

        lock.unlock();

        if (fencesExternal.empty()) {
            // No need for work pool, just wait with host driver.
            return enc->vkWaitForFences(
                device, fenceCount, pFences, waitAll, timeout, true /* do lock */);
        } else {
            // Depending on wait any or wait all,
            // schedule a wait group with waitAny/waitAll
            std::vector<WorkPool::Task> tasks;

            ALOGV("%s: scheduling ext waits\n", __func__);

            for (auto fd : fencesExternalWaitFds) {
                ALOGV("%s: wait on %d\n", __func__, fd);
                tasks.push_back([fd] {
                    sync_wait(fd, 3000);
                    ALOGV("done waiting on fd %d\n", fd);
                });
            }

            if (!fencesNonExternal.empty()) {
                tasks.push_back([this,
                                 fencesNonExternal /* copy of vector */,
                                 device, waitAll, timeout] {
                    auto hostConn = ResourceTracker::threadingCallbacks.hostConnectionGetFunc();
                    auto vkEncoder = ResourceTracker::threadingCallbacks.vkEncoderGetFunc(hostConn);
                    ALOGV("%s: vkWaitForFences to host\n", __func__);
                    vkEncoder->vkWaitForFences(device, fencesNonExternal.size(), fencesNonExternal.data(), waitAll, timeout, true /* do lock */);
                });
            }

            auto waitGroupHandle = mWorkPool.schedule(tasks);

            // Convert timeout to microseconds from nanoseconds
            bool waitRes = false;
            if (waitAll) {
                waitRes = mWorkPool.waitAll(waitGroupHandle, timeout / 1000);
            } else {
                waitRes = mWorkPool.waitAny(waitGroupHandle, timeout / 1000);
            }

            if (waitRes) {
                ALOGV("%s: VK_SUCCESS\n", __func__);
                return VK_SUCCESS;
            } else {
                ALOGV("%s: VK_TIMEOUT\n", __func__);
                return VK_TIMEOUT;
            }
        }
#else
        return enc->vkWaitForFences(
            device, fenceCount, pFences, waitAll, timeout, true /* do lock */);
#endif
    }

    VkResult on_vkCreateDescriptorPool(
        void* context,
        VkResult,
        VkDevice device,
        const VkDescriptorPoolCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDescriptorPool* pDescriptorPool) {

        VkEncoder* enc = (VkEncoder*)context;

        VkResult res = enc->vkCreateDescriptorPool(
            device, pCreateInfo, pAllocator, pDescriptorPool, true /* do lock */);

        if (res != VK_SUCCESS) return res;

        VkDescriptorPool pool = *pDescriptorPool;

        struct goldfish_VkDescriptorPool* dp = as_goldfish_VkDescriptorPool(pool);
        dp->allocInfo = new DescriptorPoolAllocationInfo;
        dp->allocInfo->device = device;
        dp->allocInfo->createFlags = pCreateInfo->flags;
        dp->allocInfo->maxSets = pCreateInfo->maxSets;
        dp->allocInfo->usedSets = 0;

        for (uint32_t i = 0; i < pCreateInfo->poolSizeCount; ++i) {
            dp->allocInfo->descriptorCountInfo.push_back({
                pCreateInfo->pPoolSizes[i].type,
                pCreateInfo->pPoolSizes[i].descriptorCount,
                0, /* used */
            });
        }

        if (mFeatureInfo->hasVulkanBatchedDescriptorSetUpdate) {
            std::vector<uint64_t> poolIds(pCreateInfo->maxSets);

            uint32_t count = pCreateInfo->maxSets;
            enc->vkCollectDescriptorPoolIdsGOOGLE(
                device, pool, &count, poolIds.data(), true /* do lock */);

            dp->allocInfo->freePoolIds = poolIds;
        }

        return res;
    }

    void on_vkDestroyDescriptorPool(
        void* context,
        VkDevice device,
        VkDescriptorPool descriptorPool,
        const VkAllocationCallbacks* pAllocator) {

        if (!descriptorPool) return;

        VkEncoder* enc = (VkEncoder*)context;

        clearDescriptorPoolAndUnregisterDescriptorSets(context, device, descriptorPool);

        enc->vkDestroyDescriptorPool(device, descriptorPool, pAllocator, true /* do lock */);
    }

    VkResult on_vkResetDescriptorPool(
        void* context,
        VkResult,
        VkDevice device,
        VkDescriptorPool descriptorPool,
        VkDescriptorPoolResetFlags flags) {

        if (!descriptorPool) return VK_ERROR_INITIALIZATION_FAILED;

        VkEncoder* enc = (VkEncoder*)context;

        VkResult res = enc->vkResetDescriptorPool(device, descriptorPool, flags, true /* do lock */);

        if (res != VK_SUCCESS) return res;

        clearDescriptorPoolAndUnregisterDescriptorSets(context, device, descriptorPool);
        return res;
    }

    VkResult on_vkAllocateDescriptorSets(
        void* context,
        VkResult,
        VkDevice device,
        const VkDescriptorSetAllocateInfo*          pAllocateInfo,
        VkDescriptorSet*                            pDescriptorSets) {

        VkEncoder* enc = (VkEncoder*)context;

        return allocAndInitializeDescriptorSets(context, device, pAllocateInfo, pDescriptorSets);
    }

    VkResult on_vkFreeDescriptorSets(
        void* context,
        VkResult,
        VkDevice                                    device,
        VkDescriptorPool                            descriptorPool,
        uint32_t                                    descriptorSetCount,
        const VkDescriptorSet*                      pDescriptorSets) {

        VkEncoder* enc = (VkEncoder*)context;

        // Bit of robustness so that we can double free descriptor sets
        // and do other invalid usages
        // https://github.com/KhronosGroup/Vulkan-Docs/issues/1070
        // (people expect VK_SUCCESS to always be returned by vkFreeDescriptorSets)
        std::vector<VkDescriptorSet> toActuallyFree;
        {
            AutoLock lock(mLock);

            // Pool was destroyed
            if (info_VkDescriptorPool.find(descriptorPool) == info_VkDescriptorPool.end()) {
                return VK_SUCCESS;
            }

            if (!descriptorPoolSupportsIndividualFreeLocked(descriptorPool))
                return VK_SUCCESS;

            std::vector<VkDescriptorSet> existingDescriptorSets;;

            // Check if this descriptor set was in the pool's set of allocated descriptor sets,
            // to guard against double free (Double free is allowed by the client)
            {
                auto allocedSets = as_goldfish_VkDescriptorPool(descriptorPool)->allocInfo->allocedSets;

                for (uint32_t i = 0; i < descriptorSetCount; ++i) {

                    if (allocedSets.end() == allocedSets.find(pDescriptorSets[i])) {
                        ALOGV("%s: Warning: descriptor set %p not found in pool. Was this double-freed?\n", __func__,
                              (void*)pDescriptorSets[i]);
                        continue;
                    }

                    auto it = info_VkDescriptorSet.find(pDescriptorSets[i]);
                    if (it == info_VkDescriptorSet.end())
                        continue;

                    existingDescriptorSets.push_back(pDescriptorSets[i]);
                }
            }

            for (auto set : existingDescriptorSets) {
                if (removeDescriptorSetFromPool(set, mFeatureInfo->hasVulkanBatchedDescriptorSetUpdate)) {
                    toActuallyFree.push_back(set);
                }
            }

            if (toActuallyFree.empty()) return VK_SUCCESS;
        }

        if (mFeatureInfo->hasVulkanBatchedDescriptorSetUpdate) {
            // In the batched set update case, decrement refcount on the set layout
            // and only free on host if we satisfied a pending allocation on the
            // host.
            for (uint32_t i = 0; i < toActuallyFree.size(); ++i) {
                VkDescriptorSetLayout setLayout = as_goldfish_VkDescriptorSet(toActuallyFree[i])->reified->setLayout;
                decDescriptorSetLayoutRef(context, device, setLayout, nullptr);
            }
            freeDescriptorSetsIfHostAllocated(
                enc, device, (uint32_t)toActuallyFree.size(), toActuallyFree.data());
        } else {
            // In the non-batched set update case, just free them directly.
            enc->vkFreeDescriptorSets(device, descriptorPool, (uint32_t)toActuallyFree.size(), toActuallyFree.data(), true /* do lock */);
        }
        return VK_SUCCESS;
    }

    VkResult on_vkCreateDescriptorSetLayout(
        void* context,
        VkResult,
        VkDevice device,
        const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDescriptorSetLayout* pSetLayout) {

        VkEncoder* enc = (VkEncoder*)context;

        VkResult res = enc->vkCreateDescriptorSetLayout(
            device, pCreateInfo, pAllocator, pSetLayout, true /* do lock */);

        if (res != VK_SUCCESS) return res;

        struct goldfish_VkDescriptorSetLayout* dsl =
            as_goldfish_VkDescriptorSetLayout(*pSetLayout);
        dsl->layoutInfo = new DescriptorSetLayoutInfo;
        for (uint32_t i = 0; i < pCreateInfo->bindingCount; ++i) {
            dsl->layoutInfo->bindings.push_back(pCreateInfo->pBindings[i]);
        }
        dsl->layoutInfo->refcount = 1;

        return res;
    }

    void on_vkUpdateDescriptorSets(
        void* context,
        VkDevice device,
        uint32_t descriptorWriteCount,
        const VkWriteDescriptorSet* pDescriptorWrites,
        uint32_t descriptorCopyCount,
        const VkCopyDescriptorSet* pDescriptorCopies) {

        VkEncoder* enc = (VkEncoder*)context;

        std::vector<VkDescriptorImageInfo> transformedImageInfos;
        std::vector<VkWriteDescriptorSet> transformedWrites(descriptorWriteCount);

        memcpy(transformedWrites.data(), pDescriptorWrites, sizeof(VkWriteDescriptorSet) * descriptorWriteCount);

        size_t imageInfosNeeded = 0;
        for (uint32_t i = 0; i < descriptorWriteCount; ++i) {
            if (!isDescriptorTypeImageInfo(transformedWrites[i].descriptorType)) continue;
            if (!transformedWrites[i].pImageInfo) continue;

            imageInfosNeeded += transformedWrites[i].descriptorCount;
        }

        transformedImageInfos.resize(imageInfosNeeded);

        size_t imageInfoIndex = 0;
        for (uint32_t i = 0; i < descriptorWriteCount; ++i) {
            if (!isDescriptorTypeImageInfo(transformedWrites[i].descriptorType)) continue;
            if (!transformedWrites[i].pImageInfo) continue;

            for (uint32_t j = 0; j < transformedWrites[i].descriptorCount; ++j) {
                transformedImageInfos[imageInfoIndex] = transformedWrites[i].pImageInfo[j];
                ++imageInfoIndex;
            }
            transformedWrites[i].pImageInfo = &transformedImageInfos[imageInfoIndex - transformedWrites[i].descriptorCount];
        }

        {
            // Validate and filter samplers
            AutoLock lock(mLock);
            size_t imageInfoIndex = 0;
            for (uint32_t i = 0; i < descriptorWriteCount; ++i) {

                if (!isDescriptorTypeImageInfo(transformedWrites[i].descriptorType)) continue;
                if (!transformedWrites[i].pImageInfo) continue;

                bool isImmutableSampler =
                    descriptorBindingIsImmutableSampler(
                        transformedWrites[i].dstSet,
                        transformedWrites[i].dstBinding);

                for (uint32_t j = 0; j < transformedWrites[i].descriptorCount; ++j) {
                    if (isImmutableSampler) {
                        transformedImageInfos[imageInfoIndex].sampler = 0;
                    }
                    transformedImageInfos[imageInfoIndex] =
                        filterNonexistentSampler(transformedImageInfos[imageInfoIndex]);
                    ++imageInfoIndex;
                }
            }
        }

        if (mFeatureInfo->hasVulkanBatchedDescriptorSetUpdate) {
            for (uint32_t i = 0; i < descriptorWriteCount; ++i) {
                VkDescriptorSet set = transformedWrites[i].dstSet;
                doEmulatedDescriptorWrite(&transformedWrites[i],
                        as_goldfish_VkDescriptorSet(set)->reified);
            }

            for (uint32_t i = 0; i < descriptorCopyCount; ++i) {
                doEmulatedDescriptorCopy(&pDescriptorCopies[i],
                        as_goldfish_VkDescriptorSet(pDescriptorCopies[i].srcSet)->reified,
                        as_goldfish_VkDescriptorSet(pDescriptorCopies[i].dstSet)->reified);
            }
        } else {
            enc->vkUpdateDescriptorSets(
                    device, descriptorWriteCount, transformedWrites.data(),
                    descriptorCopyCount, pDescriptorCopies, true /* do lock */);
        }
    }

    void on_vkDestroyImage(
        void* context,
        VkDevice device, VkImage image, const VkAllocationCallbacks *pAllocator) {
        VkEncoder* enc = (VkEncoder*)context;
        enc->vkDestroyImage(device, image, pAllocator, true /* do lock */);
    }

    void setMemoryRequirementsForSysmemBackedImage(
        VkImage image, VkMemoryRequirements *pMemoryRequirements) {
#ifdef VK_USE_PLATFORM_FUCHSIA
        auto it = info_VkImage.find(image);
        if (it == info_VkImage.end()) return;
        auto& info = it->second;
        if (info.isSysmemBackedMemory) {
            auto width = info.createInfo.extent.width;
            auto height = info.createInfo.extent.height;
            pMemoryRequirements->size = width * height * 4;
        }
#else
        // Bypass "unused parameter" checks.
        (void)image;
        (void)pMemoryRequirements;
#endif
    }

    void on_vkGetImageMemoryRequirements(
        void *context, VkDevice device, VkImage image,
        VkMemoryRequirements *pMemoryRequirements) {

        AutoLock lock(mLock);

        auto it = info_VkImage.find(image);
        if (it == info_VkImage.end()) return;

        auto& info = it->second;

        if (info.baseRequirementsKnown) {
            *pMemoryRequirements = info.baseRequirements;
            return;
        }

        lock.unlock();

        VkEncoder* enc = (VkEncoder*)context;

        enc->vkGetImageMemoryRequirements(
            device, image, pMemoryRequirements, true /* do lock */);

        lock.lock();

        transformImageMemoryRequirementsForGuestLocked(
            image, pMemoryRequirements);

        info.baseRequirementsKnown = true;
        info.baseRequirements = *pMemoryRequirements;
    }

    void on_vkGetImageMemoryRequirements2(
        void *context, VkDevice device, const VkImageMemoryRequirementsInfo2 *pInfo,
        VkMemoryRequirements2 *pMemoryRequirements) {
        VkEncoder* enc = (VkEncoder*)context;
        enc->vkGetImageMemoryRequirements2(
            device, pInfo, pMemoryRequirements, true /* do lock */);
        transformImageMemoryRequirements2ForGuest(
            pInfo->image, pMemoryRequirements);
    }

    void on_vkGetImageMemoryRequirements2KHR(
        void *context, VkDevice device, const VkImageMemoryRequirementsInfo2 *pInfo,
        VkMemoryRequirements2 *pMemoryRequirements) {
        VkEncoder* enc = (VkEncoder*)context;
        enc->vkGetImageMemoryRequirements2KHR(
            device, pInfo, pMemoryRequirements, true /* do lock */);
        transformImageMemoryRequirements2ForGuest(
            pInfo->image, pMemoryRequirements);
    }

    VkResult on_vkBindImageMemory(
        void* context, VkResult,
        VkDevice device, VkImage image, VkDeviceMemory memory,
        VkDeviceSize memoryOffset) {
        VkEncoder* enc = (VkEncoder*)context;
        return enc->vkBindImageMemory(device, image, memory, memoryOffset, true /* do lock */);
    }

    VkResult on_vkBindImageMemory2(
        void* context, VkResult,
        VkDevice device, uint32_t bindingCount, const VkBindImageMemoryInfo* pBindInfos) {
        VkEncoder* enc = (VkEncoder*)context;
        return enc->vkBindImageMemory2(device, bindingCount, pBindInfos, true /* do lock */);
    }

    VkResult on_vkBindImageMemory2KHR(
        void* context, VkResult,
        VkDevice device, uint32_t bindingCount, const VkBindImageMemoryInfo* pBindInfos) {
        VkEncoder* enc = (VkEncoder*)context;
        return enc->vkBindImageMemory2KHR(device, bindingCount, pBindInfos, true /* do lock */);
    }

    VkResult on_vkCreateBuffer(
        void* context, VkResult,
        VkDevice device, const VkBufferCreateInfo *pCreateInfo,
        const VkAllocationCallbacks *pAllocator,
        VkBuffer *pBuffer) {
        VkEncoder* enc = (VkEncoder*)context;

#ifdef VK_USE_PLATFORM_FUCHSIA
        Optional<zx::vmo> vmo;
        bool isSysmemBackedMemory = false;

        const VkExternalMemoryBufferCreateInfo* extBufCiPtr =
            vk_find_struct<VkExternalMemoryBufferCreateInfo>(pCreateInfo);
        if (extBufCiPtr &&
            ((extBufCiPtr->handleTypes &
             VK_EXTERNAL_MEMORY_HANDLE_TYPE_TEMP_ZIRCON_VMO_BIT_FUCHSIA) ||
            (extBufCiPtr->handleTypes &
             VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA))) {
            isSysmemBackedMemory = true;
        }

        const auto* extBufferCollectionPtr =
                vk_find_struct<VkBufferCollectionBufferCreateInfoFUCHSIA>(
                        pCreateInfo);

        if (extBufferCollectionPtr) {
            auto collection = reinterpret_cast<
                fidl::WireSyncClient<fuchsia_sysmem::BufferCollection>*>(
                extBufferCollectionPtr->collection);
            uint32_t index = extBufferCollectionPtr->index;

            auto result = collection->WaitForBuffersAllocated();
            if (result.ok() && result.Unwrap()->status == ZX_OK) {
                auto& info = result.Unwrap()->buffer_collection_info;
                if (index < info.buffer_count) {
                    vmo = android::base::makeOptional(
                            std::move(info.buffers[index].vmo));
                }
            } else {
                ALOGE("WaitForBuffersAllocated failed: %d %d", result.status(),
                      GET_STATUS_SAFE(result, status));
            }

            if (vmo && vmo->is_valid()) {
                fidl::FidlAllocator allocator;
                fuchsia_hardware_goldfish::wire::CreateBuffer2Params createParams(allocator);
                createParams.set_size(allocator, pCreateInfo->size)
                    .set_memory_property(allocator,
                        fuchsia_hardware_goldfish::wire::kMemoryPropertyDeviceLocal);

                auto result =
                    mControlDevice->CreateBuffer2(std::move(*vmo), std::move(createParams));
                if (!result.ok() ||
                    (result.Unwrap()->result.is_err() != ZX_OK &&
                     result.Unwrap()->result.err() != ZX_ERR_ALREADY_EXISTS)) {
                    ALOGE("CreateBuffer2 failed: %d:%d", result.status(),
                          GET_STATUS_SAFE(result, result.err()));
                }
                isSysmemBackedMemory = true;
            }
        }
#endif  // VK_USE_PLATFORM_FUCHSIA

        VkResult res;
        VkMemoryRequirements memReqs;

        if (supportsCreateResourcesWithRequirements()) {
            res = enc->vkCreateBufferWithRequirementsGOOGLE(device, pCreateInfo, pAllocator, pBuffer, &memReqs, true /* do lock */);
        } else {
            res = enc->vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer, true /* do lock */);
        }

        if (res != VK_SUCCESS) return res;

        AutoLock lock(mLock);

        auto it = info_VkBuffer.find(*pBuffer);
        if (it == info_VkBuffer.end()) return VK_ERROR_INITIALIZATION_FAILED;

        auto& info = it->second;

        info.createInfo = *pCreateInfo;
        info.createInfo.pNext = nullptr;

        if (supportsCreateResourcesWithRequirements()) {
            info.baseRequirementsKnown = true;
        }

        const VkExternalMemoryBufferCreateInfo* extBufCi =
            vk_find_struct<VkExternalMemoryBufferCreateInfo>(pCreateInfo);

        if (extBufCi) {
            info.external = true;
            info.externalCreateInfo = *extBufCi;
        }

#ifdef VK_USE_PLATFORM_FUCHSIA
        if (isSysmemBackedMemory) {
            info.isSysmemBackedMemory = true;
        }
#endif

        if (info.baseRequirementsKnown) {
            transformBufferMemoryRequirementsForGuestLocked(*pBuffer, &memReqs);
            info.baseRequirements = memReqs;
        }

        return res;
    }

    void on_vkDestroyBuffer(
        void* context,
        VkDevice device, VkBuffer buffer, const VkAllocationCallbacks *pAllocator) {
        VkEncoder* enc = (VkEncoder*)context;
        enc->vkDestroyBuffer(device, buffer, pAllocator, true /* do lock */);
    }

    void on_vkGetBufferMemoryRequirements(
        void* context, VkDevice device, VkBuffer buffer, VkMemoryRequirements *pMemoryRequirements) {

        AutoLock lock(mLock);

        auto it = info_VkBuffer.find(buffer);
        if (it == info_VkBuffer.end()) return;

        auto& info = it->second;

        if (info.baseRequirementsKnown) {
            *pMemoryRequirements = info.baseRequirements;
            return;
        }

        lock.unlock();

        VkEncoder* enc = (VkEncoder*)context;
        enc->vkGetBufferMemoryRequirements(
            device, buffer, pMemoryRequirements, true /* do lock */);

        lock.lock();

        transformBufferMemoryRequirementsForGuestLocked(
            buffer, pMemoryRequirements);
        info.baseRequirementsKnown = true;
        info.baseRequirements = *pMemoryRequirements;
    }

    void on_vkGetBufferMemoryRequirements2(
        void* context, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
        VkMemoryRequirements2* pMemoryRequirements) {
        VkEncoder* enc = (VkEncoder*)context;
        enc->vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements, true /* do lock */);
        transformBufferMemoryRequirements2ForGuest(
            pInfo->buffer, pMemoryRequirements);
    }

    void on_vkGetBufferMemoryRequirements2KHR(
        void* context, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
        VkMemoryRequirements2* pMemoryRequirements) {
        VkEncoder* enc = (VkEncoder*)context;
        enc->vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements, true /* do lock */);
        transformBufferMemoryRequirements2ForGuest(
            pInfo->buffer, pMemoryRequirements);
    }

    VkResult on_vkBindBufferMemory(
        void *context, VkResult,
        VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
        VkEncoder *enc = (VkEncoder *)context;
        return enc->vkBindBufferMemory(
            device, buffer, memory, memoryOffset, true /* do lock */);
    }

    VkResult on_vkBindBufferMemory2(
        void *context, VkResult,
        VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo *pBindInfos) {
        VkEncoder *enc = (VkEncoder *)context;
        return enc->vkBindBufferMemory2(
            device, bindInfoCount, pBindInfos, true /* do lock */);
    }

    VkResult on_vkBindBufferMemory2KHR(
        void *context, VkResult,
        VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo *pBindInfos) {
        VkEncoder *enc = (VkEncoder *)context;
        return enc->vkBindBufferMemory2KHR(
            device, bindInfoCount, pBindInfos, true /* do lock */);
    }

    void ensureSyncDeviceFd() {
        if (mSyncDeviceFd >= 0) return;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        mSyncDeviceFd = goldfish_sync_open();
        if (mSyncDeviceFd >= 0) {
            ALOGD("%s: created sync device for current Vulkan process: %d\n", __func__, mSyncDeviceFd);
        } else {
            ALOGD("%s: failed to create sync device for current Vulkan process\n", __func__);
        }
#endif
    }

    VkResult on_vkCreateSemaphore(
        void* context, VkResult input_result,
        VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSemaphore* pSemaphore) {

        VkEncoder* enc = (VkEncoder*)context;

        VkSemaphoreCreateInfo finalCreateInfo = *pCreateInfo;

        const VkExportSemaphoreCreateInfoKHR* exportSemaphoreInfoPtr =
            vk_find_struct<VkExportSemaphoreCreateInfoKHR>(pCreateInfo);

#ifdef VK_USE_PLATFORM_FUCHSIA
        bool exportEvent = exportSemaphoreInfoPtr &&
            ((exportSemaphoreInfoPtr->handleTypes &
             VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TEMP_ZIRCON_EVENT_BIT_FUCHSIA) ||
            (exportSemaphoreInfoPtr->handleTypes &
             VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA));

        if (exportEvent) {
            finalCreateInfo.pNext = nullptr;
            // If we have timeline semaphores externally, leave it there.
            const VkSemaphoreTypeCreateInfo* typeCi =
                vk_find_struct<VkSemaphoreTypeCreateInfo>(pCreateInfo);
            if (typeCi) finalCreateInfo.pNext = typeCi;
        }
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        bool exportSyncFd = exportSemaphoreInfoPtr &&
            (exportSemaphoreInfoPtr->handleTypes &
             VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT);

        if (exportSyncFd) {
            finalCreateInfo.pNext = nullptr;
            // If we have timeline semaphores externally, leave it there.
            const VkSemaphoreTypeCreateInfo* typeCi =
                vk_find_struct<VkSemaphoreTypeCreateInfo>(pCreateInfo);
            if (typeCi) finalCreateInfo.pNext = typeCi;
        }
#endif
        input_result = enc->vkCreateSemaphore(
            device, &finalCreateInfo, pAllocator, pSemaphore, true /* do lock */);

        zx_handle_t event_handle = ZX_HANDLE_INVALID;

#ifdef VK_USE_PLATFORM_FUCHSIA
        if (exportEvent) {
            zx_event_create(0, &event_handle);
        }
#endif

        AutoLock lock(mLock);

        auto it = info_VkSemaphore.find(*pSemaphore);
        if (it == info_VkSemaphore.end()) return VK_ERROR_INITIALIZATION_FAILED;

        auto& info = it->second;

        info.device = device;
        info.eventHandle = event_handle;
#ifdef VK_USE_PLATFORM_FUCHSIA
        info.eventKoid = getEventKoid(info.eventHandle);
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        if (exportSyncFd) {
            if (mFeatureInfo->hasVirtioGpuNativeSync) {
#if !defined(HOST_BUILD)
                uint64_t hostFenceHandle = get_host_u64_VkSemaphore(*pSemaphore);
                uint32_t hostFenceHandleLo = (uint32_t)hostFenceHandle;
                uint32_t hostFenceHandleHi = (uint32_t)(hostFenceHandle >> 32);

                uint64_t hostDeviceHandle = get_host_u64_VkDevice(device);
                uint32_t hostDeviceHandleLo = (uint32_t)hostDeviceHandle;
                uint32_t hostDeviceHandleHi = (uint32_t)(hostFenceHandle >> 32);

                #define VIRTIO_GPU_NATIVE_SYNC_VULKAN_CREATE_EXPORT_FD 0xa000

                uint32_t cmdDwords[5] = {
                    VIRTIO_GPU_NATIVE_SYNC_VULKAN_CREATE_EXPORT_FD,
                    hostDeviceHandleLo,
                    hostDeviceHandleHi,
                    hostFenceHandleLo,
                    hostFenceHandleHi,
                };

                drm_virtgpu_execbuffer execbuffer = {
                    .flags = VIRTGPU_EXECBUF_FENCE_FD_OUT,
                    .size = 5 * sizeof(uint32_t),
                    .command = (uint64_t)(cmdDwords),
                    .bo_handles = 0,
                    .num_bo_handles = 0,
                    .fence_fd = -1,
                };

                int res = drmIoctl(mRendernodeFd, DRM_IOCTL_VIRTGPU_EXECBUFFER, &execbuffer);
                if (res) {
                    ALOGE("%s: Failed to virtgpu execbuffer: sterror: %s errno: %d\n", __func__,
                            strerror(errno), errno);
                    abort();
                }

                info.syncFd = execbuffer.fence_fd;
#endif
            } else {
                ensureSyncDeviceFd();

                if (exportSyncFd) {
                    int syncFd = -1;
                    goldfish_sync_queue_work(
                            mSyncDeviceFd,
                            get_host_u64_VkSemaphore(*pSemaphore) /* the handle */,
                            GOLDFISH_SYNC_VULKAN_SEMAPHORE_SYNC /* thread handle (doubling as type field) */,
                            &syncFd);
                    info.syncFd = syncFd;
                }
            }
        }
#endif

        return VK_SUCCESS;
    }

    void on_vkDestroySemaphore(
        void* context,
        VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks *pAllocator) {
        VkEncoder* enc = (VkEncoder*)context;
        enc->vkDestroySemaphore(device, semaphore, pAllocator, true /* do lock */);
    }

    // https://www.khronos.org/registry/vulkan/specs/1.0-extensions/html/vkspec.html#vkGetSemaphoreFdKHR
    // Each call to vkGetSemaphoreFdKHR must create a new file descriptor and transfer ownership
    // of it to the application. To avoid leaking resources, the application must release ownership
    // of the file descriptor when it is no longer needed.
    VkResult on_vkGetSemaphoreFdKHR(
        void* context, VkResult,
        VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo,
        int* pFd) {
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        VkEncoder* enc = (VkEncoder*)context;
        bool getSyncFd =
            pGetFdInfo->handleType & VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT;

        if (getSyncFd) {
            AutoLock lock(mLock);
            auto it = info_VkSemaphore.find(pGetFdInfo->semaphore);
            if (it == info_VkSemaphore.end()) return VK_ERROR_OUT_OF_HOST_MEMORY;
            auto& semInfo = it->second;
            *pFd = dup(semInfo.syncFd);
            return VK_SUCCESS;
        } else {
            // opaque fd
            int hostFd = 0;
            VkResult result = enc->vkGetSemaphoreFdKHR(device, pGetFdInfo, &hostFd, true /* do lock */);
            if (result != VK_SUCCESS) {
                return result;
            }
            *pFd = memfd_create("vk_opaque_fd", 0);
            write(*pFd, &hostFd, sizeof(hostFd));
            return VK_SUCCESS;
        }
#else
        (void)context;
        (void)device;
        (void)pGetFdInfo;
        (void)pFd;
        return VK_ERROR_INCOMPATIBLE_DRIVER;
#endif
    }

    VkResult on_vkImportSemaphoreFdKHR(
        void* context, VkResult input_result,
        VkDevice device,
        const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) {
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        VkEncoder* enc = (VkEncoder*)context;
        if (input_result != VK_SUCCESS) {
            return input_result;
        }

        if (pImportSemaphoreFdInfo->handleType &
            VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT) {
            VkImportSemaphoreFdInfoKHR tmpInfo = *pImportSemaphoreFdInfo;

            AutoLock lock(mLock);

            auto semaphoreIt = info_VkSemaphore.find(pImportSemaphoreFdInfo->semaphore);
            auto& info = semaphoreIt->second;

            if (info.syncFd >= 0) {
                close(info.syncFd);
            }

            info.syncFd = pImportSemaphoreFdInfo->fd;

            return VK_SUCCESS;
        } else {
            int fd = pImportSemaphoreFdInfo->fd;
            int err = lseek(fd, 0, SEEK_SET);
            if (err == -1) {
                ALOGE("lseek fail on import semaphore");
            }
            int hostFd = 0;
            read(fd, &hostFd, sizeof(hostFd));
            VkImportSemaphoreFdInfoKHR tmpInfo = *pImportSemaphoreFdInfo;
            tmpInfo.fd = hostFd;
            VkResult result = enc->vkImportSemaphoreFdKHR(device, &tmpInfo, true /* do lock */);
            close(fd);
            return result;
        }
#else
        (void)context;
        (void)input_result;
        (void)device;
        (void)pImportSemaphoreFdInfo;
        return VK_ERROR_INCOMPATIBLE_DRIVER;
#endif
    }

    struct CommandBufferPendingDescriptorSets {
        std::unordered_set<VkDescriptorSet> sets;
    };

    void collectAllPendingDescriptorSetsBottomUp(const std::vector<VkCommandBuffer>& workingSet, std::unordered_set<VkDescriptorSet>& allDs) {
        if (workingSet.empty()) return;

        std::vector<VkCommandBuffer> nextLevel;
        for (auto commandBuffer : workingSet) {
            struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(commandBuffer);
            forAllObjects(cb->subObjects, [&nextLevel](void* secondary) {
                    nextLevel.push_back((VkCommandBuffer)secondary);
                    });
        }

        collectAllPendingDescriptorSetsBottomUp(nextLevel, allDs);

        for (auto cmdbuf : workingSet) {
            struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(cmdbuf);

            if (!cb->userPtr) {
                continue; // No descriptors to update.
            }

            CommandBufferPendingDescriptorSets* pendingDescriptorSets =
                (CommandBufferPendingDescriptorSets*)(cb->userPtr);

            if (pendingDescriptorSets->sets.empty()) {
                continue; // No descriptors to update.
            }

            allDs.insert(pendingDescriptorSets->sets.begin(), pendingDescriptorSets->sets.end());
        }
    }

    void commitDescriptorSetUpdates(void* context, VkQueue queue, const std::unordered_set<VkDescriptorSet>& sets) {
        VkEncoder* enc = (VkEncoder*)context;

        std::unordered_map<VkDescriptorPool, uint32_t> poolSet;
        std::vector<VkDescriptorPool> pools;
        std::vector<VkDescriptorSetLayout> setLayouts;
        std::vector<uint64_t> poolIds;
        std::vector<uint32_t> descriptorSetWhichPool;
        std::vector<uint32_t> pendingAllocations;
        std::vector<uint32_t> writeStartingIndices;
        std::vector<VkWriteDescriptorSet> writesForHost;

        uint32_t poolIndex = 0;
        uint32_t currentWriteIndex = 0;
        for (auto set : sets) {
            ReifiedDescriptorSet* reified = as_goldfish_VkDescriptorSet(set)->reified;
            VkDescriptorPool pool = reified->pool;
            VkDescriptorSetLayout setLayout = reified->setLayout;

            auto it = poolSet.find(pool);
            if (it == poolSet.end()) {
                poolSet[pool] = poolIndex;
                descriptorSetWhichPool.push_back(poolIndex);
                pools.push_back(pool);
                ++poolIndex;
            } else {
                uint32_t savedPoolIndex = it->second;
                descriptorSetWhichPool.push_back(savedPoolIndex);
            }

            poolIds.push_back(reified->poolId);
            setLayouts.push_back(setLayout);
            pendingAllocations.push_back(reified->allocationPending ? 1 : 0);
            writeStartingIndices.push_back(currentWriteIndex);

            auto& writes = reified->allWrites;

            for (size_t i = 0; i < writes.size(); ++i) {
                uint32_t binding = i;

                for (size_t j = 0; j < writes[i].size(); ++j) {
                    auto& write = writes[i][j];

                    if (write.type == DescriptorWriteType::Empty) continue;

                    uint32_t dstArrayElement = 0;

                    VkDescriptorImageInfo* imageInfo = nullptr;
                    VkDescriptorBufferInfo* bufferInfo = nullptr;
                    VkBufferView* bufferView = nullptr;

                    switch (write.type) {
                        case DescriptorWriteType::Empty:
                            break;
                        case DescriptorWriteType::ImageInfo:
                            dstArrayElement = j;
                            imageInfo = &write.imageInfo;
                            break;
                        case DescriptorWriteType::BufferInfo:
                            dstArrayElement = j;
                            bufferInfo = &write.bufferInfo;
                            break;
                        case DescriptorWriteType::BufferView:
                            dstArrayElement = j;
                            bufferView = &write.bufferView;
                            break;
                        case DescriptorWriteType::InlineUniformBlock:
                        case DescriptorWriteType::AccelerationStructure:
                            // TODO
                            ALOGE("Encountered pending inline uniform block or acceleration structure desc write, abort (NYI)\n");
                            abort();
                        default:
                            break;

                    }

                    // TODO: Combine multiple writes into one VkWriteDescriptorSet.
                    VkWriteDescriptorSet forHost = {
                        VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET, 0 /* TODO: inline uniform block */,
                        set,
                        binding,
                        dstArrayElement,
                        1,
                        write.descriptorType,
                        imageInfo,
                        bufferInfo,
                        bufferView,
                    };

                    writesForHost.push_back(forHost);
                    ++currentWriteIndex;

                    // Set it back to empty.
                    write.type = DescriptorWriteType::Empty;
                }
            }
        }

        // Skip out if there's nothing to VkWriteDescriptorSet home about.
        if (writesForHost.empty()) {
            return;
        }

        enc->vkQueueCommitDescriptorSetUpdatesGOOGLE(
            queue, 
            (uint32_t)pools.size(), pools.data(),
            (uint32_t)sets.size(),
            setLayouts.data(),
            poolIds.data(),
            descriptorSetWhichPool.data(),
            pendingAllocations.data(),
            writeStartingIndices.data(),
            (uint32_t)writesForHost.size(),
            writesForHost.data(),
            false /* no lock */);

        // If we got here, then we definitely serviced the allocations.
        for (auto set : sets) {
            ReifiedDescriptorSet* reified = as_goldfish_VkDescriptorSet(set)->reified;
            reified->allocationPending = false;
        }
    }

    void flushCommandBufferPendingCommandsBottomUp(void* context, VkQueue queue, const std::vector<VkCommandBuffer>& workingSet) {
        if (workingSet.empty()) return;

        std::vector<VkCommandBuffer> nextLevel;
        for (auto commandBuffer : workingSet) {
            struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(commandBuffer);
            forAllObjects(cb->subObjects, [&nextLevel](void* secondary) {
                nextLevel.push_back((VkCommandBuffer)secondary);
            });
        }

        flushCommandBufferPendingCommandsBottomUp(context, queue, nextLevel);

        // After this point, everyone at the previous level has been flushed
        for (auto cmdbuf : workingSet) {
            struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(cmdbuf);

            // There's no pending commands here, skip. (case 1)
            if (!cb->privateStream) continue;

            unsigned char* writtenPtr = 0;
            size_t written = 0;
            ((CommandBufferStagingStream*)cb->privateStream)->getWritten(&writtenPtr, &written);

            // There's no pending commands here, skip. (case 2, stream created but no new recordings)
            if (!written) continue;

            // There are pending commands to flush.
            VkEncoder* enc = (VkEncoder*)context;
            enc->vkQueueFlushCommandsGOOGLE(queue, cmdbuf, written, (const void*)writtenPtr, true /* do lock */);

            // Reset this stream.
            ((CommandBufferStagingStream*)cb->privateStream)->reset();
        }
    }

    // Unlike resetCommandBufferStagingInfo, this does not always erase its
    // superObjects pointers because the command buffer has merely been
    // submitted, not reset.  However, if the command buffer was recorded with
    // ONE_TIME_SUBMIT_BIT, then it will also reset its primaries.
    //
    // Also, we save the set of descriptor sets referenced by this command
    // buffer because we only submitted the command buffer and it's possible to
    // update the descriptor set again and re-submit the same command without
    // recording it (Update-after-bind descriptor sets)
    void resetCommandBufferPendingTopology(VkCommandBuffer commandBuffer) {
        struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(commandBuffer);
        if (cb->flags & VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT) {
            resetCommandBufferStagingInfo(commandBuffer,
                true /* reset primaries */,
                true /* clear pending descriptor sets */);
        } else {
            resetCommandBufferStagingInfo(commandBuffer,
                false /* Don't reset primaries */,
                false /* Don't clear pending descriptor sets */);
        }
    }

    void flushStagingStreams(void* context, VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits) {
        std::vector<VkCommandBuffer> toFlush;
        for (uint32_t i = 0; i < submitCount; ++i) {
            for (uint32_t j = 0; j < pSubmits[i].commandBufferCount; ++j) {
                toFlush.push_back(pSubmits[i].pCommandBuffers[j]);
            }
        }

        std::unordered_set<VkDescriptorSet> pendingSets;
        collectAllPendingDescriptorSetsBottomUp(toFlush, pendingSets);
        commitDescriptorSetUpdates(context, queue, pendingSets);

        flushCommandBufferPendingCommandsBottomUp(context, queue, toFlush);

        for (auto cb : toFlush) {
            resetCommandBufferPendingTopology(cb);
        }
    }

    VkResult on_vkQueueSubmit(
        void* context, VkResult input_result,
        VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
        AEMU_SCOPED_TRACE("on_vkQueueSubmit");

        flushStagingStreams(context, queue, submitCount, pSubmits);

        std::vector<VkSemaphore> pre_signal_semaphores;
        std::vector<zx_handle_t> pre_signal_events;
        std::vector<int> pre_signal_sync_fds;
        std::vector<std::pair<zx_handle_t, zx_koid_t>> post_wait_events;
        std::vector<int> post_wait_sync_fds;

        VkEncoder* enc = (VkEncoder*)context;

        AutoLock lock(mLock);

        for (uint32_t i = 0; i < submitCount; ++i) {
            for (uint32_t j = 0; j < pSubmits[i].waitSemaphoreCount; ++j) {
                auto it = info_VkSemaphore.find(pSubmits[i].pWaitSemaphores[j]);
                if (it != info_VkSemaphore.end()) {
                    auto& semInfo = it->second;
#ifdef VK_USE_PLATFORM_FUCHSIA
                    if (semInfo.eventHandle) {
                        pre_signal_events.push_back(semInfo.eventHandle);
                        pre_signal_semaphores.push_back(pSubmits[i].pWaitSemaphores[j]);
                    }
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
                    if (semInfo.syncFd >= 0) {
                        pre_signal_sync_fds.push_back(semInfo.syncFd);
                        pre_signal_semaphores.push_back(pSubmits[i].pWaitSemaphores[j]);
                    }
#endif
                }
            }
            for (uint32_t j = 0; j < pSubmits[i].signalSemaphoreCount; ++j) {
                auto it = info_VkSemaphore.find(pSubmits[i].pSignalSemaphores[j]);
                if (it != info_VkSemaphore.end()) {
                    auto& semInfo = it->second;
#ifdef VK_USE_PLATFORM_FUCHSIA
                    if (semInfo.eventHandle) {
                        post_wait_events.push_back(
                            {semInfo.eventHandle, semInfo.eventKoid});
#ifndef FUCHSIA_NO_TRACE
                        if (semInfo.eventKoid != ZX_KOID_INVALID) {
                            // TODO(fxbug.dev/66098): Remove the "semaphore"
                            // FLOW_END events once it is removed from clients
                            // (for example, gfx Engine).
                            TRACE_FLOW_END("gfx", "semaphore",
                                           semInfo.eventKoid);
                            TRACE_FLOW_BEGIN("gfx", "goldfish_post_wait_event",
                                             semInfo.eventKoid);
                        }
#endif
                    }
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
                    if (semInfo.syncFd >= 0) {
                        post_wait_sync_fds.push_back(semInfo.syncFd);
                    }
#endif
                }
            }
        }
        lock.unlock();

        if (pre_signal_semaphores.empty()) {
            if (supportsAsyncQueueSubmit()) {
                enc->vkQueueSubmitAsyncGOOGLE(queue, submitCount, pSubmits, fence, true /* do lock */);
                input_result = VK_SUCCESS;
            } else {
                input_result = enc->vkQueueSubmit(queue, submitCount, pSubmits, fence, true /* do lock */);
                if (input_result != VK_SUCCESS) return input_result;
            }
        } else {
            // Schedule waits on the OS external objects and
            // signal the wait semaphores
            // in a separate thread.
            std::vector<WorkPool::Task> preSignalTasks;
            std::vector<WorkPool::Task> preSignalQueueSubmitTasks;;
#ifdef VK_USE_PLATFORM_FUCHSIA
            for (auto event : pre_signal_events) {
                preSignalTasks.push_back([event] {
                    zx_object_wait_one(
                        event,
                        ZX_EVENT_SIGNALED,
                        ZX_TIME_INFINITE,
                        nullptr);
                });
            }
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
            for (auto fd : pre_signal_sync_fds) {
                preSignalTasks.push_back([fd] {
                    sync_wait(fd, 3000);
                });
            }
#endif
            auto waitGroupHandle = mWorkPool.schedule(preSignalTasks);
            mWorkPool.waitAll(waitGroupHandle);

            VkSubmitInfo submit_info = {
                .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
                .waitSemaphoreCount = 0,
                .pWaitSemaphores = nullptr,
                .pWaitDstStageMask = nullptr,
                .signalSemaphoreCount =
                    static_cast<uint32_t>(pre_signal_semaphores.size()),
                .pSignalSemaphores = pre_signal_semaphores.data()};

            if (supportsAsyncQueueSubmit()) {
                enc->vkQueueSubmitAsyncGOOGLE(queue, 1, &submit_info, VK_NULL_HANDLE, true /* do lock */);
            } else {
                enc->vkQueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE, true /* do lock */);
            }

            if (supportsAsyncQueueSubmit()) {
                enc->vkQueueSubmitAsyncGOOGLE(queue, submitCount, pSubmits, fence, true /* do lock */);
                input_result = VK_SUCCESS;
            } else {
                input_result = enc->vkQueueSubmit(queue, submitCount, pSubmits, fence, true /* do lock */);
                if (input_result != VK_SUCCESS) return input_result;
            }
        }

        lock.lock();
        int externalFenceFdToSignal = -1;

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        if (fence != VK_NULL_HANDLE) {
            auto it = info_VkFence.find(fence);
            if (it != info_VkFence.end()) {
                const auto& info = it->second;
                if (info.syncFd >= 0) {
                    externalFenceFdToSignal = info.syncFd;
                }
            }
        }
#endif
        if (externalFenceFdToSignal >= 0 ||
            !post_wait_events.empty() ||
            !post_wait_sync_fds.empty()) {

            std::vector<WorkPool::Task> tasks;

            tasks.push_back([queue, externalFenceFdToSignal,
                             post_wait_events /* copy of zx handles */,
                             post_wait_sync_fds /* copy of sync fds */] {
                auto hostConn = ResourceTracker::threadingCallbacks.hostConnectionGetFunc();
                auto vkEncoder = ResourceTracker::threadingCallbacks.vkEncoderGetFunc(hostConn);
                auto waitIdleRes = vkEncoder->vkQueueWaitIdle(queue, true /* do lock */);
#ifdef VK_USE_PLATFORM_FUCHSIA
                AEMU_SCOPED_TRACE("on_vkQueueSubmit::SignalSemaphores");
                (void)externalFenceFdToSignal;
                for (auto& [event, koid] : post_wait_events) {
#ifndef FUCHSIA_NO_TRACE
                    if (koid != ZX_KOID_INVALID) {
                        TRACE_FLOW_END("gfx", "goldfish_post_wait_event", koid);
                        TRACE_FLOW_BEGIN("gfx", "event_signal", koid);
                    }
#endif
                    zx_object_signal(event, 0, ZX_EVENT_SIGNALED);
                }
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
                for (auto& fd : post_wait_sync_fds) {
                    goldfish_sync_signal(fd);
                }

                if (externalFenceFdToSignal >= 0) {
                    ALOGV("%s: external fence real signal: %d\n", __func__, externalFenceFdToSignal);
                    goldfish_sync_signal(externalFenceFdToSignal);
                }
#endif
            });
            auto queueAsyncWaitHandle = mWorkPool.schedule(tasks);
            auto& queueWorkItems = mQueueSensitiveWorkPoolItems[queue];
            queueWorkItems.push_back(queueAsyncWaitHandle);
        }

        return VK_SUCCESS;
    }

    VkResult on_vkQueueWaitIdle(
        void* context, VkResult,
        VkQueue queue) {

        VkEncoder* enc = (VkEncoder*)context;

        AutoLock lock(mLock);
        std::vector<WorkPool::WaitGroupHandle> toWait =
            mQueueSensitiveWorkPoolItems[queue];
        mQueueSensitiveWorkPoolItems[queue].clear();
        lock.unlock();

        if (toWait.empty()) {
            ALOGV("%s: No queue-specific work pool items\n", __func__);
            return enc->vkQueueWaitIdle(queue, true /* do lock */);
        }

        for (auto handle : toWait) {
            ALOGV("%s: waiting on work group item: %llu\n", __func__,
                  (unsigned long long)handle);
            mWorkPool.waitAll(handle);
        }

        // now done waiting, get the host's opinion
        return enc->vkQueueWaitIdle(queue, true /* do lock */);
    }

    void unwrap_VkNativeBufferANDROID(
        const VkImageCreateInfo* pCreateInfo,
        VkImageCreateInfo* local_pCreateInfo) {

        if (!pCreateInfo->pNext) return;

        const VkNativeBufferANDROID* nativeInfo =
            vk_find_struct<VkNativeBufferANDROID>(pCreateInfo);
        if (!nativeInfo) {
            return;
        }

        if (!nativeInfo->handle) return;

        VkNativeBufferANDROID* nativeInfoOut =
            reinterpret_cast<VkNativeBufferANDROID*>(
                const_cast<void*>(
                    local_pCreateInfo->pNext));

        if (!nativeInfoOut->handle) {
            ALOGE("FATAL: Local native buffer info not properly allocated!");
            abort();
        }

        *(uint32_t*)(nativeInfoOut->handle) =
            ResourceTracker::threadingCallbacks.hostConnectionGetFunc()->
                grallocHelper()->getHostHandle(
                    (const native_handle_t*)nativeInfo->handle);
    }

    void unwrap_vkAcquireImageANDROID_nativeFenceFd(int fd, int*) {
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        if (fd != -1) {
            // Implicit Synchronization
            sync_wait(fd, 3000);
            // From libvulkan's swapchain.cpp:
            // """
            // NOTE: we're relying on AcquireImageANDROID to close fence_clone,
            // even if the call fails. We could close it ourselves on failure, but
            // that would create a race condition if the driver closes it on a
            // failure path: some other thread might create an fd with the same
            // number between the time the driver closes it and the time we close
            // it. We must assume one of: the driver *always* closes it even on
            // failure, or *never* closes it on failure.
            // """
            // Therefore, assume contract where we need to close fd in this driver
            close(fd);
        }
#endif
    }

    // Action of vkMapMemoryIntoAddressSpaceGOOGLE:
    // 1. preprocess (on_vkMapMemoryIntoAddressSpaceGOOGLE_pre):
    //    uses address space device to reserve the right size of
    //    memory.
    // 2. the reservation results in a physical address. the physical
    //    address is set as |*pAddress|.
    // 3. after pre, the API call is encoded to the host, where the
    //    value of pAddress is also sent (the physical address).
    // 4. the host will obtain the actual gpu pointer and send it
    //    back out in |*pAddress|.
    // 5. postprocess (on_vkMapMemoryIntoAddressSpaceGOOGLE) will run,
    //    using the mmap() method of GoldfishAddressSpaceBlock to obtain
    //    a pointer in guest userspace corresponding to the host pointer.
    VkResult on_vkMapMemoryIntoAddressSpaceGOOGLE_pre(
        void*,
        VkResult,
        VkDevice,
        VkDeviceMemory memory,
        uint64_t* pAddress) {

        AutoLock lock(mLock);

        auto it = info_VkDeviceMemory.find(memory);
        if (it == info_VkDeviceMemory.end()) {
            return VK_ERROR_OUT_OF_HOST_MEMORY;
        }

        auto& memInfo = it->second;
        memInfo.goldfishAddressSpaceBlock =
            new GoldfishAddressSpaceBlock;
        auto& block = *(memInfo.goldfishAddressSpaceBlock);

        block.allocate(
            mGoldfishAddressSpaceBlockProvider.get(),
            memInfo.mappedSize);

        *pAddress = block.physAddr();

        return VK_SUCCESS;
    }

    VkResult on_vkMapMemoryIntoAddressSpaceGOOGLE(
        void*,
        VkResult input_result,
        VkDevice,
        VkDeviceMemory memory,
        uint64_t* pAddress) {

        if (input_result != VK_SUCCESS) {
            return input_result;
        }

        // Now pAddress points to the gpu addr from host.
        AutoLock lock(mLock);

        auto it = info_VkDeviceMemory.find(memory);
        if (it == info_VkDeviceMemory.end()) {
            return VK_ERROR_OUT_OF_HOST_MEMORY;
        }

        auto& memInfo = it->second;
        auto& block = *(memInfo.goldfishAddressSpaceBlock);

        uint64_t gpuAddr = *pAddress;

        void* userPtr = block.mmap(gpuAddr);

        D("%s: Got new host visible alloc. "
          "Sizeof void: %zu map size: %zu Range: [%p %p]",
          __func__,
          sizeof(void*), (size_t)memInfo.mappedSize,
          userPtr,
          (unsigned char*)userPtr + memInfo.mappedSize);

        *pAddress = (uint64_t)(uintptr_t)userPtr;

        return input_result;
    }

    VkResult initDescriptorUpdateTemplateBuffers(
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
        VkDescriptorUpdateTemplate descriptorUpdateTemplate) {

        AutoLock lock(mLock);

        auto it = info_VkDescriptorUpdateTemplate.find(descriptorUpdateTemplate);
        if (it == info_VkDescriptorUpdateTemplate.end()) {
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        auto& info = it->second;

        for (uint32_t i = 0; i < pCreateInfo->descriptorUpdateEntryCount; ++i) {
            const auto& entry = pCreateInfo->pDescriptorUpdateEntries[i];
            uint32_t descCount = entry.descriptorCount;
            VkDescriptorType descType = entry.descriptorType;
            ++info.templateEntryCount;
            for (uint32_t j = 0; j < descCount; ++j) {
                if (isDescriptorTypeImageInfo(descType)) {
                    ++info.imageInfoCount;
                } else if (isDescriptorTypeBufferInfo(descType)) {
                    ++info.bufferInfoCount;
                } else if (isDescriptorTypeBufferView(descType)) {
                    ++info.bufferViewCount;
                } else {
                    ALOGE("%s: FATAL: Unknown descriptor type %d\n", __func__, descType);
                    abort();
                }
            }
        }

        if (info.templateEntryCount)
            info.templateEntries = new VkDescriptorUpdateTemplateEntry[info.templateEntryCount];

        if (info.imageInfoCount) {
            info.imageInfoIndices = new uint32_t[info.imageInfoCount];
            info.imageInfos = new VkDescriptorImageInfo[info.imageInfoCount];
        }

        if (info.bufferInfoCount) {
            info.bufferInfoIndices = new uint32_t[info.bufferInfoCount];
            info.bufferInfos = new VkDescriptorBufferInfo[info.bufferInfoCount];
        }

        if (info.bufferViewCount) {
            info.bufferViewIndices = new uint32_t[info.bufferViewCount];
            info.bufferViews = new VkBufferView[info.bufferViewCount];
        }

        uint32_t imageInfoIndex = 0;
        uint32_t bufferInfoIndex = 0;
        uint32_t bufferViewIndex = 0;

        for (uint32_t i = 0; i < pCreateInfo->descriptorUpdateEntryCount; ++i) {
            const auto& entry = pCreateInfo->pDescriptorUpdateEntries[i];
            uint32_t descCount = entry.descriptorCount;
            VkDescriptorType descType = entry.descriptorType;

            info.templateEntries[i] = entry;

            for (uint32_t j = 0; j < descCount; ++j) {
                if (isDescriptorTypeImageInfo(descType)) {
                    info.imageInfoIndices[imageInfoIndex] = i;
                    ++imageInfoIndex;
                } else if (isDescriptorTypeBufferInfo(descType)) {
                    info.bufferInfoIndices[bufferInfoIndex] = i;
                    ++bufferInfoIndex;
                } else if (isDescriptorTypeBufferView(descType)) {
                    info.bufferViewIndices[bufferViewIndex] = i;
                    ++bufferViewIndex;
                } else {
                    ALOGE("%s: FATAL: Unknown descriptor type %d\n", __func__, descType);
                    abort();
                }
            }
        }

        return VK_SUCCESS;
    }

    VkResult on_vkCreateDescriptorUpdateTemplate(
        void* context, VkResult input_result,
        VkDevice device,
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {

        (void)context;
        (void)device;
        (void)pAllocator;

        if (input_result != VK_SUCCESS) return input_result;

        return initDescriptorUpdateTemplateBuffers(pCreateInfo, *pDescriptorUpdateTemplate);
    }

    VkResult on_vkCreateDescriptorUpdateTemplateKHR(
        void* context, VkResult input_result,
        VkDevice device,
        const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {

        (void)context;
        (void)device;
        (void)pAllocator;

        if (input_result != VK_SUCCESS) return input_result;

        return initDescriptorUpdateTemplateBuffers(pCreateInfo, *pDescriptorUpdateTemplate);
    }

    void on_vkUpdateDescriptorSetWithTemplate(
        void* context,
        VkDevice device,
        VkDescriptorSet descriptorSet,
        VkDescriptorUpdateTemplate descriptorUpdateTemplate,
        const void* pData) {

        VkEncoder* enc = (VkEncoder*)context;

        uint8_t* userBuffer = (uint8_t*)pData;
        if (!userBuffer) return;

        // TODO: Make this thread safe
        AutoLock lock(mLock);

        auto it = info_VkDescriptorUpdateTemplate.find(descriptorUpdateTemplate);
        if (it == info_VkDescriptorUpdateTemplate.end()) {
            return;
        }

        auto& info = it->second;

        uint32_t templateEntryCount = info.templateEntryCount;
        VkDescriptorUpdateTemplateEntry* templateEntries = info.templateEntries;

        uint32_t imageInfoCount = info.imageInfoCount;
        uint32_t bufferInfoCount = info.bufferInfoCount;
        uint32_t bufferViewCount = info.bufferViewCount;
        uint32_t* imageInfoIndices = info.imageInfoIndices;
        uint32_t* bufferInfoIndices = info.bufferInfoIndices;
        uint32_t* bufferViewIndices = info.bufferViewIndices;
        VkDescriptorImageInfo* imageInfos = info.imageInfos;
        VkDescriptorBufferInfo* bufferInfos = info.bufferInfos;
        VkBufferView* bufferViews = info.bufferViews;

        lock.unlock();

        size_t currImageInfoOffset = 0;
        size_t currBufferInfoOffset = 0;
        size_t currBufferViewOffset = 0;

        struct goldfish_VkDescriptorSet* ds = as_goldfish_VkDescriptorSet(descriptorSet);
        ReifiedDescriptorSet* reified = ds->reified;

        bool batched = mFeatureInfo->hasVulkanBatchedDescriptorSetUpdate;

        for (uint32_t i = 0; i < templateEntryCount; ++i) {
            const auto& entry = templateEntries[i];
            VkDescriptorType descType = entry.descriptorType;
            uint32_t dstBinding = entry.dstBinding;

            auto offset = entry.offset;
            auto stride = entry.stride;
            auto dstArrayElement = entry.dstArrayElement;

            uint32_t descCount = entry.descriptorCount;

            if (isDescriptorTypeImageInfo(descType)) {

                if (!stride) stride = sizeof(VkDescriptorImageInfo);

                const VkDescriptorImageInfo* currImageInfoBegin =
                    (const VkDescriptorImageInfo*)((uint8_t*)imageInfos + currImageInfoOffset);

                for (uint32_t j = 0; j < descCount; ++j) {
                    const VkDescriptorImageInfo* user =
                        (const VkDescriptorImageInfo*)(userBuffer + offset + j * stride);

                    memcpy(((uint8_t*)imageInfos) + currImageInfoOffset,
                           userBuffer + offset + j * stride,
                           sizeof(VkDescriptorImageInfo));
                    currImageInfoOffset += sizeof(VkDescriptorImageInfo);
                }

                if (batched) doEmulatedDescriptorImageInfoWriteFromTemplate(
                        descType,
                        dstBinding,
                        dstArrayElement,
                        descCount,
                        currImageInfoBegin,
                        reified);

            } else if (isDescriptorTypeBufferInfo(descType)) {


                if (!stride) stride = sizeof(VkDescriptorBufferInfo);

                const VkDescriptorBufferInfo* currBufferInfoBegin =
                    (const VkDescriptorBufferInfo*)((uint8_t*)bufferInfos + currBufferInfoOffset);

                for (uint32_t j = 0; j < descCount; ++j) {
                    const VkDescriptorBufferInfo* user =
                        (const VkDescriptorBufferInfo*)(userBuffer + offset + j * stride);

                    memcpy(((uint8_t*)bufferInfos) + currBufferInfoOffset,
                           userBuffer + offset + j * stride,
                           sizeof(VkDescriptorBufferInfo));
                    currBufferInfoOffset += sizeof(VkDescriptorBufferInfo);
                }

                if (batched) doEmulatedDescriptorBufferInfoWriteFromTemplate(
                        descType,
                        dstBinding,
                        dstArrayElement,
                        descCount,
                        currBufferInfoBegin,
                        reified);

            } else if (isDescriptorTypeBufferView(descType)) {
                if (!stride) stride = sizeof(VkBufferView);

                const VkBufferView* currBufferViewBegin =
                    (const VkBufferView*)((uint8_t*)bufferViews + currBufferViewOffset);

                for (uint32_t j = 0; j < descCount; ++j) {
                    memcpy(((uint8_t*)bufferViews) + currBufferViewOffset,
                           userBuffer + offset + j * stride,
                           sizeof(VkBufferView));
                    currBufferViewOffset += sizeof(VkBufferView);
                }

                if (batched) doEmulatedDescriptorBufferViewWriteFromTemplate(
                        descType,
                        dstBinding,
                        dstArrayElement,
                        descCount,
                        currBufferViewBegin,
                        reified);
            } else {
                ALOGE("%s: FATAL: Unknown descriptor type %d\n", __func__, descType);
                abort();
            }
        }

        if (batched) return;

        enc->vkUpdateDescriptorSetWithTemplateSizedGOOGLE(
            device,
            descriptorSet,
            descriptorUpdateTemplate,
            imageInfoCount,
            bufferInfoCount,
            bufferViewCount,
            imageInfoIndices,
            bufferInfoIndices,
            bufferViewIndices,
            imageInfos,
            bufferInfos,
            bufferViews,
            true /* do lock */);
    }

    VkResult on_vkGetPhysicalDeviceImageFormatProperties2_common(
        bool isKhr,
        void* context, VkResult input_result,
        VkPhysicalDevice physicalDevice,
        const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
        VkImageFormatProperties2* pImageFormatProperties) {

        VkEncoder* enc = (VkEncoder*)context;
        (void)input_result;

#ifdef VK_USE_PLATFORM_FUCHSIA

        constexpr VkFormat kExternalImageSupportedFormats[] = {
            VK_FORMAT_B8G8R8A8_SINT,
            VK_FORMAT_B8G8R8A8_UNORM,
            VK_FORMAT_B8G8R8A8_SRGB,
            VK_FORMAT_B8G8R8A8_SNORM,
            VK_FORMAT_B8G8R8A8_SSCALED,
            VK_FORMAT_B8G8R8A8_USCALED,
            VK_FORMAT_R8G8B8A8_SINT,
            VK_FORMAT_R8G8B8A8_UNORM,
            VK_FORMAT_R8G8B8A8_SRGB,
            VK_FORMAT_R8G8B8A8_SNORM,
            VK_FORMAT_R8G8B8A8_SSCALED,
            VK_FORMAT_R8G8B8A8_USCALED,
            VK_FORMAT_R8_UNORM,
            VK_FORMAT_R8_UINT,
            VK_FORMAT_R8_USCALED,
            VK_FORMAT_R8_SNORM,
            VK_FORMAT_R8_SINT,
            VK_FORMAT_R8_SSCALED,
            VK_FORMAT_R8_SRGB,
            VK_FORMAT_R8G8_UNORM,
            VK_FORMAT_R8G8_UINT,
            VK_FORMAT_R8G8_USCALED,
            VK_FORMAT_R8G8_SNORM,
            VK_FORMAT_R8G8_SINT,
            VK_FORMAT_R8G8_SSCALED,
            VK_FORMAT_R8G8_SRGB,
        };

        VkExternalImageFormatProperties* ext_img_properties =
            vk_find_struct<VkExternalImageFormatProperties>(pImageFormatProperties);

        if (ext_img_properties) {
          if (std::find(std::begin(kExternalImageSupportedFormats),
                        std::end(kExternalImageSupportedFormats),
                        pImageFormatInfo->format) == std::end(kExternalImageSupportedFormats)) {
            return VK_ERROR_FORMAT_NOT_SUPPORTED;
          }
        }
#endif

        VkAndroidHardwareBufferUsageANDROID* output_ahw_usage =
            vk_find_struct<VkAndroidHardwareBufferUsageANDROID>(pImageFormatProperties);

        VkResult hostRes;

        if (isKhr) {
            hostRes = enc->vkGetPhysicalDeviceImageFormatProperties2KHR(
                physicalDevice, pImageFormatInfo,
                pImageFormatProperties, true /* do lock */);
        } else {
            hostRes = enc->vkGetPhysicalDeviceImageFormatProperties2(
                physicalDevice, pImageFormatInfo,
                pImageFormatProperties, true /* do lock */);
        }

        if (hostRes != VK_SUCCESS) return hostRes;

#ifdef VK_USE_PLATFORM_FUCHSIA
        if (ext_img_properties) {
            const VkPhysicalDeviceExternalImageFormatInfo* ext_img_info =
                vk_find_struct<VkPhysicalDeviceExternalImageFormatInfo>(pImageFormatInfo);
            if (ext_img_info) {
                switch (static_cast<uint32_t>(ext_img_info->handleType)) {
                case VK_EXTERNAL_MEMORY_HANDLE_TYPE_TEMP_ZIRCON_VMO_BIT_FUCHSIA:
                    ext_img_properties->externalMemoryProperties = {
                        .externalMemoryFeatures = VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT |
                                                  VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT,
                        .exportFromImportedHandleTypes =
                            VK_EXTERNAL_MEMORY_HANDLE_TYPE_TEMP_ZIRCON_VMO_BIT_FUCHSIA,
                        .compatibleHandleTypes =
                            VK_EXTERNAL_MEMORY_HANDLE_TYPE_TEMP_ZIRCON_VMO_BIT_FUCHSIA,
                    };
                    break;
                case VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA:
                    ext_img_properties->externalMemoryProperties = {
                        .externalMemoryFeatures = VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT |
                                                  VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT,
                        .exportFromImportedHandleTypes =
                            VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA,
                        .compatibleHandleTypes =
                            VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA,
                    };
                    break;
                }
            }
        }
#endif

        if (output_ahw_usage) {
            output_ahw_usage->androidHardwareBufferUsage =
                getAndroidHardwareBufferUsageFromVkUsage(
                    pImageFormatInfo->flags,
                    pImageFormatInfo->usage);
        }

        return hostRes;
    }

    VkResult on_vkGetPhysicalDeviceImageFormatProperties2(
        void* context, VkResult input_result,
        VkPhysicalDevice physicalDevice,
        const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
        VkImageFormatProperties2* pImageFormatProperties) {
        return on_vkGetPhysicalDeviceImageFormatProperties2_common(
            false /* not KHR */, context, input_result,
            physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }

    VkResult on_vkGetPhysicalDeviceImageFormatProperties2KHR(
        void* context, VkResult input_result,
        VkPhysicalDevice physicalDevice,
        const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
        VkImageFormatProperties2* pImageFormatProperties) {
        return on_vkGetPhysicalDeviceImageFormatProperties2_common(
            true /* is KHR */, context, input_result,
            physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }

    void on_vkGetPhysicalDeviceExternalSemaphoreProperties(
        void*,
        VkPhysicalDevice,
        const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
        VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
        (void)pExternalSemaphoreInfo;
        (void)pExternalSemaphoreProperties;
#ifdef VK_USE_PLATFORM_FUCHSIA
        if (pExternalSemaphoreInfo->handleType ==
            VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TEMP_ZIRCON_EVENT_BIT_FUCHSIA) {
            pExternalSemaphoreProperties->compatibleHandleTypes |=
                VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TEMP_ZIRCON_EVENT_BIT_FUCHSIA;
            pExternalSemaphoreProperties->exportFromImportedHandleTypes |=
                VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TEMP_ZIRCON_EVENT_BIT_FUCHSIA;
            pExternalSemaphoreProperties->externalSemaphoreFeatures |=
                VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT |
                VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT;
        }
        if (pExternalSemaphoreInfo->handleType ==
            static_cast<uint32_t>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA)) {
            pExternalSemaphoreProperties->compatibleHandleTypes |=
                VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA;
            pExternalSemaphoreProperties->exportFromImportedHandleTypes |=
                VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA;
            pExternalSemaphoreProperties->externalSemaphoreFeatures |=
                VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT |
                VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT;
        }
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        if (pExternalSemaphoreInfo->handleType ==
            VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT) {
            pExternalSemaphoreProperties->compatibleHandleTypes |=
                VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT;
            pExternalSemaphoreProperties->exportFromImportedHandleTypes |=
                VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT;
            pExternalSemaphoreProperties->externalSemaphoreFeatures |=
                VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT |
                VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT;
        }
#endif  // VK_USE_PLATFORM_ANDROID_KHR
    }

    void registerEncoderCleanupCallback(const VkEncoder* encoder, void* object, CleanupCallback callback) {
        AutoLock lock(mLock);
        auto& callbacks = mEncoderCleanupCallbacks[encoder];
        callbacks[object] = callback;
    }

    void unregisterEncoderCleanupCallback(const VkEncoder* encoder, void* object) {
        AutoLock lock(mLock);
        mEncoderCleanupCallbacks[encoder].erase(object);
    }

    void onEncoderDeleted(const VkEncoder* encoder) {
        AutoLock lock(mLock);
        if (mEncoderCleanupCallbacks.find(encoder) == mEncoderCleanupCallbacks.end()) return;

        std::unordered_map<void*, CleanupCallback> callbackCopies = mEncoderCleanupCallbacks[encoder];

        mEncoderCleanupCallbacks.erase(encoder);
        lock.unlock();

        for (auto it : callbackCopies) {
            it.second();
        }
    }

    uint32_t syncEncodersForCommandBuffer(VkCommandBuffer commandBuffer, VkEncoder* currentEncoder) {
        struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(commandBuffer);
        if (!cb) return 0;

        auto lastEncoder = cb->lastUsedEncoder;

        if (lastEncoder == currentEncoder) return 0;

        currentEncoder->incRef();

        cb->lastUsedEncoder = currentEncoder;

        if (!lastEncoder) return 0;

        auto oldSeq = cb->sequenceNumber;
        cb->sequenceNumber += 2;
        lastEncoder->vkCommandBufferHostSyncGOOGLE(commandBuffer, false, oldSeq + 1, true /* do lock */);
        lastEncoder->flush();
        currentEncoder->vkCommandBufferHostSyncGOOGLE(commandBuffer, true, oldSeq + 2, true /* do lock */);

        if (lastEncoder->decRef()) {
            cb->lastUsedEncoder = nullptr;
        }
        return 0;
    }

    uint32_t syncEncodersForQueue(VkQueue queue, VkEncoder* currentEncoder) {
        if (!supportsAsyncQueueSubmit()) {
            return 0;
        }

        struct goldfish_VkQueue* q = as_goldfish_VkQueue(queue);
        if (!q) return 0;

        auto lastEncoder = q->lastUsedEncoder;

        if (lastEncoder == currentEncoder) return 0;

        currentEncoder->incRef();

        q->lastUsedEncoder = currentEncoder;

        if (!lastEncoder) return 0;

        auto oldSeq = q->sequenceNumber;
        q->sequenceNumber += 2;
        lastEncoder->vkQueueHostSyncGOOGLE(queue, false, oldSeq + 1, true /* do lock */);
        lastEncoder->flush();
        currentEncoder->vkQueueHostSyncGOOGLE(queue, true, oldSeq + 2, true /* do lock */);

        if (lastEncoder->decRef()) {
            q->lastUsedEncoder = nullptr;
        }

        return 0;
    }

    VkResult on_vkBeginCommandBuffer(
        void* context, VkResult input_result,
        VkCommandBuffer commandBuffer,
        const VkCommandBufferBeginInfo* pBeginInfo) {

        (void)context;

        resetCommandBufferStagingInfo(commandBuffer, true /* also reset primaries */, true /* also clear pending descriptor sets */);

        VkEncoder* enc = ResourceTracker::getCommandBufferEncoder(commandBuffer);
        (void)input_result;

        struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(commandBuffer);
        cb->flags = pBeginInfo->flags;

        VkCommandBufferBeginInfo modifiedBeginInfo;

        if (pBeginInfo->pInheritanceInfo && !cb->isSecondary) {
            modifiedBeginInfo = *pBeginInfo;
            modifiedBeginInfo.pInheritanceInfo = nullptr;
            pBeginInfo = &modifiedBeginInfo;
        }

        if (!supportsDeferredCommands()) {
            return enc->vkBeginCommandBuffer(commandBuffer, pBeginInfo, true /* do lock */);
        }

        enc->vkBeginCommandBufferAsyncGOOGLE(commandBuffer, pBeginInfo, true /* do lock */);

        return VK_SUCCESS;
    }

    VkResult on_vkEndCommandBuffer(
        void* context, VkResult input_result,
        VkCommandBuffer commandBuffer) {

        VkEncoder* enc = (VkEncoder*)context;
        (void)input_result;

        if (!supportsDeferredCommands()) {
            return enc->vkEndCommandBuffer(commandBuffer, true /* do lock */);
        }

        enc->vkEndCommandBufferAsyncGOOGLE(commandBuffer, true /* do lock */);

        return VK_SUCCESS;
    }

    VkResult on_vkResetCommandBuffer(
        void* context, VkResult input_result,
        VkCommandBuffer commandBuffer,
        VkCommandBufferResetFlags flags) {

        resetCommandBufferStagingInfo(commandBuffer, true /* also reset primaries */, true /* also clear pending descriptor sets */);

        VkEncoder* enc = (VkEncoder*)context;
        (void)input_result;

        if (!supportsDeferredCommands()) {
            return enc->vkResetCommandBuffer(commandBuffer, flags, true /* do lock */);
        }

        enc->vkResetCommandBufferAsyncGOOGLE(commandBuffer, flags, true /* do lock */);
        return VK_SUCCESS;
    }

    VkResult on_vkCreateImageView(
        void* context, VkResult input_result,
        VkDevice device,
        const VkImageViewCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkImageView* pView) {

        VkEncoder* enc = (VkEncoder*)context;
        (void)input_result;

        VkImageViewCreateInfo localCreateInfo = vk_make_orphan_copy(*pCreateInfo);

#ifdef VK_USE_PLATFORM_ANDROID_KHR
        const VkExternalFormatANDROID* extFormatAndroidPtr =
            vk_find_struct<VkExternalFormatANDROID>(pCreateInfo);
        if (extFormatAndroidPtr) {
            if (extFormatAndroidPtr->externalFormat) {
                localCreateInfo.format =
                    vk_format_from_android(extFormatAndroidPtr->externalFormat);
            }
        }
#endif

        return enc->vkCreateImageView(device, &localCreateInfo, pAllocator, pView, true /* do lock */);
    }

    void on_vkCmdExecuteCommands(
        void* context,
        VkCommandBuffer commandBuffer,
        uint32_t commandBufferCount,
        const VkCommandBuffer* pCommandBuffers) {

        VkEncoder* enc = (VkEncoder*)context;

        if (!mFeatureInfo->hasVulkanQueueSubmitWithCommands) {
            enc->vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers, true /* do lock */);
            return;
        }

        struct goldfish_VkCommandBuffer* primary = as_goldfish_VkCommandBuffer(commandBuffer);
        for (uint32_t i = 0; i < commandBufferCount; ++i) {
            struct goldfish_VkCommandBuffer* secondary = as_goldfish_VkCommandBuffer(pCommandBuffers[i]);
            appendObject(&secondary->superObjects, primary);
            appendObject(&primary->subObjects, secondary);
        }

        enc->vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers, true /* do lock */);
    }

    void addPendingDescriptorSets(VkCommandBuffer commandBuffer, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) {
        struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(commandBuffer);

        if (!cb->userPtr) {
            CommandBufferPendingDescriptorSets* newPendingSets =
                new CommandBufferPendingDescriptorSets;
            cb->userPtr = newPendingSets;
        }

        CommandBufferPendingDescriptorSets* pendingSets =
            (CommandBufferPendingDescriptorSets*)cb->userPtr;

        for (uint32_t i = 0; i < descriptorSetCount; ++i) {
            pendingSets->sets.insert(pDescriptorSets[i]);
        }
    }

    void on_vkCmdBindDescriptorSets(
        void* context,
        VkCommandBuffer commandBuffer,
        VkPipelineBindPoint pipelineBindPoint,
        VkPipelineLayout layout,
        uint32_t firstSet,
        uint32_t descriptorSetCount,
        const VkDescriptorSet* pDescriptorSets,
        uint32_t dynamicOffsetCount,
        const uint32_t* pDynamicOffsets) {

        VkEncoder* enc = (VkEncoder*)context;

        if (mFeatureInfo->hasVulkanBatchedDescriptorSetUpdate)
            addPendingDescriptorSets(commandBuffer, descriptorSetCount, pDescriptorSets);

        enc->vkCmdBindDescriptorSets(
            commandBuffer,
            pipelineBindPoint,
            layout,
            firstSet,
            descriptorSetCount,
            pDescriptorSets,
            dynamicOffsetCount,
            pDynamicOffsets,
            true /* do lock */);
    }

    void decDescriptorSetLayoutRef(
        void* context,
        VkDevice device,
        VkDescriptorSetLayout descriptorSetLayout,
        const VkAllocationCallbacks* pAllocator) {

        if (!descriptorSetLayout) return;

        struct goldfish_VkDescriptorSetLayout* setLayout = as_goldfish_VkDescriptorSetLayout(descriptorSetLayout);

        if (0 == --setLayout->layoutInfo->refcount) {
            VkEncoder* enc = (VkEncoder*)context;
            enc->vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator, true /* do lock */);
        }
    }

    void on_vkDestroyDescriptorSetLayout(
        void* context,
        VkDevice device,
        VkDescriptorSetLayout descriptorSetLayout,
        const VkAllocationCallbacks* pAllocator) {
        decDescriptorSetLayoutRef(context, device, descriptorSetLayout, pAllocator);
    }

    VkResult on_vkAllocateCommandBuffers(
        void* context,
        VkResult input_result,
        VkDevice device,
        const VkCommandBufferAllocateInfo* pAllocateInfo,
        VkCommandBuffer* pCommandBuffers) {

        (void)input_result;

        VkEncoder* enc = (VkEncoder*)context;
        VkResult res = enc->vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers, true /* do lock */);
        if (VK_SUCCESS != res) return res;

        for (uint32_t i = 0; i < pAllocateInfo->commandBufferCount; ++i) {
            struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(pCommandBuffers[i]);
            cb->isSecondary = pAllocateInfo->level == VK_COMMAND_BUFFER_LEVEL_SECONDARY;
        }

        return res;
    }

    uint32_t getApiVersionFromInstance(VkInstance instance) const {
        AutoLock lock(mLock);
        uint32_t api = kDefaultApiVersion;

        auto it = info_VkInstance.find(instance);
        if (it == info_VkInstance.end()) return api;

        api = it->second.highestApiVersion;

        return api;
    }

    uint32_t getApiVersionFromDevice(VkDevice device) const {
        AutoLock lock(mLock);

        uint32_t api = kDefaultApiVersion;

        auto it = info_VkDevice.find(device);
        if (it == info_VkDevice.end()) return api;

        api = it->second.apiVersion;

        return api;
    }

    bool hasInstanceExtension(VkInstance instance, const std::string& name) const {
        AutoLock lock(mLock);

        auto it = info_VkInstance.find(instance);
        if (it == info_VkInstance.end()) return false;

        return it->second.enabledExtensions.find(name) !=
               it->second.enabledExtensions.end();
    }

    bool hasDeviceExtension(VkDevice device, const std::string& name) const {
        AutoLock lock(mLock);

        auto it = info_VkDevice.find(device);
        if (it == info_VkDevice.end()) return false;

        return it->second.enabledExtensions.find(name) !=
               it->second.enabledExtensions.end();
    }

    // Resets staging stream for this command buffer and primary command buffers
    // where this command buffer has been recorded.
    void resetCommandBufferStagingInfo(VkCommandBuffer commandBuffer, bool alsoResetPrimaries, bool alsoClearPendingDescriptorSets) {
        struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(commandBuffer);
        if (!cb) {
            return;
        }
        if (cb->privateEncoder) {
            sStaging.pushStaging((CommandBufferStagingStream*)cb->privateStream, cb->privateEncoder);
            cb->privateEncoder = nullptr;
            cb->privateStream = nullptr;
        }

        if (alsoClearPendingDescriptorSets && cb->userPtr) {
            CommandBufferPendingDescriptorSets* pendingSets = (CommandBufferPendingDescriptorSets*)cb->userPtr;
            pendingSets->sets.clear();
        }

        if (alsoResetPrimaries) {
            forAllObjects(cb->superObjects, [this, alsoResetPrimaries, alsoClearPendingDescriptorSets](void* obj) {
                VkCommandBuffer superCommandBuffer = (VkCommandBuffer)obj;
                struct goldfish_VkCommandBuffer* superCb = as_goldfish_VkCommandBuffer(superCommandBuffer);
                this->resetCommandBufferStagingInfo(superCommandBuffer, alsoResetPrimaries, alsoClearPendingDescriptorSets);
            });
            eraseObjects(&cb->superObjects);
        }

        forAllObjects(cb->subObjects, [cb](void* obj) {
            VkCommandBuffer subCommandBuffer = (VkCommandBuffer)obj;
            struct goldfish_VkCommandBuffer* subCb = as_goldfish_VkCommandBuffer(subCommandBuffer);
            // We don't do resetCommandBufferStagingInfo(subCommandBuffer)
            // since the user still might have submittable stuff pending there.
            eraseObject(&subCb->superObjects, (void*)cb);
        });

        eraseObjects(&cb->subObjects);
    }

    void resetCommandPoolStagingInfo(VkCommandPool commandPool) {
        struct goldfish_VkCommandPool* p = as_goldfish_VkCommandPool(commandPool);

        if (!p) return;

        forAllObjects(p->subObjects, [this](void* commandBuffer) {
            this->resetCommandBufferStagingInfo((VkCommandBuffer)commandBuffer, true /* also reset primaries */, true /* also clear pending descriptor sets */);
        });
    }

    void addToCommandPool(VkCommandPool commandPool,
                          uint32_t commandBufferCount,
                          VkCommandBuffer* pCommandBuffers) {
        for (uint32_t i = 0; i < commandBufferCount; ++i) {
            struct goldfish_VkCommandPool* p = as_goldfish_VkCommandPool(commandPool);
            struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(pCommandBuffers[i]);
            appendObject(&p->subObjects, (void*)(pCommandBuffers[i]));
            appendObject(&cb->poolObjects, (void*)commandPool);
        }
    }

    void clearCommandPool(VkCommandPool commandPool) {
        resetCommandPoolStagingInfo(commandPool);
        struct goldfish_VkCommandPool* p = as_goldfish_VkCommandPool(commandPool);
        forAllObjects(p->subObjects, [this](void* commandBuffer) {
            this->unregister_VkCommandBuffer((VkCommandBuffer)commandBuffer);
        });
        eraseObjects(&p->subObjects);
    }

private:
    mutable RecursiveLock mLock;
    HostVisibleMemoryVirtualizationInfo mHostVisibleMemoryVirtInfo;
    std::unique_ptr<EmulatorFeatureInfo> mFeatureInfo;
    std::unique_ptr<GoldfishAddressSpaceBlockProvider> mGoldfishAddressSpaceBlockProvider;

    std::vector<VkExtensionProperties> mHostInstanceExtensions;
    std::vector<VkExtensionProperties> mHostDeviceExtensions;

    int mSyncDeviceFd = -1;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    int mRendernodeFd = -1;
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
    std::unique_ptr<
        fidl::WireSyncClient<fuchsia_hardware_goldfish::ControlDevice>>
        mControlDevice;
    std::unique_ptr<fidl::WireSyncClient<fuchsia_sysmem::Allocator>>
        mSysmemAllocator;
#endif

    WorkPool mWorkPool { 4 };
    std::unordered_map<VkQueue, std::vector<WorkPool::WaitGroupHandle>>
        mQueueSensitiveWorkPoolItems;

    std::unordered_map<const VkEncoder*, std::unordered_map<void*, CleanupCallback>> mEncoderCleanupCallbacks;

};

ResourceTracker::ResourceTracker() : mImpl(new ResourceTracker::Impl()) { }
ResourceTracker::~ResourceTracker() { }
VulkanHandleMapping* ResourceTracker::createMapping() {
    return &mImpl->createMapping;
}
VulkanHandleMapping* ResourceTracker::unwrapMapping() {
    return &mImpl->unwrapMapping;
}
VulkanHandleMapping* ResourceTracker::destroyMapping() {
    return &mImpl->destroyMapping;
}
VulkanHandleMapping* ResourceTracker::defaultMapping() {
    return &mImpl->defaultMapping;
}
static ResourceTracker* sTracker = nullptr;
// static
ResourceTracker* ResourceTracker::get() {
    if (!sTracker) {
        // To be initialized once on vulkan device open.
        sTracker = new ResourceTracker;
    }
    return sTracker;
}

#define HANDLE_REGISTER_IMPL(type) \
    void ResourceTracker::register_##type(type obj) { \
        mImpl->register_##type(obj); \
    } \
    void ResourceTracker::unregister_##type(type obj) { \
        mImpl->unregister_##type(obj); \
    } \

GOLDFISH_VK_LIST_HANDLE_TYPES(HANDLE_REGISTER_IMPL)

bool ResourceTracker::isMemoryTypeHostVisible(
    VkDevice device, uint32_t typeIndex) const {
    return mImpl->isMemoryTypeHostVisible(device, typeIndex);
}

uint8_t* ResourceTracker::getMappedPointer(VkDeviceMemory memory) {
    return mImpl->getMappedPointer(memory);
}

VkDeviceSize ResourceTracker::getMappedSize(VkDeviceMemory memory) {
    return mImpl->getMappedSize(memory);
}

VkDeviceSize ResourceTracker::getNonCoherentExtendedSize(VkDevice device, VkDeviceSize basicSize) const {
    return mImpl->getNonCoherentExtendedSize(device, basicSize);
}

bool ResourceTracker::isValidMemoryRange(const VkMappedMemoryRange& range) const {
    return mImpl->isValidMemoryRange(range);
}

void ResourceTracker::setupFeatures(const EmulatorFeatureInfo* features) {
    mImpl->setupFeatures(features);
}

void ResourceTracker::setThreadingCallbacks(const ResourceTracker::ThreadingCallbacks& callbacks) {
    mImpl->setThreadingCallbacks(callbacks);
}

bool ResourceTracker::hostSupportsVulkan() const {
    return mImpl->hostSupportsVulkan();
}

bool ResourceTracker::usingDirectMapping() const {
    return mImpl->usingDirectMapping();
}

uint32_t ResourceTracker::getStreamFeatures() const {
    return mImpl->getStreamFeatures();
}

uint32_t ResourceTracker::getApiVersionFromInstance(VkInstance instance) const {
    return mImpl->getApiVersionFromInstance(instance);
}

uint32_t ResourceTracker::getApiVersionFromDevice(VkDevice device) const {
    return mImpl->getApiVersionFromDevice(device);
}
bool ResourceTracker::hasInstanceExtension(VkInstance instance, const std::string &name) const {
    return mImpl->hasInstanceExtension(instance, name);
}
bool ResourceTracker::hasDeviceExtension(VkDevice device, const std::string &name) const {
    return mImpl->hasDeviceExtension(device, name);
}
void ResourceTracker::addToCommandPool(VkCommandPool commandPool,
                      uint32_t commandBufferCount,
                      VkCommandBuffer* pCommandBuffers) {
    mImpl->addToCommandPool(commandPool, commandBufferCount, pCommandBuffers);
}
void ResourceTracker::resetCommandPoolStagingInfo(VkCommandPool commandPool) {
    mImpl->resetCommandPoolStagingInfo(commandPool);
}


// static
__attribute__((always_inline)) VkEncoder* ResourceTracker::getCommandBufferEncoder(VkCommandBuffer commandBuffer) {
    if (!(ResourceTracker::streamFeatureBits & VULKAN_STREAM_FEATURE_QUEUE_SUBMIT_WITH_COMMANDS_BIT)) {
        auto enc = ResourceTracker::getThreadLocalEncoder();
        ResourceTracker::get()->syncEncodersForCommandBuffer(commandBuffer, enc);
        return enc;
    }

    struct goldfish_VkCommandBuffer* cb = as_goldfish_VkCommandBuffer(commandBuffer);
    if (!cb->privateEncoder) {
        sStaging.popStaging((CommandBufferStagingStream**)&cb->privateStream, &cb->privateEncoder);
    }
    uint8_t* writtenPtr; size_t written;
    ((CommandBufferStagingStream*)cb->privateStream)->getWritten(&writtenPtr, &written);
    return cb->privateEncoder;
}

// static
__attribute__((always_inline)) VkEncoder* ResourceTracker::getQueueEncoder(VkQueue queue) {
    auto enc = ResourceTracker::getThreadLocalEncoder();
    if (!(ResourceTracker::streamFeatureBits & VULKAN_STREAM_FEATURE_QUEUE_SUBMIT_WITH_COMMANDS_BIT)) {
        ResourceTracker::get()->syncEncodersForQueue(queue, enc);
    }
    return enc;
}

// static
__attribute__((always_inline)) VkEncoder* ResourceTracker::getThreadLocalEncoder() {
    auto hostConn = ResourceTracker::threadingCallbacks.hostConnectionGetFunc();
    auto vkEncoder = ResourceTracker::threadingCallbacks.vkEncoderGetFunc(hostConn);
    return vkEncoder;
}

// static
void ResourceTracker::setSeqnoPtr(uint32_t* seqnoptr) {
    sSeqnoPtr = seqnoptr;
}

// static
__attribute__((always_inline)) uint32_t ResourceTracker::nextSeqno() {
    uint32_t res = __atomic_add_fetch(sSeqnoPtr, 1, __ATOMIC_SEQ_CST);
    return res;
}

// static
__attribute__((always_inline)) uint32_t ResourceTracker::getSeqno() {
    uint32_t res = __atomic_load_n(sSeqnoPtr, __ATOMIC_SEQ_CST);
    return res;
}

VkResult ResourceTracker::on_vkEnumerateInstanceExtensionProperties(
    void* context,
    VkResult input_result,
    const char* pLayerName,
    uint32_t* pPropertyCount,
    VkExtensionProperties* pProperties) {
    return mImpl->on_vkEnumerateInstanceExtensionProperties(
        context, input_result, pLayerName, pPropertyCount, pProperties);
}

VkResult ResourceTracker::on_vkEnumerateDeviceExtensionProperties(
    void* context,
    VkResult input_result,
    VkPhysicalDevice physicalDevice,
    const char* pLayerName,
    uint32_t* pPropertyCount,
    VkExtensionProperties* pProperties) {
    return mImpl->on_vkEnumerateDeviceExtensionProperties(
        context, input_result, physicalDevice, pLayerName, pPropertyCount, pProperties);
}

VkResult ResourceTracker::on_vkEnumeratePhysicalDevices(
    void* context, VkResult input_result,
    VkInstance instance, uint32_t* pPhysicalDeviceCount,
    VkPhysicalDevice* pPhysicalDevices) {
    return mImpl->on_vkEnumeratePhysicalDevices(
        context, input_result, instance, pPhysicalDeviceCount,
        pPhysicalDevices);
}

void ResourceTracker::on_vkGetPhysicalDeviceProperties(
    void* context,
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceProperties* pProperties) {
    mImpl->on_vkGetPhysicalDeviceProperties(context, physicalDevice,
        pProperties);
}

void ResourceTracker::on_vkGetPhysicalDeviceProperties2(
    void* context,
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceProperties2* pProperties) {
    mImpl->on_vkGetPhysicalDeviceProperties2(context, physicalDevice,
        pProperties);
}

void ResourceTracker::on_vkGetPhysicalDeviceProperties2KHR(
    void* context,
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceProperties2* pProperties) {
    mImpl->on_vkGetPhysicalDeviceProperties2(context, physicalDevice,
        pProperties);
}

void ResourceTracker::on_vkGetPhysicalDeviceMemoryProperties(
    void* context,
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceMemoryProperties* pMemoryProperties) {
    mImpl->on_vkGetPhysicalDeviceMemoryProperties(
        context, physicalDevice, pMemoryProperties);
}

void ResourceTracker::on_vkGetPhysicalDeviceMemoryProperties2(
    void* context,
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
    mImpl->on_vkGetPhysicalDeviceMemoryProperties2(
        context, physicalDevice, pMemoryProperties);
}

void ResourceTracker::on_vkGetPhysicalDeviceMemoryProperties2KHR(
    void* context,
    VkPhysicalDevice physicalDevice,
    VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
    mImpl->on_vkGetPhysicalDeviceMemoryProperties2(
        context, physicalDevice, pMemoryProperties);
}

void ResourceTracker::on_vkGetDeviceQueue(void* context,
                                          VkDevice device,
                                          uint32_t queueFamilyIndex,
                                          uint32_t queueIndex,
                                          VkQueue* pQueue) {
    mImpl->on_vkGetDeviceQueue(context, device, queueFamilyIndex, queueIndex,
                               pQueue);
}

void ResourceTracker::on_vkGetDeviceQueue2(void* context,
                                           VkDevice device,
                                           const VkDeviceQueueInfo2* pQueueInfo,
                                           VkQueue* pQueue) {
    mImpl->on_vkGetDeviceQueue2(context, device, pQueueInfo, pQueue);
}

VkResult ResourceTracker::on_vkCreateInstance(
    void* context,
    VkResult input_result,
    const VkInstanceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance* pInstance) {
    return mImpl->on_vkCreateInstance(
        context, input_result, pCreateInfo, pAllocator, pInstance);
}

VkResult ResourceTracker::on_vkCreateDevice(
    void* context,
    VkResult input_result,
    VkPhysicalDevice physicalDevice,
    const VkDeviceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDevice* pDevice) {
    return mImpl->on_vkCreateDevice(
        context, input_result, physicalDevice, pCreateInfo, pAllocator, pDevice);
}

void ResourceTracker::on_vkDestroyDevice_pre(
    void* context,
    VkDevice device,
    const VkAllocationCallbacks* pAllocator) {
    mImpl->on_vkDestroyDevice_pre(context, device, pAllocator);
}

VkResult ResourceTracker::on_vkAllocateMemory(
    void* context,
    VkResult input_result,
    VkDevice device,
    const VkMemoryAllocateInfo* pAllocateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDeviceMemory* pMemory) {
    return mImpl->on_vkAllocateMemory(
        context, input_result, device, pAllocateInfo, pAllocator, pMemory);
}

void ResourceTracker::on_vkFreeMemory(
    void* context,
    VkDevice device,
    VkDeviceMemory memory,
    const VkAllocationCallbacks* pAllocator) {
    return mImpl->on_vkFreeMemory(
        context, device, memory, pAllocator);
}

VkResult ResourceTracker::on_vkMapMemory(
    void* context,
    VkResult input_result,
    VkDevice device,
    VkDeviceMemory memory,
    VkDeviceSize offset,
    VkDeviceSize size,
    VkMemoryMapFlags flags,
    void** ppData) {
    return mImpl->on_vkMapMemory(
        context, input_result, device, memory, offset, size, flags, ppData);
}

void ResourceTracker::on_vkUnmapMemory(
    void* context,
    VkDevice device,
    VkDeviceMemory memory) {
    mImpl->on_vkUnmapMemory(context, device, memory);
}

VkResult ResourceTracker::on_vkCreateImage(
    void* context, VkResult input_result,
    VkDevice device, const VkImageCreateInfo *pCreateInfo,
    const VkAllocationCallbacks *pAllocator,
    VkImage *pImage) {
    return mImpl->on_vkCreateImage(
        context, input_result,
        device, pCreateInfo, pAllocator, pImage);
}

void ResourceTracker::on_vkDestroyImage(
    void* context,
    VkDevice device, VkImage image, const VkAllocationCallbacks *pAllocator) {
    mImpl->on_vkDestroyImage(context,
        device, image, pAllocator);
}

void ResourceTracker::on_vkGetImageMemoryRequirements(
    void *context, VkDevice device, VkImage image,
    VkMemoryRequirements *pMemoryRequirements) {
    mImpl->on_vkGetImageMemoryRequirements(
        context, device, image, pMemoryRequirements);
}

void ResourceTracker::on_vkGetImageMemoryRequirements2(
    void *context, VkDevice device, const VkImageMemoryRequirementsInfo2 *pInfo,
    VkMemoryRequirements2 *pMemoryRequirements) {
    mImpl->on_vkGetImageMemoryRequirements2(
        context, device, pInfo, pMemoryRequirements);
}

void ResourceTracker::on_vkGetImageMemoryRequirements2KHR(
    void *context, VkDevice device, const VkImageMemoryRequirementsInfo2 *pInfo,
    VkMemoryRequirements2 *pMemoryRequirements) {
    mImpl->on_vkGetImageMemoryRequirements2KHR(
        context, device, pInfo, pMemoryRequirements);
}

VkResult ResourceTracker::on_vkBindImageMemory(
    void* context, VkResult input_result,
    VkDevice device, VkImage image, VkDeviceMemory memory,
    VkDeviceSize memoryOffset) {
    return mImpl->on_vkBindImageMemory(
        context, input_result, device, image, memory, memoryOffset);
}

VkResult ResourceTracker::on_vkBindImageMemory2(
    void* context, VkResult input_result,
    VkDevice device, uint32_t bindingCount, const VkBindImageMemoryInfo* pBindInfos) {
    return mImpl->on_vkBindImageMemory2(
        context, input_result, device, bindingCount, pBindInfos);
}

VkResult ResourceTracker::on_vkBindImageMemory2KHR(
    void* context, VkResult input_result,
    VkDevice device, uint32_t bindingCount, const VkBindImageMemoryInfo* pBindInfos) {
    return mImpl->on_vkBindImageMemory2KHR(
        context, input_result, device, bindingCount, pBindInfos);
}

VkResult ResourceTracker::on_vkCreateBuffer(
    void* context, VkResult input_result,
    VkDevice device, const VkBufferCreateInfo *pCreateInfo,
    const VkAllocationCallbacks *pAllocator,
    VkBuffer *pBuffer) {
    return mImpl->on_vkCreateBuffer(
        context, input_result,
        device, pCreateInfo, pAllocator, pBuffer);
}

void ResourceTracker::on_vkDestroyBuffer(
    void* context,
    VkDevice device, VkBuffer buffer, const VkAllocationCallbacks *pAllocator) {
    mImpl->on_vkDestroyBuffer(context, device, buffer, pAllocator);
}

void ResourceTracker::on_vkGetBufferMemoryRequirements(
    void* context, VkDevice device, VkBuffer buffer, VkMemoryRequirements *pMemoryRequirements) {
    mImpl->on_vkGetBufferMemoryRequirements(context, device, buffer, pMemoryRequirements);
}

void ResourceTracker::on_vkGetBufferMemoryRequirements2(
    void* context, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
    VkMemoryRequirements2* pMemoryRequirements) {
    mImpl->on_vkGetBufferMemoryRequirements2(
        context, device, pInfo, pMemoryRequirements);
}

void ResourceTracker::on_vkGetBufferMemoryRequirements2KHR(
    void* context, VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo,
    VkMemoryRequirements2* pMemoryRequirements) {
    mImpl->on_vkGetBufferMemoryRequirements2KHR(
        context, device, pInfo, pMemoryRequirements);
}

VkResult ResourceTracker::on_vkBindBufferMemory(
    void* context, VkResult input_result,
    VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    return mImpl->on_vkBindBufferMemory(
        context, input_result,
        device, buffer, memory, memoryOffset);
}

VkResult ResourceTracker::on_vkBindBufferMemory2(
    void* context, VkResult input_result,
    VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo *pBindInfos) {
    return mImpl->on_vkBindBufferMemory2(
        context, input_result,
        device, bindInfoCount, pBindInfos);
}

VkResult ResourceTracker::on_vkBindBufferMemory2KHR(
    void* context, VkResult input_result,
    VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo *pBindInfos) {
    return mImpl->on_vkBindBufferMemory2KHR(
        context, input_result,
        device, bindInfoCount, pBindInfos);
}

VkResult ResourceTracker::on_vkCreateSemaphore(
    void* context, VkResult input_result,
    VkDevice device, const VkSemaphoreCreateInfo *pCreateInfo,
    const VkAllocationCallbacks *pAllocator,
    VkSemaphore *pSemaphore) {
    return mImpl->on_vkCreateSemaphore(
        context, input_result,
        device, pCreateInfo, pAllocator, pSemaphore);
}

void ResourceTracker::on_vkDestroySemaphore(
    void* context,
    VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks *pAllocator) {
    mImpl->on_vkDestroySemaphore(context, device, semaphore, pAllocator);
}

VkResult ResourceTracker::on_vkQueueSubmit(
    void* context, VkResult input_result,
    VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    return mImpl->on_vkQueueSubmit(
        context, input_result, queue, submitCount, pSubmits, fence);
}

VkResult ResourceTracker::on_vkQueueWaitIdle(
    void* context, VkResult input_result,
    VkQueue queue) {
    return mImpl->on_vkQueueWaitIdle(context, input_result, queue);
}

VkResult ResourceTracker::on_vkGetSemaphoreFdKHR(
    void* context, VkResult input_result,
    VkDevice device,
    const VkSemaphoreGetFdInfoKHR* pGetFdInfo,
    int* pFd) {
    return mImpl->on_vkGetSemaphoreFdKHR(context, input_result, device, pGetFdInfo, pFd);
}

VkResult ResourceTracker::on_vkImportSemaphoreFdKHR(
    void* context, VkResult input_result,
    VkDevice device,
    const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) {
    return mImpl->on_vkImportSemaphoreFdKHR(context, input_result, device, pImportSemaphoreFdInfo);
}

void ResourceTracker::unwrap_VkNativeBufferANDROID(
    const VkImageCreateInfo* pCreateInfo,
    VkImageCreateInfo* local_pCreateInfo) {
    mImpl->unwrap_VkNativeBufferANDROID(pCreateInfo, local_pCreateInfo);
}

void ResourceTracker::unwrap_vkAcquireImageANDROID_nativeFenceFd(int fd, int* fd_out) {
    mImpl->unwrap_vkAcquireImageANDROID_nativeFenceFd(fd, fd_out);
}

#ifdef VK_USE_PLATFORM_FUCHSIA
VkResult ResourceTracker::on_vkGetMemoryZirconHandleFUCHSIA(
    void* context, VkResult input_result,
    VkDevice device,
    const VkMemoryGetZirconHandleInfoFUCHSIA* pInfo,
    uint32_t* pHandle) {
    return mImpl->on_vkGetMemoryZirconHandleFUCHSIA(
        context, input_result, device, pInfo, pHandle);
}

VkResult ResourceTracker::on_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    void* context, VkResult input_result,
    VkDevice device,
    VkExternalMemoryHandleTypeFlagBits handleType,
    uint32_t handle,
    VkMemoryZirconHandlePropertiesFUCHSIA* pProperties) {
    return mImpl->on_vkGetMemoryZirconHandlePropertiesFUCHSIA(
        context, input_result, device, handleType, handle, pProperties);
}

VkResult ResourceTracker::on_vkGetSemaphoreZirconHandleFUCHSIA(
    void* context, VkResult input_result,
    VkDevice device,
    const VkSemaphoreGetZirconHandleInfoFUCHSIA* pInfo,
    uint32_t* pHandle) {
    return mImpl->on_vkGetSemaphoreZirconHandleFUCHSIA(
        context, input_result, device, pInfo, pHandle);
}

VkResult ResourceTracker::on_vkImportSemaphoreZirconHandleFUCHSIA(
    void* context, VkResult input_result,
    VkDevice device,
    const VkImportSemaphoreZirconHandleInfoFUCHSIA* pInfo) {
    return mImpl->on_vkImportSemaphoreZirconHandleFUCHSIA(
        context, input_result, device, pInfo);
}

VkResult ResourceTracker::on_vkCreateBufferCollectionFUCHSIA(
    void* context, VkResult input_result,
    VkDevice device,
    const VkBufferCollectionCreateInfoFUCHSIA* pInfo,
    const VkAllocationCallbacks* pAllocator,
    VkBufferCollectionFUCHSIA* pCollection) {
    return mImpl->on_vkCreateBufferCollectionFUCHSIA(
        context, input_result, device, pInfo, pAllocator, pCollection);
}

void ResourceTracker::on_vkDestroyBufferCollectionFUCHSIA(
        void* context, VkResult input_result,
        VkDevice device,
        VkBufferCollectionFUCHSIA collection,
        const VkAllocationCallbacks* pAllocator) {
    return mImpl->on_vkDestroyBufferCollectionFUCHSIA(
        context, input_result, device, collection, pAllocator);
}

VkResult ResourceTracker::on_vkSetBufferCollectionConstraintsFUCHSIA(
        void* context, VkResult input_result,
        VkDevice device,
        VkBufferCollectionFUCHSIA collection,
        const VkImageCreateInfo* pImageInfo) {
    return mImpl->on_vkSetBufferCollectionConstraintsFUCHSIA(
        context, input_result, device, collection, pImageInfo);
}

VkResult ResourceTracker::on_vkSetBufferCollectionBufferConstraintsFUCHSIA(
        void* context, VkResult input_result,
        VkDevice device,
        VkBufferCollectionFUCHSIA collection,
        const VkBufferConstraintsInfoFUCHSIA* pBufferDConstraintsInfo) {
    return mImpl->on_vkSetBufferCollectionBufferConstraintsFUCHSIA(
        context, input_result, device, collection, pBufferDConstraintsInfo);
}

VkResult ResourceTracker::on_vkSetBufferCollectionImageConstraintsFUCHSIA(
    void* context,
    VkResult input_result,
    VkDevice device,
    VkBufferCollectionFUCHSIA collection,
    const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) {
    return mImpl->on_vkSetBufferCollectionImageConstraintsFUCHSIA(
        context, input_result, device, collection, pImageConstraintsInfo);
}

VkResult ResourceTracker::on_vkGetBufferCollectionPropertiesFUCHSIA(
        void* context, VkResult input_result,
        VkDevice device,
        VkBufferCollectionFUCHSIA collection,
        VkBufferCollectionPropertiesFUCHSIA* pProperties) {
    return mImpl->on_vkGetBufferCollectionPropertiesFUCHSIA(
        context, input_result, device, collection, pProperties);
}

VkResult ResourceTracker::on_vkGetBufferCollectionProperties2FUCHSIA(
    void* context,
    VkResult input_result,
    VkDevice device,
    VkBufferCollectionFUCHSIA collection,
    VkBufferCollectionProperties2FUCHSIA* pProperties) {
    return mImpl->on_vkGetBufferCollectionProperties2FUCHSIA(
        context, input_result, device, collection, pProperties);
}
#endif

VkResult ResourceTracker::on_vkGetAndroidHardwareBufferPropertiesANDROID(
    void* context, VkResult input_result,
    VkDevice device,
    const AHardwareBuffer* buffer,
    VkAndroidHardwareBufferPropertiesANDROID* pProperties) {
    return mImpl->on_vkGetAndroidHardwareBufferPropertiesANDROID(
        context, input_result, device, buffer, pProperties);
}
VkResult ResourceTracker::on_vkGetMemoryAndroidHardwareBufferANDROID(
    void* context, VkResult input_result,
    VkDevice device,
    const VkMemoryGetAndroidHardwareBufferInfoANDROID *pInfo,
    struct AHardwareBuffer** pBuffer) {
    return mImpl->on_vkGetMemoryAndroidHardwareBufferANDROID(
        context, input_result,
        device, pInfo, pBuffer);
}

VkResult ResourceTracker::on_vkCreateSamplerYcbcrConversion(
    void* context, VkResult input_result,
    VkDevice device,
    const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkSamplerYcbcrConversion* pYcbcrConversion) {
    return mImpl->on_vkCreateSamplerYcbcrConversion(
        context, input_result, device, pCreateInfo, pAllocator, pYcbcrConversion);
}

void ResourceTracker::on_vkDestroySamplerYcbcrConversion(
    void* context,
    VkDevice device,
    VkSamplerYcbcrConversion ycbcrConversion,
    const VkAllocationCallbacks* pAllocator) {
    mImpl->on_vkDestroySamplerYcbcrConversion(
        context, device, ycbcrConversion, pAllocator);
}

VkResult ResourceTracker::on_vkCreateSamplerYcbcrConversionKHR(
    void* context, VkResult input_result,
    VkDevice device,
    const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkSamplerYcbcrConversion* pYcbcrConversion) {
    return mImpl->on_vkCreateSamplerYcbcrConversionKHR(
        context, input_result, device, pCreateInfo, pAllocator, pYcbcrConversion);
}

void ResourceTracker::on_vkDestroySamplerYcbcrConversionKHR(
    void* context,
    VkDevice device,
    VkSamplerYcbcrConversion ycbcrConversion,
    const VkAllocationCallbacks* pAllocator) {
    mImpl->on_vkDestroySamplerYcbcrConversionKHR(
        context, device, ycbcrConversion, pAllocator);
}

VkResult ResourceTracker::on_vkCreateSampler(
    void* context, VkResult input_result,
    VkDevice device,
    const VkSamplerCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkSampler* pSampler) {
    return mImpl->on_vkCreateSampler(
        context, input_result, device, pCreateInfo, pAllocator, pSampler);
}

void ResourceTracker::on_vkGetPhysicalDeviceExternalFenceProperties(
    void* context,
    VkPhysicalDevice physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
    VkExternalFenceProperties* pExternalFenceProperties) {
    mImpl->on_vkGetPhysicalDeviceExternalFenceProperties(
        context, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

void ResourceTracker::on_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    void* context,
    VkPhysicalDevice physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
    VkExternalFenceProperties* pExternalFenceProperties) {
    mImpl->on_vkGetPhysicalDeviceExternalFenceProperties(
        context, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VkResult ResourceTracker::on_vkCreateFence(
    void* context,
    VkResult input_result,
    VkDevice device,
    const VkFenceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    return mImpl->on_vkCreateFence(
        context, input_result, device, pCreateInfo, pAllocator, pFence);
}

void ResourceTracker::on_vkDestroyFence(
    void* context,
    VkDevice device,
    VkFence fence,
    const VkAllocationCallbacks* pAllocator) {
    mImpl->on_vkDestroyFence(
        context, device, fence, pAllocator);
}

VkResult ResourceTracker::on_vkResetFences(
    void* context,
    VkResult input_result,
    VkDevice device,
    uint32_t fenceCount,
    const VkFence* pFences) {
    return mImpl->on_vkResetFences(
        context, input_result, device, fenceCount, pFences);
}

VkResult ResourceTracker::on_vkImportFenceFdKHR(
    void* context,
    VkResult input_result,
    VkDevice device,
    const VkImportFenceFdInfoKHR* pImportFenceFdInfo) {
    return mImpl->on_vkImportFenceFdKHR(
        context, input_result, device, pImportFenceFdInfo);
}

VkResult ResourceTracker::on_vkGetFenceFdKHR(
    void* context,
    VkResult input_result,
    VkDevice device,
    const VkFenceGetFdInfoKHR* pGetFdInfo,
    int* pFd) {
    return mImpl->on_vkGetFenceFdKHR(
        context, input_result, device, pGetFdInfo, pFd);
}

VkResult ResourceTracker::on_vkWaitForFences(
    void* context,
    VkResult input_result,
    VkDevice device,
    uint32_t fenceCount,
    const VkFence* pFences,
    VkBool32 waitAll,
    uint64_t timeout) {
    return mImpl->on_vkWaitForFences(
        context, input_result, device, fenceCount, pFences, waitAll, timeout);
}

VkResult ResourceTracker::on_vkCreateDescriptorPool(
    void* context,
    VkResult input_result,
    VkDevice device,
    const VkDescriptorPoolCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDescriptorPool* pDescriptorPool) {
    return mImpl->on_vkCreateDescriptorPool(
        context, input_result, device, pCreateInfo, pAllocator, pDescriptorPool);
}

void ResourceTracker::on_vkDestroyDescriptorPool(
    void* context,
    VkDevice device,
    VkDescriptorPool descriptorPool,
    const VkAllocationCallbacks* pAllocator) {
    mImpl->on_vkDestroyDescriptorPool(context, device, descriptorPool, pAllocator);
}

VkResult ResourceTracker::on_vkResetDescriptorPool(
    void* context,
    VkResult input_result,
    VkDevice device,
    VkDescriptorPool descriptorPool,
    VkDescriptorPoolResetFlags flags) {
    return mImpl->on_vkResetDescriptorPool(
        context, input_result, device, descriptorPool, flags);
}

VkResult ResourceTracker::on_vkAllocateDescriptorSets(
    void* context,
    VkResult input_result,
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets) {
    return mImpl->on_vkAllocateDescriptorSets(
        context, input_result, device, pAllocateInfo, pDescriptorSets);
}

VkResult ResourceTracker::on_vkFreeDescriptorSets(
    void* context,
    VkResult input_result,
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets) {
    return mImpl->on_vkFreeDescriptorSets(
        context, input_result, device, descriptorPool, descriptorSetCount, pDescriptorSets);
}

VkResult ResourceTracker::on_vkCreateDescriptorSetLayout(
    void* context,
    VkResult input_result,
    VkDevice device,
    const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDescriptorSetLayout* pSetLayout) {
    return mImpl->on_vkCreateDescriptorSetLayout(
        context, input_result, device, pCreateInfo, pAllocator, pSetLayout);
}

void ResourceTracker::on_vkUpdateDescriptorSets(
    void* context,
    VkDevice device,
    uint32_t descriptorWriteCount,
    const VkWriteDescriptorSet* pDescriptorWrites,
    uint32_t descriptorCopyCount,
    const VkCopyDescriptorSet* pDescriptorCopies) {
    return mImpl->on_vkUpdateDescriptorSets(
        context, device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VkResult ResourceTracker::on_vkMapMemoryIntoAddressSpaceGOOGLE_pre(
    void* context,
    VkResult input_result,
    VkDevice device,
    VkDeviceMemory memory,
    uint64_t* pAddress) {
    return mImpl->on_vkMapMemoryIntoAddressSpaceGOOGLE_pre(
        context, input_result, device, memory, pAddress);
}

VkResult ResourceTracker::on_vkMapMemoryIntoAddressSpaceGOOGLE(
    void* context,
    VkResult input_result,
    VkDevice device,
    VkDeviceMemory memory,
    uint64_t* pAddress) {
    return mImpl->on_vkMapMemoryIntoAddressSpaceGOOGLE(
        context, input_result, device, memory, pAddress);
}

VkResult ResourceTracker::on_vkCreateDescriptorUpdateTemplate(
    void* context, VkResult input_result,
    VkDevice device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
    return mImpl->on_vkCreateDescriptorUpdateTemplate(
        context, input_result,
        device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
}

VkResult ResourceTracker::on_vkCreateDescriptorUpdateTemplateKHR(
    void* context, VkResult input_result,
    VkDevice device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
    return mImpl->on_vkCreateDescriptorUpdateTemplateKHR(
        context, input_result,
        device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
}

void ResourceTracker::on_vkUpdateDescriptorSetWithTemplate(
    void* context,
    VkDevice device,
    VkDescriptorSet descriptorSet,
    VkDescriptorUpdateTemplate descriptorUpdateTemplate,
    const void* pData) {
    mImpl->on_vkUpdateDescriptorSetWithTemplate(
        context, device, descriptorSet,
        descriptorUpdateTemplate, pData);
}

VkResult ResourceTracker::on_vkGetPhysicalDeviceImageFormatProperties2(
    void* context, VkResult input_result,
    VkPhysicalDevice physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
    VkImageFormatProperties2* pImageFormatProperties) {
    return mImpl->on_vkGetPhysicalDeviceImageFormatProperties2(
        context, input_result, physicalDevice, pImageFormatInfo,
        pImageFormatProperties);
}

VkResult ResourceTracker::on_vkGetPhysicalDeviceImageFormatProperties2KHR(
    void* context, VkResult input_result,
    VkPhysicalDevice physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
    VkImageFormatProperties2* pImageFormatProperties) {
    return mImpl->on_vkGetPhysicalDeviceImageFormatProperties2KHR(
        context, input_result, physicalDevice, pImageFormatInfo,
        pImageFormatProperties);
}

void ResourceTracker::on_vkGetPhysicalDeviceExternalSemaphoreProperties(
    void* context,
    VkPhysicalDevice physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
    mImpl->on_vkGetPhysicalDeviceExternalSemaphoreProperties(
        context, physicalDevice, pExternalSemaphoreInfo,
        pExternalSemaphoreProperties);
}

void ResourceTracker::on_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    void* context,
    VkPhysicalDevice physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
    mImpl->on_vkGetPhysicalDeviceExternalSemaphoreProperties(
        context, physicalDevice, pExternalSemaphoreInfo,
        pExternalSemaphoreProperties);
}

void ResourceTracker::registerEncoderCleanupCallback(const VkEncoder* encoder, void* handle, ResourceTracker::CleanupCallback callback) {
    mImpl->registerEncoderCleanupCallback(encoder, handle, callback);
}

void ResourceTracker::unregisterEncoderCleanupCallback(const VkEncoder* encoder, void* handle) {
    mImpl->unregisterEncoderCleanupCallback(encoder, handle);
}

void ResourceTracker::onEncoderDeleted(const VkEncoder* encoder) {
    mImpl->onEncoderDeleted(encoder);
}

uint32_t ResourceTracker::syncEncodersForCommandBuffer(VkCommandBuffer commandBuffer, VkEncoder* current) {
    return mImpl->syncEncodersForCommandBuffer(commandBuffer, current);
}

uint32_t ResourceTracker::syncEncodersForQueue(VkQueue queue, VkEncoder* current) {
    return mImpl->syncEncodersForQueue(queue, current);
}


VkResult ResourceTracker::on_vkBeginCommandBuffer(
    void* context, VkResult input_result,
    VkCommandBuffer commandBuffer,
    const VkCommandBufferBeginInfo* pBeginInfo) {
    return mImpl->on_vkBeginCommandBuffer(
        context, input_result, commandBuffer, pBeginInfo);
}

VkResult ResourceTracker::on_vkEndCommandBuffer(
    void* context, VkResult input_result,
    VkCommandBuffer commandBuffer) {
    return mImpl->on_vkEndCommandBuffer(
        context, input_result, commandBuffer);
}

VkResult ResourceTracker::on_vkResetCommandBuffer(
    void* context, VkResult input_result,
    VkCommandBuffer commandBuffer,
    VkCommandBufferResetFlags flags) {
    return mImpl->on_vkResetCommandBuffer(
        context, input_result, commandBuffer, flags);
}

VkResult ResourceTracker::on_vkCreateImageView(
    void* context, VkResult input_result,
    VkDevice device,
    const VkImageViewCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkImageView* pView) {
    return mImpl->on_vkCreateImageView(
        context, input_result, device, pCreateInfo, pAllocator, pView);
}

void ResourceTracker::on_vkCmdExecuteCommands(
    void* context,
    VkCommandBuffer commandBuffer,
    uint32_t commandBufferCount,
    const VkCommandBuffer* pCommandBuffers) {
    mImpl->on_vkCmdExecuteCommands(
        context, commandBuffer, commandBufferCount, pCommandBuffers);
}

void ResourceTracker::on_vkCmdBindDescriptorSets(
    void* context,
    VkCommandBuffer commandBuffer,
    VkPipelineBindPoint pipelineBindPoint,
    VkPipelineLayout layout,
    uint32_t firstSet,
    uint32_t descriptorSetCount,
    const VkDescriptorSet* pDescriptorSets,
    uint32_t dynamicOffsetCount,
    const uint32_t* pDynamicOffsets) {
    mImpl->on_vkCmdBindDescriptorSets(
        context,
        commandBuffer,
        pipelineBindPoint, 
        layout,
        firstSet,
        descriptorSetCount,
        pDescriptorSets,
        dynamicOffsetCount,
        pDynamicOffsets);
}

void ResourceTracker::on_vkDestroyDescriptorSetLayout(
    void* context,
    VkDevice device,
    VkDescriptorSetLayout descriptorSetLayout,
    const VkAllocationCallbacks* pAllocator) {
    mImpl->on_vkDestroyDescriptorSetLayout(context, device, descriptorSetLayout, pAllocator);
}

VkResult ResourceTracker::on_vkAllocateCommandBuffers(
    void* context,
    VkResult input_result,
    VkDevice device,
    const VkCommandBufferAllocateInfo* pAllocateInfo,
    VkCommandBuffer* pCommandBuffers) {
    return mImpl->on_vkAllocateCommandBuffers(context, input_result, device, pAllocateInfo, pCommandBuffers);
}

void ResourceTracker::deviceMemoryTransform_tohost(
    VkDeviceMemory* memory, uint32_t memoryCount,
    VkDeviceSize* offset, uint32_t offsetCount,
    VkDeviceSize* size, uint32_t sizeCount,
    uint32_t* typeIndex, uint32_t typeIndexCount,
    uint32_t* typeBits, uint32_t typeBitsCount) {
    mImpl->deviceMemoryTransform_tohost(
        memory, memoryCount,
        offset, offsetCount,
        size, sizeCount,
        typeIndex, typeIndexCount,
        typeBits, typeBitsCount);
}

void ResourceTracker::deviceMemoryTransform_fromhost(
    VkDeviceMemory* memory, uint32_t memoryCount,
    VkDeviceSize* offset, uint32_t offsetCount,
    VkDeviceSize* size, uint32_t sizeCount,
    uint32_t* typeIndex, uint32_t typeIndexCount,
    uint32_t* typeBits, uint32_t typeBitsCount) {
    mImpl->deviceMemoryTransform_fromhost(
        memory, memoryCount,
        offset, offsetCount,
        size, sizeCount,
        typeIndex, typeIndexCount,
        typeBits, typeBitsCount);
}

void ResourceTracker::transformImpl_VkExternalMemoryProperties_fromhost(
    VkExternalMemoryProperties* pProperties,
    uint32_t lenAccess) {
    mImpl->transformImpl_VkExternalMemoryProperties_fromhost(pProperties,
                                                             lenAccess);
}

void ResourceTracker::transformImpl_VkExternalMemoryProperties_tohost(
    VkExternalMemoryProperties*, uint32_t) {}

#define DEFINE_TRANSFORMED_TYPE_IMPL(type)                                  \
    void ResourceTracker::transformImpl_##type##_tohost(type*, uint32_t) {} \
    void ResourceTracker::transformImpl_##type##_fromhost(type*, uint32_t) {}

LIST_TRIVIAL_TRANSFORMED_TYPES(DEFINE_TRANSFORMED_TYPE_IMPL)

} // namespace goldfish_vk
