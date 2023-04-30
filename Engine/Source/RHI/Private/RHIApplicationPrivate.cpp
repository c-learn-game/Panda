//
// Created by chendebi on 2023/4/30.
//

#include "RHIApplicationPrivate.h"
#include "RHIApplicationPrivateGLFW.h"

namespace Panda
{
    RHIApplicationPrivate* RHIApplicationPrivate::Get()
    {
        static RHIApplicationPrivateGLFW AppP;
        return &AppP;
    }
}