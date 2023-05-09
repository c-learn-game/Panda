
#ifndef PANDA_FILEINFO_H
#define PANDA_FILEINFO_H

#include "Basic/Basic.h"

namespace Panda
{
    class FFileInfo
    {
    public:
        explicit FFileInfo(const FString& InFilePath);

        bool IsDir() const;

        //bool IsFile() const;

        static bool Exist(const FString& FilePath);

        class FDirectory Dir();

    private:
        FString FilePath;
    };
}

#endif //PANDA_FILEINFO_H
