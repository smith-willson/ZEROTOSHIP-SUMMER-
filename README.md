# ZeroToShip Summer Activity 2026 - Lab-Share

A lightweight equipment-sharing registry for lab hardware, built in phases as part of the CIS Community (NEDUET) ZeroToShip program.

## Phases

* [Phase 1](./Phase-1) – Component data model and serialization
* [Phase 2](./Phase-2) – Authentication session manager and access gatekeeper
* [Phase 3](./Phase-3) – Equipment state transition engine and JSON persistence layer
* [Phase 4](./Phase-4) – CLI display layer
* Phase 5 – TBD
* Final Integration – Complete integrated project

## Project Overview

The Lab-Share project is developed incrementally across multiple phases. Each phase introduces new functionality while maintaining a modular and object-oriented architecture.

* **Phase 1** establishes the core `Component` model and serialization helpers.
* **Phase 2** adds authentication and session management for controlled access.
* **Phase 3** implements secure equipment status transitions and persistent JSON storage, ensuring that components can only move between valid states and that data is preserved between program executions.
* **Phase 4** introduces a terminal-based CLI display layer, rendering equipment data as a formatted, color-coded table alongside a navigable menu, while keeping display logic fully separated from the `Component` data class.
* **Future phases** will expand the system with additional features and integrate all modules into a complete application.

## Technologies

* C++17
* Object-Oriented Programming (OOP)
* nlohmann/json (header-only JSON library)
* Git & GitHub

## Repository Structure

```text
ZEROTOSHIP-SUMMER-
├── Phase-1
├── Phase-2
├── Phase-3
├── Phase-4
└── README.md
```