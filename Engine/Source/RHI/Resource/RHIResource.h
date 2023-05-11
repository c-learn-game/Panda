#ifndef PANDA_RHIRESOURCE_H
#define PANDA_RHIRESOURCE_H

#include "Basic/Basic.h"

namespace Panda
{
    // 不应该持有内存数据，在生成GPU资源后应该释放或者通过高级接口直接将数据拷贝到显存上
    // RHIResource必须提供释放GPU资源的方式，派生类需要实现这两个函数
    // 暂时不直接将数据拷贝到显存，使用opengl接口
	class FRHIResource
	{
	public:
		virtual ~FRHIResource() = default;

		virtual void ReleaseResource() = 0;

		virtual bool IsValid() const = 0;
	};
}

#endif // !PANDA_RHIRESOURCE_H
