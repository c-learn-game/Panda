//
// Created by chendebi on 2023/4/30.
//

#ifndef PANDA_RHIWINDOWPRIVATE_H
#define PANDA_RHIWINDOWPRIVATE_H

#include "Basic/Basic.h"

#define RHIWINDOW_DEFAULT_WIDTH 600
#define RHIWINDOW_DEFAULT_HEIGHT 400

namespace Panda
{
    class RHIWindowPrivate
    {
    public:
        explicit RHIWindowPrivate(class RHIWindow* ParentWindow) { PANDA_UNUSED(ParentWindow) }

        virtual ~RHIWindowPrivate() = default;

        // window通过调用此函数创建窗口
        virtual bool CreateWindow(const FString& WindowTitle) = 0;

        // windowp生命周期和window周期一致，在window销毁时会显示调用销毁的函数
        // windowp通过此函数或者在析构函数中销毁窗口
        virtual void Destroy() {}

        virtual bool SetWindowTitle(const FString& NewTitle) = 0;

        virtual bool SetWindowSize(int Width, int Height) = 0;

        virtual void ShowWindow(bool bShow) = 0;

        static SharedPtr<RHIWindowPrivate> Get(class RHIWindow* ParentWindow);
    };
}


#endif //PANDA_RHIWINDOWPRIVATE_H
