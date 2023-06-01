
#ifndef PANDA_WORLD_H
#define PANDA_WORLD_H

#include "Core/Engine/TickableObject.h"

namespace Panda
{
    class UWorld : public UTickableObject
    {
    public:
        virtual ~UWorld() override;

    protected:
        friend class UViewportClient;
        friend class UObject;

        void Tick(double Duration) override;

        void AddChild(UObject* Object);

        bool RemoveChild(UObject* Object);

    public:
        TArray<class AActor*> Actors;

    private:
        // 所有的子对象
        TArray<class UObject*> ChildObjects;
    };
}


#endif //PANDA_WORLD_H
