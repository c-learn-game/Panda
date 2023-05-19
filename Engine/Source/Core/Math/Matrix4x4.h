
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

        void Translate(const FVector3& Offset);

        void Scale(const FVector3& InScale);

        void Rotate(float Radius, const FVector3& Axis);

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

    inline void FMatrix4x4::Translate(const FVector3 &Offset)
    {
        Data[12] = Offset.X;
        Data[13] = Offset.Y;
        Data[14] = Offset.Z;
    }

    inline void FMatrix4x4::Scale(const FVector3 &InScale)
    {
        Data[0] *= InScale.X;
        Data[5] *= InScale.Y;
        Data[10] *= InScale.Z;
    }

    inline void FMatrix4x4::Rotate(float Radius, const FVector3& Axis)
    {

    }
}

#endif //PANDA_MATRIX4X4_H
