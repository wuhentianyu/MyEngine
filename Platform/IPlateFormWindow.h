//
// Created by Administrator on 2024/3/21.
//

#ifndef IPLATEFORMWINDOW_H
#define IPLATEFORMWINDOW_H

#include <memory>




class IPlateFormWindow {
public:
    virtual void Create() = 0;
    virtual bool Tick() = 0;
};





#endif //IPLATEFORMWINDOW_H
