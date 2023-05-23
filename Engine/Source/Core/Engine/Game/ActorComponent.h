
#ifndef PANDA_ACTORCOMPONENT_H
#define PANDA_ACTORCOMPONENT_H

#include "Core/Engine/TickableObject.h"

namespace Panda
{
    class UActorComponent : public UTickableObject
    {
    public:
        UActorComponent();
        ~UActorComponent() = default;
    };
}


#endif //PANDA_ACTORCOMPONENT_H
