//
// Created by chendebi on 2023/5/04.
// ���г���λ�Ƶ����
//

#ifndef PANDA_SCENECOMPONENT_H
#define PANDA_SCENECOMPONENT_H

#include "Basic/Basic.h"

namespace Panda
{
	class FSceneProxy
	{
	public:
		explicit FSceneProxy(USceneComponent* InComponent)
		{}

		virtual ~FSceneProxy() = default;
	};
}

#endif