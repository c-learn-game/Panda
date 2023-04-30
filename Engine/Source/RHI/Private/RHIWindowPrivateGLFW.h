//
// Created by chendebi on 2023/4/30.
//

#ifndef PANDA_RHIWINDOWPRIVATEGLFW_H
#define PANDA_RHIWINDOWPRIVATEGLFW_H

#include "RHIWindowPrivate.h"

struct GLFWwindow;

namespace Panda
{
    class RHIWindowPrivateGLFW : public RHIWindowPrivate
    {
    public:
        explicit RHIWindowPrivateGLFW(RHIWindow* ParentWindow);

        ~RHIWindowPrivateGLFW() override;

        bool CreateWindow(const FString& WindowTitle) override;

        void Destroy() override;

        bool SetWindowTitle(const FString& NewTitle) override;

        bool SetWindowSize(int Width, int Height) override;

        void ShowWindow(bool bShow) override;

    private:
        RHIWindow* Window = nullptr;
        GLFWwindow* WindowP = nullptr;
    };

}

#endif //PANDA_RHIWINDOWPRIVATEGLFW_H
