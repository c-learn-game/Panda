
#ifndef PANDA_VIEWPORTCLIENT_H
#define PANDA_VIEWPORTCLIENT_H

#include "Core/Engine/TickableObject.h"

namespace Panda
{
    class UWorld;
    class FSceneView;

    class UViewportClient : public UTickableObject
    {
    public:
        explicit UViewportClient(FIntRect DefaultViewportRect = FIntRect());

        virtual ~UViewportClient();

        void ResizeViewport(int x, int y, int w, int h);

        FIntRect GetViewportRect() const { return ViewportRect; }

        UWorld* GetWorld() const { return World; }

        FSceneView* CreateSceneView();

        void Tick(double Duration) override;

    private:
        FIntRect ViewportRect;
        class UWorld* World = nullptr;
        FSceneView* SceneView = nullptr;
    };
}


#endif //PANDA_VIEWPORTCLIENT_H
