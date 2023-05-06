
#ifndef PANDA_ACTOR_H
#define PANDA_ACTOR_H

#include "Basic/Basic.h"

namespace Panda
{
    class AActor
    {
    public:
        explicit AActor();

        virtual ~AActor();

        void AddComponent(const SharedPtr<class UPrimitiveSceneComponent> &NewComponent);

    private:
        SharedPtr<class UActorComponent> RootComponent = nullptr;
        TArray<SharedPtr<class UPrimitiveSceneComponent>> Components;
    };
}

#endif //PANDA_ACTOR_H
