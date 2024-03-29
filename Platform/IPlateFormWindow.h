//
// Created by Administrator on 2024/3/21.
//

#ifndef IPLATEFORMWINDOW_H
#define IPLATEFORMWINDOW_H

#include <memory>




class IPlateFormWindow {
public:
    virtual ~IPlateFormWindow() = default;
    virtual void Create(int width,int height) = 0;
    virtual bool Tick() = 0;

    int GetWidth() const {return width;}
    int GetHeight() const {return height;}

protected:
    int width;
    int height;
};





#endif //IPLATEFORMWINDOW_H
