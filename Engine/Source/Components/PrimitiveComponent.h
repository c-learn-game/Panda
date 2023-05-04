//
// Created by chendebi on 2023/5/04.
//

#ifndef PANDA_PRIMITIVECOMPONENT_H
#define PANDA_PRIMITIVECOMPONENT_H

#include "SceneComponent.h"
#include "Core/Math/Vector4.h"

namespace Panda
{

	struct FPrimitiveVertex
	{
		FVector4 VertexPosition; // primitive vertices
		FVector4 VertexColors[3]; // vertex colors

		explicit FPrimitiveVertex()
			: VertexPosition({0,0,0,0})
		{
			VertexPosition = {0,0,0,0};
		}

        explicit FPrimitiveVertex(const FVector4& Position,
			const FVector4& VertexColor0 = { 0,0,0,0 },
			const FVector4& VertexColor1 = { 0,0,0,0 },
			const FVector4& VertexColor2 = { 0,0,0,0 }
			)
			: VertexPosition(Position)
		{
			VertexColors[0] = VertexColor0;
			VertexColors[1] = VertexColor1;
			VertexColors[2] = VertexColor2;
		}
	};

	struct FPrimitiveElementIndex
	{
		union
		{
			struct
			{
				uint Index0, Index1, Index2;
			};
			uint Data[3];
		};

		FPrimitiveElementIndex()
			: Index0(0), Index1(0), Index2(0)
		{}

		FPrimitiveElementIndex(
			const uint& InIndex0,
			const uint& InIndex1,
			const uint& InIndex2
		)
			: Index0(InIndex0), Index1(InIndex1), Index2(InIndex2)
		{}
	};

	class UPrimitiveComponent : public USceneComponent
	{
	public:
		explicit UPrimitiveComponent(const SharedPtr<UActorComponent>& Parent = nullptr);

		virtual ~UPrimitiveComponent();

		void AddVertex(const FPrimitiveVertex& Vertex);

		void AddVertex(const FVector4& VertexPosition, 
			const FVector4& VertexColor0 = {0,0,0,0},
			const FVector4& VertexColor1 = {0,0,0,0},
			const FVector4& VertexColor2 = {0,0,0,0}
		);

		void AddElementIndex(const FPrimitiveElementIndex& InIndex);

		void AddElementIndex(uint Index0, uint Index1, uint Index2);

		void SetVertexColor(const int& Index, const int& ColorIndex, const FVector4& VertexColor);

		FSceneProxy* CreateProxy() override;

	private:
	    friend class FPrimitiveProxy;
		TArray<FPrimitiveVertex> Vertices;
		TArray<FPrimitiveElementIndex> Indices;
	};
}

#endif