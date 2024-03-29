cmake_minimum_required(VERSION 3.27)
project(MyEngine)

set(CMAKE_CXX_STANDARD 23)

add_executable(MyEngine main.cpp
        Platform/IPlateFormWindow.h
        Platform/windows/windows.cpp
        Platform/windows/windows.h
        Platform/IPlateFormWindow.cpp
        RenderModule/RHI.h
        RenderSystem/RenderSystem.cpp
        RenderSystem/RenderSystem.h
        ISystem.h
        ApplicationContext.cpp
        ApplicationContext.h
)


add_subdirectory(RenderModule/D3D11)


target_link_libraries(MyEngine D3D11Context)
