//
// Created by chendebi on 2023/5/04.
//

#ifndef PANDA_ACTORCOMPONENT_H
#define PANDA_ACTORCOMPONENT_H

#include "Basic/Basic.h"

namespace Panda
{
	class UActorComponent
	{
	public:
		explicit UActorComponent(const SharedPtr<UActorComponent>& Parent = nullptr)
		: ParentComponent(Parent){}

		virtual ~UActorComponent() = default;

	private:
		SharedPtr<UActorComponent> ParentComponent;
	};
}

#endif