//
// Created by chendebi on 2023/4/25.
//

#ifndef PANDA_BASICVARIABLES_H
#define PANDA_BASICVARIABLES_H

#include <iostream>
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
}

#endif //PANDA_BASICVARIABLES_H
