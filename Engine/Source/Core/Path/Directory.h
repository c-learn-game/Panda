
#ifndef PANDA_DIRECTORY_H
#define PANDA_DIRECTORY_H

#include "Basic/Basic.h"

namespace Panda
{
    class FDirectory
    {
    public:
        explicit FDirectory(const FString &InDirPath = "");

        bool CdUp();

        FString GetDirectoryLocalPath();

        bool Cd(const FString& DirectoryName);

        FString GetFilePath(const FString& FileName, bool& Success);

        FString ParentPath() const;

       bool Exist() const;

    private:
        FString DirPath;
    };
}


#endif //PANDA_DIRECTORY_H
