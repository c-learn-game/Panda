#ifndef PANDA_RHIVERTEXARRAYRESOURCE_H
#define PANDA_RHIVERTEXARRAYRESOURCE_H

#include "RHIResource.h"

namespace Panda
{
	class FRHIVertexArrayResource : public FRHIResource
	{
	public:
		virtual void SetVertexBufferResource(SharedPtr<class FRHIVertexBufferResource> BufferResource) = 0;

		static SharedPtr<FRHIVertexArrayResource> Create();
	};
}

#endif // !PANDA_RHIVERTEXARRAYRESOURCE_H
