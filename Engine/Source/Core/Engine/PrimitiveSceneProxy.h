#ifndef PANDA_PRIMITIVESCENEPROXY_H
#define PANDA_PRIMITIVESCENEPROXY_H

#include "Basic/Basic.h"

namespace Panda
{
    class FPrimitiveSceneProxy
	{
	public:
		explicit FPrimitiveSceneProxy(class UPrimitiveSceneComponent* InComponent);

		void CreateRHI();

    public:
		class UPrimitiveSceneComponent* SceneComponent = nullptr;
		SharedPtr<class FRHIVertexArrayResource> VertexArray = nullptr;
		SharedPtr<class FRHIIndexBufferResource> IndexBuffer = nullptr;
	};
}

#endif // !PANDA_PRIMITIVESCENEPROXY_H
