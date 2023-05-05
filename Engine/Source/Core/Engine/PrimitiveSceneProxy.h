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

	private:
		class UPrimitiveSceneComponent* SceneComponent = nullptr;
		SharedPtr<class FOpenGLVertexArrayObject> vao = nullptr;
		SharedPtr<class FOpenGLIndexBufferObject> ibo = nullptr;
	};
}

#endif // !PANDA_PRIMITIVESCENEPROXY_H
