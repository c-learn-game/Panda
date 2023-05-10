//
// Created by chendebi on 2023/5/1.
//

#include "Renderer/Renderer.h"
#include "Core/Math/Vector4.h"
#include "Core/Engine/PrimitiveSceneComponent.h"
#include "Core/Engine/PrimitiveSceneProxy.h"
#include "Core/Engine/Material.h"
#include "Core/Engine/MaterialResourceProxy.h"
#include "Core/Path/Path.h"
#include "RHI/RHI.h"

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
        Component = MakeShared<UPrimitiveSceneComponent>();
        Component->AddVertex(FVector4( -0.5f, -0.5f, 0.0f, 1.0f));
        Component->AddVertex(FVector4( 0.5f, -0.5f, 0.0f, 1.0f));
        Component->AddVertex(FVector4( 0.0f, 0.5f, 0.0f, 1.0f));
        Component->AddVertex(FVector4( -0.5f, 0.5f, 0.0f, 1.0f));
		Component->SetVertexColor(0, 0, { 1.0f, 0.0f, 0.0f });
		Component->SetVertexColor(1, 0, { 0.0f, 1.0f, 0.0f });
		Component->SetVertexColor(2, 0, { 0.0f, 0.0f, 1.0f });
		Component->SetVertexColor(3, 0, { 1.0f, 1.0f, 0.0f });
		Component->AddElementIndex(0, 1, 2);
		Component->AddElementIndex(0, 2, 3);
        Proxy = Component->CreateProxy();
        Proxy->CreateResource();


        Material = UMaterial::LoadMaterial(UMaterial::EngineShaderSourcePath("/Private/LocalStaticMesh.vert"),
                                           UMaterial::EngineShaderSourcePath("/Private/LocalStaticMesh.frag"));
        MaterialProxy = MakeShared<FMaterialResourceProxy>(Material);
        MaterialProxy->CreateResource();
        LogInfo("Renderer initialize success.")
    }

    void FRenderer::RendererMain()
    {
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);

        MaterialProxy->Shader->Bind();
        RHICommand->DrawMesh(Proxy->GetVertexArrayResource(), Proxy->GetIndexBufferResource());
        Context->SwapBuffer();
    }

	void FRenderer::DestroyRenderer()
	{
        MaterialProxy = nullptr;
	}
}