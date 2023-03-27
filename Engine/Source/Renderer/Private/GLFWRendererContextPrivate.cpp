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

    checkmsg(Status, "Initilize glad failed!")
}

void Panda::FGLFWRendererContextPrivate::SwapBuffers()
{
    glfwSwapBuffers(WindowHandle);
}
