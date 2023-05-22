
#ifndef PANDA_GAMETIMER_H
#define PANDA_GAMETIMER_H

#include "Basic/Basic.h"
#include <chrono>

namespace Panda
{
    class UTimer
    {
    public:
        explicit UTimer();

        void Reset();

        float Elapsed() const;

        float ElapsedMillis() const;

        static double Now();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> StartTime;
    };
}


#endif //PANDA_GAMETIMER_H
