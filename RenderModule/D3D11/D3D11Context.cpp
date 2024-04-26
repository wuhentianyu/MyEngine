//
// Created by Administrator on 2024/3/27.
//


#include <memory>
#include "D3D11Context.h"
#include "../../Platform/IPlateFormWindow.h"
#include "../../ApplicationContext.h"


extern ApplicationContext app;
bool D3D11Context::Init() {
    auto Plateform = app.GetPlateform();
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

    if(Plateform == nullptr) return false;


    // 创建交换链
    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
    swapChainDesc.BufferCount = 2;  // 后缓冲区数量
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;  // 缓冲区格式
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;  // 缓冲区用途
    swapChainDesc.BufferDesc.Width = Plateform->GetWidth();  // 缓冲区宽度
    swapChainDesc.BufferDesc.Height = Plateform->GetHeight();  // 缓冲区高度
    swapChainDesc.OutputWindow = Plateform->GetWindowHandle();  // 输出窗口的句柄
    swapChainDesc.SampleDesc.Count = 1;  // 多重采样数量
    swapChainDesc.SampleDesc.Quality = 0;  // 多重采样质量
    swapChainDesc.Windowed = TRUE;  // 是否窗口化
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
    depthStencilDesc.Width = Plateform->GetWidth();  // 纹理宽度
    depthStencilDesc.Height = Plateform->GetHeight();  // 纹理高度
    depthStencilDesc.MipLevels = 1;  // Mipmap级别，1表示只有一级
    depthStencilDesc.ArraySize = 1;  // 纹理数组的大小，1表示只有一个纹理
    depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;  // 纹理格式，这里是24位深度+8位模板
    depthStencilDesc.SampleDesc.Count = 1;  // 多重采样数量
    depthStencilDesc.SampleDesc.Quality = 0;  // 多重采样质量
    depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;  // 纹理的使用方式，这里是默认
    depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;  // 绑定标志，这里是深度模板
    depthStencilDesc.CPUAccessFlags = 0;  // CPU访问标志，0表示CPU无法访问
    depthStencilDesc.MiscFlags = 0;  // 其他标志，0表示无其他标志

    device->CreateTexture2D(&depthStencilDesc, nullptr, &depthStencilBuffer);

    device->CreateDepthStencilView(depthStencilBuffer.Get(), nullptr, &depthStencilView);

    // 设置视口
    D3D11_VIEWPORT viewport = {};
    viewport.TopLeftX = 0;  // 视口的左上角的x坐标
    viewport.TopLeftY = 0;  // 视口的左上角的y坐标
    viewport.Width = static_cast<float>(Plateform->GetWidth());  // 视口的宽度
    viewport.Height = static_cast<float>(Plateform->GetHeight());  // 视口的高度
    viewport.MinDepth = 0.0f;  // 最小深度值
    viewport.MaxDepth = 1.0f;  // 最大深度值
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
    float clearColor[4] = { 1.0f, 0.0f, 0.0f, 1.0f }; // RGBA
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