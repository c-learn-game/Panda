//
// Created by chendebi on 2023/4/25.
//

#ifndef PANDA_BASICVARIABLES_H
#define PANDA_BASICVARIABLES_H

#include <iostream>
#include <vector>
#include <unordered_map>
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

    template<typename T>
    using TArray = std::vector<T>;

	template<typename Key, typename Value>
    using THash = std::unordered_map<Key, Value>;

    using uint = unsigned int;
    using uint8 = unsigned char;
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
