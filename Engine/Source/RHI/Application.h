//
// Created by chendebi on 2023/4/30.
//

#ifndef PANDA_APPLICATION_H
#define PANDA_APPLICATION_H

#include "Basic/Basic.h"

namespace Panda
{
    class Application
    {
    public:
        explicit Application(int argc, char *argv[]);

        virtual ~Application();

        // 关闭程序
        void Quit();

        int Exec();

        SharedPtr<class RHIWindow> ContextWindow() const { return MainWindow; }

        static Application* Get();

    private:
        static Application* GApp;

        bool bShouldQuit = false;

        // p指针
        class RHIApplicationPrivate* P = nullptr;

        TArray<FString> Arguments;

        // context window
        SharedPtr<class RHIWindow> MainWindow = nullptr;
    };
}

extern Panda::SharedPtr<Panda::Application> RegisterApplication(int argc, char *argv[]);

#endif //PANDA_APPLICATION_H
