//
// Created by chendebi on 2023/5/1.
//

#ifndef TEST_RENDERCONTEXTGLFW_H
#define TEST_RENDERCONTEXTGLFW_H

#include "RHI/RenderContext.h"

struct GLFWwindow;

namespace Panda
{
    class RenderContextGLFW : public FRenderContext
    {
    public:
        explicit RenderContextGLFW(const SharedPtr<RHIWindow> &ContextWindow);

        void MakeCurrent() override;

        void SwapBuffer() override;

    private:
        GLFWwindow* Window;
    };
}

#endif //TEST_RENDERCONTEXTGLFW_H
