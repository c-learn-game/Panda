#include "Renderer/Public/RendererContext.h"
#include "RendererContextPrivate.h"

namespace Panda
{
    FRenderContext::FRenderContext(const SharedPtr<CWindow>& InContextWindow)
        : ContextWindow(InContextWindow)
    {
        P = FRendererContextPrivate::Create(InContextWindow);
    }

    void FRenderContext::Init()
    {
        P->Init();
    }

    void FRenderContext::SwapBuffers()
    {
        P->SwapBuffers();
    }
}
