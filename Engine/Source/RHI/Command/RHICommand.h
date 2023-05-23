
#ifndef PANDA_RHICOMMAND_H
#define PANDA_RHICOMMAND_H

#include "Basic/Basic.h"

namespace Panda
{
    enum FClearFlag
    {
        Color = FLAG(1),
        Depth = FLAG(2)
    };

    class FRHICommand
    {
    public:
        virtual ~FRHICommand() = default;

        virtual void SetViewport(const FIntRect& NewViewport) = 0;

        virtual void DrawMesh(const SharedPtr<class FRHIVertexArrayResource>& VertexArrayResource,
                              const SharedPtr<class FRHIIndexBufferResource>& IndexBufferResource) = 0;

        virtual void SetClearColor(const FLinearColor& Color = {0,0,0,1}) = 0;

        virtual void Clear(int Flag = FClearFlag::Color) = 0;

        static FRHICommand* Get();
    };
}

#endif //PANDA_RHICOMMAND_H
