//
// Created by chendebi on 2023/4/29.
//

#ifndef PANDA_BASICMACROS_H
#define PANDA_BASICMACROS_H

#if defined(PANDA_DEBUG)
    #if defined(_MSC_VER)
        #define PANDA_DEBUGBREAK() __debugbreak();
    #elif defined(__GNUC__)
        #define PANDA_DEBUGBREAK() __builtin_trap();
    #else
        #warning "current compiler not support debugbreak"
        #define PANDA_DEBUGBREAK()
    #endif
#else
    #define PANDA_DEBUGBREAK()
#endif

#define PANDA_UNUSED(VAR) (void)VAR;

#endif //PANDA_BASICMACROS_H
