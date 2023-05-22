
#ifndef PANDA_TICKABLEOBJECT_H
#define PANDA_TICKABLEOBJECT_H

#include "Basic/Basic.h"

namespace Panda
{
    class UTickableObject
    {
    public:
        virtual ~UTickableObject() = default;

    protected:
        virtual void Tick(double Duration) { PANDA_UNUSED(Duration) }
    };
}


#endif //PANDA_TICKABLEOBJECT_H
