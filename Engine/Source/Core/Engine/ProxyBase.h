
#ifndef PANDA_FPROXYBASE_H
#define PANDA_FPROXYBASE_H

#include "Basic/Basic.h"

namespace Panda
{
    class FProxyBase
    {
    public:
        virtual ~FProxyBase() = default;

        virtual void CreateResource() = 0;

        virtual void ReleaseResource() = 0;
    };
}

#endif //PANDA_FPROXYBASE_H
