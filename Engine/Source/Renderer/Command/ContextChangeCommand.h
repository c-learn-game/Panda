#ifndef CONTEXTCHANGECOMMAND_H
#define CONTEXTCHANGECOMMAND_H
#include "Base/Public/Pointer.h"
#include "Renderer/Private/Command/RenderCommandBase.h"

namespace Panda
{
    class FContextChangeCommand : public FRenderCommandBase
    {
    public:
        explicit FContextChangeCommand(const SharedPtr<class FRenderContext>& NewContext);

        void Execute() override;
        
        SharedPtr<class FRenderContext> Context;
    };
}

#endif