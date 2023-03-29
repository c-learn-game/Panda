#include "VertexArrayObject.h"

#include "VertexBufferObject.h"
#include "glad/glad.h"
namespace Panda
{
    FVertexArrayObject::FVertexArrayObject()
        : VAO(0),
          CurrentOffset(0)
    {
    }

    void FVertexArrayObject::Init()
    {
        check(!IsValid())
        glGenVertexArrays(1, &VAO);
        Use();
        
    }

    void FVertexArrayObject::Destroy()
    {
        check(IsValid())
        PANDA_GL_CALL(glDeleteVertexArrays(1, &VAO))
        VAO = 0;
    }

    void FVertexArrayObject::Use()
    {
        check(IsValid())
        PANDA_GL_CALL(glBindVertexArray(VAO))
    }

    void FVertexArrayObject::UnUse()
    {
        check(IsValid())
        PANDA_GL_CALL(glBindVertexArray(0))
        for (const auto Index : VertexIndices)
        {
            PANDA_GL_CALL(glDisableVertexAttribArray(Index))
        }
    }

    bool FVertexArrayObject::IsValid()
    {
        return VAO > 0;
    }

    void FVertexArrayObject::SetBuffer(FVertexBufferObject* vbo)
    {
        check(IsValid())
        Use();
        vbo->Use();
        for (int Index = 0; Index < vbo->GetLayouts().size(); ++Index)
        {
            auto Layout = vbo->GetLayouts()[Index];
            PANDA_GL_CALL(glEnableVertexAttribArray(Index))
            PANDA_GL_CALL(glVertexAttribPointer(Index, Layout.Count, Layout.Type, Layout.bNormalized, Layout.Stride, (void*)Layout.Offset))
        }
    }
}
