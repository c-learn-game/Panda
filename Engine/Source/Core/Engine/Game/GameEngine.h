
#ifndef PANDA_GAMEENGINE_H
#define PANDA_GAMEENGINE_H

#include "Core/Instance.h"
#include "ViewportClient.h"

namespace Panda
{

    class UWorld;

    class UGameEngine : public UInstance<UGameEngine>
    {
        INSTANCE_CLASS(UGameEngine)

    public:
        ~UGameEngine() override;

        UViewportClient* GetViewportClient() const { return ViewportClient; }

        UWorld* GetCurrentWorld() const;

        void Tick(double Duration);

    protected:
        void Initialize() override;

    private:
        UViewportClient* ViewportClient = nullptr;
    };
}


#endif //PANDA_GAMEENGINE_H
