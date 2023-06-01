
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
        virtual ~UObject() override;

    private:
        template <typename T, typename ...Args>
        friend T* NewObject(class UWorld* World, Args&& ...args);

        void SetObjectWorld(UWorld* NewWorld);

    private:
        UWorld* World = nullptr;
    };

    template <typename T, typename ...Args>
    T* NewObject(class UWorld* World, Args&& ...args)
    {
        UObject* Object = new T(std::forward<Args>(args) ...);
        Object->SetObjectWorld(World ? World : UGameEngine::Get()->GetCurrentWorld());
        return (T*)Object;
    }
}


#endif //PANDA_GAMEOBJECT_H
