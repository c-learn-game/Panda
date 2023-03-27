//
//  WindowEvent.h
//  Panda
//
//  Created by chendebi on 2023/3/25.
//

#ifndef APPLICATIONEVENTS_H
#define APPLICATIONEVENTS_H

#include "Event.h"
#include "WindowEvents.h"

namespace Panda
{

    class CWindowBaseEvent : public CEvent
    {
    public:
        explicit CWindowBaseEvent(CWindow* InWindow)
            : Window(InWindow) {}
        
        CWindow* Window;
    };
    
    class CWindowCloseEvent : public CWindowBaseEvent
    {
        PANDA_REGISTER_EVENT(CloseEvent, ApplicationEventCategory)
        
    public:
        explicit CWindowCloseEvent(class CWindow* InWindow) : CWindowBaseEvent(InWindow) {}

        CCloseEvent GetWindowEvent() const
        {
            return CCloseEvent();
        }
    };

    class CWindowResizeEvent : public CWindowBaseEvent
    {
        PANDA_REGISTER_EVENT(ResizeEvent, ApplicationEventCategory)

        explicit CWindowResizeEvent(class CWindow* InWindow, int InWidth, int InHeight)
            : CWindowBaseEvent(InWindow), ResizeEvent(InWidth, InHeight) {}

        CResizeEvent GetWindowEvent() const
        {
            return ResizeEvent;
        }
        
    private:
        CResizeEvent ResizeEvent;
    };
}

#endif /* APPLICATIONEVENTS_H */
