#ifndef RENDERER_H
#define RENDERER_H
#include "Base/Public/Pointer.h"
#include "Base/Public/Types/Array.h"

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
    private:
        explicit FRenderer() = default;

        virtual ~FRenderer() = default;
        
    public:
        static FRenderer* Get();
        
    };

    void RenderThreadMain(const SharedPtr<FRenderContext>& Context);
}

#endif