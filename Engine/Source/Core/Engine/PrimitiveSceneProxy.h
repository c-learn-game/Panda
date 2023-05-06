#ifndef PANDA_PRIMITIVESCENEPROXY_H
#define PANDA_PRIMITIVESCENEPROXY_H

#include "ProxyBase.h"

namespace Panda
{
    class FPrimitiveSceneProxy : public FProxyBase
	{
	public:
		explicit FPrimitiveSceneProxy(class UPrimitiveSceneComponent* InComponent);

		void CreateResource() override;

        void ReleaseResource() override;

	public:
		class UPrimitiveSceneComponent* SceneComponent = nullptr;
		SharedPtr<class FRHIVertexArrayResource> vao = nullptr;
		SharedPtr<class FRHIIndexBufferResource> ibo = nullptr;
	};
}

#endif // !PANDA_PRIMITIVESCENEPROXY_H
