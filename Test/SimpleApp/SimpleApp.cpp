#include "Basic/Basic.h"
#include "Basic/Logging/Logging.h"
class Person
{
public:
    explicit Person(const std::string& name)
    {
        Name = name;
    }

public:
    std::string Name;
};

using namespace Panda;

int main()
{
    FLoggerSubsystem::Init(FLoggerSubsystem::Debug);
    FLoggerSubsystem::GetCoreLogger()->info("this is a info log");
}