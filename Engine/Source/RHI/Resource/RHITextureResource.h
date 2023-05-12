
#ifndef PANDA_RHITEXTURERESOURCE_H
#define PANDA_RHITEXTURERESOURCE_H

#include "RHIResource.h"

namespace Panda
{
    enum class FTextureFormat : uint8
    {
        RGB,
        RGBA
    };

    enum class FTextureTilingMethod : uint8
    {
        Wrap,
        Clamp,
        Mirror
    };

    enum class FTextureFilter : uint8
    {
        Nearest,
        Linear
    };

    class FRHITextureResource : public FRHIResource
    {
    public:

        virtual void InitResource(void* Data) = 0;

        virtual void Bind(const int& TexSlot) = 0;

        static SharedPtr<FRHITextureResource> Create(int Width, int Height, FTextureFormat Format);

    public:
        int Width = 0;
        int Height = 0;
        FTextureFormat Format = FTextureFormat::RGB;
        bool bAutoMipmaps = true;

        FTextureTilingMethod XAxisTilingMethod = FTextureTilingMethod::Wrap;
        FTextureTilingMethod YAxisTilingMethod = FTextureTilingMethod::Wrap;

        FTextureFilter Filter = FTextureFilter::Linear;
    };
}


#endif //PANDA_RHITEXTURERESOURCE_H
