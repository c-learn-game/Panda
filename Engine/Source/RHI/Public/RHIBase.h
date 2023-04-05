//
// Created by chendebi on 2023/4/6.
//

#ifndef PANDA_RHIBASE_H
#define PANDA_RHIBASE_H

#include "Base/Base.h"

#define PLATFORM_VAR_FLOAT 0x1406 // GL_FLOAT

namespace Panda
{
    enum class EBufferUsage
    {
        BU_STATIC = 0x88E4,
    };

    struct FVertexBufferLayout
    {

        int VariableType;
        uint8 Normalized;
        int Count;
        int Offset;
    };
}

#endif //PANDA_RHIBASE_H
