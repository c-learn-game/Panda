//
// Created by chendebi on 2023/4/30.
//

#include "RHI/RHIWindow.h"
#include "RHI/Private/RHIWindowPrivate.h"

namespace Panda
{
    RHIWindow::RHIWindow(const FString &DefaultWindowTitle)
    : WindowTitle(DefaultWindowTitle)
    {
        P = RHIWindowPrivate::Get(this);
        P->CreateWindow(DefaultWindowTitle);
    }

    RHIWindow::~RHIWindow()
    {
        P->Destroy();
    }

    void RHIWindow::SetWindowTitle(const FString &NewTitle)
    {
        if (P->SetWindowTitle(NewTitle))
        {
            WindowTitle = NewTitle;
        }
    }

    void RHIWindow::SetWindowSize(const int &Width, const int &Height)
    {
        if (P->SetWindowSize(Width, Height))
        {
            WindowSize = { Width, Height };
        }
    }

    void RHIWindow::Show()
    { P->ShowWindow(true); }

    void RHIWindow::Hide()
    { P->ShowWindow(false); }
}