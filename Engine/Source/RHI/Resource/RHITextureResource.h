
#ifndef PANDA_RHITEXTURERESOURCE_H
#define PANDA_RHITEXTURERESOURCE_H

#include "RHIResource.h"

namespace Panda
{
    enum FTextureFormat
    {
        RGB,
        RGBA
    };

    class FRHITextureResource : public FRHIResource
    {
    public:
        //virtual void SetData(int Width, int Height, FTextureFormat Format) = 0;

        static SharedPtr<FRHITextureResource> Create();
    };
}


#endif //PANDA_RHITEXTURERESOURCE_H
