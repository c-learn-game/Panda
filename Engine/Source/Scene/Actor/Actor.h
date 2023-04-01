//
//  Actor.h
//  Panda
//
//  Created by chendebi on 2023/4/1.
//

#ifndef Actor_h
#define Actor_h

#include "Base/Base.h"

namespace Panda
{
    class AActor
    {
    public:
        virtual ~AActor() = default;
        
        
    protected:
        virtual void Tick() {}
        
    private:
        
    }
}


#endif /* Actor_h */
