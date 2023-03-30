#include "RenderThread.h"

#include "Base/Public/Logging/Logging.h"

namespace Panda
{

    FMutex FRenderThread::EventMutex;

    FThreadCondition FRenderThread::Condition;

    CDequeue<int> FRenderThread::Numbers;
    
    FRenderThread::FRenderThread()
        : FThreadBase("Render Thread")
    {
    }

    void FRenderThread::PushNumber(int x)
    {
        std::lock_guard<FMutex> Lock(EventMutex);

        LogInfo(LogSystem, "get number: %d", x)
        Numbers.push_back(x);
        Condition.notify_one();
    }

    void FRenderThread::ThreadMain()
    {
        while (true)
        {
            FUniqueLock<FMutex> Lock(EventMutex);
            Condition.wait(Lock, [this]() { return !Numbers.empty(); });
            int Num = Numbers.front();
            LogInfo(LogSystem, "Process number: %d", Num)
            Numbers.pop_front();
        }
    }
}
