#ifndef REGISTRYCORE_H
#define REGISTRYCORE_H

#include "../Component.h"

class RegistryCore
{
public:
    
    static bool borrowComponent(Component& component);

    
    static bool returnComponent(Component& component);

    
    static bool changeStatus(Component& component, const std::string& newStatus);
};

#endif