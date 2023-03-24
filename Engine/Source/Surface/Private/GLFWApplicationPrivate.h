#ifndef GLFWAPPLICATIONPRIVATE_H
#define GLFWAPPLICATIONPRIVATE_H

#include "ApplicationPrivate.h"

namespace Panda
{
    class CGLFWApplicationPrivate : public  CApplicationPrivate
    {
    public:
        explicit CGLFWApplicationPrivate();

        void PollEvents() override;
    };
}

#endif