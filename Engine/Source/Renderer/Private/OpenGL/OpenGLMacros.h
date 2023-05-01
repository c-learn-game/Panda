//
// Created by chendebi on 2023/5/1.
//

#ifndef TEST_OPENGLMACROS_H
#define TEST_OPENGLMACROS_H

#include "Basic/Basic.h"
#include "glad/glad.h"

#if PANDA_OPENGL_VERSION_MAJOR <=4 and PANDA_OPENGL_VERSION_MINOR < 5
#define PANDA_GL_CALL(e) \
    e;                     \
    {                    \
    while (GLenum ErrorCode = glGetError())\
    {\
        LogWarn("OpenGL called with error code {0:x}", ErrorCode)\
        LogWarn("   File: {}", __FILE__)        \
        LogWarn("   Line: {}", __LINE__)         \
    }}
#else
#define PANDA_GL_CALL(e) e;
#endif

#endif //TEST_OPENGLMACROS_H
