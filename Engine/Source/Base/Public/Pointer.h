#ifndef POINTER_H
#define POINTER_H
#include <complex>
#include <memory>

namespace Panda
{
    template<typename _T>
    using SharedPtr = std::shared_ptr<_T>;

    template<typename _T, typename ... Args>
    constexpr SharedPtr<_T> MakeSharedPtr(Args&& ... args)
    {
        return std::make_shared<_T>(std::forward<Args>(args)...);
    }

    template<typename ClassType>
    using UniquePtr = std::unique_ptr<ClassType>;

    template<typename _T, typename ... Args>
    constexpr UniquePtr<_T> MakeUniquePtr(Args&& ... args)
    {
        return std::make_unique<_T>(std::forward<Args>(args)...);
    }
}

#endif