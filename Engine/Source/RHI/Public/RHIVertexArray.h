//
// Created by chendebi on 2023/4/5.
//

#ifndef PANDA_RHIVERTEXARRAY_H
#define PANDA_RHIVERTEXARRAY_H

#include "Base/Base.h"

namespace Panda
{
    class FRHIVertexArray {

    public:
        explicit FRHIVertexArray() = delete;

        explicit FRHIVertexArray(const SharedPtr<class FRHIVertexBuffer>& Buffer);


    private:
        uint VAOId = 0;

    };
}


#endif //PANDA_RHIVERTEXARRAY_H
