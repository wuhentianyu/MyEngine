//
// Created by Administrator on 2024/3/27.
//

#ifndef RHI_H
#define RHI_H
class RHI {
public:
    virtual ~RHI() = default;

    virtual bool Init() = 0;
    virtual void Cleanup() = 0;

    virtual void BeginRender() = 0;
    virtual void EndRender() = 0;
};
#endif //RHI_H
