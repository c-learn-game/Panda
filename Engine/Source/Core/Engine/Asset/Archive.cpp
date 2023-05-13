
#include "Archive.h"

namespace Panda
{
    FArchive::FArchive(FFile *InAssetFile)
    : AssetFile(InAssetFile)
    {
    }

    void FArchive::Serialize(int Type, void *Data, long DataSize)
    {
        AssetFile->Write(&Type, sizeof (int));
        AssetFile->Write(&DataSize, sizeof (long));
        AssetFile->Write(Data, DataSize);
    }
}