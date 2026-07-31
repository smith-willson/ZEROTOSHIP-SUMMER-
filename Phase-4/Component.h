#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component
{
private:
    int id;
    std::string name;
    std::string category;
    std::string status;

public:
    Component();

    Component(
        int id,
        const std::string& name,
        const std::string& category,
        const std::string& status = "Available"
    );

    int getId() const;
    std::string getName() const;
    std::string getCategory() const;
    std::string getStatus() const;

    void setStatus(const std::string& status);
};

#endif