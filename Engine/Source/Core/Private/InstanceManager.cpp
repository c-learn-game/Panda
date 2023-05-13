
#include "Core/InstanceManager.h"
#include "Core/Engine/Asset/AssetManager.h"

namespace Panda
{
    UAssetManager* UInstanceManager::GetAssetManager()
    {
        return UAssetManager::Get();
    }

    void UInstanceManager::Initialize()
    {
        UAssetManager::Get()->Initialize();
    }
}