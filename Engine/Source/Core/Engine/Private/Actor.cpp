//
// Created by Administrator on 2023/5/6.
//

#include "Core/Engine/Actor.h"
#include "Core/Engine/ActorComponent.h"

namespace Panda
{
    AActor::AActor()
    {
        RootComponent = MakeShared<UActorComponent>();
    }
}
