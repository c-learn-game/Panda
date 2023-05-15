
#ifndef PANDA_ASSETOBJECT_H
#define PANDA_ASSETOBJECT_H

#include "Archive.h"

namespace Panda
{

    class UAssetObject
    {
    protected:
        friend class UPackage;

        template<typename T>
        friend T* LoadObject(const FString& AssetPath);

        virtual void Serialize( FArchive& Archive) { PANDA_UNUSED(Archive) }

        virtual void Deserialize( FArchive& Archive) { PANDA_UNUSED(Archive) }

    public:
        virtual ~UAssetObject() = default;

    public:
        FString AssetPath;
    };
}


#endif //PANDA_ASSETOBJECT_H
