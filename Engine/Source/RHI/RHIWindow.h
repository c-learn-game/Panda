//
// Created by chendebi on 2023/4/30.
//

#ifndef PANDA_RHIWINDOW_H
#define PANDA_RHIWINDOW_H

#include "Basic/Basic.h"

namespace Panda
{

    class RHIWindow
    {
    public:
        explicit RHIWindow(const FString &DefaultWindowTitle = "Panda");

        virtual ~RHIWindow();

        void SetWindowTitle(const FString& NewTitle);

        FString GetWindowTitle() const { return WindowTitle; }

        void SetWindowSize(const int& Width, const int& Height);

        FSize GetWindowSize() const { return WindowSize; }

        void Show();

        void Hide();

    private:
        friend class RenderContextGLFW;
        FString WindowTitle;

        FSize WindowSize;

        SharedPtr<class RHIWindowPrivate> P = nullptr;
    };
}

#endif //PANDA_RHIWINDOW_H
