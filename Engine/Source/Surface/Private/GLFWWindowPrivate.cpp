#include "GLFWWindowPrivate.h"

#include "GLFW/glfw3.h"

Panda::CGLFWWindowPrivate::CGLFWWindowPrivate(const CString& WindowTitle)
{
    WindowHandle = glfwCreateWindow(WindowDefaultWidth, WindowDefaultHeight, WindowTitle.c_str(),nullptr, nullptr);
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
    check(WindowHandle)
    glfwSetWindowTitle(WindowHandle, NewTitle.c_str());
}

void Panda::CGLFWWindowPrivate::SetWindowSize(CIntSize NewSize)
{
    check(WindowHandle)
    glfwSetWindowSize(WindowHandle, NewSize.Width, NewSize.Height);
}
