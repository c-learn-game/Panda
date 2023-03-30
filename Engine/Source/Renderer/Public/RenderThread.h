#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include "Base/Public/Thread/ThreadBase.h"
#include "Base/Base.h"

namespace Panda
{
    class FRenderThread : public FThreadBase<FRenderThread>
    {
    public:
        FRenderThread();

        static void PushNumber(int x);
        
        void ThreadMain() override;

    private:
        static FThreadCondition Condition;
        static FMutex EventMutex;
        
        static CDequeue<int> Numbers;
    };
}

#endif