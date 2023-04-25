//
// Created by chendebi on 2023/4/25.
//

#include "Basic/Logging/Logging.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Panda
{
    SharedPtr<spdlog::logger> FLoggerSubsystem::CoreLogger;
    SharedPtr<spdlog::logger> FLoggerSubsystem::ClientLogger;

    void FLoggerSubsystem::Init(FLogLevel LogLevel)
    {
        std::vector<spdlog::sink_ptr> sinks;
        sinks.emplace_back(MakeShared<spdlog::sinks::stdout_color_sink_mt>());

        sinks[0]->set_pattern("%^[%T] [%n] [%l]: %v%$");

        CoreLogger = MakeShared<spdlog::logger>("Panda", sinks.begin(), sinks.end());
        CoreLogger->set_level(static_cast<spdlog::level::level_enum>(LogLevel));
        spdlog::register_logger(CoreLogger);

        ClientLogger = MakeShared<spdlog::logger>("Client", sinks.begin(), sinks.end());
        ClientLogger->set_level(static_cast<spdlog::level::level_enum>(LogLevel));
        spdlog::register_logger(ClientLogger);
    }
}