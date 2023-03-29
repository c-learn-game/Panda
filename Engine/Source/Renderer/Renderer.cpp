#include "Renderer.h"
#include "glad/glad.h"
#include "Public/RendererContext.h"
#include "RHI/OpenGL/Public/VertexBufferObject.h"

#include "RHI/OpenGL/Public/OpenGLShaderObject.h"
#include "RHI/OpenGL/Public/VertexArrayObject.h"
#include "Surface/Public/Application.h"

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

namespace Panda
{
    FRenderer* FRenderer::Get()
    {
        static FRenderer Renderer;
        return &Renderer;
    }

    void RenderThreadMain(const SharedPtr<FRenderContext>& Context)
    {
        Context->Init();
        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

        FOpenGLShaderObject Shader(vertexShaderSource, fragmentShaderSource);
        
        float vertices[] =
        {
            -0.5, -0.5, 0.0,
            0.5, -0.5, 0.0,
            0.0, 0.5, 0.0
        };
        FVertexArrayObject vao;
        FVertexBufferObject vbo(vertices, sizeof(vertices));
        vbo.Init();
        vbo.AddLayout<float>(3, false);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        vao.Init();
        vao.SetBuffer(&vbo);
        
        glViewport(0, 0, 800, 600);
        while (true)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            Shader.Use();
            vao.Use();
            PANDA_GL_CALL(glDrawArrays(GL_TRIANGLES, 0, 3))
            Context->SwapBuffers();
        }
    }
    
}
