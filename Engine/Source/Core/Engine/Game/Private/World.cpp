
#include "Core/Engine/Game/World.h"
#include "Core/Engine/Game/Actor.h"
#include "Core/Engine/GameObject.h"

namespace Panda
{
    UWorld::~UWorld()
    {
        auto AllObjects = ChildObjects;
        ChildObjects.clear();
        for (auto & ChildObject : AllObjects)
        {
            delete ChildObject;
        }
    }

    void UWorld::Tick(double Duration)
    {
        for(auto Actor : Actors)
        {
            Actor->Tick(Duration);
        }
    }

    void UWorld::AddChild(UObject *Object)
    {
        if (Object && std::find(ChildObjects.begin(), ChildObjects.end(), Object) != ChildObjects.end())
        {
            ChildObjects.push_back(Object);
        }
    }

    bool UWorld::RemoveChild(UObject *Object)
    {
        return std::remove(ChildObjects.begin(), ChildObjects.end(), Object) != ChildObjects.end();
    }
}