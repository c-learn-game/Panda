#include "RendererContextPrivate.h"
#include "GLFWRendererContextPrivate.h"
#include "Surface/Public/Window.h"

namespace Panda
{
    FRendererContextPrivate::FRendererContextPrivate(const SharedPtr<CWindow>& InContextWindow)
        : PrivateWindow(InContextWindow->P)
    {
    }

    FRendererContextPrivate* FRendererContextPrivate::Create(const SharedPtr<CWindow>& InContextWindow)
    {
#ifdef PANDA_PLATFORM_GLFW
        return new FGLFWRendererContextPrivate(InContextWindow);
#endif
        return nullptr;
    }
}
