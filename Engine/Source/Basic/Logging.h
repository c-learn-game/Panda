//
// Created by chendebi on 2023/4/25.
//

#ifndef PANDA_LOGGING_H
#define PANDA_LOGGING_H

#include "Basic/BasicVariables.h"
#include "spdlog/spdlog.h"

namespace Panda
{
    class FLoggerSubsystem
    {
    public:
        enum FLogLevel
        {
            Debug = spdlog::level::debug,
            Info,
            Warn,
            Error,
            Critical
        };
    public:
        static void Init(FLogLevel LogLevel);

        static SharedPtr<spdlog::logger> CreateLogger(const FString& LoggerName, FLogLevel LogLevel);

        static SharedPtr<spdlog::logger> GetCoreLogger()  { return CoreLogger; }

    private:
        static SharedPtr<spdlog::logger> CoreLogger;
    };
}

#define LogDebug(...) Panda::FLoggerSubsystem::GetCoreLogger()->debug(__VA_ARGS__);
#define LogInfo(...) Panda::FLoggerSubsystem::GetCoreLogger()->info(__VA_ARGS__);
#define LogWarn(...) Panda::FLoggerSubsystem::GetCoreLogger()->warn(__VA_ARGS__);
#define LogError(...) Panda::FLoggerSubsystem::GetCoreLogger()->error(__VA_ARGS__);
#define LogCritical(...) Panda::FLoggerSubsystem::GetCoreLogger()->critical(__VA_ARGS__);

#endif //PANDA_LOGGING_H
