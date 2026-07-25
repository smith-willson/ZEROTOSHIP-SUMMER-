#include <iostream>
#include "Component.h"
#include "services/Auth.h"

int main() {
    std::cout << "=== Lab-Share Phase 2: Auth & Gatekeeper Manual Test ===" << std::endl;

    Component comp(101, "Arduino Uno R3", "Smith");

    std::cout << "\nAttempting to change status with NO active session..." << std::endl;
    bool blocked = comp.setStatus("Checked Out");
    std::cout << (!blocked ? "PASS: update correctly blocked."
                            : "FAIL: update went through unauthenticated.") << std::endl;

    std::cout << "\nLogging in as student 'haseeb123'..." << std::endl;
    Auth::login("haseeb123");

    std::cout << "Attempting to change status WITH active session..." << std::endl;
    bool allowed = comp.setStatus("Checked Out");
    std::cout << (allowed ? "PASS: update succeeded while logged in."
                           : "FAIL: update blocked unexpectedly.") << std::endl;

    comp.print();

    Auth::logout();
    std::cout << "\nLogged out. Session cleared." << std::endl;

    std::cout << "\nAttempting to change owner after logout..." << std::endl;
    bool blockedOwner = comp.setOwner("Haseeb");
    std::cout << (!blockedOwner ? "PASS: owner update correctly blocked after logout."
                                 : "FAIL: owner update went through after logout.") << std::endl;

    return 0;
}