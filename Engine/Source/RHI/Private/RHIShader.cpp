//
// Created by chendebi on 2023/4/1.
//

#include "RHI/Public/RHIShader.h"
#include "RHI/Public/PlatformRHI.h"

namespace Panda
{
    FRHIShader::FRHIShader()
    {}

    FRHIShader::FRHIShader(const CString &VertexShaderSource, const CString &FragShaderSource) {
        ShaderID = RHICommand->CompileShader(VertexShaderSource, FragShaderSource);
    }

    void FRHIShader::Execute()
    {
        RHICommand->UseShader(ShaderID);
    }
}