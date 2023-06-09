
#ifndef PANDA_STRING_H
#define PANDA_STRING_H

#include <string>
#include "Containers.h"

namespace Panda
{
    class FString
    {
    public:
        FString()  =default;

        FString(const char* InString);

        FString(const std::string& InString);

        FString(const FString& InString);

        ~FString() = default;

        FString& Replace(const FString& OldString, const FString& NewString);

        FString Replace(const FString& OldString, const FString& NewString) const;

        FString& Append(const FString& InString);

        bool IsEmpty() const;

        std::string ToStdString() const { return String; }

        size_t Count() const { return String.size(); }

        TArray<FString> Split(const FString& Delimiters = "") const;


        // operators
        FString& operator=(const char * InString);

        bool operator==(const FString& InString) const;

        bool operator!=(const FString& InString) const;

        char operator[](int Index) const;

        char &operator[](int Index);

    private:
        std::string String;
    };
}

namespace std
{
    template<>
    struct hash<Panda::FString>
    {
    public:
        ::size_t operator()(const Panda::FString& String) const
        {
            return hash<std::string>()(String.ToStdString());
        }
    };
}

#endif //PANDA_STRING_H
