//
// Created by chendebi on 2023/5/1.
//

#ifndef PANDA_OPENGLSHADERRESOURCE_H
#define PANDA_OPENGLSHADERRESOURCE_H

#include "RHI/Resource/RHIShaderResource.h"

namespace Panda
{
    class FRHITextureResource;

    class FOpenGLShaderResource : public FRHIShaderResource
    {
    public:
        ~FOpenGLShaderResource() override;

        void Bind() override;

        bool IsValid() const override;

        void InitResource(const FString& VertexShaderSource, const FString& FragShaderSource) override;

        void ReleaseResource() override;

        void AddUniformParameter(const FString& ParameterName) override;

        void SetMatParameter(const FString& ParameterName, const FMatrix& Mat) override;

        void SetTexture2DParameter(const FString& ParameterName, FRHITextureResource* Texture, int Slot) override;

    private:
        THash<FString, int> UniformLocations;
        uint ShaderId = 0;
    };
}

#endif //TEST_OPENGLSHADEROBJECT_H
