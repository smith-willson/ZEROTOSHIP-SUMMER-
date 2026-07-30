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
    // Constructors
    Component();
    Component(int id, const std::string& name,
              const std::string& category,
              const std::string& status = "Available");

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getCategory() const;
    std::string getStatus() const;

    // Setters
    void setName(const std::string& name);
    void setCategory(const std::string& category);
    void setStatus(const std::string& status);
};

#endif