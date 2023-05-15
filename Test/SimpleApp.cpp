#include "Application.h"
#include "Core/Math/Vector4.h"
#include "Basic/Basic.h"
#include "Core/Engine/Asset/Archive.h"
#include "Core/Engine/Private/EngineMacros.h"

using namespace Panda;

Panda::SharedPtr<Panda::Application> GetApplication(const Panda::TArray<Panda::FString>& Arguments)
{
    auto app = Panda::MakeShared<Panda::Application>(Arguments);
    return app;
}