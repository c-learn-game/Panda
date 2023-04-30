//
// Created by chendebi on 2023/4/30.
//

#ifndef PANDA_APPLICATION_H
#define PANDA_APPLICATION_H

#include "RHI/RHIWindow.h"

int main(int argc, char** argv);

namespace Panda
{
    class Application
    {
    public:
        explicit Application(const TArray<FString>& InArguments);

        virtual ~Application();

        bool Initialize();

        // 关闭程序
        void Quit();

        int Exec();

        SharedPtr<class RHIWindow> ContextWindow() const { return MainWindow; }

        static Application* Get();

    protected:
        friend int ::main(int, char**);
        virtual void PreInitApplication() {}
        virtual void PostInitApplication() {}

    public:
        static FString AppName;

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

extern Panda::SharedPtr<Panda::Application> GetApplication(const Panda::TArray<Panda::FString>& Arguments);

#endif //PANDA_APPLICATION_H
