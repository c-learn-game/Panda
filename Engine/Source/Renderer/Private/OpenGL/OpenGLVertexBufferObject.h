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
        Float,
        Float3,
        Float4
    };

    struct FVertexBufferElement
    {
        FString Name;
        FVertexBufferElementType DataType;
        int Count;
        int Offset;
        bool Normalized;

        FVertexBufferElement(const FString& InName, const FVertexBufferElementType& InDataType,
                              bool bNormalized = false)
                                : Name(InName), DataType(InDataType)
                                , Normalized(bNormalized)
        {
            switch (InDataType) {
                case FVertexBufferElementType::Float:
                    Count = 1;
                    break;
                case FVertexBufferElementType::Float3:
                    Count = 3;
                    break;;
                case FVertexBufferElementType::Float4:
                    Count = 4;
                    break;
                default:
                    break;
            }
        }

        size_t ElementStride()
        {
            switch (DataType) {
                case FVertexBufferElementType::Float:
                case FVertexBufferElementType::Float3:
                case FVertexBufferElementType::Float4:
                    return Count * sizeof (float );
                default:
                    break;
            }
            return 0;
        }
    };

    class FVertexBufferLayout
    {
    public:
        explicit FVertexBufferLayout(std::initializer_list<FVertexBufferElement> InElements = {})
        : Elements(InElements)
        {
            size_t Offset = 0;
            for (int i = 0; i < Elements.size(); ++i)
            {
                Elements[i].Offset = Offset;
                Offset += Elements[i].ElementStride();
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

        size_t Stride = 0;
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

        int GetVertexCount() const { return DataSize / DataLayout.GetStride(); }

    private:
        int CurrentOffset = 0;
        FVertexBufferLayout DataLayout;
        uint BufferId = 0;
        void* VertexData = nullptr;
        int DataSize = 0;
    };

}

#endif //TEST_OPENGLVERTEXBUFFEROBJECT_H
