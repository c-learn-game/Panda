
#ifndef PANDA_MATERIALRESOURCEPROXY_H
#define PANDA_MATERIALRESOURCEPROXY_H

#include "ProxyBase.h"

namespace Panda
{
    class FMaterialResourceProxy : public FProxyBase
    {
    public:
        explicit FMaterialResourceProxy(const SharedPtr<class UMaterial>& InMaterial);

        virtual ~FMaterialResourceProxy() = default;

        bool IsValid() const;

        void CreateResource() override;

        void ReleaseResource() override;

        void Update(const SharedPtr<FMaterialResourceProxy>& OldProxy = nullptr);

    public:
        SharedPtr<class UMaterial> Material;
        FString VertexShaderSource, FragShaderSource;
        SharedPtr<class FRHIShaderResource> Shader;
    };
}

#endif //PANDA_MATERIALRESOURCEPROXY_H
