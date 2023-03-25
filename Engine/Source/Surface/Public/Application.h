#ifndef APPLICATION_H
#define APPLICATION_H
#include "Base/Base.h"
#include "Event/Public/Event.h"

int main(int, char**);

namespace Panda
{
    class CWindow;

    struct FApplicationArguments
    {
        int Count;
        CArray<CString> Arguments;

        FApplicationArguments() : Count(0) {}

        FApplicationArguments(int InCount, char** InParams)
            : Count(InCount)
        {
            for (int Index = 0; Index < Count; ++Index)
            {
                Arguments.Add(std::move(InParams[Index]));
            }
        }
    };
    
    class CApplication
    {
    public:
        explicit CApplication(const FApplicationArguments& InArguments);

        virtual ~CApplication() = default;

        void SetApplicationName(const CString& InApplicationName);

        void SetApplicationVersion(const CString& InVersion);

        CString GetApplicationName() const { return ApplicationName; }

        CString GetApplicationVersion() const { return ApplicationVersion; }

        static CApplication* Get();
        
        void Quit();
        
        void AddEvent(CEvent*  InEvent);
        
    protected:
        void OnWindowCloseEvent(class CWindowCloseEvent *InEvent);
        
    private:
        void ExecuteAppEvents();

    private:
        friend int ::main(int, char**);
        void PreInit();
        
        int Exec();
        
    protected:
        // 程序名称
        CString ApplicationName;
        // 程序版本号
        CString ApplicationVersion;

    private:
        // 退出状态码
        int QuitCode;

        bool bRunning;

        static CApplication* AppInst;

        class CApplicationPrivate* P;

        SharedPtr<CWindow> ContextWindow;
        
        CList<CEvent*> AppEventList;
    };

    // 实现此函数
    CApplication* PandaCreateApplication(const FApplicationArguments& InArguments);
}

#endif
