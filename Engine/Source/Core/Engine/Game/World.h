
#ifndef PANDA_WORLD_H
#define PANDA_WORLD_H

#include "Core/Engine/TickableObject.h"

namespace Panda
{
    class UWorld : public UTickableObject
    {
    public:
        virtual ~UWorld() = default;

    protected:
        friend class UViewportClient;
        void Tick(double Duration) override;

    public:
        TArray<class AActor*> Actors;
    };
}


#endif //PANDA_WORLD_H
