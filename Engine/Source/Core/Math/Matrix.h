
#ifndef PANDA_MATRIX4X4_H
#define PANDA_MATRIX4X4_H

#include "Vector3.h"
#include "Vector4.h"

namespace Panda
{
    struct FMatrix
    {
        float M[16]{0};

        explicit FMatrix(float v = 0.0f);

        explicit FMatrix(float *NewM);

        FMatrix(const std::initializer_list<float>& InitValues);

        const float* ValuePtr() const { return &M[0]; }

        static FMatrix Translate(const FMatrix& Mat, const FVector3 &Offset)
        {
            FMatrix NewMat = Mat;
            NewMat.M[12] = Offset.X;
            NewMat.M[13] = Offset.Y;
            NewMat.M[14] = Offset.Z;
            return NewMat;
        }

        static FMatrix Scale(const FMatrix& Mat, const FVector3 &InScale)
        {
            FMatrix NewMat = Mat;
            NewMat.M[0] *= InScale.X;
            NewMat.M[5] *= InScale.Y;
            NewMat.M[10] *= InScale.Z;
            return NewMat;
        }

        static FMatrix Rotate(const FMatrix& Mat, const FVector3& Axis, float Angle)
        {
            return FMatrix();
        }
    };

    inline FMatrix::FMatrix(float v)
    {
        memset(M, 0, 16 * sizeof (float));
        for (int i = 0; i < 4; i++)
        {
            M[i+i*4] = v;
        }
    }

    inline FMatrix::FMatrix(float *NewM)
    {
        std::memcpy(&M[0], NewM, sizeof (M));
    }

    inline FMatrix::FMatrix(const std::initializer_list<float> &InitValues)
    {
        int i = 0;
        for(auto it = InitValues.begin(); i < 16 && it!=InitValues.end(); ++it)
        {
            M[i++] = *it;
        }
    }
}

#endif //PANDA_MATRIX4X4_H
