#include "Core/Engine/Game/PrimitiveSceneComponent.h"
#include "Core/Engine/Renderer/PrimitiveSceneProxy.h"

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
	void UPrimitiveSceneComponent::AddVertex(const FVector4 & VertexPosition, const FVector4& Normal, const FVector4 & VertexColor0, const FVector4 & VertexColor1, const FVector4 & VertexColor2 )
	{
		Vertices.emplace_back(VertexPosition, Normal, VertexColor0, VertexColor1, VertexColor2);
	}

	void UPrimitiveSceneComponent::SetVertexColor(const int & Index, const int& ColorIndex, const FVector4 & VertexColor)
	{
		Vertices[Index].VertexColors[ColorIndex] = VertexColor;
	}

    void UPrimitiveSceneComponent::SetVertexUV(const int &Index, int UVIndex, float U, float V)
    {
        if (0 <= UVIndex && UVIndex < 2)
        {
            Vertices[Index].VertexUV0[UVIndex*2] = U;
            Vertices[Index].VertexUV0[UVIndex*2+1] = V;
        }
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

	void UPrimitiveSceneComponent::SetVertexNormal(const int &Index, const FVector4 &InNormal)
	{
	    Vertices[Index].VertexNormal = InNormal;
	}

	FPrimitiveSceneProxy *UPrimitiveSceneComponent::CreateProxy()
    {
        return new FPrimitiveSceneProxy(this);
    }

    void UPrimitiveSceneComponent::Serialize(FArchive &Archive)
    {
        LogInfo("serialize")
        Archive.Serialize(Vertices.data(), Vertices.size() * sizeof (FPrimitiveVertex));
        Archive.Serialize(Indices.data(), Indices.size() * sizeof (FPrimitiveElementIndex));
    }

    void UPrimitiveSceneComponent::Deserialize(FArchive &Archive)
    {
        longlong VerticesSize = 0;
        void* VerticesData = Archive.Deserialize(VerticesSize);
        Vertices.resize(VerticesSize / sizeof (FPrimitiveVertex));
        memcpy(Vertices.data(), VerticesData, VerticesSize);

        longlong IndicesSize;
        void* IndicesData = Archive.Deserialize(IndicesSize);
        Indices.resize(IndicesSize / sizeof (FPrimitiveElementIndex));
        memcpy(Indices.data(), IndicesData, IndicesSize);
    }
}