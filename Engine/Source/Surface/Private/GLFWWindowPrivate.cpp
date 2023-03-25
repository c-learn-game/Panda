#include "GLFWWindowPrivate.h"

#include "GLFW/glfw3.h"
#include "Surface/Public/Window.h"
#include "Surface/Public/Application.h"
#include "Event/Public/ApplicationEvents.h"

void OnGLFWWindowClose(GLFWwindow* WindowHandle)
{
    Panda::CWindow* Interface = reinterpret_cast<Panda::CWindow*>(glfwGetWindowUserPointer(WindowHandle));
    check(Interface)
    Panda::CApplication::Get()->AddEvent(new Panda::CWindowCloseEvent(Interface));
}

Panda::CGLFWWindowPrivate::CGLFWWindowPrivate(CWindow* WindowInterface, const CString& WindowTitle)
    : CWindowPrivate(WindowInterface, WindowTitle)
{
    check(WindowInterface)
    WindowHandle = glfwCreateWindow(WindowDefaultWidth, WindowDefaultHeight, WindowTitle.c_str(),nullptr, nullptr);
    check(WindowHandle)
    
    
    glfwSetWindowUserPointer(WindowHandle, WindowInterface);
    glfwSetWindowCloseCallback(WindowHandle,OnGLFWWindowClose);
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
