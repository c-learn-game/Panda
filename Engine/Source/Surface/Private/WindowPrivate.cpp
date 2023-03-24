#include "WindowPrivate.h"

#include "GLFWApplicationPrivate.h"
#include "GLFWWindowPrivate.h"

namespace Panda
{
    CWindowPrivate* CWindowPrivate::Create(const CString& WindowTitle)
    {
#ifdef PANDA_PLATFORM_GLFW
        return new CGLFWWindowPrivate(WindowTitle);
#endif
        return nullptr;
    }
}
