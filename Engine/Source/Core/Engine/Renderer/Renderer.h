//
// Created by chendebi on 2023/5/1.
//

#ifndef TEST_RENDERER_H
#define TEST_RENDERER_H

#include "RHI/RenderContext.h"
#include "Core/Math/Matrix4x4.h"

namespace Panda
{
    class FRenderer
    {
    public:
        explicit FRenderer(const SharedPtr<FRenderContext> &RenderContext);
        virtual ~FRenderer() = default;

        virtual void Initialize();

        virtual void RendererMain();

		void DestroyRenderer();

    private:
        SharedPtr<FRenderContext> Context;

        // 临时测试
        class UPrimitiveSceneComponent* Component;
        class FPrimitiveSceneProxy* Proxy = nullptr;

        SharedPtr<class UMaterial> Material = nullptr;
        class FMaterialResourceProxy* MaterialProxy = nullptr;

        SharedPtr<class UTexture> Texture = nullptr;
        SharedPtr<class FTextureResourceProxy> TextureProxy = nullptr;

        FMatrix4x4 Transform = FMatrix4x4(1.0);
        double  TotalTime = 0.0;

        class FSceneView* SceneView = nullptr;
    };
}


#endif //TEST_RENDERER_H
