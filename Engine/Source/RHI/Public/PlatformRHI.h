﻿#ifndef PLATFORMRHI_H
#define PLATFORMRHI_H

#include "Base/Base.h"

namespace Panda
{
	enum class EBufferUsage
	{
		BU_STATIC = 0x88E4,
	};

    class FPlatformRHI
    {
    public:
        virtual ~FPlatformRHI() = default;

        virtual  void Clear() = 0;

        virtual void SetClearColor(float r=0.0f, float g=0.0f, float b=0.0f, float a=1.0f) = 0;
        
        virtual void SetViewport(int x, int y, int w, int h) = 0;

        virtual int CompileShader(const char* VertShaderSource, const char* FragShaderSource) = 0;

        virtual void UseShader(const int& ShaderId) = 0;

		virtual uint SubmitVertexBuffer(float* Vertices, int BufferSize, EBufferUsage Usage = EBufferUsage::BU_STATIC) = 0;
        
        static FPlatformRHI* GetRHI();
    };

#define RHICommand FPlatformRHI::GetRHI()
    
}

#endif