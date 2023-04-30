//
// Created by chendebi on 2023/4/30.
//

#ifndef PANDA_RHIAPPLICATIONPRIVATE_H
#define PANDA_RHIAPPLICATIONPRIVATE_H

#include "Basic/Basic.h"

namespace Panda
{

    class RHIApplicationPrivate
    {
    public:
        explicit RHIApplicationPrivate() = default;

        virtual  ~RHIApplicationPrivate() = default;

        virtual bool Initialize() = 0;

        virtual void DestroyApplication() = 0;

        virtual void PollEvents() = 0;

        static RHIApplicationPrivate* Get();
    };

}

#endif //PANDA_RHIAPPLICATIONPRIVATE_H
