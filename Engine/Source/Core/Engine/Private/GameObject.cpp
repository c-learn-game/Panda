
#include "Core/Engine/GameObject.h"
#include "Core/Engine/Game/GameEngine.h"

namespace Panda
{
    UObject::UObject(UObject* InParent)
    {
        SetParent(InParent);
        UGameEngine::Get()->AddGameObject(this);
    }

    UObject::~UObject()
    {
        for (auto Child: ObjectChildren) {
            delete Child;
        }
        ObjectChildren.clear();
        if (Parent)
            Parent->RemoveChildObject(this);
        UGameEngine::Get()->RemoveGameObject(this);
    }

    void UObject::SetParent(UObject *NewParent)
    {
        if (NewParent && NewParent != Parent)
        {
            if (Parent)
                Parent->RemoveChildObject(this);
            Parent = NewParent;
            Parent->AddChildObject(this);
        }
    }

    void UObject::AddChildObject(UObject *Object)
    {
        if (Object && std::find(ObjectChildren.begin(), ObjectChildren.end(), Object) == ObjectChildren.end())
        {
            ObjectChildren.push_back(Object);
        }
    }

    void UObject::RemoveChildObject(UObject *Object)
    {
        if (Object)
        {
            auto it = std::find(ObjectChildren.begin(), ObjectChildren.end(), Object);
            if (it != ObjectChildren.end())
            {
                std::remove(ObjectChildren.begin(), ObjectChildren.end(), Object);
            }
        }
    }
}