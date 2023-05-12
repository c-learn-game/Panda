
#include "Path.h"
#include "FileInfo.h"
#include "Directory.h"

namespace Panda
{
    FString Path::EnginContentPath;
    FString Path::EngineShaderPath;

    FString Path::GetApplicationPath()
    {
        return "";
    }

    void Path::InitApplicationPaths()
    {
#ifdef PANDA_RELEASE
        static_asset(false)
#else
        FDirectory Directory = FFileInfo(__FILE__).Dir();
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

    FString Path::ToLocalPath(const FString &PathString)
    {
#ifdef PANDA_PLATFORM_WIN
        return PathString.Replace("/", "\\");
#endif
    }
}