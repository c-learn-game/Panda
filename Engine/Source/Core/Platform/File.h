
#ifndef PANDA_FILE_H
#define PANDA_FILE_H

#include "Basic/Basic.h"
#include <fstream>

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

        void Close();

        char * ReadAll();

    private:
        void Release();

    private:
        std::fstream FileStream;
        std::ofstream WriteStream;
        FString FilePath;
        TArray<char*> ReadedDatas;
    };
}

#endif //PANDA_FILE_H
