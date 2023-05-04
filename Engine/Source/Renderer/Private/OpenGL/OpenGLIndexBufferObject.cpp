//
// Created by chendebi on 2023/5/3.
//

#include "OpenGLIndexBufferObject.h"
#include "OpenGLMacros.h"

namespace Panda
{
    FOpenGLIndexBufferObject::FOpenGLIndexBufferObject(uint *InIndexData, size_t InDataSize)
    {
        SetIndexData(InIndexData, InDataSize);
    }

    FOpenGLIndexBufferObject::~FOpenGLIndexBufferObject()
    {
        if (IsValid())
        {
            Destroy();
        }
    }

    void FOpenGLIndexBufferObject::Generate()
    {
        check(!IsValid() && IndexData && DataSize > 0)
        PANDA_GL_CALL(glGenBuffers(1, &BufferId))
        PANDA_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BufferId))
        PANDA_GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, DataSize, IndexData, GL_STATIC_DRAW))
    }

    void FOpenGLIndexBufferObject::SetIndexData(uint *InIndexData, size_t InDataSize)
    {
        check(!IsValid())
        IndexData = InIndexData;
        DataSize = InDataSize;
        VertexCount = InDataSize / sizeof (uint) * 3;
    }

    void FOpenGLIndexBufferObject::Destroy()
    {
        check(IsValid())
        PANDA_GL_CALL(glDeleteBuffers(1, &BufferId))
        BufferId = 0;
    }

    void FOpenGLIndexBufferObject::Bind()
    {
        PANDA_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BufferId))
    }
}