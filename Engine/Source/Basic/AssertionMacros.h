//
// Created by chendebi on 2023/4/29.
//

#ifndef PANDA_ASSERTIONMACROS_H
#define PANDA_ASSERTIONMACROS_H

#include "BasicVariables.h"
#include "Logging.h"
#include "BasicMacros.h"

#define check(e) \
    if (!(e))    \
    {            \
        LogWarn("check {} failed!", #e) \
        LogWarn("   File: {}",  __FILE__)         \
        LogWarn("   Line: {}",  __LINE__)         \
        PANDA_DEBUGBREAK()             \
    }

#ifdef __MSVC_VAR__
#define checkf(e, ...) \
    if (!(e))    \
    {                               \
        LogWarn(##__VA_ARGS__)                            \
        LogWarn("check {} failed!", #e) \
        LogWarn("   File: {}",  __FILE__)         \
        LogWarn("   Line: {}",  __LINE__)         \
        PANDA_DEBUGBREAK()             \
    }
#else
#define checkf(e, msg, ...) \
    if (!(e))    \
    {                               \
        LogWarn(msg, ##__VA_ARGS__)                            \
        LogWarn("check {} failed!", #e) \
        LogWarn("   File: {}",  __FILE__)         \
        LogWarn("   Line: {}",  __LINE__)         \
        PANDA_DEBUGBREAK()             \
    }
#endif

#endif //PANDA_ASSERTIONMACROS_H
