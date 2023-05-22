
#ifndef PANDA_RHICOMMAND_H
#define PANDA_RHICOMMAND_H

#include "Basic/Basic.h"

namespace Panda
{
    class FRHICommand
    {
    public:
        virtual ~FRHICommand() = default;

        virtual void SetViewport(const FIntRect& NewViewport) = 0;

        virtual void DrawMesh(const SharedPtr<class FRHIVertexArrayResource>& VertexArrayResource,
                              const SharedPtr<class FRHIIndexBufferResource>& IndexBufferResource) = 0;

        static FRHICommand* Get();
    };
}

#endif //PANDA_RHICOMMAND_H
