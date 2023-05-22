
#ifndef PANDA_SCENEVIEW_H
#define PANDA_SCENEVIEW_H

#include "Basic/Basic.h"

namespace Panda
{
    class FSceneView
    {
    public:
        explicit FSceneView(class UWorld* InWorld);

    private:
        UWorld* World = nullptr;
        FIntRect ViewportRect;
    };
}


#endif //PANDA_SCENEVIEW_H
