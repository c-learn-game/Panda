
#include "Core/Engine/Game/ViewportClient.h"
#include "Core/Engine/Renderer/SceneView.h"
#include "Core/Engine/Game/World.h"

namespace Panda
{
    UViewportClient::UViewportClient(FIntRect DefaultViewportRect)
    : ViewportRect(DefaultViewportRect)
    {
        World = new UWorld;
    }

    UViewportClient::~UViewportClient()
    {
        delete World;
    }

    void UViewportClient::ResizeViewport(int x, int y, int w, int h)
    {
        ViewportRect = {x, y, w, h};
        if (SceneView)
            SceneView->ViewportRect = ViewportRect;
    }

    FSceneView* UViewportClient::CreateSceneView()
    {
        SceneView = new FSceneView();
        SceneView->ViewportRect = ViewportRect;
        return SceneView;
    }

    void UViewportClient::Tick(double Duration)
    {
        World->Tick(Duration);
        SceneView->Duration = Duration;
    }
}