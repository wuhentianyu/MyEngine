#include <iostream>

#include <memory>

#include "Platform/MainLoop.h"
#include "Platform/windows/windows.h"

extern std::unique_ptr<IPlateFormWindow> Plateform;
int main() {
    if(!Plateform)
    {
        std::cout << "WindowsPlateform is nullptr" << std::endl;
        return 1;
    }
    else {
        Plateform->Create();
        MainLoop mainLoop;
        mainLoop.Init();
        mainLoop.Update();
    }
    return 0;
}
