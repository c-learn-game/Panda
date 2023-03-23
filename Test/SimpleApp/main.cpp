#include "Core/Public/Types/Array.h"
#include <iostream>

int main(void)
{
    Panda::CArray<int> Counts;
    Counts.Add(7);
    std::cout << Counts[0];
}