//
// Created by chendebi on 2023/4/5.
//

#ifndef PANDA_RHIOBJECT_H
#define PANDA_RHIOBJECT_H

#include "Base/Base.h"

namespace Panda
{
    // 应该确保在释放的时候调用Release对gpu资源进行释放
    class FRHIObject
    {
        virtual ~FRHIObject() = default;
    };
}

#endif //PANDA_RHIOBJECT_H
