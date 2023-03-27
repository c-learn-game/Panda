#include "Surface/Public/Window.h"

#include "WindowPrivate.h"
#include "Event/Public/WindowEvents.h"

namespace Panda
{
    CWindow::CWindow(CWindow* Parent, const CString& DefaultTitle)
        : ParentWindow(Parent), WindowTitle(DefaultTitle),
          WindowSize(CWindowPrivate::WindowDefaultWidth, CWindowPrivate::WindowDefaultHeight)
    {
        P = CWindowPrivate::Create(this, DefaultTitle);
    }

    CWindow::~CWindow()
    {
        P->DestroyWindow();
    }

    void CWindow::SetWindowTitle(const CString& NewWindowTitle)
    {
        if (NewWindowTitle.empty()) return;
        WindowTitle = NewWindowTitle;
        P->SetWindowTitle(NewWindowTitle);
    }

    void CWindow::SetWindowSize(CIntSize NewSize)
    {
        if (!NewSize.IsValid()) return;
        WindowSize = NewSize;
        P->SetWindowSize(NewSize);
    }

    void CWindow::ResizeEvent(CResizeEvent* InEvent)
    {
        LogInfo(LogSystem, "resize event: %dx%d", InEvent->With(), InEvent->Height())
    }
}
