
#include "Core/InstanceManager.h"
#include "Core/Engine/Asset/AssetManager.h"
#include "Core/Engine/Game/GameEngine.h"

namespace Panda
{
    UAssetManager* UInstanceManager::GetAssetManager()
    {
        return UAssetManager::Get();
    }

    void UInstanceManager::Initialize()
    {
        UAssetManager::Get()->Initialize();
        UGameEngine::Get()->Initialize();
    }
}