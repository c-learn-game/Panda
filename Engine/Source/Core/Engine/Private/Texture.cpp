
#include "Core/Engine/Texture.h"
#include "Core/Platform/Path.h"
#include "Core/Engine/TextureResourceProxy.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Panda
{
    UTexture::UTexture(const FString &InAssetPath)
    : TextureAssetPath(FPath::ToLocalPath(InAssetPath))
    {

    }

    UTexture::~UTexture()
    {
        stbi_image_free(AssetData);
    }

    bool UTexture::LoadAsset()
    {
        LogInfo("load texture data.")
        LogInfo("   {}", TextureAssetPath.ToStdString())
        AssetData = stbi_load(TextureAssetPath.ToStdString().c_str(), &Width, &Height, &ChannelCount, 0);
        if (!AssetData)
        {
            LogWarn("Load Texture {} failed!", TextureAssetPath.ToStdString())
            return false;
        }
        return true;
    }

    FTextureResourceProxy* UTexture::CreateProxy()
    {
        Proxy = new FTextureResourceProxy(this);
        return Proxy;
    }
}