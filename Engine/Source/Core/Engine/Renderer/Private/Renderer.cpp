

#include "Core/Engine/Renderer/Renderer.h"
#include "Core/Math/Vector4.h"
#include "Core/Engine/Game/PrimitiveSceneComponent.h"
#include "Core/Engine/Renderer/PrimitiveSceneProxy.h"
#include "Core/Engine/Game/Material.h"
#include "Core/Engine/Renderer/MaterialResourceProxy.h"
#include "Core/Engine/Game/Texture.h"
#include "Core/Engine/Renderer/TextureResourceProxy.h"
#include "Core/Engine/Private/EngineMacros.h"
#include "RHI/RHI.h"
#include "Core/Engine/Asset/Package.h"
#include "Core/Math/MathCore.h"
#include "Core/Engine/Engine.h"
#include "Core/Engine/Renderer/SceneView.h"

namespace Panda
{
    FRenderer::FRenderer(const SharedPtr<FRenderContext> &RenderContext)
    : Context(RenderContext)
    {

    }

    void FRenderer::Initialize()
    {
        Context->MakeCurrent();

        SceneView = GGame->GetViewportClient()->CreateSceneView();

        Component = LoadObject<UPrimitiveSceneComponent>("/Engine/SimpleMesh.asset");

        Material = MakeShared<UMaterial>(ENGINE_SHADER("/Private/LocalStaticMesh.vert"),
                                         ENGINE_SHADER("/Private/LocalStaticMesh.frag"));
        Material->LoadAsset();

        Texture = MakeShared<UTexture>(ENGINE_RESOURCE("/Test/container.jpg"));
        Texture->LoadAsset();

        FaceTexture = MakeShared<UTexture>(ENGINE_RESOURCE("/Test/awesomeface.png"));
        FaceTexture->LoadAsset();
        FaceTexture->Format = FTextureFormat::RGBA;

        Proxy = Component->CreateProxy();
        Proxy->CreateRHI();

        MaterialProxy = Material->CreateProxy();
        MaterialProxy->CreateRHI();
        MaterialProxy->Shader->Bind();
        MaterialProxy->Shader->AddUniformParameter("Transform");
        MaterialProxy->Shader->AddUniformParameter("ContainerTex");
        MaterialProxy->Shader->AddUniformParameter("ColorTex");

        TextureProxy = SharedPtr<FTextureResourceProxy>(Texture->CreateProxy());
        TextureProxy->CreateRHI();

        FaceTextureProxy = SharedPtr<FTextureResourceProxy>(FaceTexture->CreateProxy());
        FaceTextureProxy->CreateRHI();

        LogInfo("Renderer initialize success.")
    }

    void FRenderer::RendererMain()
    {
        TotalTime += SceneView->Duration;
        RHICommand->SetClearColor({0.2f, 0.3f, 0.3f, 1.0f});
        RHICommand->Clear();
        auto Mat = FMath::Translate(Transform, {static_cast<float>(FMath::Sin(TotalTime)), 0, 0});
        RHICommand->SetViewport(SceneView->ViewportRect);
        MaterialProxy->Shader->Bind();
        MaterialProxy->Shader->SetMatParameter("Transform", Mat);
        MaterialProxy->Shader->SetTexture2DParameter("ContainerTex", TextureProxy->TextureResource.get(), 0);
        MaterialProxy->Shader->SetTexture2DParameter("ColorTex", FaceTextureProxy->TextureResource.get(), 1);
        RHICommand->DrawMesh(Proxy->VertexArray, Proxy->IndexBuffer);
        Context->SwapBuffer();
    }

	void FRenderer::DestroyRenderer()
	{
        delete Proxy;
        delete MaterialProxy;
        TextureProxy = nullptr;
        FaceTextureProxy = nullptr;
        delete Component;
	}
}