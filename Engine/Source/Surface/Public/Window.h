#ifndef WINDOW_H
#define WINDOW_H

#include "Base/Base.h"

namespace Panda
{
    class CWindow
    {
    public:
        explicit CWindow(CWindow* Parent = nullptr, const CString& DefaultTitle = "Window");

        void SetWindowTitle(const CString& NewWindowTitle);

        void SetWindowSize(CIntSize NewSize);

    private:
        class CWindowPrivate* P;

        CWindow* ParentWindow;

        CString WindowTitle;

        CIntSize WindowSize;
    };
}

#endif