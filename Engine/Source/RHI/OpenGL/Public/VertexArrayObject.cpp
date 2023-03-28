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
        for (int Index : VertexIndices)
        {
            PANDA_GL_CALL(glEnableVertexAttribArray(Index))
        }
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

    void FVertexArrayObject::AddAttributes(FVertexBufferObject* VBO,
        const CArray<FVertexArrayAttributes>& Attributes)
    {
        check(IsValid())
        Use();
        VBO->Use();
        for (int Index = 0; Index < Attributes.size(); ++Index)
        {
            const auto Attribute = Attributes[Index];
            PANDA_GL_CALL(glVertexAttribPointer(Index, Attribute.VertexCount, GL_FLOAT, Attribute.bNormalized, Attribute.Stride, (void*)CurrentOffset))
            CurrentOffset += Attribute.Stride;
            VertexIndices.Add(Index);
        }
        VBO->UnUse();
    }
}
