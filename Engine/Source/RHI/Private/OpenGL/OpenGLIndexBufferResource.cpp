//
// Created by chendebi on 2023/5/3.
//

#include "OpenGLIndexBufferResorce.h"
#include "OpenGLMacros.h"

namespace Panda
{

    void FOpenGLIndexBufferResource::InitResource()
    {
        check(!IsValid() && IndexData && DataSize > 0)
        PANDA_GL_CALL(glGenBuffers(1, &BufferId))
        PANDA_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BufferId))
        PANDA_GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, DataSize, IndexData, GL_STATIC_DRAW))
    }

    void FOpenGLIndexBufferResource::SetData(void *InIndexData, size_t InDataSize)
    {
        check(!IsValid())
        IndexData = InIndexData;
        DataSize = InDataSize;
        IndexCount = InDataSize / sizeof (uint) * 3;
    }

    void FOpenGLIndexBufferResource::ReleaseResource()
    {
        check(IsValid())
        PANDA_GL_CALL(glDeleteBuffers(1, &BufferId))
        BufferId = 0;
    }

    void FOpenGLIndexBufferResource::Bind()
    {
        check(IsValid())
        PANDA_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BufferId))
    }
}