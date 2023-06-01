#ifndef PANDA_MATH_H
#define PANDA_MATH_H


#include "Basic/Basic.h"
#include <cmath>

namespace Panda
{
    struct FMath
    {
    public:
        static double Pow(double Base, double Exp)
        {
            return std::pow(Base, Exp);
        }

        static double Sin(double Value)
        {
            return std::sin(Value);
        }
    };
}

#endif