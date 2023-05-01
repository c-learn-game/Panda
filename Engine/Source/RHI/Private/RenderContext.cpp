//
// Created by chendebi on 2023/5/1.
//

#include "RHI/RenderContext.h"
#include "RenderContextGLFW.h"

namespace Panda
{
    SharedPtr<FRenderContext> FRenderContext::Get(const SharedPtr<RHIWindow> &ContextWindow)
    {
        return MakeShared<RenderContextGLFW>(ContextWindow);
    }
}
