#include "RHI/OpenGL/Public/OpenGLBase.h"
#include "glad/glad.h"

namespace Panda
{
    bool GLCheckError()
    {
        bool bNoError = true;
        while (const GLenum ErrorCode = glGetError())
        {
            LogInfo(LogSystem, "OpenGL Error With Code: %d", ErrorCode)
            bNoError = false;
        }

        return bNoError;
    }

    void GLClearError()
    {
        while (GLenum ErrorCode = glGetError());
    }
}
