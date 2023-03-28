#ifndef VERTEXBUFFEROBJECT_H
#define VERTEXBUFFEROBJECT_H

#include "OpenGLBase.h"

namespace Panda
{
    class FVertexBufferObject : FOpenGLObject
    {
    public:
        explicit FVertexBufferObject();

        explicit FVertexBufferObject(float* InBufferData, int InBufferSize);

        void Init() override;

        void Destroy() override;

        void Use() override;

        void UnUse() override;

        bool IsValid() override;

    private:
        uint VBO;
        float* BufferData;
        int BufferSize;
    };
}

#endif