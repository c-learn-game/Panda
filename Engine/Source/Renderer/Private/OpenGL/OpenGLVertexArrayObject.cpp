//
// Created by chendebi on 2023/5/2.
//

#include "OpenGLVertexArrayObject.h"
#include "OpenGLVertexBufferObject.h"

namespace Panda
{

    static GLenum ElementTypeToOpenGLType(const FVertexBufferElementType& Type)
    {
        switch (Type)
        {
            case FVertexBufferElementType::Float:
            case FVertexBufferElementType::Float3:
            case FVertexBufferElementType::Float4:
                return GL_FLOAT;
        }

        return 0;
    }

    FOpenGLVertexArrayObject::FOpenGLVertexArrayObject(
            const SharedPtr<class FOpenGLVertexBufferObject> &InVertexBufferObject)
    {
        SetVertexBufferObject(InVertexBufferObject);
    }

    void
    FOpenGLVertexArrayObject::SetVertexBufferObject(const SharedPtr<FOpenGLVertexBufferObject> &InVertexBufferObject)
    {
        check(!IsValid())
        VertexBufferObject = InVertexBufferObject;
    }

    void FOpenGLVertexArrayObject::Generate()
    {
        check(VertexBufferObject != nullptr && VertexBufferObject->IsValid())
        PANDA_GL_CALL(glGenVertexArrays(1, &ArrayId))
        PANDA_GL_CALL(glBindVertexArray(ArrayId))
        VertexBufferObject->Bind();
        auto Layout = VertexBufferObject->GetLayout();
        for (int i = 0; i < Layout.ElementCount(); ++i)
        {
            auto Element = Layout[i];
            PANDA_GL_CALL(glVertexAttribPointer(i, Element.Count,
                                                ElementTypeToOpenGLType(Element.DataType),
                                                Element.Normalized ? GL_TRUE : GL_FALSE,
                                                Layout.GetStride(), (void*)Element.Offset))
            PANDA_GL_CALL(glEnableVertexAttribArray(i))

        }
        VertexCount = VertexBufferObject->GetVertexCount();
    }

    void FOpenGLVertexArrayObject::Destroy()
    {
        check(IsValid())
        PANDA_GL_CALL(glDeleteVertexArrays(1, &ArrayId))
        ArrayId = 0;
    }

    void FOpenGLVertexArrayObject::Draw()
    {
        PANDA_GL_CALL(glBindVertexArray(ArrayId))
        PANDA_GL_CALL(glDrawArrays(GL_TRIANGLES, 0, VertexCount))
    }
}