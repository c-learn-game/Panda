#include "Application.h"
#include "Core/Math/Vector4.h"

Panda::SharedPtr<Panda::Application> GetApplication(const Panda::TArray<Panda::FString>& Arguments)
{
    auto app = Panda::MakeShared<Panda::Application>(Arguments);
	Panda::FVector4 x(1,3,5,7);
	LogInfo("vector4 size: {}",sizeof(x))
    return app;
}