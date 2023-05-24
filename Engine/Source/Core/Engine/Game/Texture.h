
#ifndef PANDA_TEXTURE_H
#define PANDA_TEXTURE_H

#include "Basic/Basic.h"
#include "RHI/Resource/RHITextureResource.h"

namespace Panda
{
    class UTexture
    {
    private:
        friend class FTextureResourceProxy;
        FString TextureAssetPath;
        class FTextureResourceProxy* Proxy = nullptr;
        uint8* AssetData = nullptr;
        int Width = 0;
        int Height = 0;
        int ChannelCount = 0;

    public:
        FTextureFormat Format = FTextureFormat::RGB;

    public:
        explicit UTexture(const FString& InAssetPath);

        ~UTexture();

        bool LoadAsset();

        FTextureResourceProxy* CreateProxy();
    };
}

#endif //PANDA_TEXTURE_H
