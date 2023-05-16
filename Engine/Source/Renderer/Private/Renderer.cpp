

#include "Renderer/Renderer.h"
#include "Core/Math/Vector4.h"
#include "Core/Engine/PrimitiveSceneComponent.h"
#include "Core/Engine/PrimitiveSceneProxy.h"
#include "Core/Engine/Material.h"
#include "Core/Engine/MaterialResourceProxy.h"
#include "Core/Engine/Texture.h"
#include "Core/Engine/TextureResourceProxy.h"
#include "Core/Engine/Private/EngineMacros.h"
#include "Core/Platform/Path.h"
#include "RHI/RHI.h"
#include "Core/Engine/Asset/Package.h"

static Panda::uint indices[] = {
        0, 1, 2,
        0, 2, 3
};

namespace Panda
{
    FRenderer::FRenderer(const SharedPtr<FRenderContext> &RenderContext)
    : Context(RenderContext)
    {

    }

    void FRenderer::Initialize()
    {
        Context->MakeCurrent();

        Component = LoadObject<UPrimitiveSceneComponent>("/Engine/SimpleMesh.asset");
        Proxy = Component->CreateProxy();
        Proxy->CreateRHI();


        Material = MakeShared<UMaterial>(ENGINE_SHADER("/Private/LocalStaticMesh.vert"),
                                           ENGINE_SHADER("/Private/LocalStaticMesh.frag"));
        Material->LoadAsset();
        MaterialProxy = Material->CreateProxy();
        MaterialProxy->CreateRHI();

        Texture = MakeShared<UTexture>(ENGINE_RESOURCE("/Test/container.jpg"));
        Texture->LoadAsset();
        TextureProxy = SharedPtr<FTextureResourceProxy>(Texture->CreateProxy());
        TextureProxy->CreateRHI();
        LogInfo("Renderer initialize success.")
    }

    void FRenderer::RendererMain()
    {
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);

        MaterialProxy->Shader->Bind();
        TextureProxy->Bind(0);
        RHICommand->DrawMesh(Proxy->VertexArray, Proxy->IndexBuffer);
        Context->SwapBuffer();
    }

	void FRenderer::DestroyRenderer()
	{
        delete Proxy;
        delete MaterialProxy;
        delete Component;
	}
}