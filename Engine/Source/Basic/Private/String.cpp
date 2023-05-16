
#include "Basic/String.h"

namespace Panda
{


    FString::FString(const char *const InString)
    {
        String = InString;
    }

    FString& FString::operator=(const char * const InString)
    {
        String = InString;
        return *this;
    }

    FString& FString::Replace(const FString &OldString, const FString &NewString)
    {
        size_t SubStringStartPos = String.find(OldString.ToStdString());
        while (SubStringStartPos != std::string::npos)
        {
            String.replace(SubStringStartPos, OldString.Count(), NewString.String);
            SubStringStartPos = String.find(OldString.ToStdString());
        }
        return *this;
    }

    FString& FString::Append(const FString &InString)
    {
        String += InString.String;
        return *this;
    }

    bool FString::IsEmpty() const
    {
        return String.empty();
    }

    char FString::operator[](int Index) const
    {
        return String[Index];
    }

    FString::FString(const std::string &InString)
    {
        String = InString;
    }

    FString::FString(const FString &InString)
    {
        String = InString.String;
    }

    bool FString::operator==(const FString &InString) const
    {
        return String == InString.String;
    }

    char &FString::operator[](int Index)
    {
        return String[Index];
    }

    FString FString::Replace(const FString &OldString, const FString &NewString) const
    {
        FString ReplacedString = *this;
        ReplacedString.Replace(OldString, NewString);
        return ReplacedString;
    }

    TArray<FString> FString::Split(const FString &Delimiters) const
    {
        TArray<FString> OutArray;
        size_t LastPos = String.find_first_not_of(Delimiters.String, 0);
        size_t Pos = String.find_first_of(Delimiters.String, LastPos);
        while (LastPos != std::string::npos || Pos != std::string::npos)
        {
            OutArray.emplace_back(String.substr(LastPos, Pos - LastPos));
            LastPos = String.find_first_not_of(Delimiters.String, Pos);
            Pos = String.find_first_of(Delimiters.String, LastPos);
        }
        return OutArray;
    }

    bool FString::operator!=(const FString &InString) const
    {
        return !(*this == InString);
    }
}