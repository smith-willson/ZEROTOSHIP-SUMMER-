#include "services/CliDisplay.h"
#include "Component.h"
#include <vector>
#include <iostream>

int main()
{
    std::vector<Component> components;

    components.push_back(Component(1, "Arduino Uno", "Microcontroller", "Available"));
    components.push_back(Component(2, "ESP32 Dev Board", "Microcontroller", "Available"));
    components.push_back(Component(3, "Digital Oscilloscope", "Test Equipment", "Borrowed"));
    components.push_back(Component(4, "Breadboard", "Prototyping", "Available"));
    components.push_back(Component(5, "Function Generator", "Test Equipment", "Borrowed"));

    CliDisplay::clearScreen();
    CliDisplay::printHeader();
    CliDisplay::displayComponents(components);
    CliDisplay::printMenu();

    components[2].setStatus("Available");

    std::cout << "\nAfter returning Oscilloscope:\n\n";
    CliDisplay::displayComponents(components);

    return 0;
}