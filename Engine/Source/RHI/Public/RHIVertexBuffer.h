//
// Created by chendebi on 2023/4/2.
//

#ifndef PANDA_RHIVERTEXBUFFER_H
#define PANDA_RHIVERTEXBUFFER_H

#include "Base/Base.h"

namespace Panda
{
	struct FRHIVertexBufferLayout
	{
		int Type = 0;
		uint8 Normalized = false;
	};

    class FRHIVertexBuffer
    {
    public:
        explicit FRHIVertexBuffer();

        explicit FRHIVertexBuffer(float *Buffer);

		template<typename T>
		void AddLayout(int Type, int Count);

		template<>
		void AddLayout<float>(int Type, int Count);

	private:
		uint BufferID = 0;
		CArray<FRHIVertexBufferLayout> BufferLayouts;
    };

	template<typename T>
	inline void FRHIVertexBuffer::AddLayout(int Type, int Count)
	{
		static_assert(false)
	}

	template<>
	inline void FRHIVertexBuffer::AddLayout<float>(int Type, int Count)
	{
		BufferLayouts.Add({ Type, false });
	}
}



#endif //PANDA_RHIVERTEXBUFFER_H
