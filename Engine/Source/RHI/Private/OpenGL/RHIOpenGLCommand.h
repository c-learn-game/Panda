//
// Created by chendebi on 2023/5/7.
//

#ifndef PANDA_RHIOPENGLCOMMAND_H
#define PANDA_RHIOPENGLCOMMAND_H

#include "RHI/Command/RHICommand.h"

namespace Panda
{
    class FRHIOpenGLCommand : public FRHICommand
    {
    public:

        void SetViewport(const FIntRect& NewViewport) override;

        void DrawMesh(const SharedPtr<class FRHIVertexArrayResource>& InVertexArrayResource,
                      const SharedPtr<class FRHIIndexBufferResource>& InIndexBufferResource) override;

        void SetClearColor(const FLinearColor& Color = {0,0,0,1}) override;

        void Clear(int Flag = FClearFlag::Color) override;
    };
}


#endif //PANDA_RHIOPENGLCOMMAND_H
