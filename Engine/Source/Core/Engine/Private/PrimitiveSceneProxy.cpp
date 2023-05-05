#include "Core/Engine/PrimitiveSceneProxy.h"
#include "Core/Engine/PrimitiveSceneComponent.h"
#include "Renderer/Private/OpenGL/OpenGLShaderObject.h"
#include "Renderer/Private/OpenGL/OpenGLVertexBufferObject.h"
#include "Renderer/Private/OpenGL/OpenGLVertexArrayObject.h"
#include "Renderer/Private/OpenGL/OpenGLIndexBufferObject.h"

namespace Panda
{
	FPrimitiveSceneProxy::FPrimitiveSceneProxy(UPrimitiveSceneComponent* InComponent)
		: SceneComponent(InComponent)
	{
		auto vbo = MakeShared<FOpenGLVertexBufferObject>();
		vbo->SetData(SceneComponent->Vertices.data(), SceneComponent->Vertices.size() * sizeof(FPrimitiveVertex));
		vbo->Generate();
		FVertexBufferLayout Layout ({
			FVertexBufferElement("Position", FVertexBufferElementType::Float4),
			FVertexBufferElement("Color0", FVertexBufferElementType::Float4),
			FVertexBufferElement("Color1", FVertexBufferElementType::Float4),
			FVertexBufferElement("Color2", FVertexBufferElementType::Float4)
			});
		vbo->SetLayout(Layout);
		vao = MakeShared<FOpenGLVertexArrayObject>(vbo);
		vao->Generate();
		ibo = MakeShared<FOpenGLIndexBufferObject>();
		ibo->SetIndexData((uint*)(SceneComponent->Indices.data()), sizeof(FPrimitiveElementIndex) * SceneComponent->Indices.size());
		ibo->Generate();
	}

	void FPrimitiveSceneProxy::Draw()
	{
		vao->DrawElements(ibo);
	}
}