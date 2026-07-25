#ifndef AUTH_H
#define AUTH_H

#include <string>

class Auth {
public:
    static bool login(const std::string& studentId);
    static void logout();
    static bool isLoggedIn();
    static std::string currentUser();

private:
    static std::string activeStudentId;
};

#endif 


git add .
  git commit -m "Phase 2: add Auth session manager and gatekeeper checks on Component updates"
  git push origin main