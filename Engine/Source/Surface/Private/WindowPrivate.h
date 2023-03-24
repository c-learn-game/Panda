#ifndef WINDOWPRIVATE_H
#define WINDOWPRIVATE_H

#include "Base/Base.h"

namespace Panda
{
    class CWindowPrivate
    {
    public:
        constexpr static int WindowDefaultWidth = 600;
        constexpr static int WindowDefaultHeight = 400;
        
    public:
        explicit CWindowPrivate(const CString& WindowTitle = "Window") {}

        virtual ~CWindowPrivate() = default;

        virtual void SetWindowSize(CIntSize NewSize) = 0;

        virtual void SetWindowTitle(const CString& NewTitle) = 0;

        static CWindowPrivate* Create(const CString& WindowTitle = "Window");
    };
}

#endif