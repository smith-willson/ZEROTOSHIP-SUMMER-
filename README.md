# Lab-Share — Phase 1: Component Data Model

Part of the ZeroToShip Summer Activity 2026 (CIS Community, NEDUET).

## Overview
Lab-Share is a lightweight equipment-sharing registry for lab hardware
(Arduinos, ESP32s, sensors, etc.). Phase 1 implements the core `Component`
data model in C++, including manual serialization to/from a dictionary
(`std::map`) as a foundation for future JSON persistence.

## Structure

## Component Class
- `id` (int)
- `name` (string)
- `owner` (string)
- `status` (string, defaults to "Available")

Includes `to_dict()` and `from_dict()` for converting between the object
and a flat `std::map<std::string, std::string>` representation.

## How to run
cd models
g++ -std=c++17 manual_test.cpp Component.cpp -o manual_test
./manual_test


## Sample Output
See `screenshot.png` for a sample run — tests 3 mock components and
confirms round-trip serialization integrity.


