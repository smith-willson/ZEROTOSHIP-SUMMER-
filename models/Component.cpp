#include "Component.h"
#include <iostream>

Component::Component(int id, const std::string& name, const std::string& owner, const std::string& status)
    : id(id), name(name), owner(owner), status(status) {}

std::map<std::string, std::string> Component::to_dict() const {
    std::map<std::string, std::string> data;
    data["id"] = std::to_string(id);
    data["name"] = name;
    data["owner"] = owner;
    data["status"] = status;
    return data;
}

Component Component::from_dict(const std::map<std::string, std::string>& data) {
    int id = std::stoi(data.at("id"));
    std::string name = data.at("name");
    std::string owner = data.at("owner");
    std::string status = data.at("status");
    return Component(id, name, owner, status);
}

void Component::print() const {
    std::cout << "Component { id: " << id
               << ", name: " << name
               << ", owner: " << owner
               << ", status: " << status
               << " }" << std::endl;
}