#include "Basic/Basic.h"
using namespace Panda;

int main()
{
    FLoggerSubsystem::Init(FLoggerSubsystem::Debug);
    LogDebug("this is a debug log")
    LogInfo("this is a info log")
    LogWarn("this is a warn log")
    LogError("this is a error log")
    LogCritical("this is a critical log")
    check(false)
}