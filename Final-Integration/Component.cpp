#include "Component.h"
using json = nlohmann::json;

Component::Component()
{
    id = 0;
    name = "";
    category = "";
    status = "Available";
}

Component::Component(int id,
                     const std::string& name,
                     const std::string& category,
                     const std::string& status)
{
    this->id = id;
    this->name = name;
    this->category = category;
    this->status = status;
}


int Component::getId() const
{
    return id;
}

std::string Component::getName() const
{
    return name;
}

std::string Component::getCategory() const
{
    return category;
}

std::string Component::getStatus() const
{
    return status;
}


void Component::setName(const std::string& name)
{
    this->name = name;
}

void Component::setCategory(const std::string& category)
{
    this->category = category;
}

void Component::setStatus(const std::string& status)
{
    this->status = status;
}


json Component::toJson() const
{
    return {
        {"id", id},
        {"name", name},
        {"category", category},
        {"status", status}
    };
}


Component Component::fromJson(const json& j)
{
    return Component(
        j.at("id").get<int>(),
        j.at("name").get<std::string>(),
        j.at("category").get<std::string>(),
        j.at("status").get<std::string>()
    );
}