#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <map>

class Component {
public:
    int id;
    std::string name;
    std::string owner;
    std::string status;

    Component(int id,
               const std::string& name,
               const std::string& owner,
               const std::string& status = "Available");

    std::map<std::string, std::string> to_dict() const;

    static Component from_dict(const std::map<std::string, std::string>& data);

    void print() const;
};

#endif // COMPONENT_H