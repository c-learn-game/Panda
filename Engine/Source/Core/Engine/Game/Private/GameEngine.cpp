
#include "Core/Engine/Game/GameEngine.h"

namespace Panda
{
    UGameEngine::~UGameEngine()
    {
        delete ViewportClient;
    }

    void UGameEngine::Initialize()
    {
        ViewportClient = new UViewportClient;
        ViewportClient->ResizeViewport(0,0,600,400);
    }

    void UGameEngine::Tick(double Duration)
    {
        ViewportClient->Tick(Duration);
    }
}