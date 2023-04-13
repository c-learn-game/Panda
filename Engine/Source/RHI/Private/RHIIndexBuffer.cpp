//
// Created by chendebi on 2023/4/13.
//

#include "RHI/Public/RHIIndexBuffer.h"
#include "RHI/Public/PlatformRHI.h"

namespace Panda
{
    FRHIIndexBuffer::FRHIIndexBuffer(uint *InBufferData, int InBufferSize)
            : BufferSize(InBufferSize / sizeof (uint))
    {
        BufferId = RHICommand->CreateIndexBufferObject(InBufferData, InBufferSize);
    }

    void FRHIIndexBuffer::Bind()
    {
        RHICommand->UseIndexBufferObject(BufferId);
    }
}