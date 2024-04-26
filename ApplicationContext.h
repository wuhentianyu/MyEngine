//
// Created by Administrator on 2024/3/30.
//

#ifndef MYENGINE_APPLICATIONCONTEXT_H
#define MYENGINE_APPLICATIONCONTEXT_H
#include "Platform/IPlateFormWindow.h"
#include "RenderModule/RHI.h"


class ApplicationContext {
public:
    bool Init();
    void Cleanup();
    void Tick();
    std::shared_ptr<IPlateFormWindow> GetPlateform() { return Plateform; }
    ~ApplicationContext();
private:
    std::shared_ptr<IPlateFormWindow> Plateform;
    std::unique_ptr<RHI> RenderContext;
};


#endif //MYENGINE_APPLICATIONCONTEXT_H
