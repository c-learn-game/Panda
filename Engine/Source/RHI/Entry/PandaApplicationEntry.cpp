//
// Created by chendebi on 2023/5/1.
//

#include "RHI/Application.h"

using namespace Panda;
int main(int argc, char **argv)
{
    FLoggerSubsystem::Init(FLoggerSubsystem::Debug);
    auto app = RegisterApplication(argc, argv);
    return app->Exec();
}