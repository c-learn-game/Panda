
#ifndef PANDA_FILE_H
#define PANDA_FILE_H

#include "Basic/Basic.h"

namespace Panda
{
    class FFile
    {
    public:
        enum EFileOpenState
        {
            ReadOnly,
            WriteOnly,
            ReadWrite
        };

    public:
        explicit FFile(const FString& FilePath);

        ~FFile();

        bool Open(EFileOpenState OpenState = EFileOpenState::ReadOnly);

        // 数据在FFile对象释放时释放
        char *GetData();

    private:
        TArray<char*> ReadedDatas;
    };
}

#endif //PANDA_FILE_H
