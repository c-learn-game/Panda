//
// Created by chendebi on 2023/5/1.
//

#ifndef TEST_SHADER_H
#define TEST_SHADER_H

#include "RendererObject.h"

namespace Panda
{
    class FShaderObject : public FRendererObject
    {
    public:
        explicit FShaderObject(const FString& VertexShaderSource, const FString& PixelShaderSource)
        { PANDA_UNUSED(VertexShaderSource) PANDA_UNUSED(PixelShaderSource)}

        virtual void Bind() = 0;

        static SharedPtr<FShaderObject> Get(const FString& VertexShaderSource, const FString& PixelShaderSource);
    };
}

#endif //TEST_SHADER_H
