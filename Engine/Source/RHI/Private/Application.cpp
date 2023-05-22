//
// Created by chendebi on 2023/4/30.
//

#include "Application.h"
#include "RHI/Private/RHIApplicationPrivate.h"
#include "RHI/RHIWindow.h"
#include "RHI/RenderContext.h"
#include "Core/Engine/Renderer/Renderer.h"
#include "Core/Engine/Game/ViewportClient.h"
#include "Core/Engine/Engine.h"
#include "Core/Timer.h"

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
        LastFrameTime = UTimer::Now();
        while (!bShouldQuit)
        {
            double CurrentFrameTime = UTimer::Now();
            double TickDuration = CurrentFrameTime - LastFrameTime;
            LastFrameTime = CurrentFrameTime;
            P->PollEvents();
            GGame->GetViewportClient()->Tick(TickDuration);
            Renderer->RendererMain();
        }
		LogInfo("Quit Application")
		Renderer->DestroyRenderer();
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
        if (P->Initialize())
        {
            MainWindow = MakeShared<RHIWindow>(AppName);
            RenderContext = FRenderContext::Get(MainWindow);
            Renderer = MakeShared<FRenderer>(RenderContext);
            Renderer->Initialize();
            LogInfo("Application [{}] initialize success.", AppName.ToStdString())
            return true;
        }
        return false;
    }
}