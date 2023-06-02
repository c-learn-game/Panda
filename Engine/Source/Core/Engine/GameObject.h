
#ifndef PANDA_GAMEOBJECT_H
#define PANDA_GAMEOBJECT_H

#include "TickableObject.h"
#include "Game/GameEngine.h"

namespace Panda
{
    class UWorld;
    class UObject : public UTickableObject
    {
    public:
        explicit UObject(UObject* InParent = nullptr);

        virtual ~UObject() override;

        void SetParent(UObject* NewParent);

    private:

        void AddChildObject(UObject* Object);

        void RemoveChildObject(UObject* Object);

    private:
        UObject* Parent = nullptr;

        TArray<UObject*> ObjectChildren;
    };
}


#endif //PANDA_GAMEOBJECT_H
