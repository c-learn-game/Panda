#ifndef VIEWPORTCOMMAND_H
#define VIEWPORTCOMMAND_H

#include "Renderer/Private/Command/RenderCommandBase.h"

namespace Panda
{
    class FViewportCommand : public  FRenderCommandBase
    {
    public:
        explicit FViewportCommand(int XPos, int YPos, int With, int Height);

        void Execute() override;

    private:
        int x, y, w, h;
    };
}

#endif