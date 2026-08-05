#include "Storage.h"

#include <fstream>
#include "../include/json.hpp"

using json = nlohmann::json;

bool Storage::saveToFile(const std::vector<Component>& components,
                         const std::string& filename)
{
    json data = json::array();

    for (const auto& component : components)
    {
        data.push_back(component.toJson());
    }

    std::ofstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    file << data.dump(4);

    file.close();

    return true;
}

bool Storage::loadFromFile(std::vector<Component>& components,
                           const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    json data;

    try
    {
        file >> data;
    }
    catch (...)
    {
        return false;
    }

    components.clear();

    for (const auto& item : data)
    {
        components.push_back(Component::fromJson(item));
    }

    

    file.close();

    return true;
}