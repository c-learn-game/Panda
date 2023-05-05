
#ifndef PANDA_OPENGLVERTEXARRAYRESOURCE_H
#define PANDA_OPENGLVERTEXARRAYRESOURCE_H

#include "RHI/Resource/RHIVertexArrayResource.h"

namespace Panda
{
    class FOpenGLVertexArrayResource : public FRHIVertexArrayResource
    {
    public:
        explicit FOpenGLVertexArrayResource();

        bool IsValid() const override
        { return ArrayId > 0; }

        void Bind() override;

		void SetVertexBufferResource(SharedPtr<class FRHIVertexBufferResource> InBufferResource) override;

        void InitResource() override;

        void ReleaseResource() override;

    private:
        uint ArrayId = 0;
        SharedPtr<class FRHIVertexBufferResource> BufferResource = nullptr;

    };
}


#endif //PANDA_OPENGLVERTEXARRAYRESOURCE_H
