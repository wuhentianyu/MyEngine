cmake_minimum_required(VERSION 3.28)
project(MyEngine)

set(CMAKE_CXX_STANDARD 23)

add_executable(MyEngine main.cpp
        Platform/IPlateFormWindow.h
        Platform/windows/windows.cpp
        Platform/windows/windows.h
        Platform/IPlateFormWindow.cpp)
