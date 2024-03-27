#include <iostream>

#include <memory>

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
    }
    return 0;
}
