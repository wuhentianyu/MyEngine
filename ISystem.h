//
// Created by Administrator on 2024/3/30.
//

#ifndef MYENGINE_ISYSTEM_H
#define MYENGINE_ISYSTEM_H


class ISystem {
public:
    virtual ~ISystem() = default;

    virtual bool Init() = 0;
    virtual void Cleanup() = 0;
    virtual void Tick() = 0;
};


#endif //MYENGINE_ISYSTEM_H
