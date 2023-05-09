
#ifndef PANDA_PATH_H
#define PANDA_PATH_H

#include "Basic/Basic.h"

namespace Panda
{
    class Path
    {
    public:

        static FString GetApplicationPath();

        static void InitApplicationPaths();

    public:
        static FString ResourcePath;
        static FString EngineShaderPath;
    };
}

#endif //PANDA_PATH_H
