#include <iostream>
#include <unordered_map>
using namespace std;

/*
====================================================
WITHOUT AUTHENTICATION
====================================================

Problem:

Anyone can access the application.

*/

class UserService {

public:

    void viewProfile() {

        cout << "Profile Information\n";

    }

};

int main() {

    UserService service;

    service.viewProfile();

}

/*

Problems:

- Anyone can access data.
- No identity verification.
- Serious security risk.

====================================================
WITH AUTHENTICATION
====================================================

Solution:

Verify username and password
before granting access.

*/

class AuthService {

private:

    unordered_map<string,string> users;

public:

    AuthService() {

        users["bhuvan"] = "password123";

    }

    bool login(string username,
               string password) {

        if(users.count(username) &&
           users[username] == password) {

            return true;

        }

        return false;

    }

};

class UserService {

public:

    void viewProfile() {

        cout << "Profile Information\n";

    }

};

int main() {

    AuthService auth;

    UserService service;

    if(auth.login("bhuvan",
                  "password123")) {

        service.viewProfile();

    }
    else {

        cout << "Authentication Failed\n";

    }

}

/*

Output:

Profile Information

Only authenticated users
can access the service.

*/