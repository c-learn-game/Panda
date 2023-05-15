
#include "Archive.h"

namespace Panda
{
    FArchive::FArchive(FFile *InAssetFile)
    : AssetFile(InAssetFile)
    {
    }

    void FArchive::Serialize(void *Data, longlong DataSize)
    {
        LogInfo("size: {}", DataSize)
        AssetFile->Write(&DataSize, sizeof (longlong));
        AssetFile->Write(Data, DataSize);
    }

    void *FArchive::Deserialize(size_t &Size)
    {
        Size = (size_t)*(longlong *) (AssetFile->Read(sizeof(longlong)));
        return AssetFile->Read(Size);
    }
}