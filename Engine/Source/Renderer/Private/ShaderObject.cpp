//
// Created by chendebi on 2023/5/1.
//
#include "ShaderObject.h"
#include "Renderer/Private/OpenGL/OpenGLShaderObject.h"

namespace Panda
{
    SharedPtr<FShaderObject> FShaderObject::Get(const FString &VertexShaderSource, const FString &PixelShaderSource)
    {
        return MakeShared<FOpenGLShaderObject>(VertexShaderSource, PixelShaderSource);
    }
}
