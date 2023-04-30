#include "RHI/Application.h"

Panda::SharedPtr<Panda::Application> RegisterApplication(int argc, char *argv[])
{
    return Panda::MakeShared<Panda::Application>(argc, argv);
}