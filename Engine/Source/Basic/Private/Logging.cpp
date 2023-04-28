//
// Created by chendebi on 2023/4/25.
//

#include "Basic/Logging.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Panda
{
    SharedPtr<spdlog::logger> FLoggerSubsystem::CoreLogger;

    void FLoggerSubsystem::Init(FLogLevel LogLevel)
    {
        CoreLogger = CreateLogger("Panda", LogLevel);
    }

    SharedPtr<spdlog::logger> FLoggerSubsystem::CreateLogger(const FString &LoggerName, FLogLevel LogLevel)
    {
        std::vector<spdlog::sink_ptr> sinks;
        sinks.emplace_back(MakeShared<spdlog::sinks::stdout_color_sink_mt>());

        sinks[0]->set_pattern("%^[%T] [%n] [%l]: %v%$");
        auto Logger = MakeShared<spdlog::logger>("Panda", sinks.begin(), sinks.end());
        Logger->set_level(static_cast<spdlog::level::level_enum>(LogLevel));
        spdlog::register_logger(Logger);
        return Logger;
    }
}