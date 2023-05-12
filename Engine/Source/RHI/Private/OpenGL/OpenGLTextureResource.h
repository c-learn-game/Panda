
#ifndef PANDA_OPENGLTEXTURERESOURCE_H
#define PANDA_OPENGLTEXTURERESOURCE_H

#include "RHI/Resource/RHITextureResource.h"

namespace Panda
{
    class FOpenGLTextureResource : public FRHITextureResource
    {
    public:
        ~FOpenGLTextureResource() override;

        void InitResource(void* Data) override;

        void ReleaseResource() override;

        void Bind(const int& TexSlot) override;

        bool IsValid() const { return TexId > 0; }

    private:
        uint TexId = 0;
    };
}


#endif //PANDA_OPENGLTEXTURERESOURCE_H
