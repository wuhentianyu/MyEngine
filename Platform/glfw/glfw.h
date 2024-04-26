//
// Created by Administrator on 2024/4/11.
//

#ifndef GLFW_H
#define GLFW_H
#include "../IPlateFormWindow.h"
#include <GLFW/glfw3.h>
#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#endif


class glfw : public IPlateFormWindow{
public:
    void Create(int width,int height) override;
    bool Tick() override;
    void CleanUp() override;
#ifdef _WIN32
    HWND GetWindowHandle() override;
#endif
private:
    GLFWwindow* window;

};



#endif //GLFW_H
