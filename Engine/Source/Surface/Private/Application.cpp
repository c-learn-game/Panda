#include "Surface/Public/Application.h"
#include "ApplicationPrivate.h"
#include "Surface/Public/Window.h"
#include "Event/Public/ApplicationEvents.h"

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
        
    }

    void CApplication::AddEvent(CEvent* InEvent)
    {
        checkmsg(InEvent.GetInCategory(CEvent::ApplicationEventcategory), "An event of a type other than ApplicationEventCategory, whitch type is: %s", InEvent.GetEventName().c_str())
        
        AppEventList.push_back(InEvent);
    }

    void CApplication::PreInit()
    {
        ContextWindow = MakeSharedPtr<CWindow>(nullptr, ApplicationName);
    }

    int CApplication::Exec()
    {
        while (bRunning)
        {
            P->PollEvents();
            ExecuteAppEvents();
        }
        return QuitCode;
    }

    void CApplication::ExecuteAppEvents()
    {
        for (auto Event : AppEventList) {
            if (Event->GetType() == CEvent::EEventType::CloseEvent)
            {
                OnWindowCloseEvent(dynamic_cast<CWindowCloseEvent*>(Event));
            }
        }
    }

    void CApplication::OnWindowCloseEvent(CWindowCloseEvent *InEvent)
    {
        if (InEvent->CloseWindow == ContextWindow.get())
        {
            bRunning = false;
        }
    }
}
