#include "RegistryCore.h"


bool RegistryCore::borrowComponent(Component& component)
{
    if (component.getStatus() != "Available")
    {
        return false;
    }

    component.setStatus("Borrowed");
    return true;
}


bool RegistryCore::returnComponent(Component& component)
{
    if (component.getStatus() != "Borrowed")
    {
        return false;
    }

    component.setStatus("Available");
    return true;
}


bool RegistryCore::changeStatus(Component& component, const std::string& newStatus)
{
    std::string currentStatus = component.getStatus();

    
    if (currentStatus == "Available" && newStatus == "Borrowed")
    {
        component.setStatus(newStatus);
        return true;
    }

    
    if (currentStatus == "Borrowed" && newStatus == "Available")
    {
        component.setStatus(newStatus);
        return true;
    }

    
    return false;
}