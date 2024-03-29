//
// Created by Administrator on 2024/3/21.
//

#include "windows.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;

        case WM_KEYDOWN:
            // 处理键盘输入
            // wParam包含被按下的键的虚拟键码
            break;

        case WM_MOUSEMOVE:
            // 处理鼠标移动
            // 使用LOWORD(lParam)和HIWORD(lParam)获取鼠标的x和y坐标
            break;

        case WM_SIZE:
            // 处理窗口大小改变
            // 使用LOWORD(lParam)和HIWORD(lParam)获取新的窗口宽度和高度
            break;

            // 其他消息...
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void windows::Create(int width, int height) {
    const char CLASS_NAME[]  = "myengine";

    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "Learn to Program Windows",     // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,

        NULL,       // Parent window
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return;
    }
    this->width = width;
    this->height = height;

    ShowWindow(hwnd, SW_SHOWDEFAULT);
}


bool windows::Tick() {
    MSG msg = {0};

    while(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        if(msg.message == WM_QUIT || msg.message == WM_CLOSE) {
            return true;
        }
    }
    return false;
}

