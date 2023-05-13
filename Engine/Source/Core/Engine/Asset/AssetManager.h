
#ifndef PANDA_ASSETMANAGER_H
#define PANDA_ASSETMANAGER_H

#include "Core/Instance.h"

namespace Panda
{
    class UAssetManager : public UInstance<UAssetManager>
    {
        INSTANCE_CLASS(UAssetManager)

    public:
        FString LoadFileText(const FString& FilePath);

    };
}


#endif //PANDA_ASSETMANAGER_H
