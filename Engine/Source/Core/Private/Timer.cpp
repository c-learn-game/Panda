
#include "Core/Timer.h"
#include "GLFW/glfw3.h"

namespace Panda
{
    UTimer::UTimer()
    {
        Reset();
    }

    void UTimer::Reset()
    {
        StartTime = std::chrono::high_resolution_clock::now();
    }

    float UTimer::Elapsed() const
    {
        using namespace std::chrono;
        return duration_cast<nanoseconds>(high_resolution_clock::now()-StartTime).count() * 0.001f * 0.001f * 0.001f;
    }

    float UTimer::ElapsedMillis() const
    {
        return Elapsed() * 1000.0f;
    }

    double UTimer::Now()
    {
        return glfwGetTime();
    }
}