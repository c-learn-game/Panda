
#ifndef PANDA_GAMEENGINE_H
#define PANDA_GAMEENGINE_H

#include "Core/Instance.h"
#include "ViewportClient.h"

namespace Panda
{

    class UObject;
    class UWorld;

    class UGameEngine : public UInstance<UGameEngine>
    {
        INSTANCE_CLASS(UGameEngine)

    public:
        ~UGameEngine() override;

        UViewportClient* GetViewportClient() const { return ViewportClient; }

        UWorld* GetCurrentWorld();

        void Tick(double Duration);

    protected:
        void Initialize() override;

    private:
        friend class UObject;
        void AddGameObject(UObject* GameObject);

        void RemoveGameObject(UObject* GameObject);

    private:
        UViewportClient* ViewportClient = nullptr;
        TArray<UObject*> GameObjects;
    };
}


#endif //PANDA_GAMEENGINE_H
