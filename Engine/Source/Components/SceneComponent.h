//
// Created by chendebi on 2023/5/04.
// ���г���λ�Ƶ����
//

#ifndef PANDA_SCENECOMPONENT_H
#define PANDA_SCENECOMPONENT_H

#include "ActorComponent.h"

namespace Panda
{
	class USceneComponent : public UActorComponent
	{
	public:
		explicit USceneComponent(const SharedPtr<UActorComponent>& Parent = nullptr)
		: UActorComponent(Parent){}

		virtual ~USceneComponent() = default;

		virtual class FSceneProxy* CreateProxy() { return nullptr; }
	};
}

#endif