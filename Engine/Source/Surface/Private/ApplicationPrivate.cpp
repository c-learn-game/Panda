#include "ApplicationPrivate.h"

#include "GLFWApplicationPrivate.h"

namespace Panda
{
    CApplicationPrivate* CApplicationPrivate::Create()
    {
#ifdef PANDA_PLATFORM_GLFW
        return new CGLFWApplicationPrivate();
#else
#error Not specified Platform micro!
#endif
        return nullptr;
    }
}
