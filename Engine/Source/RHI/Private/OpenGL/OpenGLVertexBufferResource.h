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

        void SetData(void * InVertexData, size_t InDataSize) override;

        void InitResource() override;

        void ReleaseResource() override;

		bool IsValid() const override { return BufferId > 0; }

        void Bind() override;

        int GetVertexCount() const { return DataSize / GetLayout().GetStride(); }

    private:
        int CurrentOffset = 0;
        uint BufferId = 0;
        void* VertexData = nullptr;
        size_t DataSize = 0;
    };

}

#endif //TEST_OPENGLVERTEXBUFFEROBJECT_H
