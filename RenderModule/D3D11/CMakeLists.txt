add_library(D3D11Context D3D11Context.cpp D3D11Context.h)
target_link_libraries(D3D11Context d3d11.lib d3dcompiler.lib dxgi.lib)