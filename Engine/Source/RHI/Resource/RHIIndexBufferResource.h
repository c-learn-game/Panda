
#ifndef TEST_RHIINDEXBUFFERRESOURCE_H
#define TEST_RHIINDEXBUFFERRESOURCE_H

#include "RHIResource.h"

namespace Panda
{
    class FRHIIndexBufferResource : public FRHIResource
    {
    public:

        virtual void SetData(void* IndexData, size_t DataSize) = 0;

        virtual size_t GetIndexCount() const = 0;

        virtual void Bind() = 0;

        virtual void InitResource() = 0;

        static SharedPtr<FRHIIndexBufferResource> Create();
    };
}

#endif //TEST_RHIINDEXBUFFERRESOURCE_H
