//
// Created by Administrator on 2024/3/21.
//

#ifndef WINDOWS_H
#define WINDOWS_H
#include "../IPlateFormWindow.h"
#include <windows.h>



class windows : public IPlateFormWindow {
public:
    void Create(int width,int height) override;
    bool Tick() override;
    HWND GetWindowHandle() const {return hwnd;}
private:
    HWND hwnd;
};



#endif //WINDOWS_H
