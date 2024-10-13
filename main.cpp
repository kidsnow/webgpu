#include <webgpu/webgpu.h>
#include <iostream>

int main()
{
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

#ifdef WEBGPU_BACKEND_EMSCRIPTEN
    WGPUInstance instance = wgpuCreateInstance(nullptr);
#else // WEBGPU_BACKEND_EMSCRIPTEN
    WGPUInstance instance = wgpuCreateInstance(&desc);
#endif // WEBGPU_BACKEND_EMSCRIPTEN

    if (instance == nullptr)
    {
        std::cerr << "Could not initialize WebGPU!" << std::endl;
        return 1;
    }

    std::cout << "WGPU instance: " << instance << std::endl;

    wgpuInstanceRelease(instance);

    return 0;
}