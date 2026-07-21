#include <iostream>
#include <map>
#include <vector>
#include "Component.h"

// Helper: runs the full serialize -> deserialize -> verify cycle on one component
bool testRoundTrip(const Component& original) {
    std::cout << "\nOriginal object:" << std::endl;
    original.print();

    std::map<std::string, std::string> dict = original.to_dict();
    std::cout << "Serialized dictionary:" << std::endl;
    for (const auto& pair : dict) {
        std::cout << "  " << pair.first << " -> " << pair.second << std::endl;
    }

    Component rebuilt = Component::from_dict(dict);
    std::cout << "Rebuilt object:" << std::endl;
    rebuilt.print();

    bool match = (rebuilt.id == original.id) &&
                 (rebuilt.name == original.name) &&
                 (rebuilt.owner == original.owner) &&
                 (rebuilt.status == original.status);

    std::cout << (match ? "PASS: round-trip data integrity confirmed."
                          : "FAIL: mismatch detected after round-trip.") << std::endl;
    return match;
}

int main() {
    std::cout << "=== Lab-Share Phase 1: Component Model Manual Test ===" << std::endl;

    // A small mock inventory to exercise the model with realistic lab data
    std::vector<Component> inventory = {
        Component(101, "Arduino Uno R3", "Smith"),                    // uses default status
        Component(102, "ESP32 DevKit V1", "Haseeb", "Checked Out"),
        Component(103, "DHT11 Temp Sensor", "Umar", "Available")
    };

    int passCount = 0;
    for (const auto& item : inventory) {
        if (testRoundTrip(item)) {
            passCount++;
        }
        std::cout << "----------------------------------------" << std::endl;
    }

    std::cout << "\nSummary: " << passCount << "/" << inventory.size()
                << " components passed the serialization round-trip test." << std::endl;

    return 0;
}