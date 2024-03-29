//
// Created by Administrator on 2024/3/30.
//

#ifndef MYENGINE_RENDERSYSTEM_H
#define MYENGINE_RENDERSYSTEM_H


#include "../ISystem.h"

class RenderSystem : public ISystem{
public:
    bool Init() override;
    void Cleanup() override;
    void Tick() override;

    ~RenderSystem() override;
};


#endif //MYENGINE_RENDERSYSTEM_H
