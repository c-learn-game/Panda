#include "GraphicsThreadPoolSubsystem.h"

namespace Panda
{
    FGraphicsThreadPoolSubsystem::~FGraphicsThreadPoolSubsystem()
    {
    }

    // 支持多线程访问，无需加锁
    FGraphicsThreadPoolSubsystem* FGraphicsThreadPoolSubsystem::Get()
    {
        static FGraphicsThreadPoolSubsystem PoolInst;
        return &PoolInst;
    }
}
