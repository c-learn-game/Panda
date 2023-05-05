#ifndef PANDA_RHIRESOURCE_H
#define PANDA_RHIRESOURCE_H

#include "Basic/Basic.h"

namespace Panda
{
	class FRHIResource
	{
	public:
		virtual ~FRHIResource() = default;

		virtual void InitResource() = 0;

		virtual void ReleaseResource() = 0;

		virtual void Bind() = 0;

		virtual bool IsValid() const { return false; }
	};
}

#endif // !PANDA_RHIRESOURCE_H
