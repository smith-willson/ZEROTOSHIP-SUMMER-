#include "Auth.h"

std::string Auth::activeStudentId = "";

bool Auth::login(const std::string& studentId) {
    if (studentId.empty()) return false;
    activeStudentId = studentId;
    return true;
}

void Auth::logout() {
    activeStudentId.clear();
}

bool Auth::isLoggedIn() {
    return !activeStudentId.empty();
}

std::string Auth::currentUser() {
    return activeStudentId;
}