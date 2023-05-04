//
// Created by chendebi on 2023/5/2.
//

#include "OpenGLVertexBufferObject.h"

namespace Panda
{

    FOpenGLVertexBufferObject::FOpenGLVertexBufferObject()
    : FRendererObject()
    {
    }

    void FOpenGLVertexBufferObject::SetData(void *InVertexData, int InDataSize)
    {
        VertexData = InVertexData;
        DataSize = InDataSize;
    }

    void FOpenGLVertexBufferObject::SetLayout(const FVertexBufferLayout &InLayout)
    {
        DataLayout = InLayout;
    }

    void FOpenGLVertexBufferObject::Generate()
    {
        check(DataSize > 0 && VertexData)
        PANDA_GL_CALL(glGenBuffers(1, &BufferId))
        PANDA_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, BufferId))
        PANDA_GL_CALL(glBufferData(GL_ARRAY_BUFFER, DataSize, VertexData, GL_STATIC_DRAW))
    }

    void FOpenGLVertexBufferObject::Destroy()
    {
        if (IsValid())
        {
            PANDA_GL_CALL(glDeleteBuffers(1, &BufferId))
            BufferId = 0;
        }
    }

    void FOpenGLVertexBufferObject::Bind()
    {
        check(IsValid())
        PANDA_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, BufferId));
    }
}