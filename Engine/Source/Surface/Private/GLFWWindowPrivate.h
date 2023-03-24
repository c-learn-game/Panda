#ifndef GLFWWINDOWPRIVATE_H
#define GLFWWINDOWPRIVATE_H

#include "WindowPrivate.h"

struct GLFWwindow;

namespace Panda
{
    class CGLFWWindowPrivate : public CWindowPrivate
    {
    public:
        explicit CGLFWWindowPrivate(const CString& WindowTitle);

        ~CGLFWWindowPrivate() override;

        void SetWindowTitle(const CString& NewTitle) override;

        void SetWindowSize(CIntSize NewSize) override;

    private:
        GLFWwindow* WindowHandle;
    
    };
}

#endif