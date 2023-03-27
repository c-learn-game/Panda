#ifndef GLFWRENDERERCONTEXTPRIVATE_H
#define GLFWRENDERERCONTEXTPRIVATE_H

#include "RendererContextPrivate.h"

struct GLFWwindow;

namespace Panda
{
    class FGLFWRendererContextPrivate : public FRendererContextPrivate
    {
    public:
        explicit FGLFWRendererContextPrivate(const SharedPtr<CWindow>& InContextWindow);

        void Init() override;

        void SwapBuffers() override;

    private:
        SharedPtr<CWindow> ContextWindow;
        GLFWwindow* WindowHandle;
    };
}

#endif