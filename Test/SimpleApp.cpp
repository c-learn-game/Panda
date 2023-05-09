#include "Application.h"
#include "Core/Math/Vector4.h"
#include "Core/Path/Path.h"
#include <filesystem>

Panda::SharedPtr<Panda::Application> GetApplication(const Panda::TArray<Panda::FString>& Arguments)
{
    auto app = Panda::MakeShared<Panda::Application>(Arguments);

    LogInfo("Engine Shader Path: {}", Panda::Path::EngineShaderPath)

    return app;
}