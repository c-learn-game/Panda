//
// Created by chendebi on 2023/5/4.
//

#ifndef PANDA_VECTOR4_H
#define PANDA_VECTOR4_H

#include "spdlog/fmt/fmt.h"

namespace Panda
{
	struct FVector4
	{
		union
		{
			struct {
				float X;
				float Y;
				float Z;
				float W;
			};
			float Data[4];
		};

		FVector4()
		{
			memset(Data, 0, sizeof(Data));
		}

		FVector4(float x, float y=0.0f, float z=0.0f, float w=0.0f)
			: X(std::move(x))
			, Y(std::move(y))
			, Z(std::move(z))
			, W(std::move(w))
		{}

        float &operator[](int Index)
        {
            return Data[Index];
        }

		FString ToString()
		{
			return FString(fmt::format("Vector4({}, {}, {}, {})", X, Y, Z, W));
		}
	};
}

#endif