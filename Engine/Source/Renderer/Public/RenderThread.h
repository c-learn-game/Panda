#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include "Base/Public/Thread/ThreadBase.h"
#include "Base/Base.h"
#include "Base/Public/Thread/Thread.h"

namespace Panda
{
    class FRenderer
    {
    public:
        explicit FRenderer();

        void SetContext(const SharedPtr<class FRenderContext>& NewContext);

        void InitContext() const;

    public:
        
        static FRenderer* Get();
        
        template <typename CommandType, typename... Args>
        static void AddDrawCommand(Args... CommandArgs);
        
    private:
        friend class FRenderThread;
        static FThreadCondition Condition;
        static FMutex CommandMutex;
        static CDequeue<SharedPtr<class FRenderCommandBase>> Commands;

    private:
        SharedPtr<class FRenderContext> Context;
    };

    class FRenderThread : public FThreadBase<FRenderThread>
    {
    public:
        FRenderThread(SharedPtr<class FRenderContext> Context);
        
        void ThreadMain() override;

    private:
        bool bRunning = true;
    };

    template <typename CommandType, typename ... Args>
    void FRenderer::AddDrawCommand(Args... CommandArgs)
    {
        CGuardLock<FMutex> Lock(CommandMutex);
        Commands.push_back(MakeSharedPtr<CommandType>(CommandArgs...));
        Condition.notify_one();
    }
}

#endif