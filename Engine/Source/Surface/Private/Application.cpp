#include "Surface/Public/Application.h"
#include "ApplicationPrivate.h"
#include "Surface/Public/Window.h"
#include "Event/Public/ApplicationEvents.h"
#include "Launch/GraphicsThreadPoolSubsystem.h"
#include "Renderer/Public/RendererContext.h"
#include "Renderer/Public/RenderThread.h"

namespace Panda
{

    CApplication* CApplication::AppInst = nullptr;
    
    CApplication::CApplication(const FApplicationArguments& InParameter)
        : ApplicationName("PandaEngine"),
          ApplicationVersion("0.0.1"),
          QuitCode(0),
          bRunning(true)
    {
        PANDA_UNUSED(InParameter);
        checkmsg(!AppInst, "Application already existed!")
        AppInst = this;
        P = CApplicationPrivate::Create();
    }

    void CApplication::SetApplicationName(const CString& InApplicationName)
    {
        ApplicationName = InApplicationName;
    }

    void CApplication::SetApplicationVersion(const CString& InVersion)
    {
        ApplicationVersion = InVersion;
    }

    CApplication* CApplication::Get()
    {
        return AppInst;
    }

    void CApplication::Quit()
    {
        bRunning = false;
    }

    bool CApplication::OnWindowCloseEvent(SharedPtr<CWindowCloseEvent> InEvent)
    {
        if (InEvent->Window == ContextWindow.get())
        {
            bRunning = false;
        }
        return true;
    }

    bool CApplication::OnWindowResizeEvent(SharedPtr<CWindowResizeEvent> InEvent)
    {
        CResizeEvent Event = InEvent->GetWindowEvent();
        ContextWindow->ResizeEvent(&Event);
        return true;
    }

    void CApplication::PreInit()
    {
        ContextWindow = MakeSharedPtr<CWindow>(nullptr, ApplicationName);
        Context = MakeSharedPtr<FRenderContext>(ContextWindow);
    }

    int CApplication::Exec()
    {
        while (bRunning)
        {
            P->PollEvents();
            ExecuteAppEvents();
        }
		FGraphicsThreadPoolSubsystem::Get()->RenderThread->Stop();
        return QuitCode;
    }

    void CApplication::ExecuteAppEvents()
    {
        CScopedLock<CMutex> Lock(FGraphicsThreadPoolSubsystem::Get()->MainThreadMutex);
        for (auto Event : FGraphicsThreadPoolSubsystem::Get()->MainThreadEvents) {
            CEventDispatcher Dispatcher(Event);
            Dispatcher.Dispatch<CWindowCloseEvent>(PANDA_BIND_FUNC(CApplication::OnWindowCloseEvent));
            Dispatcher.Dispatch<CWindowResizeEvent>(PANDA_BIND_FUNC(CApplication::OnWindowResizeEvent));
        }
        FGraphicsThreadPoolSubsystem::Get()->MainThreadEvents.clear();
    }
}
