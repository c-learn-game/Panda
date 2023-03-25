#include "GraphicsThreadPoolSubsystem.h"
#include "Base/Public/Thread/Thread.h"

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

    void FGraphicsThreadPoolSubsystem::Init()
    {
        MainThread = new CThread(std::this_thread::get_id());
        //RendererThread = new CThread<>
    }
}
