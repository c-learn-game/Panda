
#ifndef PANDA_MATHCORE_H
#define PANDA_MATHCORE_H

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

namespace Panda
{
    struct FMath
    {
        static FMatrix4x4 Translate(const FMatrix4x4& Mat, const FVector3 &Offset)
        {
            FMatrix4x4 NewMat = Mat;
            NewMat.Data[12] = Offset.X;
            NewMat.Data[13] = Offset.Y;
            NewMat.Data[14] = Offset.Z;
            return NewMat;
        }

        static FMatrix4x4 Scale(const FMatrix4x4& Mat, const FVector3 &InScale)
        {
            FMatrix4x4 NewMat = Mat;
            NewMat.Data[0] *= InScale.X;
            NewMat.Data[5] *= InScale.Y;
            NewMat.Data[10] *= InScale.Z;
            return NewMat;
        }

        static double Sin(const double& Value)
        {
            return std::sin(Value);
        }
    };
}

#endif //PANDA_MATHCORE_H
