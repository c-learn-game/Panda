#ifndef VERTEXARRAYOBJECT_H
#define VERTEXARRAYOBJECT_H

#include "OpenGLBase.h"

namespace Panda
{
    class FVertexBufferObject;
}

namespace Panda
{
    struct FVertexArrayAttributes
    {
        int VertexCount = 0;
        bool bNormalized = false;
        int Stride = 0;

        FVertexArrayAttributes(int InVertexCount, bool InNormalized, int InStride)
            : VertexCount(InVertexCount), bNormalized(InNormalized), Stride(InStride)
        {}
    };
    
    class FVertexArrayObject : public FOpenGLObject
    {
    public:
        explicit FVertexArrayObject();

        void Init() override;

        void Destroy() override;

        void Use() override;

        void UnUse() override;

        bool IsValid() override;

        void AddAttributes(FVertexBufferObject* VBO, const CArray<FVertexArrayAttributes>& Attribute);
        
    private:
        uint VAO;
        CArray<int> VertexIndices;
        int CurrentOffset;
    };
}

#endif