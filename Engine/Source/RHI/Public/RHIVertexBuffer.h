//
// Created by chendebi on 2023/4/2.
//

#ifndef PANDA_RHIVERTEXBUFFER_H
#define PANDA_RHIVERTEXBUFFER_H

#include "RHIObject.h"

namespace Panda
{
	struct FRHIVertexBufferLayout
	{
		int Type = 0;
		uint8 Normalized = false;
	};

    class FRHIVertexBuffer : public FRHIObject
    {
    public:
        explicit FRHIVertexBuffer() = default;

        explicit FRHIVertexBuffer(float *Buffer, int BufferSize);

        ~FRHIVertexBuffer() override;

		template<typename T>
		void AddLayout(int Count);

		template<>
		void AddLayout<float>( int Count);

		CArray<FVertexBufferLayout> GetLayouts() const {
		    return BufferLayouts;
		}

	private:
		uint BufferID = 0;
		CArray<FVertexBufferLayout> BufferLayouts;
    };

	template<typename T>
	inline void FRHIVertexBuffer::AddLayout(int Count)
	{
		//static_assert(false);
        check(false)
	}

    template<>
	inline void FRHIVertexBuffer::AddLayout<float>( int Count)
	{
		BufferLayouts.Add({PLATFORM_VAR_FLOAT, false, Count, 4 * sizeof (float )});
	}
}



#endif //PANDA_RHIVERTEXBUFFER_H
