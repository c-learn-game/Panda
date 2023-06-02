
#include "Core/Engine/Game/GameEngine.h"
#include "Core/Engine/Game/World.h"

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

    UWorld* UGameEngine::GetCurrentWorld()
    {
        return ViewportClient->GetWorld();
    }

    void UGameEngine::AddGameObject(UObject *GameObject)
    {
        if (GameObject)
            GameObjects.push_back(GameObject);
    }

    void UGameEngine::RemoveGameObject(UObject *GameObject)
    {
        if (GameObject)
            std::remove(GameObjects.begin(), GameObjects.end(), GameObject);
    }
}