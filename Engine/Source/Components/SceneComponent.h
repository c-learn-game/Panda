//
// Created by chendebi on 2023/5/04.
// ���г���λ�Ƶ����
//

#ifndef PANDA_SCENECOMPONENT_H
#define PANDA_SCENECOMPONENT_H

#include "ActorComponent.h"

namespace Panda
{
    class FSceneProxy
    {
    public:
        explicit FSceneProxy(class USceneComponent* InComponent);

        virtual ~FSceneProxy() = default;

        virtual void Draw() { check(false) }

    private:
        class USceneComponent* SceneComponent;
    };

    class USceneComponent : public UActorComponent
	{
	public:
		explicit USceneComponent(const SharedPtr<UActorComponent>& Parent = nullptr)
		: UActorComponent(Parent){}

		virtual ~USceneComponent() = default;

		virtual FSceneProxy* CreateProxy() { return new FSceneProxy(this); }
	};
}

#endif