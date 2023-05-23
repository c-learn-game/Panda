
#include "Core/Engine/Renderer/MaterialResourceProxy.h"
#include "RHI/Resource/RHIShaderResource.h"
#include "Core/Engine/Game/Material.h"

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
        Shader->InitResource(VertexShaderSource,FragShaderSource);
        return true;
    }
}