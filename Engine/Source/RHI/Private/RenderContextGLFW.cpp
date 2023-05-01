//
// Created by chendebi on 2023/5/1.
//

#include "RenderContextGLFW.h"
#include "RHIWindowPrivateGLFW.h"
#include "Application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

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
    }

    void RenderContextGLFW::SwapBuffer()
    {
        glfwSwapBuffers(Window);
    }
}
