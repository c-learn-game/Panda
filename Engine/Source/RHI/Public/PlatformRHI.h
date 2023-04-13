#ifndef PLATFORMRHI_H
#define PLATFORMRHI_H

#include "RHIBase.h"

namespace Panda
{

    class FPlatformRHI
    {
    public:
        virtual ~FPlatformRHI() = default;

        virtual  void Clear() = 0;

        virtual void SetClearColor(float r=0.0f, float g=0.0f, float b=0.0f, float a=1.0f) = 0;
        
        virtual void SetViewport(int x, int y, int w, int h) = 0;

        virtual int CompileShader(const char* VertShaderSource, const char* FragShaderSource) = 0;

        virtual void UseShader(const int& ShaderId) = 0;

		virtual void UseIndexBufferObject(const uint& BufferId) = 0;

		virtual uint CreateVertexBufferObject(const float* Vertices, int BufferSize, EBufferUsage Usage = EBufferUsage::BU_STATIC) = 0;

		virtual uint CreateIndexBufferObject(const uint* Indices, int BufferSize, EBufferUsage Usage = EBufferUsage::BU_STATIC) = 0;

		virtual uint CreateVertexArrayObject(uint VboId, int StrideSize, const CArray<FVertexBufferLayout>& Layouts) = 0;

		virtual void DrawArray(uint VaoId, int Count) = 0;

		virtual void DrawElements(uint VaoId, int ElementSize) = 0;

		virtual void UseVertexBuffer(uint VboId) = 0;
        
        static FPlatformRHI* GetRHI();
    };

#define RHICommand FPlatformRHI::GetRHI()
    
}

#endif