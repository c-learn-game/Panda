#include "PrimitiveComponent.h"
#include "Renderer/Private/OpenGL/OpenGLIndexBufferObject.h"
#include "Renderer/Private/OpenGL/OpenGLVertexBufferObject.h"
#include "Renderer/Private/OpenGL/OpenGLVertexArrayObject.h"

namespace Panda
{
    class FPrimitiveProxy : public FSceneProxy
    {
    public:
        explicit FPrimitiveProxy(UPrimitiveComponent* InComponent)
        : FSceneProxy(InComponent)
        {
            auto vbo = MakeShared<FOpenGLVertexBufferObject>();
            vbo->SetData(InComponent->Vertices.data(), sizeof (FPrimitiveVertex) * InComponent->Vertices.size());
            FVertexBufferLayout layout({
                FVertexBufferElement("Position", FVertexBufferElementType::Float4),
                FVertexBufferElement("Color0", FVertexBufferElementType::Float4),
                FVertexBufferElement("Color1", FVertexBufferElementType::Float4),
                FVertexBufferElement("Color2", FVertexBufferElementType::Float4)
            });
            vbo->Generate();
            vbo->SetLayout(layout);
            vao = MakeShared<FOpenGLVertexArrayObject>(vbo);
            vao->Generate();
        }

        void Draw() override
        {
            vao->Draw();
        }

    private:
        SharedPtr<FOpenGLVertexArrayObject> vao = nullptr;
        SharedPtr<FOpenGLIndexBufferObject> ibo = nullptr;
    };

	UPrimitiveComponent::UPrimitiveComponent(const SharedPtr<UActorComponent>& Parent)
		: USceneComponent(Parent)
	{

	}
	UPrimitiveComponent::~UPrimitiveComponent()
	{
	}
	void UPrimitiveComponent::AddVertex(const FPrimitiveVertex & Vertex)
	{
		Vertices.push_back(Vertex);
	}
	void UPrimitiveComponent::AddVertex(const FVector4 & VertexPosition, const FVector4 & VertexColor0, const FVector4 & VertexColor1, const FVector4 & VertexColor2 )
	{
		Vertices.emplace_back(VertexPosition, VertexColor0, VertexColor1, VertexColor2);
	}

	void UPrimitiveComponent::SetVertexColor(const int & Index, const int& ColorIndex, const FVector4 & VertexColor)
	{
		Vertices[Index].VertexColors[ColorIndex] = VertexColor;
	}

	void UPrimitiveComponent::AddElementIndex(const FPrimitiveElementIndex& InIndex)
	{
		Indices.push_back(InIndex);
	}
	void UPrimitiveComponent::AddElementIndex(uint Index0, uint Index1, uint Index2)
	{
		Indices.emplace_back(Index0, Index1, Index2);
	}

    FSceneProxy *UPrimitiveComponent::CreateProxy() {
        return new FPrimitiveProxy(this);
    }
}