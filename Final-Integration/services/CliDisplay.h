#ifndef CLIDISPLAY_H
#define CLIDISPLAY_H

#include <vector>
#include "../Component.h"

class CliDisplay
{
public:
    static void clearScreen();

    static void printHeader();

    static void printMenu();

    static void displayComponents(const std::vector<Component>& components);

    static void printStatus(const std::string& status);
};

#endif