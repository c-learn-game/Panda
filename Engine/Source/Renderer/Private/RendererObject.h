//
// Created by chendebi on 2023/5/1.
//

#ifndef TEST_RENDEREROBJECT_H
#define TEST_RENDEREROBJECT_H

#include "Basic/Basic.h"

namespace Panda
{
    class FRendererObject
    {
    public:
        virtual ~FRendererObject() = default;

        virtual bool IsValid() const = 0;

        virtual void Destroy() = 0;
    };
}

#endif //TEST_RENDEREROBJECT_H
