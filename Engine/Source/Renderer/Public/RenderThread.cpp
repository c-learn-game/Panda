#include "RenderThread.h"

#include "RendererContext.h"
#include "Base/Public/Logging/Logging.h"
#include "Renderer/Private/Command/RenderCommandBase.h"
#include "RHI/Public/PlatformRHI.h"

namespace Panda
{

    FMutex FRenderer::CommandMutex;

    FThreadCondition FRenderer::Condition;

    CDequeue<SharedPtr<FRenderCommandBase>> FRenderer::Commands;

    FRenderer::FRenderer()
    {
    }

    void FRenderer::SetContext(const SharedPtr<FRenderContext>& NewContext)
    {
        // 必须在渲染线程调用
        Context = NewContext;
        Commands.clear();
    }

    void FRenderer::InitContext() const
    {
        Context->Init();
        RHICommand->SetClearColor(0.2f, 0.4f, 0.8f);
    }

    FRenderer* FRenderer::Get()
    {
        static FRenderer Renderer;
        return &Renderer;
    }

    FRenderThread::FRenderThread(SharedPtr<FRenderContext> Context)
        : FThreadBase("Render Thread")
    {
        FRenderer::Get()->SetContext(Context);
    }

    void FRenderThread::ThreadMain()
    {
        FRenderer::Get()->InitContext();
        RHICommand->Clear();
        FRenderer::Get()->Context->SwapBuffers();
        while (bRunning)
        {
            FUniqueLock<FMutex> Lock(FRenderer::CommandMutex);
            FRenderer::Condition.wait(Lock);
            RHICommand->Clear();
            for (const auto& Command : FRenderer::Commands)
            {
                Command->Execute();
            }
            FRenderer::Commands.clear();
            FRenderer::Get()->Context->SwapBuffers();
            
        }
        LogInfo(LogSystem, "Thread %d Quit", GetThreadId())
    }
}
