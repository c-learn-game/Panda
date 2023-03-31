﻿#ifndef OPENGLBASE_H
#define OPENGLBASE_H

#include "Base/Base.h"
#include "glad/glad.h"
#include "OpenGLObject.h"

#if PANDA_OPENGL_VERSION_MAJOR <= 4 and PANDA_OPENGL_VERSION_MINOR < 5 and defined PANDA_BUDEG

#define PANDA_GL_CALL(exp)\
    exp;\
    {\
        bool bHasError = false;\
        while (const GLenum ErrorCode = glGetError())\
        {\
            LogInfo(LogSystem, "OpenGL Error With Code: %x", ErrorCode)\
            bHasError = true;\
        }\
        check(!bHasError)\
    }

#else
    #define PANDA_GL_CALL(exp) \
    exp;

#endif
#endif
