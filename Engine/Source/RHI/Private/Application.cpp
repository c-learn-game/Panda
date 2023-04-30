//
// Created by chendebi on 2023/4/30.
//

#include "RHI/Application.h"
#include "RHI/Private/RHIApplicationPrivate.h"
#include "RHI/RHIWindow.h"
namespace Panda
{
    Application* Application::GApp = nullptr;

    Application::Application(int argc, char **argv)
    {
        checkf(!GApp, "can't recreate application!")
        P = RHIApplicationPrivate::Get();
        for (int i = 0; i < argc; ++i)
        {
            Arguments.push_back(argv[i]);
        }
        GApp = this;
    }

    Application::~Application()
    {
        MainWindow = nullptr;
        P->DestroyApplication();
    }

    int Application::Exec()
    {
        if (P->Initialize())
        {
            MainWindow = MakeShared<RHIWindow>(PANDA_APPLICATION_NAME);
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
        LogCritical("Application Initialize failed, Quit!")
        return 1;
    }

    void Application::Quit()
    {
        bShouldQuit = true;
    }

    Application* Application::Get()
    {
        return GApp;
    }
}