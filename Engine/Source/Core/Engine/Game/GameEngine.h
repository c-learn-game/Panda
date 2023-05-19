
#ifndef PANDA_GAMEENGINE_H
#define PANDA_GAMEENGINE_H

#include "Core/Instance.h"
#include "ViewportClient.h"

namespace Panda
{
    class UGameEngine : public UInstance<UGameEngine>
    {
        INSTANCE_CLASS(UGameEngine)

    public:
        ~UGameEngine() override;

        UViewportClient* GetViewportClient() const { return ViewportClient; }

    protected:
        void Initialize() override;

    private:
        UViewportClient* ViewportClient = nullptr;
    };
}


#endif //PANDA_GAMEENGINE_H
