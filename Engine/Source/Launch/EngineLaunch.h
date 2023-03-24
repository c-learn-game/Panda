#ifndef ENGINELAUNCH_H
#define ENGINELAUNCH_H

#include "Surface/Public/Application.h"

int main(int Argc, char** Argv)
{
    LogInfo(LogSystem, "Start Panda Application")
    Panda::CApplication* App = Panda::PandaCreateApplication({Argc, Argv});
    LogInfo(LogSystem, "Application: %s, Version: %s", App->GetApplicationName().c_str(), App->GetApplicationVersion().c_str())

    App->PreInit();
    
    const int Code = App->Exec();

    if (Code == 0) LogInfo(LogSystem, "Application quit with code: %d", App->QuitCode)
    else LogError(LogSystem, "Application quit with code: %d", App->QuitCode)
}

#endif