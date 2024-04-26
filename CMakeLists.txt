cmake_minimum_required(VERSION 3.27)
project(MyEngine)

set(CMAKE_CXX_STANDARD 23)

add_executable(MyEngine main.cpp
        Platform/IPlateFormWindow.h
        Platform/windows/windows.cpp
        Platform/windows/windows.h
        RenderModule/RHI.h
        RenderSystem/RenderSystem.cpp
        RenderSystem/RenderSystem.h
        ISystem.h
        ApplicationContext.cpp
        ApplicationContext.h
        Platform/glfw/glfw.cpp
        Platform/glfw/glfw.h
        Platform/glfw/glfw.h
)


add_subdirectory(RenderModule/D3D11)
add_subdirectory(RenderModule/vulkan)
add_subdirectory(lib/glfw-3.4)

target_include_directories(MyEngine PRIVATE ${PROJECT_SOURCE_DIR}/lib/glfw-3.4/include)

target_link_libraries(MyEngine D3D11Context)
target_link_libraries(MyEngine glfw)
target_link_libraries(MyEngine Vulkan)
