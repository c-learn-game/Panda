
#ifndef PANDA_PATH_H
#define PANDA_PATH_H

#include "Basic/Basic.h"

namespace Panda
{
    class FPath
    {
    public:

        static FString GetApplicationPath();

        static void InitApplicationPaths();

        static FString ToLocalPath(const FString& Path);

    public:
        static FString EnginContentPath;
        static FString EngineShaderPath;
    };
}

#endif //PANDA_PATH_H
