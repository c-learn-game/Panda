//
// Created by chendebi on 2023/4/13.
//

#ifndef PANDA_RHIINDEXBUFFER_H
#define PANDA_RHIINDEXBUFFER_H

#include "RHIBase.h"

namespace Panda
{
    class FRHIIndexBuffer
    {
    public:
        explicit FRHIIndexBuffer(uint* InBufferData, int InBufferSize);

        void Bind();

        int GetBufferSize() const
        {
            return BufferSize;
        }

    private:
        uint BufferId;
        int BufferSize;
    };
}


#endif //PANDA_RHIINDEXBUFFER_H
