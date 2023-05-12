
#ifndef PANDA_OPENGLMACROS_H
#define PANDA_OPENGLMACROS_H

#include "Basic/Basic.h"
#include "glad/glad.h"

#if true//PANDA_OPENGL_VERSION_MAJOR <=4 and PANDA_OPENGL_VERSION_MINOR < 5
#define PANDA_GL_CALL(e) \
    e;                     \
    {                    \
    while (GLenum ErrorCode = glGetError())\
    {\
        LogWarn("OpenGL called with error code 0x{0:x}", ErrorCode)\
        LogWarn("   File: {}", __FILE__)        \
        LogWarn("   Line: {}", __LINE__)         \
    }}

#define PANDA_CHECK_GL_ERROR(...) \
    {                            \
        bool bError = false;\
        while (GLenum ErrorCode = glGetError())\
        {\
            LogWarn("OpenGL called with error code 0x{0:x}", ErrorCode)\
            LogWarn("   File: {}", __FILE__)        \
            LogWarn("   Line: {}", __LINE__)         \
        }\
    }
#else
#define PANDA_GL_CALL(e) e;
#define GL_CHECK_ERROR(msg)
#endif

#endif //TEST_OPENGLMACROS_H
