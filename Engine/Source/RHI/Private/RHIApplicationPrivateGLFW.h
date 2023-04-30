//
// Created by chendebi on 2023/4/30.
//

#ifndef PANDA_RHIAPPLICATIONPRIVATEGLFW_H
#define PANDA_RHIAPPLICATIONPRIVATEGLFW_H

#include "RHIApplicationPrivate.h"

namespace Panda
{
    class RHIApplicationPrivateGLFW : public RHIApplicationPrivate
    {
    public:
        explicit RHIApplicationPrivateGLFW() = default;

        ~RHIApplicationPrivateGLFW() override = default;

        bool Initialize() override;

        void DestroyApplication() override;

        void PollEvents() override;
    };
}


#endif //PANDA_RHIAPPLICATIONPRIVATEGLFW_H
