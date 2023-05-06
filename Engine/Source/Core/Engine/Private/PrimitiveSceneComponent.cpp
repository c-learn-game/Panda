#include "Core/Engine/PrimitiveSceneComponent.h"
#include "Core/Engine/PrimitiveSceneProxy.h"

namespace Panda
{
	UPrimitiveSceneComponent::UPrimitiveSceneComponent()
	{

	}
	UPrimitiveSceneComponent::~UPrimitiveSceneComponent()
	{
	}
	void UPrimitiveSceneComponent::AddVertex(const FPrimitiveVertex & Vertex)
	{
		Vertices.push_back(Vertex);
	}
	void UPrimitiveSceneComponent::AddVertex(const FVector4 & VertexPosition, const FVector4 & VertexColor0, const FVector4 & VertexColor1, const FVector4 & VertexColor2 )
	{
		Vertices.emplace_back(VertexPosition, VertexColor0, VertexColor1, VertexColor2);
	}

	void UPrimitiveSceneComponent::SetVertexColor(const int & Index, const int& ColorIndex, const FVector4 & VertexColor)
	{
		Vertices[Index].VertexColors[ColorIndex] = VertexColor;
	}

	bool UPrimitiveSceneComponent::Modified() const
	{
		return bModified;
	}

	void UPrimitiveSceneComponent::AddElementIndex(const FPrimitiveElementIndex& InIndex)
	{
		Indices.push_back(InIndex);
	}
	void UPrimitiveSceneComponent::AddElementIndex(uint Index0, uint Index1, uint Index2)
	{
		Indices.emplace_back(Index0, Index1, Index2);
	}

	FPrimitiveSceneProxy *UPrimitiveSceneComponent::CreateProxy() {
        return new FPrimitiveSceneProxy(this);
    }
}