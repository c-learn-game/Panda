//
// Created by chendebi on 2023/4/5.
//

#include "RHI/Public/RHIVertexArray.h"
#include "RHI/Public/RHIVertexBuffer.h"
#include "RHI/Public/PlatformRHI.h"

namespace Panda
{
    FRHIVertexArray::FRHIVertexArray(const SharedPtr<class FRHIVertexBuffer>& InBuffer)
            : Buffer(InBuffer)
    {
        VAOId = RHICommand->CreateVertexArrayObject( Buffer->StrideSize, Buffer->GetLayouts());
    }

    void FRHIVertexArray::DrawArray() {
        RHICommand->DrawArray(VAOId, 3);
    }
}
