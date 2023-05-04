//
// Created by chendebi on 2023/5/1.
//

#ifndef PANDA_RENDERCONTEXT_H
#define PANDA_RENDERCONTEXT_H

#include "Basic/Basic.h"
#include "RHIWindow.h"

namespace Panda
{
    class FRenderContext
    {
    public:
        explicit FRenderContext(const SharedPtr<RHIWindow> &ContextWindow) { PANDA_UNUSED(ContextWindow) }

        virtual ~FRenderContext() = default;

        virtual void MakeCurrent() = 0;

        virtual void SwapBuffer() = 0;

        static SharedPtr<FRenderContext> Get(const SharedPtr<RHIWindow> &ContextWindow);

    };
}

#endif //PANDA_RENDERCONTEXT_H
