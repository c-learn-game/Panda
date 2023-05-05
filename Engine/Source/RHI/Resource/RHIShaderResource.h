#ifndef PANDA_RHISHADERRESOURCE_H
#define PANDA_RHISHADERRESOURCE_H

#include "RHIResource.h"

namespace Panda
{
    class FRHIShaderResource : public FRHIResource
    {
    public:

        virtual void SetShaderSource(const FString& VertexShaderSource, const FString& FragShaderSource) = 0;

        static SharedPtr<FRHIShaderResource> Create();
    };
}

#endif //TEST_RHISHADERRESOURCE_H
