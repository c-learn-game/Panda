
#include "Core/Engine/Game/ViewportClient.h"

namespace Panda
{
    UViewportClient::UViewportClient(FIntRect DefaultViewportRect)
    : ViewportRect(DefaultViewportRect)
    {

    }

    void UViewportClient::ResizeViewport(int x, int y, int w, int h)
    {
        ViewportRect = {x, y, w, h};
    }
}