
#ifndef PANDA_VECTOR3_H
#define PANDA_VECTOR3_H

#include "Basic/Basic.h"
#include "spdlog/fmt/fmt.h"

namespace Panda
{
    struct FVector3
    {
        union
        {
            struct
            {
                float X, Y, Z;
            };

            float Data[3];
        };

        FVector3() : X(0), Y(0), Z(0)
        {}

        FVector3(float x, float y=0, float z=0)
        : X(x), Y(y), Z(z)
        {}

        float Length() const
        {
            return pow(pow(X,2.0f)+ pow(Y,2.0f)+ pow(Z,2.0f), 0.5f);
        }

        FString ToString() const
        {
            return FString(fmt::format("Vector3({}, {}, {})", X, Y, Z));
        }

        FVector3 operator*(const FVector3& Vector) const
        {
            return {X*Vector.X, Y*Vector.Y, Z*Vector.Z};
        }
    };
}

#endif //PANDA_VECTOR3_H
