#include "CliDisplay.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string RESET = "\033[0m";

void CliDisplay::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void CliDisplay::printHeader()
{
    cout << "+============================================================+\n";
    cout << "|                  LAB SHARE SYSTEM                          |\n";
    cout << "+============================================================+\n";
}

void CliDisplay::printMenu()
{
    cout << "| 1. View Equipment                                          |\n";
    cout << "| 2. Borrow Equipment                                        |\n";
    cout << "| 3. Return Equipment                                        |\n";
    cout << "| 4. Exit                                                    |\n";
    cout << "+============================================================+\n\n";
}

void CliDisplay::printStatus(const string& status)
{
    if(status == "Available")
        cout << GREEN << "[Available]" << RESET;
    else if(status == "Borrowed")
        cout << RED << "[Borrowed]" << RESET;
    else
        cout << "[" << status << "]";
}

void CliDisplay::displayComponents(const vector<Component>& components)
{
    cout << left;

    cout << "+----+----------------------+----------------+---------------+\n";
    cout << "| ID | Name                 | Category       | Status        |\n";
    cout << "+----+----------------------+----------------+---------------+\n";

    for(const auto& component : components)
    {
        cout << "| "
             << setw(2) << component.getId() << " ";

        cout << "| "
             << setw(20) << component.getName();

        cout << "| "
             << setw(15) << component.getCategory();

        cout << "| ";

        printStatus(component.getStatus());

        cout << " |\n";
    }

    cout << "+----+----------------------+----------------+---------------+\n";
}