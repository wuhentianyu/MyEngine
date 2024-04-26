//
// Created by Administrator on 2024/3/21.
//

#ifndef IPLATEFORMWINDOW_H
#define IPLATEFORMWINDOW_H

#include <memory>
#ifdef _WIN32
#include <windows.h>
#endif



class IPlateFormWindow {
public:
    virtual ~IPlateFormWindow() = default;
    virtual void Create(int width,int height) = 0;
    virtual bool Tick() = 0;
    virtual void CleanUp() = 0;
#ifdef _WIN32
    virtual HWND GetWindowHandle() = 0;
#endif

    int GetWidth() const {return width;}
    int GetHeight() const {return height;}

protected:
    int width;
    int height;
};





#endif //IPLATEFORMWINDOW_H
