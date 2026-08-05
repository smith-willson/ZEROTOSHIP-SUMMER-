# Lab-Share – Final Integration

## Overview

Lab-Share is a lightweight laboratory equipment sharing platform developed as the final project for the **ZeroToShip Summer Activity 2026** organized by the **CIS Community (NEDUET)**.

This final integration combines all previous phases into a single, functional application. Users can log in, view available equipment, borrow and return items, and automatically save all changes to a JSON database.

---

## Features

* Student login and session management
* View laboratory equipment
* Borrow available equipment
* Return borrowed equipment
* Secure equipment state transition rules
* JSON-based data persistence
* Color-coded terminal interface
* ASCII-based console layout
* Modular Object-Oriented C++ design

---

## Technologies Used

* C++17
* Object-Oriented Programming (OOP)
* nlohmann/json
* Git & GitHub

---

## Project Structure

```text
Final-Integration
│
├── app.cpp
├── Component.cpp
├── Component.h
├── gear.json
├── README.md
│
├── include
│   └── json.hpp
│
├── Output
│
└── services
    ├── Auth.cpp
    ├── Auth.h
    ├── CliDisplay.cpp
    ├── CliDisplay.h
    ├── RegistryCore.cpp
    ├── RegistryCore.h
    ├── Storage.cpp
    └── Storage.h
```

---

## Project Modules

### Component

Represents a single laboratory equipment item. It stores the equipment ID, name, category, and current status. The class also provides JSON serialization and deserialization functions for persistent storage.

### Authentication

Handles student login sessions. A valid, non-empty student ID starts a session, while logout clears the active user.

### RegistryCore

Implements the application's business rules. Equipment can only be borrowed when its status is **Available** and can only be returned when its status is **Borrowed**. Invalid state transitions are rejected.

### Storage

Loads equipment records from `gear.json` at startup and saves all modifications back to the file before exiting or after status updates. The module includes basic file and JSON error handling.

### CliDisplay

Provides the terminal user interface, including screen clearing, ASCII menu layouts, formatted equipment tables, and color-coded status labels for available and borrowed equipment.

---

## How to Build

Compile the project using:

```bash
g++ app.cpp Component.cpp services/Auth.cpp services/RegistryCore.cpp services/Storage.cpp services/CliDisplay.cpp -o LabShare
```

---

## How to Run

Windows:

```bash
LabShare.exe
```

Linux/macOS:

```bash
./LabShare
```

---

## How to Test

1. Run the application.
2. Enter any non-empty Student ID to log in.
3. View the list of available equipment.
4. Borrow an available component.
5. Verify its status changes to **Borrowed**.
6. Return the borrowed component.
7. Verify its status changes back to **Available**.
8. Exit the application.
9. Restart the application and confirm that equipment data is restored from `gear.json`.

---

## Design Approach

The application follows a modular architecture where each component has a single responsibility. The user interface, authentication, business logic, and storage layers are separated, making the code easier to maintain, test, and extend. This structure also allows future enhancements without affecting unrelated modules.

---

## Future Improvements

* Password-based authentication
* Search and filter equipment
* Equipment reservation system
* Due dates and borrowing history
* Multiple user roles (Student, Lab Assistant, Administrator)
* Input validation improvements
* Enhanced terminal interface

---

## Learning Outcomes

Through this project, I gained practical experience with:

* Object-Oriented Programming in C++
* Modular software architecture
* JSON serialization and file handling
* Authentication and session management
* Business logic implementation
* Terminal user interface design
* Git and GitHub version control
* Integrating multiple software modules into a complete application

---

## Author

Muhammad Haseeb

Computer Information Systems Engineering Student

NED University of Engineering & Technology

---

## Acknowledgements

Developed as part of the **ZeroToShip Summer Activity 2026** organized by the **CIS Community (NEDUET)**.
