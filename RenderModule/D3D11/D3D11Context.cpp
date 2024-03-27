//
// Created by Administrator on 2024/3/27.
//


#include "D3D11Context.h"

bool D3D11Context::Init() {
    // 创建设备和设备上下文
    D3D_FEATURE_LEVEL featureLevel;
    HRESULT hr = D3D11CreateDevice(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &device,
        &featureLevel,
        &context
    );
    if (FAILED(hr)) {
        return false;
    }

    // 创建交换链
    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
    // ...设置交换链描述
    ComPtr<IDXGIDevice> dxgiDevice;
    device.As(&dxgiDevice);
    ComPtr<IDXGIAdapter> dxgiAdapter;
    dxgiDevice->GetAdapter(&dxgiAdapter);
    ComPtr<IDXGIFactory> dxgiFactory;
    dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));
    dxgiFactory->CreateSwapChain(device.Get(), &swapChainDesc, &swapChain);

    // 创建渲染目标视图
    swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));
    device->CreateRenderTargetView(backBuffer.Get(), nullptr, &renderTargetView);

    // 创建深度模板视图
    D3D11_TEXTURE2D_DESC depthStencilDesc = {};
    // ...设置深度模板描述
    device->CreateTexture2D(&depthStencilDesc, nullptr, &depthStencilBuffer);

    device->CreateDepthStencilView(depthStencilBuffer.Get(), nullptr, &depthStencilView);

    // 设置视口
    D3D11_VIEWPORT viewport = {};
    // ...设置视口
    context->RSSetViewports(1, &viewport);

    return true;
}

void D3D11Context::Cleanup() {
    if (context) {
        context->ClearState();
    }

    // 释放深度模板视图
    depthStencilView = nullptr;
    // 释放渲染目标视图
    renderTargetView = nullptr;
    // 释放交换链
    swapChain = nullptr;
    // 释放设备上下文
    context = nullptr;
    // 释放设备
    device = nullptr;
}

void D3D11Context::BeginRender() {
    // 清除渲染目标视图
    float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f }; // RGBA
    context->ClearRenderTargetView(renderTargetView.Get(), clearColor);

    // 清除深度模板视图
    context->ClearDepthStencilView(depthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    // 设置渲染目标
    context->OMSetRenderTargets(1, renderTargetView.GetAddressOf(), depthStencilView.Get());
}

void D3D11Context::EndRender() {
    // 呈现后台缓冲区
    HRESULT hr = swapChain->Present(1, 0);
}

D3D11Context::~D3D11Context() {
    Cleanup();
}