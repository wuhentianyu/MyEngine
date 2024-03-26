//
// Created by Administrator on 2024/3/21.
//

#ifndef WINDOWS_H
#define WINDOWS_H
#include "../IPlateFormWindow.h"
#include <windows.h>



class windows : public IPlateFormWindow {
public:
    void Create() override;
    bool Tick() override;
};



#endif //WINDOWS_H
