
#ifndef PANDA_VIEWPORTCLIENT_H
#define PANDA_VIEWPORTCLIENT_H

#include "Basic/Basic.h"

namespace Panda
{
    class UViewportClient
    {
    public:
        explicit UViewportClient(FIntRect DefaultViewportRect = FIntRect());

        virtual ~UViewportClient() = default;

        void ResizeViewport(int x, int y, int w, int h);

        FIntRect GetViewportRect() const { return ViewportRect; }

    private:
        FIntRect ViewportRect;
        class UWorld* World = nullptr;
    };
}


#endif //PANDA_VIEWPORTCLIENT_H
