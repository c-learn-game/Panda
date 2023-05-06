
#include "Core/Engine/MaterialResourceProxy.h"
#include "RHI/Resource/RHIShaderResource.h"
#include "Core/Engine/Material.h"

namespace Panda
{
    FMaterialResourceProxy::FMaterialResourceProxy(const SharedPtr<UMaterial>& InMaterial)
            : Material(InMaterial)
    {
        check(Material)
        VertexShaderSource = Material->GetVertexShaderSource();
        FragShaderSource = Material->GetFragShaderSource();
    }

    void FMaterialResourceProxy::CreateResource()
    {
        Shader = nullptr;
        Shader = FRHIShaderResource::Create();
        Shader->SetShaderSource(VertexShaderSource,FragShaderSource);
        Shader->InitResource();
    }

    void FMaterialResourceProxy::ReleaseResource()
    {
        Shader = nullptr;
    }

    void FMaterialResourceProxy::Update(const SharedPtr<FMaterialResourceProxy>& OldProxy)
    {
        if (OldProxy)
        {
            Shader = OldProxy->Shader;
        }
        else
        {
            Shader = nullptr;
            Shader = FRHIShaderResource::Create();
            Shader->SetShaderSource(VertexShaderSource,FragShaderSource);
            Shader->InitResource();
        }
    }

    bool FMaterialResourceProxy::IsValid() const
    {
        return Shader != nullptr && Shader->IsValid();
    }
}