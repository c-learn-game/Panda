
#include "Path.h"
#include "FileInfo.h"
#include "Directory.h"

namespace Panda
{
    FString Path::ResourcePath;
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
#endif
    }
}