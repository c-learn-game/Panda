//
// Created by Administrator on 2023/5/12.
//

#ifndef PANDA_TEXTURERESOURCEPROXY_H
#define PANDA_TEXTURERESOURCEPROXY_H

#include "Basic/Basic.h"

namespace Panda
{
    // Proxy总是在其对象之前被删除
    class FTextureResourceProxy
    {
    public:
        explicit FTextureResourceProxy(class UTexture* Texture);

        SharedPtr<class FRHITextureResource> CreateResource();

        void Bind(int Slot) const;

    public:
        class UTexture* Texture = nullptr;
        SharedPtr<class FRHITextureResource> TextureResource;
    };
}


#endif //PANDA_TEXTURERESOURCEPROXY_H
