#ifndef OPENGLOBJECT_H
#define OPENGLOBJECT_H

namespace Panda
{
    class FOpenGLObject
    {
    public:
        virtual ~FOpenGLObject() = default;

        // 使用当前对象
        virtual void Use() = 0;

        // 不使用当前对象
        virtual void UnUse() = 0;

        // 初始化当前对象
        virtual void Init() = 0;

        //销毁当前对象
        virtual void Destroy() = 0;

        // 当前对象是否有效
        virtual bool IsValid() = 0;
    };
}

#endif