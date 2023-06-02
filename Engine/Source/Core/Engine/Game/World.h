
#ifndef PANDA_WORLD_H
#define PANDA_WORLD_H

#include "Core/Engine/GameObject.h"

namespace Panda
{
    class UWorld : public UObject
    {
    public:
        virtual ~UWorld() override;

    protected:
        friend class UViewportClient;

        void Tick(double Duration) override;

    public:
        TArray<class AActor*> Actors;
    };
}


#endif //PANDA_WORLD_H
