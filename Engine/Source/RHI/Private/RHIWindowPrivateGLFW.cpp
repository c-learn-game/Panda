//
// Created by chendebi on 2023/4/30.
//

#include "RHIWindowPrivateGLFW.h"
#include "RHI/RHIWindow.h"
#include "GLFW/glfw3.h"
#include "RHI/Application.h"

static void OnWindowClose(GLFWwindow* Window)
{
    Panda::Application::Get()->Quit();
}

namespace Panda
{
    RHIWindowPrivateGLFW::RHIWindowPrivateGLFW(RHIWindow* ParentWindow)
    : RHIWindowPrivate(ParentWindow)
    , Window(ParentWindow)
    {
    }

    RHIWindowPrivateGLFW::~RHIWindowPrivateGLFW()
    {
        Destroy();
    }

    bool RHIWindowPrivateGLFW::CreateWindow(const FString &WindowTitle)
    {
        WindowP = glfwCreateWindow(RHIWINDOW_DEFAULT_WIDTH, RHIWINDOW_DEFAULT_HEIGHT, WindowTitle.c_str(), nullptr,
                                   nullptr);
        glfwSetWindowUserPointer(WindowP, Window);
        glfwSetWindowCloseCallback(WindowP, OnWindowClose);
        checkf(WindowP != nullptr, "create glfw window failed!")
        return WindowP;
    }

    void RHIWindowPrivateGLFW::Destroy()
    {
        if (WindowP)
        {
            glfwDestroyWindow(WindowP);
            WindowP = nullptr;
        }
    }

    bool RHIWindowPrivateGLFW::SetWindowTitle(const FString &NewTitle)
    {
        glfwSetWindowTitle(WindowP, NewTitle.c_str());
        return true;
    }

    bool RHIWindowPrivateGLFW::SetWindowSize(int Width, int Height)
    {
        glfwSetWindowSize(WindowP, Width, Height);
        return true;
    }

    void RHIWindowPrivateGLFW::ShowWindow(bool bShow)
    {
        if (bShow)
            glfwShowWindow(WindowP);
        else
            glfwHideWindow(WindowP);
    }
}