//
// Created by Administrator on 2024/4/11.
//

#include "glfw.h"
#include <GLFW/glfw3.h>
#include "GLFW/glfw3native.h"

void glfw::Create(int width, int height) {
    if (!glfwInit()) {
        // Initialization failed
        return;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(width, height, "MyEngine", NULL, NULL);
    if (!window) {
        // Window or OpenGL context creation failed
        glfwTerminate();
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
}

bool glfw::Tick() {
    // Poll for and process events
    glfwPollEvents();

    // Check if the window should be closed
    if (glfwWindowShouldClose(window)) {
        return true;
    }

    return false;
}

void glfw::CleanUp() {
    // Terminate GLFW
    glfwTerminate();
}

#ifdef _WIN32
HWND glfw::GetWindowHandle() {
    return glfwGetWin32Window(window);
}
#endif