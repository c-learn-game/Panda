
#include "OpenGLVertexArrayResource.h"
#include "OpenGLVertexBufferResource.h"

namespace Panda
{

    static GLenum ComponentTypeToOpenGLType(const FVertexBufferComponentType& Type)
    {
        switch (Type)
        {
            case FVertexBufferComponentType::Float:
            case FVertexBufferComponentType::Float2:
            case FVertexBufferComponentType::Float3:
            case FVertexBufferComponentType::Float4:
                return GL_FLOAT;
        }

        return 0;
    }

    FOpenGLVertexArrayResource::FOpenGLVertexArrayResource()
    {
    }

	void SetVertexBufferResource(SharedPtr<FRHIVertexBufferResource> InBufferResource)
    {
        check(!IsValid())
		BufferResource = InBufferResource;
    }

    void FOpenGLVertexArrayResource::InitResource()
    {
        check(BufferResource != nullptr && BufferResource->IsValid())
        PANDA_GL_CALL(glGenVertexArrays(1, &ArrayId))
        PANDA_GL_CALL(glBindVertexArray(ArrayId))
        BufferResource->Bind();
        auto Layout = BufferResource->GetLayout();
        for (int i = 0; i < Layout.ComponentCount(); ++i)
        {
            auto Component = Layout[i];
            PANDA_GL_CALL(glVertexAttribPointer(i, Component.Count,
                                                ComponentTypeToOpenGLType(Component.DataType),
                                                Component.Normalized ? GL_TRUE : GL_FALSE,
                                                Layout.GetStride(), (void*)Component.Offset))
            PANDA_GL_CALL(glEnableVertexAttribArray(i))

        }
    }

    void FOpenGLVertexArrayResource::ReleaseResource()
    {
        check(IsValid())
        PANDA_GL_CALL(glDeleteVertexArrays(1, &ArrayId))
        ArrayId = 0;
    }
}