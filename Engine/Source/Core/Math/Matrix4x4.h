
#ifndef PANDA_MATRIX4X4_H
#define PANDA_MATRIX4X4_H

#include "Vector3.h"
#include "Vector4.h"

namespace Panda
{
    struct FMatrix4x4
    {
        float Data[16]{0};

        explicit FMatrix4x4(float v = 0.0f);

        explicit FMatrix4x4(float *NewData);

        FMatrix4x4(const std::initializer_list<float>& InitValues);

        const float* ValuePtr() const { return &Data[0]; }
    };

    inline FMatrix4x4::FMatrix4x4(float v)
    {
        memset(Data, 0, 16 * sizeof (float));
        for (int i = 0; i < 4; i++)
        {
            Data[i+i*4] = v;
        }
    }

    inline FMatrix4x4::FMatrix4x4(float *NewData)
    {
        std::memcpy(&Data[0], NewData, sizeof (Data));
    }

    inline FMatrix4x4::FMatrix4x4(const std::initializer_list<float> &InitValues)
    {
        int i = 0;
        for(auto it = InitValues.begin(); i < 16 && it!=InitValues.end(); ++it)
        {
            Data[i++] = *it;
        }
    }
}

#endif //PANDA_MATRIX4X4_H
