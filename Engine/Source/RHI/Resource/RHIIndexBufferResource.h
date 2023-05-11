
#ifndef TEST_RHIINDEXBUFFERRESOURCE_H
#define TEST_RHIINDEXBUFFERRESOURCE_H

#include "RHIResource.h"

namespace Panda
{
    class FRHIIndexBufferResource : public FRHIResource
    {
    public:
        virtual size_t GetIndexCount() const = 0;

        virtual void Bind() = 0;

        virtual void InitResource(void* InIndexData, size_t InDataSize) = 0;

        static SharedPtr<FRHIIndexBufferResource> Create();
    };
}

#endif //TEST_RHIINDEXBUFFERRESOURCE_H
