#include <iostream>
#include <vector>

#include "Component.h"
#include "services/RegistryCore.h"
#include "services/Storage.h"

using namespace std;

void printComponent(const Component& component)
{
    cout << "ID: " << component.getId() << endl;
    cout << "Name: " << component.getName() << endl;
    cout << "Category: " << component.getCategory() << endl;
    cout << "Status: " << component.getStatus() << endl;
    cout << "------------------------" << endl;
}

int main()
{
    vector<Component> components;


    components.push_back(Component(1, "Arduino Uno", "Microcontroller"));
    components.push_back(Component(2, "Raspberry Pi 4", "Computer"));
    components.push_back(Component(3, "Oscilloscope", "Measurement"));

    cout << "===== Initial Components =====" << endl;

    for (const auto& component : components)
    {
        printComponent(component);
    }


    cout << "\nBorrowing Arduino Uno..." << endl;

    if (RegistryCore::borrowComponent(components[0]))
        cout << "Borrow successful.\n";
    else
        cout << "Borrow failed.\n";


    cout << "\nAttempting second borrow..." << endl;

    if (RegistryCore::borrowComponent(components[0]))
        cout << "Borrow successful.\n";
    else
        cout << "Borrow rejected (already borrowed).\n";


    cout << "\nReturning Arduino Uno..." << endl;

    if (RegistryCore::returnComponent(components[0]))
        cout << "Return successful.\n";
    else
        cout << "Return failed.\n";


    cout << "\nSaving to gear.json..." << endl;

    if (Storage::saveToFile(components, "gear.json"))
        cout << "Save successful.\n";
    else
        cout << "Save failed.\n";


    components.clear();

    cout << "\nMemory cleared." << endl;

    cout << "\nLoading from gear.json..." << endl;

    if (Storage::loadFromFile(components, "gear.json"))
        cout << "Load successful.\n";
    else
        cout << "Load failed.\n";

    cout << "\n===== Loaded Components =====\n" << endl;

    for (const auto& component : components)
    {
        printComponent(component);
    }

    return 0;
}