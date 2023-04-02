//
// Created by chendebi on 2023/4/2.
//

#ifndef PANDA_RHIVERTEXBUFFER_H
#define PANDA_RHIVERTEXBUFFER_H

#include "Base/Base.h"

namespace Panda
{
    class FRHIVertexBuffer
    {
    public:
        explicit FRHIVertexBuffer();

        explicit FRHIVertexBuffer(float *Buffer);
    };
}



#endif //PANDA_RHIVERTEXBUFFER_H
