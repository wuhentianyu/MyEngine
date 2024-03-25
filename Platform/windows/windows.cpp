//
// Created by Administrator on 2024/3/21.
//

#include "windows.h"

#include "windows.h"

void windows::Create() {
    const char CLASS_NAME[]  = "myengine";

    WNDCLASS wc = { };

    wc.lpfnWndProc   = DefWindowProc;
    wc.hInstance     = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "Learn to Program Windows",     // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return;
    }

    ShowWindow(hwnd, SW_SHOWDEFAULT);
}