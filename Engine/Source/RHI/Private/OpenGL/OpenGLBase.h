#ifndef OPENGLBASE_H
#define OPENGLBASE_H

#include "Base/Base.h"
#include "glad/glad.h"

#if PANDA_OPENGL_VERSION_MAJOR <= 4 and PANDA_OPENGL_VERSION_MINOR < 5 and defined PANDA_DEBUG

#define PANDA_GL_CALL(exp)\
    exp;\
    {\
        bool bHasError = false;\
        while (const GLenum ErrorCode = glGetError())\
        {\
			CString CodeDesc("Unknown Error!");\
			switch (ErrorCode)\
			{\
				case GL_INVALID_ENUM:\
					CodeDesc = "INVALID ENUM";\
					break;\
				case GL_INVALID_VALUE:\
					CodeDesc = "INVALID VALUE";\
					break;\
				case GL_INVALID_OPERATION:\
					CodeDesc = "INVALID OPERATION";\
					break;\
				default:\
					break;\
			}\
			LogWarning(LogSystem, "OpenGL Error [%s] %x",CodeDesc.c_str(), ErrorCode)\
			LogWarning(LogSystem, "		FILE:     %s", __FILE__)\
			LogWarning(LogSystem, "		FUNCTION: %s", __FUNCTION__)\
			LogWarning(LogSystem, "		LINE:     %d", __LINE__)\
            bHasError = true;\
        }\
        check(!bHasError)\
    }

#else
    #define PANDA_GL_CALL(exp) \
    exp;

#endif
#endif
