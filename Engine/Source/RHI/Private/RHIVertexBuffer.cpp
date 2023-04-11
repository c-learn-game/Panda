//
// Created by chendebi on 2023/4/2.
//

#include "RHI/Public/PlatformRHI.h"
#include "RHI/Public/RHIVertexBuffer.h"

namespace Panda
{
	FRHIVertexBuffer::FRHIVertexBuffer(float * Buffer,  int InBufferSize)
		: BufferSize(InBufferSize)
	{
        BufferID = RHICommand->CreateVertexBufferObject(Buffer, BufferSize);
	}

    FRHIVertexBuffer::~FRHIVertexBuffer() {
	    //RHICommand
    }

    int FRHIVertexBuffer::GetVertexCount() const
    {
        return BufferSize / StrideSize;
    }
}

