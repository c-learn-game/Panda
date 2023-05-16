#ifndef PANDA_RHISHADERRESOURCE_H
#define PANDA_RHISHADERRESOURCE_H

#include "RHIResource.h"

namespace Panda
{
    struct FMatrix4x4;

    class FRHIShaderResource : public FRHIResource
    {
    public:

        virtual void Bind() = 0;

        virtual void InitResource(const FString& VertexShaderSource, const FString& FragShaderSource) = 0;

        virtual void AddUniformParameter(const FString& ParameterName) = 0;

        virtual void SetMatParameter(const FString& ParameterName, const FMatrix4x4& Mat) = 0;

        static SharedPtr<FRHIShaderResource> Create();
    };
}

#endif //TEST_RHISHADERRESOURCE_H
