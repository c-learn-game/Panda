//
// Created by chendebi on 2023/4/30.
//

#include "Application.h"
#include "RHI/Private/RHIApplicationPrivate.h"
#include "RHI/RHIWindow.h"
namespace Panda
{
    Application* Application::GApp = nullptr;

    FString Application::AppName = PANDA_APPLICATION_NAME;

    Application::Application(const TArray<FString>& InArguments)
    : Arguments(std::move(InArguments))
    {
        checkf(!GApp, "can't recreate application!")
        P = RHIApplicationPrivate::Get();
        GApp = this;
    }

    Application::~Application()
    {
        MainWindow = nullptr;
        P->DestroyApplication();
    }

    int Application::Exec()
    {
        while (true)
        {
            P->PollEvents();
            if (bShouldQuit)
            {
                break;
            }
        }
        LogInfo("Quit Application")
        return 0;
    }

    void Application::Quit()
    {
        bShouldQuit = true;
    }

    Application* Application::Get()
    {
        return GApp;
    }

    bool Application::Initialize()
    {
        FLoggerSubsystem::Init(FLoggerSubsystem::Debug);
        LogInfo("Log system initialized.")

        if (P->Initialize())
        {
            MainWindow = MakeShared<RHIWindow>(AppName);
            LogInfo("{} initialize success.", AppName)
            return true;
        }
        return false;
    }
}