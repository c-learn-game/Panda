
#ifndef PANDA_VIEWRECTCHANGEDCOMMAND_H
#define PANDA_VIEWRECTCHANGEDCOMMAND_H

#include "Basic/Basic.h"

namespace Panda
{
    class FViewRectChangedCommand
    {
    public:
        explicit FViewRectChangedCommand(FIntRect ViewRect)
        : ViewportRect(ViewRect)
        {}



    private:
        FIntRect ViewportRect;
    };
}


#endif //PANDA_VIEWRECTCHANGEDCOMMAND_H
