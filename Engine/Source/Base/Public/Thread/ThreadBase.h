#ifndef THREADBASE_H
#define THREADBASE_H


#include <thread>
#include <mutex>
#include "Base/Public/Logging/Logging.h"

namespace Panda
{

    using FMutex = std::mutex;
    using FThreadCondition = std::condition_variable;

    template <typename T>
    using FUniqueLock = std::unique_lock<T>;
    
    template<typename T>
    class FThreadBase
    {
    public:
        explicit FThreadBase(const CString& ThreadName);
        
        virtual ~FThreadBase();
        
        void Join();

        void Detach();

        bool Joinable() const;

        void Run();

        virtual void ThreadMain() {}
    
    private:
        CString ThreadName;
        std::thread StdThread;
    };

    template <typename T>
    FThreadBase<T>::FThreadBase(const CString& InThreadName)
        : ThreadName(InThreadName)
    {
    }

    template <typename T>
    FThreadBase<T>::~FThreadBase()
    {
        LogInfo(LogSystem, "Thread Destroyed(%d): %s",StdThread.get_id(), ThreadName.c_str())
        if (StdThread.joinable())
        {
            StdThread.join();
        }
    }

    template <typename T>
    void FThreadBase<T>::Join()
    {
        StdThread.join();
    }

    template <typename T>
    void FThreadBase<T>::Detach()
    {
        StdThread.detach();
    }

    template <typename T>
    bool FThreadBase<T>::Joinable() const
    {
        return StdThread.joinable();
    }

    template <typename T>
    void FThreadBase<T>::Run()
    {
        StdThread = std::thread(&T::ThreadMain, static_cast<T*>(this));
        LogInfo(LogSystem, "Create Thread : %s, whitch id is %d", ThreadName.c_str(), StdThread.get_id())
    }
}

#endif