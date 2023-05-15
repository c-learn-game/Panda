
#ifndef PANDA_PRIMITIVECOMPONENT_H
#define PANDA_PRIMITIVECOMPONENT_H

#include "Core/Engine/Asset/AssetObject.h"
#include "Core/Math/Vector4.h"

namespace Panda
{

	struct FPrimitiveVertex
	{
		FVector4 VertexPosition; // primitive vertices
		FVector4 VertexNormal = {0,0,1,1};
		FVector4 VertexColors[3]; // vertex colors
        FVector4 VertexUV0;

		explicit FPrimitiveVertex()
			: VertexPosition({0,0,0,0})
		{
			VertexPosition = {0,0,0,0};
		}

        explicit FPrimitiveVertex(const FVector4& Position,
			const FVector4& Normal = {0,0,1,1},
			const FVector4& VertexColor0 = { 0,0,0,0 },
			const FVector4& VertexColor1 = { 0,0,0,0 },
			const FVector4& VertexColor2 = { 0,0,0,0 },
            const FVector4& UV0 = {0,0,0,0}
			)
			: VertexPosition(Position)
			, VertexNormal(Normal)
            , VertexUV0(UV0)
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

    class UPrimitiveSceneComponent : public UAssetObject
	{
	public:
		explicit UPrimitiveSceneComponent();

        ~UPrimitiveSceneComponent() override;

		void AddVertex(const FPrimitiveVertex& Vertex);

		void AddVertex(const FVector4& VertexPosition,
			const FVector4& Normal = {0, 0, 1, 1},
			const FVector4& VertexColor0 = {0,0,0,0},
			const FVector4& VertexColor1 = {0,0,0,0},
			const FVector4& VertexColor2 = {0,0,0,0}
		);

		void AddElementIndex(const FPrimitiveElementIndex& InIndex);

		void AddElementIndex(uint Index0, uint Index1, uint Index2);

		void SetVertexNormal(const int& Index, const FVector4& InNormal);

		void SetVertexColor(const int& Index, const int& ColorIndex, const FVector4& VertexColor);

        void SetVertexUV(const int& Index, int UVIndex, float U, float V);

		bool Modified() const;

		class FPrimitiveSceneProxy* CreateProxy();

    protected:
        void Serialize(FArchive& Archive) override;

        void Deserialize( FArchive& Archive) override;

	private:
	    friend class FPrimitiveSceneProxy;
		TArray<FPrimitiveVertex> Vertices;
		TArray<FPrimitiveElementIndex> Indices;
		bool bModified = false;
	};
}

#endif