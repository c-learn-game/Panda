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
        explicit FRHIVertexBuffer(float *Buffer, int BufferSize);

        ~FRHIVertexBuffer() override;

		uint GetId() const { return BufferID; }

		template<typename T>
		void AddLayout(int Count, bool bNormalized=false);

		template<>
		void AddLayout<float>( int Count, bool bNormalized);

		CArray<FVertexBufferLayout> GetLayouts() const {
		    return BufferLayouts;
		}

	private:
		friend class FRHIVertexArray;
		CArray<FVertexBufferLayout> BufferLayouts;
		uint BufferID = 0;
		int StrideSize = 0;
    };

	template<typename T>
	inline void FRHIVertexBuffer::AddLayout(int Count, bool bNormalized)
	{
		//static_assert(false);
        check(false)
	}

    template<>
	inline void FRHIVertexBuffer::AddLayout<float>( int Count, bool bNormalized)
	{
		BufferLayouts.Add({PLATFORM_VAR_FLOAT, bNormalized, Count, StrideSize});
		StrideSize += Count * sizeof (float);
	}
}



#endif //PANDA_RHIVERTEXBUFFER_H
