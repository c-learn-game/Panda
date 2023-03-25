#include "WindowPrivate.h"

#include "GLFWApplicationPrivate.h"
#include "GLFWWindowPrivate.h"

namespace Panda
{
    CWindowPrivate* CWindowPrivate::Create(CWindow* WindowInterface, const CString& WindowTitle)
    {
#ifdef PANDA_PLATFORM_GLFW
        return new CGLFWWindowPrivate(WindowInterface, WindowTitle);
#endif
        return nullptr;
    }
}
