#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <map>
#include <iostream>

// Represents a single piece of lab equipment (Arduino, ESP32, sensor, etc.)
// Use only ASCII hyphens in comments to avoid encoding issues
class Component {
public:
    int id;
    std::string name;
    std::string owner;
    std::string status;

    // Inline implementations provided in header (header-only usage)
    Component(int id,
               const std::string& name,
               const std::string& owner,
               const std::string& status = "Available")
        : id(id), name(name), owner(owner), status(status) {}

    std::map<std::string, std::string> to_dict() const {
        std::map<std::string, std::string> result;
        result["id"] = std::to_string(id);
        result["name"] = name;
        result["owner"] = owner;
        result["status"] = status;
        return result;
    }

    static Component from_dict(const std::map<std::string, std::string>& data) {
        Component comp(
            std::stoi(data.at("id")),
            data.at("name"),
            data.at("owner"),
            data.at("status")
        );
        return comp;
    }

    void print() const {
        std::cout << "Component ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Owner: " << owner << "\n"
                  << "Status: " << status << "\n";
    }
};

#endif // COMPONENT_H