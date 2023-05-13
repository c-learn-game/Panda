//
// Created by chendebi on 2023/5/1.
//

#include "Application.h"

using namespace Panda;

static TArray<FString> MakeArguments(int argc, char **argv)
{
    TArray<FString> Arguments;
    for (int i = 0; i < argc; ++i)
    {
        Arguments.push_back(argv[i]);
    }
    return Arguments;
}

int main(int argc, char **argv)
{
	FLoggerSubsystem::Init(FLoggerSubsystem::Debug);
	LogInfo("Log system initialized.")

    Panda::FPath::InitApplicationPaths();
    LogInfo("Path system initialized!")

    auto app = GetApplication(MakeArguments(argc, argv));
    app->PreInitApplication();

    if (!app->Initialize())
    {
        LogCritical("application initialize failed!");
        return 1;
    }
    app->PostInitApplication();

    return app->Exec();
}