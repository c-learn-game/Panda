//
// Created by chendebi on 2023/4/30.
//

#include "RHIApplicationPrivateGLFW.h"
#include "GLFW/glfw3.h"
namespace Panda
{
    bool RHIApplicationPrivateGLFW::Initialize()
    {
        return glfwInit();
    }

    void RHIApplicationPrivateGLFW::DestroyApplication()
    {
        glfwTerminate();
    }

    void RHIApplicationPrivateGLFW::PollEvents()
    {
        glfwPollEvents();
    }
}
