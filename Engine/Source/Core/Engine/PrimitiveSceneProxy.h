#ifndef PANDA_PRIMITIVESCENEPROXY_H
#define PANDA_PRIMITIVESCENEPROXY_H

#include "Basic/Basic.h"

namespace Panda
{
	class FPrimitiveSceneProxy
	{
	public:
		explicit FPrimitiveSceneProxy(class UPrimitiveSceneComponent* InComponent);

		void Draw();

	public:
		class UPrimitiveSceneComponent* SceneComponent = nullptr;
		SharedPtr<class FRHIVertexArrayResource> vao = nullptr;
		SharedPtr<class FRHIIndexBufferResource> ibo = nullptr;
	};
}

#endif // !PANDA_PRIMITIVESCENEPROXY_H
