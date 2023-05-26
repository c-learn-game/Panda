
#ifndef PANDA_MATHCORE_H
#define PANDA_MATHCORE_H

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

namespace Panda
{
    struct FMath
    {
        static float Pow(float Base, float Exponent);

        static FVector3 Normalize(const FVector3& Vec)
        {
            return FVector3(1.0f / Vec.Length()) * Vec;
        }

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

        static FMatrix4x4 Rotate(const FMatrix4x4& Mat, const FVector3& Axis, float Angle)
        {
            auto NormalizedAxis = Normalize(Axis);
            float SinValue = sin(Angle);
            float CosValue = cos(Angle);
            float SinPair = 1 - SinValue;
            float CosPair = 1 - CosValue;

            FMatrix4x4 RotateMat = {
                    CosValue + (1-CosValue)* Pow(NormalizedAxis.X,2),

            };


        }

        static double Sin(const double& Value)
        {
            return std::sin(Value);
        }
    };

    float FMath::Pow(float Base, float Exponent)
    {
        return std::pow(Base, Exponent);
    }
}

#endif //PANDA_MATHCORE_H
