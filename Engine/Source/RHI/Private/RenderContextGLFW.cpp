//
// Created by chendebi on 2023/5/1.
//

#include "RenderContextGLFW.h"
#include "RHIWindowPrivateGLFW.h"
#include "Application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#if PANDA_OPENGL_VERSION_MAJOR >=4 and PANDA_OPENGL_VERSION_MINOR >= 5
static void OpenGLDebugMessageCallBack(GLenum source,
                                  GLenum type,
                                  GLuint id,
                                  GLenum severity,
                                  GLsizei length,
                                  const GLchar *message,
                                  const void *userParam)
{
    LogWarn("OpenGL called with error!")
    LogWarn("   {}", message)
}
#endif

namespace Panda
{
    RenderContextGLFW::RenderContextGLFW(const SharedPtr<Panda::RHIWindow> &ContextWindow)
    : FRenderContext(ContextWindow)
    {
        SharedPtr<RHIWindowPrivateGLFW> w = std::dynamic_pointer_cast<RHIWindowPrivateGLFW>(ContextWindow->P);
        check(w)
        Window = w->WindowP;
    }

    void RenderContextGLFW::MakeCurrent()
    {
        glfwMakeContextCurrent(Window);
        // load opengl functions
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        {
            LogCritical("OpenGL load failed!")
            Application::Get()->Quit();
            return;
        }
        LogInfo("OpenGL load success!")
        LogInfo("   Vendor:   {}", (char*)glGetString(GL_VENDOR))
        LogInfo("   Renderer: {}", (char*)glGetString(GL_RENDERER))
        LogInfo("   Version:  {}", (char*)glGetString(GL_VERSION))

#if PANDA_OPENGL_VERSION_MAJOR >=4 and PANDA_OPENGL_VERSION_MINOR >= 5
        glDebugMessageCallback(OpenGLDebugMessageCallBack);
#endif

    }

    void RenderContextGLFW::SwapBuffer()
    {
        glfwSwapBuffers(Window);
    }
}
