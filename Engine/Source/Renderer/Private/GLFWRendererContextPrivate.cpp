#include "GLFWRendererContextPrivate.h"
#include "Surface/Public/Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Surface/Private/GLFWWindowPrivate.h"

Panda::FGLFWRendererContextPrivate::FGLFWRendererContextPrivate(const SharedPtr<CWindow>& InContextWindow)
    : FRendererContextPrivate(InContextWindow),
      ContextWindow(InContextWindow)
{
    WindowHandle = ((CGLFWWindowPrivate*)GetContextWindowPrivate())->WindowHandle;
}

void Panda::FGLFWRendererContextPrivate::Init()
{
    glfwMakeContextCurrent(WindowHandle);
    
    int Status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    checkmsg(Status, "Initialize glad failed!")

    LogInfo(LogSystem, "OpenGL Info")
    LogInfo(LogSystem, "   OpenGL Vendor: %s", glGetString(GL_VENDOR))
    LogInfo(LogSystem, "   OpenGL Renderer: %s", glGetString(GL_RENDERER))
    LogInfo(LogSystem, "   OpenGL Version: %s", glGetString(GL_VERSION))
}

void Panda::FGLFWRendererContextPrivate::SwapBuffers()
{
    glfwSwapBuffers(WindowHandle);
}
