//
// Created by chendebi on 2023/5/3.
//

#ifndef TEST_OPENGLINDEXBUFFEROBJECT_H
#define TEST_OPENGLINDEXBUFFEROBJECT_H

#include "Renderer/Private/RendererObject.h"

namespace Panda
{
    class FOpenGLIndexBufferObject : public FRendererObject
    {
    public:
        explicit FOpenGLIndexBufferObject(uint* InIndexData = nullptr, size_t InDataSize = 0);

        ~FOpenGLIndexBufferObject() override;

        void SetIndexData(uint* InIndexData, size_t InDataSize);

        void Generate();

        bool IsValid() const override { return BufferId > 0; }

        void Destroy() override;

        void Bind();

        int GetVertexCount() const { return VertexCount; }

    private:
        uint BufferId = 0;
        uint* IndexData = nullptr;
        size_t DataSize = 0;

        size_t VertexCount = 0;
    };
}


#endif //TEST_OPENGLINDEXBUFFEROBJECT_H
