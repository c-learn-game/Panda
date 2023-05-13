#include "Core/Engine/PrimitiveSceneProxy.h"
#include "Core/Engine/PrimitiveSceneComponent.h"
#include "RHI/Resource/RHIIndexBufferResource.h"
#include "RHI/Resource/RHIVertexArrayResource.h"
#include "RHI/Resource/RHIVertexBufferResource.h"

namespace Panda
{
	FPrimitiveSceneProxy::FPrimitiveSceneProxy(UPrimitiveSceneComponent* InComponent)
		: SceneComponent(InComponent)
	{

	}

	void FPrimitiveSceneProxy::CreateRHI()
	{
        auto vbo = FRHIVertexBufferResource::Create();
        vbo->InitResource(SceneComponent->Vertices.data(), SceneComponent->Vertices.size() * sizeof(FPrimitiveVertex));
        FVertexBufferResourceLayout Layout ({
                                                    FVertexBufferComponent("Position", FVertexBufferComponentType::Float4),
                                                    FVertexBufferComponent("Normal", FVertexBufferComponentType::Float4),
                                                    FVertexBufferComponent("Color0", FVertexBufferComponentType::Float4),
                                                    FVertexBufferComponent("Color1", FVertexBufferComponentType::Float4),
                                                    FVertexBufferComponent("Color2", FVertexBufferComponentType::Float4),
                                                    FVertexBufferComponent("UV0", FVertexBufferComponentType::Float4),
                                            });
        vbo->SetLayout(Layout);
        VertexArray = FRHIVertexArrayResource::Create();
        VertexArray->SetVertexBufferResource(vbo);
        VertexArray->InitResource();
        IndexBuffer = FRHIIndexBufferResource::Create();
        IndexBuffer->InitResource(SceneComponent->Indices.data(), sizeof(FPrimitiveElementIndex) * SceneComponent->Indices.size());
	}
}