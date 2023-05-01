//
// Created by chendebi on 2023/4/30.
//

#include "RHIApplicationPrivateGLFW.h"
#include "GLFW/glfw3.h"
namespace Panda
{
    bool RHIApplicationPrivateGLFW::Initialize()
    {
        bool bInited = glfwInit();
        if (!bInited) return false;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, PANDA_OPENGL_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, PANDA_OPENGL_VERSION_MINOR);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        return true;
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
