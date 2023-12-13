// Copyright (C) 2018 The Android Open Source Project
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
#pragma once

#include <hardware/hwvulkan.h>
#include <vulkan/vulkan.h>

#include "VulkanHandles.h"

#include <inttypes.h>

#include <functional>

namespace goldfish_vk {
class VkEncoder;
struct DescriptorPoolAllocationInfo;
struct ReifiedDescriptorSet;
struct DescriptorSetLayoutInfo;
} // namespace goldfish_vk

class IOStream;

extern "C" {

struct goldfish_vk_object_list {
    void* obj;
    struct goldfish_vk_object_list* next;
};

#define GOLDFISH_VK_DEFINE_DISPATCHABLE_HANDLE_STRUCT(type) \
    struct goldfish_##type { \
        hwvulkan_dispatch_t dispatch; \
        uint64_t underlying; \
        goldfish_vk::VkEncoder* lastUsedEncoder; \
        uint32_t sequenceNumber; \
        goldfish_vk::VkEncoder* privateEncoder; \
        IOStream* privateStream; \
        uint32_t flags; \
        struct goldfish_vk_object_list* poolObjects; \
        struct goldfish_vk_object_list* subObjects; \
        struct goldfish_vk_object_list* superObjects; \
        void* userPtr; \
    }; \

#define GOLDFISH_VK_DEFINE_TRIVIAL_NON_DISPATCHABLE_HANDLE_STRUCT(type) \
    struct goldfish_##type { \
        uint64_t underlying; \
        struct goldfish_vk_object_list* poolObjects; \
        struct goldfish_vk_object_list* subObjects; \
        struct goldfish_vk_object_list* superObjects; \
        void* userPtr; \
    }; \

#define GOLDFISH_VK_NEW_FROM_HOST_DECL(type) \
    type new_from_host_##type(type);

#define GOLDFISH_VK_AS_GOLDFISH_DECL(type) \
    struct goldfish_##type* as_goldfish_##type(type);

#define GOLDFISH_VK_GET_HOST_DECL(type) \
    type get_host_##type(type);

#define GOLDFISH_VK_DELETE_GOLDFISH_DECL(type) \
    void delete_goldfish_##type(type);

#define GOLDFISH_VK_IDENTITY_DECL(type) \
    type vk_handle_identity_##type(type);

#define GOLDFISH_VK_NEW_FROM_HOST_U64_DECL(type) \
    type new_from_host_u64_##type(uint64_t);

#define GOLDFISH_VK_GET_HOST_U64_DECL(type) \
    uint64_t get_host_u64_##type(type);

GOLDFISH_VK_LIST_AUTODEFINED_STRUCT_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_DEFINE_DISPATCHABLE_HANDLE_STRUCT)
GOLDFISH_VK_LIST_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_NEW_FROM_HOST_DECL)
GOLDFISH_VK_LIST_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_AS_GOLDFISH_DECL)
GOLDFISH_VK_LIST_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_GET_HOST_DECL)
GOLDFISH_VK_LIST_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_DELETE_GOLDFISH_DECL)
GOLDFISH_VK_LIST_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_IDENTITY_DECL)
GOLDFISH_VK_LIST_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_NEW_FROM_HOST_U64_DECL)
GOLDFISH_VK_LIST_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_GET_HOST_U64_DECL)

GOLDFISH_VK_LIST_NON_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_NEW_FROM_HOST_DECL)
GOLDFISH_VK_LIST_NON_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_AS_GOLDFISH_DECL)
GOLDFISH_VK_LIST_NON_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_GET_HOST_DECL)
GOLDFISH_VK_LIST_NON_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_DELETE_GOLDFISH_DECL)
GOLDFISH_VK_LIST_NON_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_IDENTITY_DECL)
GOLDFISH_VK_LIST_NON_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_NEW_FROM_HOST_U64_DECL)
GOLDFISH_VK_LIST_NON_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_GET_HOST_U64_DECL)
GOLDFISH_VK_LIST_AUTODEFINED_STRUCT_NON_DISPATCHABLE_HANDLE_TYPES(GOLDFISH_VK_DEFINE_TRIVIAL_NON_DISPATCHABLE_HANDLE_STRUCT)

struct goldfish_VkDescriptorPool {
    uint64_t underlying;
    goldfish_vk::DescriptorPoolAllocationInfo* allocInfo;
};

struct goldfish_VkDescriptorSet {
    uint64_t underlying;
    goldfish_vk::ReifiedDescriptorSet* reified;
};

struct goldfish_VkDescriptorSetLayout {
    uint64_t underlying;
    goldfish_vk::DescriptorSetLayoutInfo* layoutInfo;
};

struct goldfish_VkCommandBuffer {
    hwvulkan_dispatch_t dispatch;
    uint64_t underlying;
    goldfish_vk::VkEncoder* lastUsedEncoder;
    uint32_t sequenceNumber;
    goldfish_vk::VkEncoder* privateEncoder;
    IOStream* privateStream;
    uint32_t flags;
    struct goldfish_vk_object_list* poolObjects;
    struct goldfish_vk_object_list* subObjects;
    struct goldfish_vk_object_list* superObjects;
    void* userPtr;
    bool isSecondary;
};

} // extern "C"

namespace goldfish_vk {

void appendObject(struct goldfish_vk_object_list** begin, void* val);
void eraseObject(struct goldfish_vk_object_list** begin, void* val);
void eraseObjects(struct goldfish_vk_object_list** begin);
void forAllObjects(struct goldfish_vk_object_list* begin, std::function<void(void*)> func);

} // namespace goldfish_vk
