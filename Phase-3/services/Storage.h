#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <string>
#include "../Component.h"

class Storage
{
public:
    
    static bool saveToFile(const std::vector<Component>& components,
                           const std::string& filename);

    
    static bool loadFromFile(std::vector<Component>& components,
                             const std::string& filename);
};

#endif