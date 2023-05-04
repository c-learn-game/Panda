//
// Created by chendebi on 2023/5/1.
//

#include "Renderer/Renderer.h"
#include "glad/glad.h"
#include "OpenGL/OpenGLShaderObject.h"
#include "OpenGL/OpenGLVertexBufferObject.h"
#include "OpenGL/OpenGLVertexArrayObject.h"
#include "OpenGL/OpenGLIndexBufferObject.h"
#include "Components/PrimitiveComponent.h"
#include "Core/Math/Vector4.h"

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

static float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f,
};

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
        Shader = MakeShared<FOpenGLShaderObject>(vertexShaderSource, fragShaderSource);
        Component = MakeShared<UPrimitiveComponent>();
        Component->AddVertex(FVector4( -0.5f, -0.5f, 0.0f, 1.0f));
        Component->AddVertex(FVector4( 0.5f, -0.5f, 0.0f, 1.0f));
        Component->AddVertex(FVector4( 0.0f, 0.5f, 0.0f, 1.0f));
        Proxy = Component->CreateProxy();
        LogInfo("Renderer initialize success.")
    }

    void FRenderer::RendererMain()
    {
        //glViewport(0, 0, 600, 400);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //LogInfo("check error {}", glGetError())
        glClear(GL_COLOR_BUFFER_BIT);
        //LogInfo("check error {}", glGetError())
        // draw our first triangle
        Shader->Bind();
        Proxy->Draw();
        //vao->DrawElements(ibo);

        Context->SwapBuffer();
    }

	void FRenderer::DestroyRenderer()
	{
		Shader = nullptr;
	}
}