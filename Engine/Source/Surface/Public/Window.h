#ifndef WINDOW_H
#define WINDOW_H

#include "Base/Base.h"

namespace Panda
{
    class CResizeEvent;
}

namespace Panda
{
    class CWindow
    {
    public:
        explicit CWindow(CWindow* Parent = nullptr, const CString& DefaultTitle = "Window");
        
        virtual ~CWindow();

        void SetWindowTitle(const CString& NewWindowTitle);

        void SetWindowSize(CIntSize NewSize);

    protected:
        friend class CApplication;
        virtual void ResizeEvent(CResizeEvent* InEvent);

    private:
        friend class FRendererContextPrivate;
        class CWindowPrivate* P;

        CWindow* ParentWindow;

        CString WindowTitle;

        CIntSize WindowSize;
    };
}

#endif
