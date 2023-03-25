//
//  WindowEvent.h
//  Panda
//
//  Created by chendebi on 2023/3/25.
//

#ifndef APPLICATIONEVENTS_H
#define APPLICATIONEVENTS_H

#include "Event.h"

namespace Panda
{
    class CWindowCloseEvent : public CEvent
    {
        PANDA_REGISTER_EVENT(CloseEvent, ApplicationEventCategory)
        
    public:
        explicit CWindowCloseEvent(class CWindow* Window) : CloseWindow(Window) {}
        
    public:
        CWindow* CloseWindow;
    };
}

#endif /* APPLICATIONEVENTS_H */
