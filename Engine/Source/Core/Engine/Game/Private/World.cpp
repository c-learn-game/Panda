
#include "Core/Engine/Game/World.h"
#include "Core/Engine/Game/Actor.h"
#include "Core/Engine/GameObject.h"

namespace Panda
{
    UWorld::~UWorld()
    {

    }

    void UWorld::Tick(double Duration)
    {
        for(auto Actor : Actors)
        {
            Actor->Tick(Duration);
        }
    }
}