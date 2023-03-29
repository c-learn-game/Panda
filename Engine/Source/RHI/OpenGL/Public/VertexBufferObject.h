#ifndef VERTEXBUFFEROBJECT_H
#define VERTEXBUFFEROBJECT_H

#include "OpenGLBase.h"

namespace Panda
{

    struct FVertexBufferLayout
    {
        int Type = 0;
        int Count = 0;
        uint8 bNormalized = 0;
        int Stride = 0;
        int Offset = 0;
        
    };
    
    class FVertexBufferObject : FOpenGLObject
    {
    public:
        explicit FVertexBufferObject();

        explicit FVertexBufferObject(float* InBufferData, int InBufferSize);

        void Init();

        void Destroy() override;

        void Use() override;

        void UnUse() override;

        bool IsValid() override;

        template <typename T>
        void AddLayout(int VertexCount, bool bNormalized)
        {
            check(false)
        }

        template <>
        void AddLayout<float>(int VertexCount, bool bNormalized);

        CArray<FVertexBufferLayout> GetLayouts() const { return Layouts; }
        
    private:
        uint VBO;
        float* BufferData;
        int BufferSize;
        int CurrentOffset = 0;
        CArray<FVertexBufferLayout> Layouts;
    };

    template <>
    void FVertexBufferObject::AddLayout<float>(int VertexCount, bool bNormalized)
    {
        const int Stride = 4 * VertexCount;
        this->Layouts.Add({GL_FLOAT, VertexCount, bNormalized, Stride, CurrentOffset});
        CurrentOffset += Stride;
    }
}

#endif