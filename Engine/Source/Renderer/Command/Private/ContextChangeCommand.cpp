#include "Renderer/Command/ContextChangeCommand.h"

#include "Renderer/Public/RendererContext.h"
#include "Renderer/Public/RenderThread.h"

namespace Panda
{
    FContextChangeCommand::FContextChangeCommand(const SharedPtr<FRenderContext>& NewContext)
        : Context(NewContext)
    {
    }

    void FContextChangeCommand::Execute()
    {
        FRenderer::Get()->SetContext(Context);
        FRenderer::Get()->InitContext();
    }
}
