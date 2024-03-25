#include <iostream>

#include <memory>
#include "Platform/windows/windows.h"

extern std::unique_ptr<IPlateFormWindow> WindowsPlateform;
int main() {
    if(!WindowsPlateform)
    {
        std::cout << "WindowsPlateform is nullptr" << std::endl;
        return 1;
    }
    else {
        WindowsPlateform->Create();
    }
    return 0;
}
