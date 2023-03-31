#include "RHI/Public/PlatformRHI.h"

#ifdef PANDA_OPENGL
#include "RHI/Private/OpenGL/OpenGLPlatformRHI.h"
#endif

namespace Panda
{
    FPlatformRHI* FPlatformRHI::GetRHI()
    {
#ifdef PANDA_OPENGL
        static FOpenGLPlatformRHI RHI;
        return &RHI;
#endif
    }
}
