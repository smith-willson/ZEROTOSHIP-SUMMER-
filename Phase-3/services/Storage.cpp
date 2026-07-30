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
        data.push_back({
            {"id", component.getId()},
            {"name", component.getName()},
            {"category", component.getCategory()},
            {"status", component.getStatus()}
        });
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
        Component component(
            item["id"],
            item["name"],
            item["category"],
            item["status"]
        );

        components.push_back(component);
    }

    file.close();

    return true;
}