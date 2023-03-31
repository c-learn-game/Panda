#include "OpenGLPlatformRHI.h"
#include "glad/glad.h"

namespace Panda
{ 
    void FOpenGLPlatformRHI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void FOpenGLPlatformRHI::SetClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void FOpenGLPlatformRHI::SetViewport(int x, int y, int w, int h)
    {
        glViewport(x, y, w, h);
    }
}
