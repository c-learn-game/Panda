//
// Created by chendebi on 2023/4/1.
//

#ifndef PANDA_RHISHADER_H
#define PANDA_RHISHADER_H

#include "RHIObject.h"

namespace Panda
{
    class FRHIShader : public FRHIObject
    {
    public:
        explicit FRHIShader() = delete;

        ~FRHIShader() override;

        explicit FRHIShader(const CString& VertexShaderSource, const CString& FragShaderSource);

        void Execute();

    private:
        int ShaderID = 0;
    };
}

#endif //PANDA_RHISHADER_H
