
#include "Core/Platform/Path.h"
#include "Core/Platform/FileInfo.h"
#include "Core/Platform/Directory.h"

namespace Panda
{
    FString FPath::EnginContentPath;
    FString FPath::EngineShaderPath;

    FString FPath::GetApplicationPath()
    {
        return "";
    }

    void FPath::InitApplicationPaths()
    {
#ifdef PANDA_RELEASE
        static_asset(false)
#else
        FDirectory Directory = FFileInfo(__FILE__).Dir();
        Directory.CdUp();
        Directory.CdUp();
        Directory.CdUp();
        Directory.CdUp();
        Directory.Cd("Shader");
        EngineShaderPath = Directory.GetDirectoryLocalPath();
        Directory.CdUp();
        Directory.Cd("Content");
        EnginContentPath = Directory.GetDirectoryLocalPath();
#endif
    }

    FString FPath::ToLocalPath(const FString &PathString)
    {
#ifdef PANDA_PLATFORM_WIN
        return PathString.Replace("/", "\\");
#else
        return PathString;
#endif
    }
}