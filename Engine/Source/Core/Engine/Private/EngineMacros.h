
#ifndef PANDA_ENGINEMACROS_H
#define PANDA_ENGINEMACROS_H

#include "Basic/Basic.h"
#include "Core/Platform/Path.h"

inline Panda::FString GetEngineContentResourcePath(const Panda::FString& ResourcePath)
{
    Panda::FString EngineContentPath = Panda::FPath::EnginContentPath;
    return EngineContentPath.Append(ResourcePath);
}

inline Panda::FString GetEngineShaderPath(const Panda::FString& ShaderPath)
{
    Panda::FString EngineShaderPath = Panda::FPath::EngineShaderPath;
    return EngineShaderPath.Append(ShaderPath);
}

#define ENGINE_RESOURCE(ResourcePath) GetEngineContentResourcePath(ResourcePath)

#define ENGINE_SHADER(ShaderPath) GetEngineShaderPath(ShaderPath)

#endif //PANDA_ENGINEMACROS_H
