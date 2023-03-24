#include "Surface/Public/Application.h"
#include "ApplicationPrivate.h"
#include "Surface/Public/Window.h"

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

    void CApplication::Quit()
    {
        
    }

    void CApplication::PreInit()
    {
        MainContextWindow = MakeSharedPtr<CWindow>(nullptr, ApplicationName);
    }

    int CApplication::Exec()
    {
        while (bRunning)
        {
            P->PollEvents();
        }
        return QuitCode;
    }
}
