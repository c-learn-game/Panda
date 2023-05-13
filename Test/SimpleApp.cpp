#include "Application.h"
#include "Core/Math/Vector4.h"
#include "Basic/Basic.h"
#include "Core/Engine/Asset/Archive.h"
#include "Core/Engine/Private/EngineMacros.h"

using namespace Panda;

Panda::SharedPtr<Panda::Application> GetApplication(const Panda::TArray<Panda::FString>& Arguments)
{
    auto app = Panda::MakeShared<Panda::Application>(Arguments);

    FFile f(ENGINE_RESOURCE("/test.asset"));
    LogInfo("write number 45 to asset")
    f.Open(FFile::Append);
    FArchive  archive(&f);
    archive << 144514;
    f.Close();
    f.Open(FFile::ReadOnly);
    FArchive ar(&f);
    int Var;
    ar >> Var;
    LogInfo("read number is: {}", Var)
    return app;
}