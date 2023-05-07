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

	void FPrimitiveSceneProxy::CreateResource()
	{
        auto vbo = FRHIVertexBufferResource::Create();
        vbo->SetData(SceneComponent->Vertices.data(), SceneComponent->Vertices.size() * sizeof(FPrimitiveVertex));
        vbo->InitResource();
        FVertexBufferResourceLayout Layout ({
                                                    FVertexBufferComponent("Position", FVertexBufferComponentType::Float4),
                                                    FVertexBufferComponent("Normal", FVertexBufferComponentType::Float4),
                                                    FVertexBufferComponent("Color0", FVertexBufferComponentType::Float4),
                                                    FVertexBufferComponent("Color1", FVertexBufferComponentType::Float4),
                                                    FVertexBufferComponent("Color2", FVertexBufferComponentType::Float4)
                                            });
        vbo->SetLayout(Layout);
        vao = FRHIVertexArrayResource::Create();
        vao->SetVertexBufferResource(vbo);
        vao->InitResource();
        ibo = FRHIIndexBufferResource::Create();
        ibo->SetData(SceneComponent->Indices.data(), sizeof(FPrimitiveElementIndex) * SceneComponent->Indices.size());
        ibo->InitResource();
	}

    void FPrimitiveSceneProxy::ReleaseResource()
    {
        vao = nullptr;
        ibo = nullptr;
    }
}