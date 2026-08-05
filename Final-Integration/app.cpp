#include <iostream>
#include <vector>

#include "Component.h"
#include "services/Auth.h"
#include "services/Storage.h"
#include "services/RegistryCore.h"
#include "services/CliDisplay.h"

using namespace std;

int main()
{
    vector<Component> components;

    Storage::loadFromFile(components, "gear.json");

    if (components.empty())
    {
        components.push_back(Component(1, "Arduino Uno", "Controller", "Available"));
        components.push_back(Component(2, "Raspberry Pi 4", "Computer", "Borrowed"));
        components.push_back(Component(3, "Oscilloscope", "Measurement", "Available"));
        components.push_back(Component(4, "Power Supply", "Electrical", "Available"));
    }

    string studentId;

    cout << "=====================================\n";
    cout << "        LAB SHARE LOGIN\n";
    cout << "=====================================\n";
    cout << "Enter Student ID: ";
    getline(cin, studentId);

    if (!Auth::login(studentId))
    {
        cout << "\nLogin failed!\n";
        return 0;
    }

    cout << "\nWelcome, " << Auth::currentUser() << "!\n";

    int choice;

    do
    {
        CliDisplay::clearScreen();
        CliDisplay::printHeader();
        CliDisplay::printMenu();

        cout << "\nCurrent User: " << Auth::currentUser() << endl;

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            CliDisplay::displayComponents(components);

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        }

        case 2:
        {
            int id;

            cout << "Enter Component ID: ";
            cin >> id;

            bool found = false;

            for (auto& component : components)
            {
                if (component.getId() == id)
                {
                    found = true;

                    if (RegistryCore::borrowComponent(component))
                        cout << "\nComponent borrowed successfully.\n";
                    else
                        cout << "\nBorrow failed. Component is not available.\n";

                    break;
                }
            }

            if (!found)
                cout << "\nComponent not found.\n";

            Storage::saveToFile(components, "gear.json");

            cout << "\nPress Enter...";
            cin.ignore();
            cin.get();

            break;
        }

        case 3:
        {
            int id;

            cout << "Enter Component ID: ";
            cin >> id;

            bool found = false;

            for (auto& component : components)
            {
                if (component.getId() == id)
                {
                    found = true;

                    if (RegistryCore::returnComponent(component))
                        cout << "\nComponent returned successfully.\n";
                    else
                        cout << "\nReturn failed. Component is already available.\n";

                    break;
                }
            }

            if (!found)
                cout << "\nComponent not found.\n";

            Storage::saveToFile(components, "gear.json");

            cout << "\nPress Enter...";
            cin.ignore();
            cin.get();

            break;
        }

        case 4:
        {
            Storage::saveToFile(components, "gear.json");
            Auth::logout();

            cout << "\nThank you for using Lab Share.\n";
            break;
        }

        default:
        {
            cout << "\nInvalid choice.\n";
            cin.ignore();
            cin.get();
        }
        }

    } while (choice != 4);

    return 0;
}