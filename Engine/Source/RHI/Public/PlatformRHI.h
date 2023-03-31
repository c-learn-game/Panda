﻿#ifndef PLATFORMRHI_H
#define PLATFORMRHI_H
#include "Base/Public/Pointer.h"
#include "Base/Public/Types/Math.h"

namespace Panda
{
    class FPlatformRHI
    {
    public:
        virtual ~FPlatformRHI() = default;

        virtual  void Clear() = 0;

        virtual void SetClearColor(float r=0.0f, float g=0.0f, float b=0.0f, float a=1.0f) = 0;
        
        virtual void SetViewport(int x, int y, int w, int h) = 0;
        
        static FPlatformRHI* GetRHI();
    };

#define RHICommand FPlatformRHI::GetRHI()
    
}

#endif