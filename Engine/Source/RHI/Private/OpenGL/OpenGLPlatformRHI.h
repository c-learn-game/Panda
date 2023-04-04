#ifndef OPENGLPLATFORMRHI_H
#define OPENGLPLATFORMRHI_H

#include "RHI/Public/PlatformRHI.h"

namespace Panda
{
    class FOpenGLPlatformRHI : public FPlatformRHI
    {
    public:
        explicit FOpenGLPlatformRHI() = default;

        void Clear() override;

        void SetClearColor(float r, float g, float b, float a) override;
        
        void SetViewport(int x, int y, int w, int h) override;

        int CompileShader(const char *VertShaderSource, const char *FragShaderSource) override;

        void UseShader(const int &ShaderId) override;

		uint SubmitVertexBuffer(float* Vertices, int BufferSize, EBufferUsage Usage = EBufferUsage::BU_STATIC) override;
    };
}

#endif