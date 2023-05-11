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

    void FOpenGLVertexBufferResource::InitResource(void* BufferData, size_t InDataSize)
    {
        DataSize = InDataSize;
        check(DataSize > 0 && BufferData)
        PANDA_GL_CALL(glGenBuffers(1, &BufferId))
        PANDA_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, BufferId))
        PANDA_GL_CALL(glBufferData(GL_ARRAY_BUFFER, DataSize, BufferData, GL_STATIC_DRAW))
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