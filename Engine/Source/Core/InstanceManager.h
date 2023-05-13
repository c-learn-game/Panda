
#ifndef PANDA_INSTANCEMANAGER_H
#define PANDA_INSTANCEMANAGER_H

#include "Instance.h"

int main(int argc, char** argv);

namespace Panda
{
    class UInstanceManager : public UInstance<UInstanceManager>
    {
        INSTANCE_CLASS(UInstanceManager)

    public:
        class UAssetManager* GetAssetManager();

    protected:
        friend int ::main(int,char**);
        void Initialize() override;
    };
}


#endif //PANDA_INSTANCEMANAGER_H
