//
// Created by chendebi on 2023/5/2.
//

#ifndef TEST_OPENGLVERTEXBUFFEROBJECT_H
#define TEST_OPENGLVERTEXBUFFEROBJECT_H

#include "Renderer/Private/RendererObject.h"
#include "OpenGLMacros.h"

namespace Panda
{
    enum class FVertexBufferElementType : int
    {
        InValid,
        FLOAT = 0x1406
    };

    struct FVertexBufferElement
    {
        FString Name;
        FVertexBufferElementType DataType;
        int Count;
        int Offset;
        bool Normalized;

        FVertexBufferElement(const FString& InName, const FVertexBufferElementType& InDataType,
                                int InCount, int InOffset, bool bNormalized = false)
                                : Name(InName), DataType(InDataType), Count(InCount), Offset(InOffset)
                                , Normalized(bNormalized)
        {}

        static int TypeSize(const FVertexBufferElementType& InType)
        {
            switch (InType) {
                case FVertexBufferElementType::FLOAT:
                    return sizeof (float);
                default:
                    break;
            }
            checkf(false, "Unsupported buffer element type: {}", static_cast<int>(InType))
            return 0;
        }
    };

    class FVertexBufferLayout
    {
    public:
        explicit FVertexBufferLayout(std::initializer_list<FVertexBufferElement> InElements = {})
        : Elements(InElements)
        {
            int Offset = 0;
            for (int i = 0; i < Elements.size(); ++i)
            {
                Elements[i].Offset = Offset;
                Offset += Elements[i].Count * FVertexBufferElement::TypeSize(Elements[i].DataType);
            }
            Stride = Offset;
        }

        int ElementCount() const { return Elements.size(); }

        FVertexBufferElement& operator[](const int& Index)
        {
            return Elements[Index];
        }

        int GetStride() const { return Stride; }

    private:
        TArray<FVertexBufferElement> Elements;

        int Stride = 0;
    };

    class FOpenGLVertexBufferObject : public FRendererObject
    {
    public:
        explicit FOpenGLVertexBufferObject();

        void SetData(void * InVertexData, int InDataSize);

        void SetLayout(const FVertexBufferLayout& InLayout);

        FVertexBufferLayout GetLayout() const { return DataLayout; }

        void Generate();

        bool IsValid() const { return BufferId > 0; }

        void Destroy() override;

        void Bind();

        int GetVertexCount() { return DataSize / DataLayout.GetStride(); }

    private:
        int CurrentOffset = 0;
        FVertexBufferLayout DataLayout;
        uint BufferId = 0;
        void* VertexData = nullptr;
        int DataSize = 0;
    };

}

#endif //TEST_OPENGLVERTEXBUFFEROBJECT_H
