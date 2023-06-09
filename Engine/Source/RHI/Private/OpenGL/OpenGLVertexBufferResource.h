//
// Created by chendebi on 2023/5/2.
//

#ifndef TEST_OPENGLVERTEXBUFFEROBJECT_H
#define TEST_OPENGLVERTEXBUFFEROBJECT_H

#include "RHI/Resource/RHIVertexBufferResource.h"
#include "OpenGLMacros.h"

namespace Panda
{
    
    class FOpenGLVertexBufferResource : public FRHIVertexBufferResource
    {
    public:
        explicit FOpenGLVertexBufferResource();

        void InitResource(void* BufferData, size_t DataSize) override;

        void ReleaseResource() override;

		bool IsValid() const override { return BufferId > 0; }

        void Bind() override;

        size_t GetVertexCount() const { return DataSize / GetLayout().GetStride(); }

    private:
        uint BufferId = 0;
        size_t DataSize = 0;
    };

}

#endif //TEST_OPENGLVERTEXBUFFEROBJECT_H
