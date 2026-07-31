# Lab-Share — Phase 4: CLI Display Layer

Part of the ZeroToShip Summer Activity 2026 (CIS Community, NEDUET).

## Overview

Phase 4 adds a terminal-based CLI display layer on top of the `Component` data model built in earlier phases. The `CliDisplay` class handles all console output — headers, menus, and a formatted equipment table with color-coded status tags — while keeping display logic fully separated from the `Component` data class itself.

## Structure

### CliDisplay Class (`services/CliDisplay.h` / `services/CliDisplay.cpp`)

A static utility class with no internal state, responsible only for rendering output to the terminal:

- `clearScreen()` — clears the terminal (cross-platform: `cls` on Windows, `clear` on Unix)
- `printHeader()` — prints the "LAB SHARE SYSTEM" banner
- `printMenu()` — prints the main menu options (View / Borrow / Return / Exit)
- `printStatus(status)` — prints a component's status as a colored tag (green `[Available]`, red `[Borrowed]`)
- `displayComponents(components)` — prints a formatted table of all components with ID, Name, Category, and Status columns

### Component Class (`Component.h` / `Component.cpp`)

Carried over from earlier phases, with getters for `id`, `name`, `category`, `status`, and a `setStatus()` mutator used to simulate borrow/return actions.

## How to Run

```
cd Phase-4
g++ manual_test_phase4.cpp Component.cpp services/CliDisplay.cpp -o manual_test_phase4
.\manual_test_phase4.exe
```

## Sample Output

`manual_test_phase4.cpp` seeds five sample components, displays the full table via `CliDisplay`, then simulates returning one borrowed item (`setStatus("Available")`) and re-displays the table to confirm the status change is reflected correctly — a simple manual proof that the display and mutation logic both work as expected.