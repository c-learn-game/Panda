//
// Created by chendebi on 2023/4/25.
//

#ifndef PANDA_BASICVARIABLES_H
#define PANDA_BASICVARIABLES_H

#include <iostream>
#include "BasicMacros.h"
#include "String.h"

namespace Panda
{
    template<typename T>
    using SharedPtr = std::shared_ptr<T>;

    template<typename T, typename ...Args>
    constexpr SharedPtr<T> MakeShared(Args&& ...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    using uint = unsigned int;
    using uint8 = unsigned char;
    using ulong = unsigned long;
    using longlong = long long;
    using ulonglong = unsigned long long;

    struct FSize
    {
        int Width;
        int Height;

        explicit FSize(int w = 0, int h = 0) : Width(w), Height(h) {}

        bool IsValid() const { return Width > 0 && Height > 0; }
    };

    struct FIntRect
    {
        int X = 0;
        int Y = 0;
        int Width = 0;
        int Height = 0;

        explicit FIntRect(int w = 0, int h = 0)
        : Width(w), Height(h)
        {}

        FIntRect(int x, int y, int w, int h)
        : X(x), Y(y), Width(w), Height(h)
        {}
    };
}

#endif //PANDA_BASICVARIABLES_H
