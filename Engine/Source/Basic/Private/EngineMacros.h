
#ifndef PANDA_ENGINEMACROS_H
#define PANDA_ENGINEMACROS_H

#include "Basic/Basic.h"
#include "Core/Path/Path.h"

inline Panda::FString GetEngineContentResourcePath(const Panda::FString& ResourcePath)
{
    Panda::FString EnginContentPath = Panda::Path::EnginContentPath;
    return EnginContentPath.Append(ResourcePath);
}

#define ENGINE_RESOURCE(ResourcePath) GetEngineContentResourcePath(ResourcePath)

#endif //PANDA_ENGINEMACROS_H
