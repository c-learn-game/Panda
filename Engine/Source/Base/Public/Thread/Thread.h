#ifndef THREAD_H
#define THREAD_H

#include <thread>
#include "Base/Base.h"

using CThreadID = std::thread::id;

namespace Panda
{
    class CThread
    {
    public:
        template<class _Fn,
        class... _Args,
        class = std::enable_if_t<!std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Fn>>, std::thread>>>
        explicit CThread(_Fn&& _Fx, _Args&&... _Ax);
        
        explicit CThread(const CThreadID& ID);
        
        explicit CThread() = default;
        
        virtual ~CThread() = default;

        bool IsReadOnly() const { return bReadOnly; }
        

    private:
        std::thread Thread;

        CThreadID Id;
        
        bool bReadOnly;
        
    };

    template <class _Fn, class ... _Args, class>
    CThread::CThread(_Fn&& _Fx, _Args&&... _Ax)
        : bReadOnly(false)
    {
        Thread = std::thread(_Fx, _Ax...);
    }
}

#endif
