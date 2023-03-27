#ifndef RENDERERCONTEXTPRIVATE_H
#define RENDERERCONTEXTPRIVATE_H
#include "Base/Public/Pointer.h"

namespace Panda
{
    class CWindowPrivate;
}

namespace Panda
{
    class CWindow;
}

namespace Panda
{
    class FRendererContextPrivate
    {
    public:
        explicit FRendererContextPrivate(const SharedPtr<CWindow>& InContextWindow);

        virtual void Init() = 0;

        virtual void SwapBuffers() = 0;

        static FRendererContextPrivate* Create(const SharedPtr<CWindow>& InContextWindow);

    protected:
        CWindowPrivate* GetContextWindowPrivate() const { return PrivateWindow; }

    private:
        CWindowPrivate* PrivateWindow;
    };
}

#endif