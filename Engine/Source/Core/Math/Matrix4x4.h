
#ifndef PANDA_MATRIX4X4_H
#define PANDA_MATRIX4X4_H

#include "Vector3.h"
#include "Vector4.h"

namespace Panda
{
    struct FMatrix4x4
    {
        float Data[16];

        explicit FMatrix4x4(float v = 0.0f);

        const float* ValuePtr() const { return &Data[0]; }
    };

    inline FMatrix4x4::FMatrix4x4(float v)
    : Data()
    {
        memset(Data, 0, 16 * sizeof (float));
        for (int i = 0; i < 4; i++)
        {
            Data[i+i*4] = v;
        }
    }
}

#endif //PANDA_MATRIX4X4_H
