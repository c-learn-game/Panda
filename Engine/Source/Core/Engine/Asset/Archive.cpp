
#include "Archive.h"

namespace Panda
{
    FArchive::FArchive(FFile *InAssetFile)
    : AssetFile(InAssetFile)
    {
    }

    void FArchive::Serialize(void *Data, longlong DataSize)
    {
        longlong Size = DataSize;
        longlong TypeSize = sizeof (longlong);
        AssetFile->Write(&Size, TypeSize);
        AssetFile->Write(Data, DataSize);
    }

    void *FArchive::Deserialize(longlong &Size)
    {
        Size = *((longlong *) (AssetFile->Read(sizeof(longlong))));
        return AssetFile->Read(Size);
    }
}