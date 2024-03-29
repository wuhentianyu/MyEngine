//
// Created by Administrator on 2024/3/30.
//

#include "RenderSystem.h"

bool RenderSystem::Init() {
    return false;
}

void RenderSystem::Tick() {
    // render
}

void RenderSystem::Cleanup() {

}

RenderSystem::~RenderSystem() {
    Cleanup();
}


