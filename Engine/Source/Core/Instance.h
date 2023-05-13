
#ifndef PANDA_INSTANCE_H
#define PANDA_INSTANCE_H

#include "Basic/Basic.h"

/**
 * 单例的创建方法：
 * 1. public继承自UInstance
 * 2. 在类的声明开头使用INSTANCE_CLASS宏
 * 3. 不得实现构造函数
 */

#define INSTANCE_CLASS(ClassName) \
        friend class UInstance<ClassName>;\
    public:                       \
        ClassName(const ClassName&) = delete;\
        ClassName operator=(const ClassName&) const = delete;\
        ClassName& operator=(const ClassName&) = delete;     \
    private:                      \
        ClassName() = default;\
    protected:                    \
        friend class UInstanceManager;

namespace Panda
{
    template<typename InstanceClass>
    class UInstance
    {
    public:
        UInstance(const UInstance& ) = delete;
        UInstance& operator=(const UInstance&) = delete;
        UInstance operator=(const UInstance&) const = delete;

        virtual ~UInstance() = default;

        static InstanceClass* Get()
        {
            static InstanceClass Inst;
            return &Inst;
        }

    protected:
        UInstance() = default;
        // 初始化单例时调用
        virtual void Initialize() {}

    };

}

#endif //PANDA_INSTANCE_H
