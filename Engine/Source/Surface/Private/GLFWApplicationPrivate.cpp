#include "GLFWApplicationPrivate.h"

#include "Base/Public/Assert.h"
#include "GLFW/glfw3.h"

void OnGLFWError(int Code, const char* Desp)
{
    LogError(LogSystem, "Glfw get error with code: %d, error: %s", Code, Desp);
}

namespace Panda
{
    CGLFWApplicationPrivate::CGLFWApplicationPrivate()
    {
        glfwSetErrorCallback(OnGLFWError);
        glfwInit();
#ifdef PANDA_OPENGL
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, PANDA_OPENGL_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, PANDA_OPENGL_VERSION_MINOR);
        glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#else
#error Not specified graphics platform
#endif
    }

    void CGLFWApplicationPrivate::PollEvents()
    {
        glfwPollEvents();
    }
}
