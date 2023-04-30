//
// Created by chendebi on 2023/4/30.
//

#include "RHIWindowPrivate.h"
#include "RHIWindowPrivateGLFW.h"

namespace Panda
{
    SharedPtr<RHIWindowPrivate> RHIWindowPrivate::Get(RHIWindow* ParentWindow)
    {
        return MakeShared<RHIWindowPrivateGLFW>(ParentWindow);
    }
}