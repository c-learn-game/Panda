#include "GraphicsThreadPoolSubsystem.h"
#include "Base/Public/Thread/Thread.h"
#include "Event/Public/Event.h"
#include "Renderer/Command/ContextChangeCommand.h"
#include "Renderer/Public/RendererContext.h"
#include "Renderer/Public/RenderThread.h"
#include "Surface/Public/Application.h"

namespace Panda
{
    CThread* FGraphicsThreadPoolSubsystem::MainThread = nullptr;
    FRenderThread* FGraphicsThreadPoolSubsystem::RenderThread = nullptr;

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
        
        RenderThread = new FRenderThread(CApplication::Get()->GetContext());
        RenderThread->Run();
        RenderThread->Detach();
    }

    void FGraphicsThreadPoolSubsystem::PushEventToMainThread(const SharedPtr<CEvent> InEvent, bool Combined)
    {
        CScopedLock<CMutex> Lock(MainThreadMutex);
        if (Combined && !MainThreadEvents.empty() && MainThreadEvents.back()->GetType() == InEvent->GetType())
        {
            MainThreadEvents.pop_back();
            MainThreadEvents.push_back(InEvent);
        }
        else
        {
            MainThreadEvents.push_back(InEvent);
        }
    }
}
