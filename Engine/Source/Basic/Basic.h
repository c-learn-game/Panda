//
// Created by chendebi on 2023/4/25.
//

#ifndef PANDA_BASIC_H
#define PANDA_BASIC_H

#include <iostream>

namespace Panda
{
    template<typename T>
    using SharedPtr = std::shared_ptr<T>;

    template<typename T, typename ...Args>
    constexpr SharedPtr<T> MakeShared(Args&& ...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

}

#endif //PANDA_BASIC_H
