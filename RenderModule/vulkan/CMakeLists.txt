find_package(Vulkan REQUIRED)

# 设置glfw库的路径
set(GLFW_DIR "${CMAKE_SOURCE_DIR}/lib/glfw-3.4")
# 告诉CMake去哪里找到glfw库
list(APPEND CMAKE_PREFIX_PATH ${GLFW_DIR})
# 查找glfw库
find_package(glfw3 REQUIRED)
# 链接glfw库
target_link_libraries(Vulkan PUBLIC glfw)

add_library(Vulkan VulkanContext.cpp VulkanContext.h)
target_link_libraries(Vulkan PUBLIC Vulkan::Vulkan)