//
// Created by Administrator on 2024/3/27.
//

#ifndef D3D11CONTEXT_H
#define D3D11CONTEXT_H

#include <d3d11.h>
#include <dxgi1_2.h>
#include <wrl.h>
#include "../RHI.h"

using Microsoft::WRL::ComPtr;

class D3D11Context : public RHI{
public:
    bool Init() override;
    void Cleanup() override;

    void BeginRender() override;
    void EndRender() override;

    ~D3D11Context() override;

private:
    ComPtr<ID3D11Device> device;
    ComPtr<ID3D11DeviceContext> context;

    ComPtr<ID3D11Texture2D> backBuffer;
    ComPtr<ID3D11RenderTargetView> renderTargetView;
    ComPtr<ID3D11Texture2D> depthStencilBuffer;
    ComPtr<ID3D11DepthStencilView> depthStencilView;
    ComPtr<IDXGISwapChain> swapChain;
};



#endif //D3D11CONTEXT_H
