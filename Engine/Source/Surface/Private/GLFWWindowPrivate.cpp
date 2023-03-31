#include "GLFWWindowPrivate.h"

#include "GLFW/glfw3.h"
#include "Surface/Public/Window.h"
#include "Launch/GraphicsThreadPoolSubsystem.h"
#include "Event/Public/ApplicationEvents.h"
#include "Renderer/Command/ViewportCommand.h"
#include "Renderer/Public/RenderThread.h"

void OnGLFWWindowClose(GLFWwindow* WindowHandle)
{
    auto* Interface = reinterpret_cast<Panda::CWindow*>(glfwGetWindowUserPointer(WindowHandle));
    check(Interface)
    Panda::FGraphicsThreadPoolSubsystem::Get()->PushEventToMainThread(Panda::MakeSharedPtr<Panda::CWindowCloseEvent>(Interface), true);
}

void OnGLFWWindowFrameBufferSizeChanged(GLFWwindow* WindowHandle, int Width, int Height)
{
    Panda::FRenderer::AddDrawCommand<Panda::FViewportCommand>(0, 0, Width, Height);
}

void OnGLFWWindowResizeEvent(GLFWwindow* WindowHandle, int Width, int Height)
{
    auto* Interface = reinterpret_cast<Panda::CWindow*>(glfwGetWindowUserPointer(WindowHandle));
    check(Interface)
    Panda::FGraphicsThreadPoolSubsystem::Get()->PushEventToMainThread(Panda::MakeSharedPtr<Panda::CWindowResizeEvent>(Interface, Width, Height), true);
}

void OnGLFWWindowMouseButtonEvent(GLFWwindow* WindowHandle, int Button, int Action, int Mods)
{
}

Panda::CGLFWWindowPrivate::CGLFWWindowPrivate(CWindow* WindowInterface, const CString& WindowTitle)
    : CWindowPrivate(WindowInterface, WindowTitle)
{
    check(WindowInterface)
    WindowHandle = glfwCreateWindow(WindowDefaultWidth, WindowDefaultHeight, WindowTitle.c_str(),nullptr, nullptr);
    check(WindowHandle)
    
    
    glfwSetWindowUserPointer(WindowHandle, WindowInterface);
    glfwSetWindowCloseCallback(WindowHandle,OnGLFWWindowClose);
    glfwSetWindowSizeCallback(WindowHandle, OnGLFWWindowResizeEvent);
    glfwSetMouseButtonCallback(WindowHandle, OnGLFWWindowMouseButtonEvent);
    glfwSetFramebufferSizeCallback(WindowHandle, OnGLFWWindowFrameBufferSizeChanged);
}

Panda::CGLFWWindowPrivate::~CGLFWWindowPrivate()
{
    if (WindowHandle)
    {
        glfwDestroyWindow(WindowHandle);
    }
}

void Panda::CGLFWWindowPrivate::SetWindowTitle(const CString& NewTitle)
{
    glfwSetWindowTitle(WindowHandle, NewTitle.c_str());
}

void Panda::CGLFWWindowPrivate::SetWindowSize(CIntSize NewSize)
{
    glfwSetWindowSize(WindowHandle, NewSize.Width, NewSize.Height);
}

void Panda::CGLFWWindowPrivate::DestroyWindow()
{
    glfwDestroyWindow(WindowHandle);
}
