//
// Created by chendebi on 2023/4/5.
//

#include "RHI/Public/RHIVertexArray.h"
#include "RHI/Public/RHIVertexBuffer.h"
#include "RHI/Public/PlatformRHI.h"

namespace Panda
{
    FRHIVertexArray::FRHIVertexArray(const SharedPtr<class FRHIVertexBuffer>& InBuffer)
    {
        VAOId = RHICommand->CreateVertexArrayObject(InBuffer->GetId(), InBuffer->StrideSize, InBuffer->GetLayouts());
		VertexCount = InBuffer->GetVertexCount();
	}

    void FRHIVertexArray::DrawArray()
    {
        RHICommand->DrawArray(VAOId, VertexCount);
    }

	void FRHIVertexArray::DrawIndexed()
	{

	}
}
