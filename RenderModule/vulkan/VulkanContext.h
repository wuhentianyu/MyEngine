#pragma once

#include <vulkan/vulkan.h>
#include "../RHI.h"

class VulkanContext :public RHI {
public:
    bool Init() override;
    void Cleanup() override;

    void BeginRender() override;
    void EndRender() override;

    ~VulkanContext()  = default;

private:
    VkInstance instance;
};


