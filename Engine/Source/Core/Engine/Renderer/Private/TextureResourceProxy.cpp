
#include "Core/Engine/Renderer/TextureResourceProxy.h"
#include "Core/Engine/Game/Texture.h"
#include "RHI/Resource/RHITextureResource.h"

namespace Panda
{
    FTextureResourceProxy::FTextureResourceProxy(UTexture *InTexture)
    : Texture(InTexture)
    {
        check(Texture)
    }

    SharedPtr<FRHITextureResource> FTextureResourceProxy::CreateRHI()
    {
        TextureResource = FRHITextureResource::Create(Texture->Width, Texture->Height, FTextureFormat::RGB);
        TextureResource->InitResource(Texture->AssetData);
        return TextureResource;
    }

    void FTextureResourceProxy::Bind(int Slot) const
    {
        TextureResource->Bind(Slot);
    }
}