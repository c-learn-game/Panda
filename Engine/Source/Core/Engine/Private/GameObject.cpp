
#include "Core/Engine/GameObject.h"
#include "Core/Engine/Game/World.h"

namespace Panda
{
    UObject::~UObject()
    {
        World->RemoveChild(this);
    }

    void UObject::SetObjectWorld(UWorld *NewWorld)
    {
        check(NewWorld)
        World = NewWorld;
        World->AddChild(this);
    }
}