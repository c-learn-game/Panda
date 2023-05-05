//
// Created by chendebi on 2023/5/2.
//

#include "OpenGLVertexBufferResource.h"

namespace Panda
{

    FOpenGLVertexBufferResource::FOpenGLVertexBufferResource()
    : FRHIVertexBufferResource()
    {
    }

    void FOpenGLVertexBufferResource::SetData(void *InVertexData, size_t InDataSize)
    {
        VertexData = InVertexData;
        DataSize = InDataSize;
    }

    void FOpenGLVertexBufferResource::InitResource()
    {
        check(DataSize > 0 && VertexData)
        PANDA_GL_CALL(glGenBuffers(1, &BufferId))
        PANDA_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, BufferId))
        PANDA_GL_CALL(glBufferData(GL_ARRAY_BUFFER, DataSize, VertexData, GL_STATIC_DRAW))
    }

    void FOpenGLVertexBufferResource::ReleaseResource()
    {
        if (IsValid())
        {
            PANDA_GL_CALL(glDeleteBuffers(1, &BufferId))
            BufferId = 0;
        }
    }

    void FOpenGLVertexBufferResource::Bind()
    {
        check(IsValid())
        PANDA_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, BufferId));
    }
}