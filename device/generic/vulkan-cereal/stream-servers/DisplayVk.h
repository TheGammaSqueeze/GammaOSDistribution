#ifndef DISPLAY_VK_H
#define DISPLAY_VK_H

#include <functional>
#include <memory>
#include <unordered_map>

#include "CompositorVk.h"
#include "Hwc2.h"
#include "RenderContext.h"
#include "SwapChainStateVk.h"
#include "vulkan/cereal/common/goldfish_vk_dispatch.h"

// The DisplayVk class holds the Vulkan and other states required to draw a
// frame in a host window.

class DisplayVk {
   public:
    class DisplayBufferInfo {
       public:
        ~DisplayBufferInfo();

       private:
        DisplayBufferInfo(const goldfish_vk::VulkanDispatch &, VkDevice,
                          uint32_t width, uint32_t height, VkFormat, VkImage);

        const goldfish_vk::VulkanDispatch &m_vk;
        VkDevice m_vkDevice;
        uint32_t m_width;
        uint32_t m_height;
        VkFormat m_vkFormat;

        VkImageView m_vkImageView;

        friend class DisplayVk;
    };
    DisplayVk(const goldfish_vk::VulkanDispatch &, VkPhysicalDevice,
              uint32_t swapChainQueueFamilyIndex,
              uint32_t compositorQueueFamilyIndex, VkDevice,
              VkQueue compositorVkQueue, VkQueue swapChainVkQueue);
    ~DisplayVk();
    void bindToSurface(VkSurfaceKHR, uint32_t width, uint32_t height);
    // The caller is responsible to make sure the VkImage lives longer than the
    // DisplayBufferInfo created here. However, given that DisplayBufferInfo
    // lives in a shared_ptr, the potential lifetime of DisplayBufferInfo is
    // aligned to DisplayVk when DisplayVk::m_surfaceState::m_prevDisplayBuffer
    // is locked and upgraded to a shared_ptr in DisplayVk::post.
    std::shared_ptr<DisplayBufferInfo> createDisplayBuffer(VkImage, VkFormat,
                                                           uint32_t width,
                                                           uint32_t height);
    void post(const std::shared_ptr<DisplayBufferInfo> &);

    void compose(
        uint32_t numLayers, const ComposeLayer layers[],
        const std::vector<std::shared_ptr<DisplayBufferInfo>> &composeBuffers);

   private:
    bool canComposite(VkFormat);
    // Returns if the composition specified by the parameter is different from
    // the previous composition. If the composition is different, update the
    // previous composition stored in m_surfaceState. Must be called after
    // bindToSurface() is called.
    bool compareAndSaveComposition(
        uint32_t renderTargetIndex, uint32_t numLayers,
        const ComposeLayer layers[],
        const std::vector<std::shared_ptr<DisplayBufferInfo>> &composeBuffers);

    const goldfish_vk::VulkanDispatch &m_vk;
    VkPhysicalDevice m_vkPhysicalDevice;
    uint32_t m_swapChainQueueFamilyIndex;
    uint32_t m_compositorQueueFamilyIndex;
    VkDevice m_vkDevice;
    VkQueue m_compositorVkQueue;
    VkQueue m_swapChainVkQueue;
    VkCommandPool m_vkCommandPool;
    VkSampler m_compositionVkSampler;
    VkFence m_frameDrawCompleteFence;
    VkSemaphore m_imageReadySem;
    VkSemaphore m_frameDrawCompleteSem;

    std::unique_ptr<SwapChainStateVk> m_swapChainStateVk;
    std::unique_ptr<CompositorVk> m_compositorVk;
    struct SurfaceState {
        struct Layer {
            ComposeLayer m_hwc2Layer;
            std::weak_ptr<DisplayBufferInfo> m_displayBuffer;
        };

        uint32_t m_width = 0;
        uint32_t m_height = 0;
        std::unordered_map<uint32_t, std::vector<std::unique_ptr<Layer>>>
            m_prevCompositions;
    };
    std::unique_ptr<SurfaceState> m_surfaceState;
    std::unordered_map<VkFormat, bool> m_canComposite;
};

#endif
