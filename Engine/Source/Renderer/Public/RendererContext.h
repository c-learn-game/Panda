#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H

#include "Base/Base.h"

namespace Panda
{
    class CWindow;

    class FRenderContext
    {
    public:
        explicit FRenderContext(const SharedPtr<CWindow>& InContextWindow);

        virtual void Init();

        virtual void SwapBuffers();

    private:
        const SharedPtr<CWindow>& ContextWindow;
        class FRendererContextPrivate* P;
    };    
}

#endif