//
// Created by chendebi on 2023/4/25.
//

#ifndef PANDA_LOGGING_H
#define PANDA_LOGGING_H

#include "Basic/Basic.h"
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

        static SharedPtr<spdlog::logger> GetCoreLogger()  { return CoreLogger; }
        static SharedPtr<spdlog::logger> GetClientLogger()  { return ClientLogger; }

    private:
        static SharedPtr<spdlog::logger> CoreLogger;
        static SharedPtr<spdlog::logger> ClientLogger;
    };
}

#endif //PANDA_LOGGING_H
