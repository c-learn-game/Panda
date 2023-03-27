#include "Base/Public/Thread/Thread.h"

namespace Panda
{
    CThread::CThread()
        : bInitWithId(false)
    {
        
    }

    CThread::CThread(const CThreadID& ID)
        : ThreadId(ID), bInitWithId(true)
    {
        
    }

    CThread::CThread(std::thread&& InThread)
        : Thread(std::move(InThread))
    {
        ThreadId = Thread.get_id();
    }

    CThread::~CThread()
    {
        if (Thread.joinable())
        {
            Thread.join();
        }
    }

    void CThread::Detach()
    {
        Thread.detach();
    }
}
