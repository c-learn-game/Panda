//
// Created by chendebi on 2023/4/25.
//

#ifndef PANDA_BASICVARIABLES_H
#define PANDA_BASICVARIABLES_H

#include <iostream>
#include <vector>
#include "BasicMacros.h"

namespace Panda
{
    template<typename T>
    using SharedPtr = std::shared_ptr<T>;

    template<typename T, typename ...Args>
    constexpr SharedPtr<T> MakeShared(Args&& ...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    // 类型别名
    using FString = std::string;

    template<typename T>
    using TArray = std::vector<T>;

    using uint = unsigned int;
    using ulong = unsigned long;

    struct FSize
    {
        int Width;
        int Height;

        FSize(int w = 0, int h = 0) : Width(w), Height(h) {}

        bool IsValid() const { return Width > 0 && Height > 0; }
    };

}

#endif //PANDA_BASICVARIABLES_H
