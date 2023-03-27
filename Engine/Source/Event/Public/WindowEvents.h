#ifndef WINDOWEVENTS_H
#define WINDOWEVENTS_H

#include "Event/Public/Event.h"

namespace Panda
{
    class CCloseEvent : public CEvent
    {
        PANDA_REGISTER_EVENT(CloseEvent, WindowEventCategory)

        explicit CCloseEvent() {}
    };

    class CResizeEvent : public CEvent
    {
        PANDA_REGISTER_EVENT(ResizeEvent, WindowEventCategory)

        explicit CResizeEvent(int InWidth, int InHeight)
            : Size(InWidth, InHeight)
        {}

        CIntSize GetSize() const { return Size; }

        int With() const { return Size.Width; }

        int Height() const { return Size.Height; }

    private:
        CIntSize Size;
    };
}

#endif