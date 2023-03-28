#include "VertexBufferObject.h"
#include "glad/glad.h"

namespace Panda
{
    FVertexBufferObject::FVertexBufferObject()
        : VBO(0),
          BufferData(nullptr),
          BufferSize(0)
    {
        
    }

    FVertexBufferObject::FVertexBufferObject(float* InBufferData, int InBufferSize)
        : VBO(0), BufferData(InBufferData), BufferSize(InBufferSize)
    {
        
    }

    void FVertexBufferObject::Init()
    {
        checkmsg(!IsValid(), "Buffer has Initialized!")
        PANDA_GL_CALL(glGenBuffers(1, &VBO))
        Use();
        PANDA_GL_CALL(glBufferData(GL_ARRAY_BUFFER, BufferSize, BufferData, GL_STATIC_DRAW))
        UnUse();
    }

    void FVertexBufferObject::Destroy()
    {
        PANDA_GL_CALL(glDeleteBuffers(1, &VBO))
        VBO = 0;
    }

    void FVertexBufferObject::Use()
    {
        check(IsValid())
        PANDA_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, VBO))
    }

    void FVertexBufferObject::UnUse()
    {
        PANDA_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0))
    }

    bool FVertexBufferObject::IsValid()
    {
        return VBO > 0;
    }
}
