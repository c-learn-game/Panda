#include "Base/Public/Thread/Thread.h"

namespace Panda
{
    CThread::CThread(const CThreadID& ID)
        : Id(ID), bReadOnly(true)
    {
        
    }
}
