#include "Application.h"
#include "Core/Math/Vector4.h"
#include "Core/Path/Path.h"

Panda::SharedPtr<Panda::Application> GetApplication(const Panda::TArray<Panda::FString>& Arguments)
{
    auto app = Panda::MakeShared<Panda::Application>(Arguments);
    return app;
}