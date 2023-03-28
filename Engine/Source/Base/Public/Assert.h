#ifndef ASSERT_H
#define ASSERT_H

#include "Logging/Logging.h"

#ifdef PANDA_BUDEG
    #if defined(PANDA_SYSTEM_WINDOWS)
        #define PANDA_DEBUGBREAK() __debugbreak();
        #define PANDA_ENABLE_ASSETS
    #else
        #warning current system doesn't support debugbreak yet!
    #endif

#else
    #define PANDA_DEBUGBREAK()
#endif

#ifdef PANDA_ENABLE_ASSETS

#define check(exp)\
    if (!(exp))\
	{\
		LogInfo(LogSystem, "check %s failed!", #exp);\
		PANDA_DEBUGBREAK();\
	}

#define checkmsg(exp, msg, ...)\
    if (!(exp))\
    {\
        LogError(LogSystem, msg, ##__VA_ARGS__)\
        PANDA_DEBUGBREAK();\
    }\

#else
#define check(...)
#define checkmsg(...)
#endif

#endif