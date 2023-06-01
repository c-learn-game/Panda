#include "Application.h"
#include "Core/Math/Vector4.h"
#include "Basic/Basic.h"
#include "Core/Engine/Asset/Archive.h"
#include "Core/Engine/Private/EngineMacros.h"
#include "Core/Engine/Asset/AssetObject.h"
#include "Core/Engine/Asset/Package.h"

using namespace Panda;

class MyApp : public Application
{
public:
    explicit MyApp(const TArray<Panda::FString>& Arguments) : Application(Arguments)
    {}
};

Application* GetApplication(const Panda::TArray<Panda::FString>& Arguments)
{
    return new MyApp(Arguments);
}