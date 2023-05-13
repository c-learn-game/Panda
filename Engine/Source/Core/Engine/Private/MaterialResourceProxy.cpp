
#include "Core/Engine/MaterialResourceProxy.h"
#include "RHI/Resource/RHIShaderResource.h"
#include "Core/Engine/Material.h"

namespace Panda
{
    FMaterialResourceProxy::FMaterialResourceProxy(UMaterial* InMaterial)
            : Material(InMaterial)
    {
        check(Material)
        VertexShaderSource = Material->VertexShaderSource;
        FragShaderSource = Material->FragShaderSource;
    }

    bool FMaterialResourceProxy::CreateRHI()
    {
        Shader = nullptr;
        Shader = FRHIShaderResource::Create();
        Shader->SetShaderSource(VertexShaderSource,FragShaderSource);
        Shader->InitResource();
        return true;
    }
}