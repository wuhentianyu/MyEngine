//
// Created by Administrator on 2024/3/21.
//

#ifdef _WIN32
#include "windows/windows.h"
std::unique_ptr<IPlateFormWindow> WindowsPlateform = std::make_unique<windows>();
#elif defined(__linux__)
#include "LinuxWindow.h"
using PlatformWindow = LinuxWindow;
#else
#error Unsupported platform
#endif