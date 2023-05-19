

#include "Core/Engine/Renderer/Renderer.h"
#include "Core/Math/Vector4.h"
#include "Core/Engine/PrimitiveSceneComponent.h"
#include "Core/Engine/PrimitiveSceneProxy.h"
#include "Core/Engine/Material.h"
#include "Core/Engine/MaterialResourceProxy.h"
#include "Core/Engine/Texture.h"
#include "Core/Engine/TextureResourceProxy.h"
#include "Core/Engine/Private/EngineMacros.h"
#include "RHI/RHI.h"
#include "Core/Engine/Asset/Package.h"
#include "Core/Math/MathCore.h"

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

        Material = MakeShared<UMaterial>(ENGINE_SHADER("/Private/LocalStaticMesh.vert"),
                                         ENGINE_SHADER("/Private/LocalStaticMesh.frag"));
        Material->LoadAsset();

        Texture = MakeShared<UTexture>(ENGINE_RESOURCE("/Test/container.jpg"));
        Texture->LoadAsset();


        Proxy = Component->CreateProxy();
        Proxy->CreateRHI();

        MaterialProxy = Material->CreateProxy();
        MaterialProxy->CreateRHI();
        MaterialProxy->Shader->AddUniformParameter("Transform");

        TextureProxy = SharedPtr<FTextureResourceProxy>(Texture->CreateProxy());
        TextureProxy->CreateRHI();

        Transform.Scale({0.5, 0.5f, 0.0f});
        Transform.Translate({0.25f, 0.25f, 0.0f});
        LogInfo("Renderer initialize success.")
    }

    void FRenderer::RendererMain()
    {
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);

        MaterialProxy->Shader->Bind();
        MaterialProxy->Shader->SetMatParameter("Transform", Transform);
        TextureProxy->Bind(0);
        RHICommand->DrawMesh(Proxy->VertexArray, Proxy->IndexBuffer);
        Context->SwapBuffer();
    }

	void FRenderer::DestroyRenderer()
	{
        delete Proxy;
        delete MaterialProxy;
        TextureProxy = nullptr;
        delete Component;
	}
}