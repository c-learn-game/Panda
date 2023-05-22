
#include "Core/Engine/Game/World.h"
#include "Core/Engine/Game/Actor.h"

namespace Panda
{
    void UWorld::Tick(double Duration)
    {
        for(auto Actor : Actors)
        {
            Actor->Tick(Duration);
        }
    }
}