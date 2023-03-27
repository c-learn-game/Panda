#ifndef THREAD_H
#define THREAD_H

#include <mutex>
#include <thread>
#include "Base/Base.h"

using CThreadID = std::thread::id;
using CMutex = std::mutex;

template<typename MutexType>
using CScopedLock = std::scoped_lock<MutexType>;

namespace Panda
{
    class CThread
    {
    public:
        explicit CThread();

        explicit CThread(const CThreadID &InitId);

        explicit CThread(std::thread&& InThread);

        ~CThread();

        void Detach();

    private:
        std::thread Thread;

        CThreadID ThreadId;

        bool bInitWithId = false;
    };
}

#endif
