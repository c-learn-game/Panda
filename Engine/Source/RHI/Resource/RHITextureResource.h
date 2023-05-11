
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
    protected:
        size_t Width = 0;
        size_t Height = 0;
        bool bAutoMipmaps = true;

        FTextureTilingMethod XAxisTilingMethod = FTextureTilingMethod::Wrap;
        FTextureTilingMethod YAxisTilingMethod = FTextureTilingMethod::Wrap;

        virtual void InitResource(void* Data, FTextureFormat Format) = 0;

    public:
        static SharedPtr<FRHITextureResource> Create(size_t Width, size_t Height, int );
    };
}


#endif //PANDA_RHITEXTURERESOURCE_H
