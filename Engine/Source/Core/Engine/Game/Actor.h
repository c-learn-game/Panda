
#ifndef PANDA_ACTOR_H
#define PANDA_ACTOR_H

#include "Core/Engine/TickableObject.h"

namespace Panda
{
    class AActor : public UTickableObject
    {
    public:
        explicit AActor();

        virtual ~AActor() = default;

        //void AddComponent(const SharedPtr<class UPrimitiveSceneComponent> &NewComponent);

    protected:
        friend class UWorld;
        void Tick(double Duration) override {}

    private:
        SharedPtr<class UActorComponent> RootComponent = nullptr;
        TArray<SharedPtr<class UPrimitiveSceneComponent>> Components;
    };
}

#endif //PANDA_ACTOR_H
