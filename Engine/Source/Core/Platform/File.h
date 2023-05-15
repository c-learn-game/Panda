
#ifndef PANDA_FILE_H
#define PANDA_FILE_H

#include "Basic/Basic.h"
#include <fstream>

namespace Panda
{
    class FFile
    {
    public:
        // 文件始终使用二进制打开方式
        enum EFileFlag
        {
            None,
            ReadOnly = FLAG(0),
            WriteOnly = FLAG(1),
            ReadWrite = FLAG(2),
            Append = FLAG(3)
        };

    public:
        explicit FFile(const FString& FilePath);

        ~FFile();

        bool Open(EFileFlag Flag = EFileFlag::ReadOnly);

        void Close();

        char* Read(long DataSize);

        char * ReadAll();

        EFileFlag GetFlag() const { return FileOpenFlag; }

        bool IsOpened() const { return FileStream.is_open(); }

        void Write(void *Data, longlong DataSize);

    private:
        void Release();

    private:
        std::fstream FileStream;
        FString FilePath;
        TArray<char*> ReadedDatas;
        EFileFlag FileOpenFlag = EFileFlag::None;
    };
}

#endif //PANDA_FILE_H
