#include "Renderer.h"
#include "glad/glad.h"
#include "Public/RendererContext.h"
#include "RHI/OpenGL/Public/VertexBufferObject.h"
#include <iostream>

#include "RHI/OpenGL/Public/VertexArrayObject.h"

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
    FRenderer::FRenderer(const SharedPtr<FRenderContext>& Context)
        : RendererContext(Context)
    {
        
    }

    void FRenderer::Init()
    {
        RendererContext->Init();
    }

    void FRenderer::RenderMain()
    {
        RendererContext->Init();
        glClearColor(0.2, 0.3, 0.4, 1.0);

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512] = {0};
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // fragment shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // link shaders
        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        
        float vertices[] =
        {
            -0.5, -0.5, 0.0,
            0.5, -0.5, 0.0,
            0.0, 0.5, 0.0
        };
        FVertexArrayObject vao;
        FVertexBufferObject vbo(vertices, sizeof(vertices));
        vbo.Init();
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        vao.Init();
        CArray<FVertexArrayAttributes> Attributes;
        Attributes.Add(FVertexArrayAttributes(3, false, 3 * sizeof(float)));
        vao.AddAttributes(&vbo, Attributes);
        
		glViewport(0, 0, 800, 600);
        while (true)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glUseProgram(shaderProgram);
			vao.Use();// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
            PANDA_GL_CALL(glDrawArrays(GL_TRIANGLES, 0, 3))
            RendererContext->SwapBuffers();
        }
    }
}
