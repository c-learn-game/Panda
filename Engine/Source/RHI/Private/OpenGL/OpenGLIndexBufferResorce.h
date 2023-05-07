
#ifndef PANDA_OPENGLINDEXBUFFERRESOURCE_H
#define PANDA_OPENGLINDEXBUFFERRESOURCE_H

#include "RHI/Resource/RHIIndexBufferResource.h"

namespace Panda
{
    class FOpenGLIndexBufferResource : public FRHIIndexBufferResource
    {
    public:

        void SetData(void* InIndexData, size_t InDataSize) override;

        void InitResource() override;

        bool IsValid() const override { return BufferId > 0; }

        void ReleaseResource() override;

        void Bind();

        size_t GetIndexCount() const override { return IndexCount; }

    private:
        uint BufferId = 0;
        void* IndexData = nullptr;
        size_t DataSize = 0;

        size_t IndexCount = 0;
    };
}


#endif //TEST_OPENGLINDEXBUFFEROBJECT_H
