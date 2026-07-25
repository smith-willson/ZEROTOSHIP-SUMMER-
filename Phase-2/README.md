# Lab-Share - Phase 2: Auth & Access Gatekeeper

Part of the ZeroToShip Summer Activity 2026 (CIS Community, NEDUET).

## Overview
Phase 2 adds a lightweight authentication/session layer on top of the
Phase 1 Component model. The system is completely headless (no UI) and
acts as an access gatekeeper: component status and ownership fields can
only be modified while a valid student session is active.

## Structure

### Auth (services/Auth.h, services/Auth.cpp)
A minimal static session tracker simulating a single-terminal login log:
- `login(studentId)` - starts a session for the given student ID
- `logout()` - clears the active session
- `isLoggedIn()` - returns whether a session is currently active
- `currentUser()` - returns the active student ID, or empty if none

This is intentionally lightweight (no passwords/hashing) since the goal
is session-state gatekeeping, not production-grade authentication.

### Component gatekeeper methods
`Component` (carried forward from Phase 1) gained two guarded setters:
- `setStatus(newStatus)`
- `setOwner(newOwner)`

Both check `Auth::isLoggedIn()` before applying the change. If no
session is active, the update is rejected and an "ACCESS DENIED"
message is printed; the method returns `false`.

**Known limitation:** `id`, `name`, `owner`, and `status` remain public
fields for compatibility with Phase 1's `to_dict()`/`from_dict()`. The
gatekeeper only protects code paths that call `setStatus()`/`setOwner()`
explicitly; a direct field assignment (`comp.status = "x"`) would still
bypass the check. A future phase could make these fields private with
gatekeeper-guarded accessors as the only entry point.

## How to run
cd Phase-2
g++ -std=c++17 manual_test_auth.cpp Component.cpp services\Auth.cpp -o manual_test_auth.exe
.\manual_test_auth.exe

## Sample Output
See `Output/Screenshot.png` for a sample run. The test confirms:
1. Status update is blocked with no active session
2. Status update succeeds once logged in
3. Owner update is blocked again after logout
