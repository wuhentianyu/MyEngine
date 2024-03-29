//
// Created by Administrator on 2024/3/30.
//

#ifndef MYENGINE_APPLICATIONCONTEXT_H
#define MYENGINE_APPLICATIONCONTEXT_H


class ApplicationContext {
public:
    bool Init();
    void Cleanup();
    void Tick();
    ~ApplicationContext();
};


#endif //MYENGINE_APPLICATIONCONTEXT_H
