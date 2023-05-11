
#ifndef PANDA_TEXTURE_H
#define PANDA_TEXTURE_H

#include "Basic/Basic.h"

namespace Panda
{
    class UTexture
    {
    public:
        explicit UTexture(const FString& InAssetPath);

        ~UTexture();



    private:
        FString TextureAssetPath;
    };
}

#endif //PANDA_TEXTURE_H
