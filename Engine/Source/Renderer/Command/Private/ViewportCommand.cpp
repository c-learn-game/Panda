#include "Renderer/Command/ViewportCommand.h"

#include "Base/Public/Logging/Logging.h"
#include "RHI/Public/PlatformRHI.h"

namespace Panda
{
    FViewportCommand::FViewportCommand(int XPos, int YPos, int With, int Height)
        : x(XPos), y(YPos), w(With), h(Height)
    {
        
    }

    void FViewportCommand::Execute()
    {
        RHICommand->SetViewport(x, y, w, h);
    }
}
