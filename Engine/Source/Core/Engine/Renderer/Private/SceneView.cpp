
#include "Core/Engine/Renderer/SceneView.h"
#include "Core/Engine/Game/World.h"

namespace Panda
{
    FSceneView::FSceneView(UWorld *InWorld)
            : World(InWorld)
            , ViewportRect()
    {
    }
}