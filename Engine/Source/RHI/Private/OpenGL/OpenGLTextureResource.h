
#ifndef PANDA_OPENGLTEXTURERESOURCE_H
#define PANDA_OPENGLTEXTURERESOURCE_H

#include "RHI/Resource/RHITextureResource.h"

namespace Panda
{
    class FOpenGLTextureResource : public FRHITextureResource
    {
    public:
        ~FOpenGLTextureResource() override;

        void SetData(void* InData, int InWidth, int InHeight, FTextureFormat InFormat) override;

        void InitResource() override;

        void ReleaseResource() override;

        void Bind() override;

        bool IsValid() const { return TexId > 0; }

    private:
        void* Data = nullptr;
        int Width = 0;
        int Height = 0;
        FTextureFormat Format = FTextureFormat::RGB;
        uint TexId = 0;
    };
}


#endif //PANDA_OPENGLTEXTURERESOURCE_H
