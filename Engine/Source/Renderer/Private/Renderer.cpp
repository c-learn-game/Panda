//
// Created by chendebi on 2023/5/1.
//

#include "Renderer/Renderer.h"
#include "glad/glad.h"
#include "Core/Math/Vector4.h"
#include "Core/Engine/PrimitiveSceneComponent.h"
#include "Core/Engine/PrimitiveSceneProxy.h"
#include "RHI/Resource/RHIShaderResource.h"
#include "RHI/Resource/RHIIndexBufferResource.h"

const static char* vertexShaderSource = "#version 400 core\n"
                             "layout(location=0) in vec3 vPos;\n"
                             "layout(location=1) in vec3 vColor;\n"
                             "out vec4 pColor;\n"
                             "void main()\n"
                             "{\n"
                             "  gl_Position = vec4(vPos.x, vPos.y, vPos.z, 1.0f);\n"
                             "  pColor = vec4(vColor.x, vColor.y, vColor.z, 1.0f);\n"
                             "}\n\0";

const static char* fragShaderSource = "#version 400 core\n"
                           "out vec4 FragColor;\n"
                           "in vec4 pColor;\n"
                           "void main()\n"
                           "{\n"
                           "    FragColor = pColor;\n"
                           "}\n\0";

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
        Shader = FRHIShaderResource::Create();
        Shader->SetShaderSource(vertexShaderSource, fragShaderSource);
        Shader->InitResource();
        Component = MakeShared<UPrimitiveSceneComponent>();
        Component->AddVertex(FVector4( -0.5f, -0.5f, 0.0f, 1.0f));
        Component->AddVertex(FVector4( 0.5f, -0.5f, 0.0f, 1.0f));
        Component->AddVertex(FVector4( 0.0f, 0.5f, 0.0f, 1.0f));
		Component->SetVertexColor(0, 0, { 1.0f, 0.0f, 0.0f });
		Component->SetVertexColor(1, 0, { 0.0f, 1.0f, 0.0f });
		Component->SetVertexColor(2, 0, { 0.0f, 0.0f, 1.0f });
		Component->AddElementIndex(0, 1, 2);
        Proxy = Component->CreateProxy();
        LogInfo("Renderer initialize success.")
    }

    void FRenderer::RendererMain()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Shader->Bind();
        Proxy->Draw();
        Proxy->ibo->Bind();
        glDrawElements(GL_TRIANGLES, Proxy->ibo->GetIndexCount(), GL_UNSIGNED_INT, nullptr);

        Context->SwapBuffer();
    }

	void FRenderer::DestroyRenderer()
	{
		Shader = nullptr;
	}
}