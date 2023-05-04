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

#define checkf(e, format_text, ...) \
    if (!(e))    \
    {                               \
        LogWarn(format_text, ##__VA_ARGS__)                            \
        LogWarn("check {} failed!", #e) \
        LogWarn("   File: {}",  __FILE__)         \
        LogWarn("   Line: {}",  __LINE__)         \
        PANDA_DEBUGBREAK()             \
    }

#endif //PANDA_ASSERTIONMACROS_H
