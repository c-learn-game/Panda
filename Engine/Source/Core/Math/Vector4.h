//
// Created by chendebi on 2023/5/4.
//

#ifndef TEST_RENDERER_H
#define TEST_RENDERER_H

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

		FVector4(float x, float y, float z, float w)
			: X(std::move(x))
			, Y(std::move(y))
			, Z(std::move(z))
			, W(std::move(w))
		{}

		FString ToString()
		{
			return fmt::format("(X={}, Y={}, Z={}, W={})", X, Y, Z, W);
		}
	};
}

#endif