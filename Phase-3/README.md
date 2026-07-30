# Phase 3 – Operational Logic and JSON Storage

## Overview

This phase implements the core operational logic of the equipment registry system. The project focuses on two major objectives:

1. Enforcing safe equipment status transitions.
2. Persisting equipment records using a JSON-based storage system.

The implementation follows an object-oriented design where each module has a single responsibility, making the code easier to understand, maintain, and extend.

---

## Project Structure

```
Phase-3
│
├── Component.h
├── Component.cpp
├── gear.json
├── manual_test_phase3.cpp
├── README.md
│
├── include
│   └── json.hpp
│
├── Output
│
└── services
    ├── RegistryCore.h
    ├── RegistryCore.cpp
    ├── Storage.h
    └── Storage.cpp
```

---

## Design Decisions

### Component

The `Component` class represents a single piece of laboratory equipment.

Each component stores:

* Equipment ID
* Equipment Name
* Category
* Current Status

The class also provides JSON serialization helpers:

* `toJson()`
* `fromJson()`

These functions allow the object to convert itself to and from JSON format.

---

### RegistryCore

`RegistryCore` contains the application's business logic.

Instead of allowing any code to change a component's status directly, all state changes pass through this module.

Implemented rules include:

* Available → Borrowed ✅
* Borrowed → Available ✅
* Borrowed → Borrowed ❌
* Available → Available ❌

This ensures that invalid equipment state transitions cannot occur.

---

### Storage

The `Storage` module is responsible for reading and writing equipment data.

Responsibilities include:

* Saving all components to `gear.json`
* Loading components from `gear.json`
* Handling file opening errors
* Handling invalid JSON input gracefully

JSON support is implemented using the header-only **nlohmann/json** library.

---

## Error Handling

The storage system includes basic fault tolerance by:

* Checking whether files can be opened.
* Catching JSON parsing errors.
* Returning `false` if a load or save operation fails.

This prevents crashes caused by missing or corrupted data files.

---

## Manual Testing

The manual test program demonstrates the complete workflow:

1. Create sample components.
2. Borrow an available component.
3. Reject an invalid borrow request.
4. Return the component.
5. Save all data to `gear.json`.
6. Clear memory.
7. Reload data from the JSON file.
8. Display the restored components.

---

## Technologies Used

* C++17
* Object-Oriented Programming
* nlohmann/json (header-only JSON library)

---

## Learning Outcomes

Through this phase, I learned how to:

* Separate business logic from storage logic.
* Enforce safe state transitions.
* Serialize objects into JSON.
* Load objects from JSON files.
* Organize a project into reusable modules.
* Implement basic fault-tolerant file handling.

---

## Conclusion

Phase 3 extends the previous phases by adding operational state management and persistent storage. The system now safely controls equipment status changes while maintaining data between program executions using a JSON-based storage layer.
