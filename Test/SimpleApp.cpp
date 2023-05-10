#include "Application.h"
#include "Core/Math/Vector4.h"
#include "Basic/Basic.h"
#include <filesystem>

Panda::SharedPtr<Panda::Application> GetApplication(const Panda::TArray<Panda::FString>& Arguments)
{
    auto app = Panda::MakeShared<Panda::Application>(Arguments);

    Panda::FString String("this is a old string");
    String.Replace("old", "new s");
    LogInfo("{}", String.ToStdString())

    return app;
}