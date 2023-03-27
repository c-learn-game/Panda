#include "GraphicsThreadPoolSubsystem.h"
#include "Base/Public/Thread/Thread.h"
#include "Event/Public/Event.h"
#include "Renderer/Renderer.h"
#include "Renderer/Public/RendererContext.h"
#include "Surface/Public/Application.h"

namespace Panda
{
    CThread* FGraphicsThreadPoolSubsystem::MainThread = nullptr;
    CThread* FGraphicsThreadPoolSubsystem::RendererThread = nullptr;

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
        
        RendererThread = new CThread(std::thread(&FRenderer::RenderMain, CApplication::Get()->GetSceneRenderer()));
        RendererThread->Detach();
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
