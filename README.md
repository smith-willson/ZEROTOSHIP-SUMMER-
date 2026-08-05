# ZeroToShip Summer Activity 2026 - Lab-Share

A lightweight equipment-sharing registry for lab hardware, built in phases as part of the CIS Community (NEDUET) ZeroToShip Summer Activity 2026.

## Phases

* [Phase 1](./Phase-1) – Component data model and serialization
* [Phase 2](./Phase-2) – Authentication session manager and access gatekeeper
* [Phase 3](./Phase-3) – Equipment state transition engine and JSON persistence layer
* [Phase 4](./Phase-4) – Terminal-based CLI presentation layer
* [Phase 5](./Phase-5) – Final system integration

  * [Final Integration](./Phase-5/Final-Integration) – Complete integrated Lab-Share application

## Project Overview

Lab-Share is developed incrementally across multiple phases, with each phase introducing new functionality while maintaining a modular, object-oriented architecture.

* **Phase 1** establishes the core `Component` model and JSON serialization helpers.
* **Phase 2** introduces authentication and session management for controlled access.
* **Phase 3** implements secure equipment status transitions and persistent JSON storage, ensuring components move only through valid states while preserving data between program executions.
* **Phase 4** adds a terminal-based user interface featuring formatted ASCII tables, color-coded equipment status indicators, and a structured navigation menu.
* **Phase 5** integrates all previous modules into one complete application by connecting authentication, business logic, persistent storage, and the terminal interface through a unified application controller.

## Features

* Equipment management using object-oriented design
* Student login and session handling
* Secure borrowing and returning rules
* JSON-based persistent storage
* Color-coded terminal interface
* Modular architecture with separated responsibilities
* Complete end-to-end integrated application

## Technologies

* C++17
* Object-Oriented Programming (OOP)
* nlohmann/json (header-only JSON library)
* Git
* GitHub

## Repository Structure

```text
ZEROTOSHIP-SUMMER-
│
├── Phase-1
├── Phase-2
├── Phase-3
├── Phase-4
├── Phase-5
│   └── Final-Integration
│
└── README.md
```

## Learning Outcomes

Throughout this project, the following concepts were practiced:

* Object-Oriented Programming (OOP)
* Modular software development
* Authentication and session management
* Business logic and state validation
* JSON serialization and file handling
* Terminal user interface development
* Software integration
* Git version control and GitHub collaboration

## Author

### Muhammad Haseeb

Computer Information Systems Engineering Student

NED University of Engineering & Technology
