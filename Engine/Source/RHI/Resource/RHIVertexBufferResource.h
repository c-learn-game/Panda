#ifndef PANDA_RHIVERTEXBUFFERRESOURCE_H
#define PANDA_RHIVERTEXBUFFERRESOURCE_H

#include "RHIResource.h"

namespace Panda
{
	enum class FVertexBufferComponentType : int
	{
		Float,
		Float2,
		Float3,
		Float4
	};

	struct FVertexBufferComponent
	{
		FString Name;
		FVertexBufferComponentType DataType;
		int Count;
		int Offset;
		bool Normalized;

		FVertexBufferComponent(const FString& InName, const FVertexBufferComponentType& InDataType,
			bool bNormalized = false)
			: Name(InName), DataType(InDataType)
			, Normalized(bNormalized)
		{
			switch (InDataType) {
			case FVertexBufferComponentType::Float:
				Count = 1;
				break;
			case FVertexBufferComponentType::Float2:
				Count = 2;
				break;
			case FVertexBufferComponentType::Float3:
				Count = 3;
				break;;
			case FVertexBufferComponentType::Float4:
				Count = 4;
				break;
			default:
				break;
			}
		}

		size_t ComponentStride()
		{
			switch (DataType) {
			case FVertexBufferComponentType::Float:
			case FVertexBufferComponentType::Float2:
			case FVertexBufferComponentType::Float3:
			case FVertexBufferComponentType::Float4:
				return Count * sizeof(float);
			default:
				break;
			}
			return 0;
		}
	};

	class FVertexBufferResourceLayout
	{
	public:
		explicit FVertexBufferResourceLayout(std::initializer_list<FVertexBufferComponent> InComponents = {})
		{
			SetLayoutComponents(InComponents);
		}

		bool IsValid() const
		{
			return Stride > 0;
		}

		void SetLayoutComponents(std::initializer_list<FVertexBufferComponent> InComponents)
		{
			Components = InComponents;
			size_t Offset = 0;
			for (int i = 0; i < Components.size(); ++i)
			{
				Components[i].Offset = Offset;
				Offset += Components[i].ComponentStride();
			}
			Stride = Offset;
		}

		int ComponentCount() const { return Components.size(); }

        FVertexBufferComponent& operator[](const int& Index)
		{
			return Components[Index];
		}

		size_t GetStride() const { return Stride; }

	private:
		TArray<FVertexBufferComponent> Components;

		size_t Stride = 0;
	};

	class FRHIVertexBufferResource : public FRHIResource
	{
	public:

		virtual void SetData(void* BufferData, size_t DataSize) = 0;

		void SetLayout(const FVertexBufferResourceLayout& InLayout)
		{
			checkf(InLayout.IsValid(), "invalid buffer layout")
			Layout = InLayout;
		}

		FVertexBufferResourceLayout GetLayout() const
		{
			return Layout;
		}

		static SharedPtr<FRHIVertexBufferResource> Create();

	private:
		FVertexBufferResourceLayout Layout;
	};
}

#endif // !PANDA_RHIVERTEXBUFFERRESOURCE_H
