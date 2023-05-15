
#include "Package.h"

namespace Panda
{
    bool UPackage::Save() const
    {
        if (Object)
        {
            FFileInfo Info(Object->AssetPath);
            if (!Info.IsDir())
            {
                FFile File(Object->AssetPath);
                if (File.Open(FFile::WriteOnly))
                {
                    FArchive Archive(&File);
                    Object->Serialize(Archive);
                    File.Close();
                    return true;
                }
            }
        }
        return false;
    }
}