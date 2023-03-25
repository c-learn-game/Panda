#ifndef GRAPHICSTHREADPOOLSUBSYSTEM_H
#define GRAPHICSTHREADPOOLSUBSYSTEM_H
#include "Base/Public/Pointer.h"

namespace Panda
{
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

        static CThread* MainThread;

        static void Init();
    };
    
}

#endif
