#include "RHI/Command/RHICommand.h"
#include "RHI/Private/OpenGL/RHIOpenGLCommand.h"

namespace Panda
{
    FRHICommand* FRHICommand::Get()
    {
        static FRHIOpenGLCommand Command;
        return &Command;
    }
}