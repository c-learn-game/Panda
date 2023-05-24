
#ifndef PANDA_MATERIALRESOURCEPROXY_H
#define PANDA_MATERIALRESOURCEPROXY_H

#include "Basic/Basic.h"

namespace Panda
{
    class FMaterialResourceProxy
    {
    public:
        explicit FMaterialResourceProxy(class UMaterial* InMaterial);

        virtual ~FMaterialResourceProxy() = default;

        bool CreateRHI();

    public:
        class UMaterial* Material = nullptr;
        FString VertexShaderSource, FragShaderSource;
        SharedPtr<class FRHIShaderResource> Shader;
        TArray<FString> AllParameters;
    };
}

#endif //PANDA_MATERIALRESOURCEPROXY_H
