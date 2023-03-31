#ifndef RENDERCOMMAND_H
#define RENDERCOMMAND_H

namespace Panda
{
    class FRenderCommandBase
    {
    public:
        virtual void Execute() = 0;
    };
}

#endif