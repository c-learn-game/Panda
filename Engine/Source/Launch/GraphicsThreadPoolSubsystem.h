#ifndef GRAPHICSTHREADPOOLSUBSYSTEM_H
#define GRAPHICSTHREADPOOLSUBSYSTEM_H
#include <mutex>

#include "Base/Public/Pointer.h"
#include "Base/Public/Thread/Thread.h"
#include "Base/Public/Types/List.h"

namespace Panda
{
    class FRenderThread;
    class CEvent;
    class CThread;
}

namespace Panda
{
    class FGraphicsThreadPoolSubsystem
    {
    private:
        explicit FGraphicsThreadPoolSubsystem() = default;

        ~FGraphicsThreadPoolSubsystem();

    public:
        static FGraphicsThreadPoolSubsystem* Get();

        static void Init();

        void PushEventToMainThread(SharedPtr<CEvent> InEvent, bool Combined = false);

    public:
        CList<SharedPtr<CEvent>> MainThreadEvents;

        CMutex MainThreadMutex;

    public:

        static CThread* MainThread;
        
        static CThread* RendererThread;

        static FRenderThread* RenderThread;
    };
    
}

#endif
