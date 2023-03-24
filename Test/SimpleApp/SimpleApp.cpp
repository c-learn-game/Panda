
#include "Launch/EngineLaunch.h"

class SimpleAppApplication : public Panda::CApplication
{
public:
    explicit SimpleAppApplication(const Panda::FApplicationArguments& Arguments)
        : CApplication(Arguments) {}
};

Panda::CApplication* Panda::PandaCreateApplication(const FApplicationArguments& InArguments)
{
    CApplication* MyApplication = new SimpleAppApplication(InArguments);
    MyApplication->SetApplicationName("Simple App");
    return MyApplication;
}
