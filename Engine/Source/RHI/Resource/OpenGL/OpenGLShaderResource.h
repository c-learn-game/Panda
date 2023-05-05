//
// Created by chendebi on 2023/5/1.
//

#ifndef PANDA_OPENGLSHADERRESOURCE_H
#define PANDA_OPENGLSHADERRESOURCE_H

#include "RHI/Resource/RHIShaderResource.h"

namespace Panda
{
    class FOpenGLShaderResource : public FRHIShaderResource
    {
    public:
        ~FOpenGLShaderResource() override;

        void Bind() override;

        bool IsValid() const override;

        void InitResource() override;

        void ReleaseResource() override;

        void SetShaderSource(const FString& InVertexShaderSource, const FString& InFragShaderSource) override;

    private:
        FString VertexShaderSource;
        FString FragShaderSource;
        uint ShaderId = 0;
    };
}

#endif //TEST_OPENGLSHADEROBJECT_H
