//
// Created by Administrator on 2024/3/30.
//

#include <memory>
#include <iostream>
#include "ApplicationContext.h"
#include "Platform/IPlateFormWindow.h"
#include "Platform/glfw/glfw.h"
#include "RenderModule/RHI.h"
#include "RenderModule/D3D11/D3D11Context.h"



bool ApplicationContext::Init() {
    Plateform = std::make_shared<glfw>();
    if(!Plateform)
    {
        std::cout << "WindowsPlateform is nullptr" << std::endl;
        return 1;
    }
    else {
        Plateform->Create(1024,768);
        RenderContext = std::make_unique<D3D11Context>();
        if(!RenderContext->Init()) {
            std::cout << "RenderContext Init failed" << std::endl;
            return 1;
        }
        while(!Plateform->Tick()) {
            RenderContext->BeginRender();
            RenderContext->EndRender();
        }
    }
    return 0;
}

void ApplicationContext::Cleanup() {
    Plateform->CleanUp();
}

void ApplicationContext::Tick() {

}

ApplicationContext::~ApplicationContext() {

}
