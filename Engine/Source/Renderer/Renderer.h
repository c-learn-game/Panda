#ifndef RENDERER_H
#define RENDERER_H
#include "Base/Public/Pointer.h"

namespace Panda
{
    class FRenderContext;
}

namespace Panda
{
    class CWindow;
}

namespace Panda
{
    class FRenderer
    {
    public:
        explicit FRenderer(const SharedPtr<FRenderContext>& Context);

        void Init();

        void RenderMain();

    private:
        SharedPtr<FRenderContext> RendererContext;
    };
}

#endif