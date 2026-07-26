#include <iostream>
#include <unordered_map>
using namespace std;

/*
====================================================
WITHOUT AUTHORIZATION
====================================================

Problem:

Every authenticated user
can delete users.

*/

class UserService {

public:

    void deleteUser() {

        cout << "User Deleted\n";

    }

};

// int main() {

//     UserService service;

//     service.deleteUser();

// }

/*

Problems:

- Employees can delete users.
- No permission checks.
- Serious security issue.

====================================================
WITH AUTHORIZATION
====================================================

Solution:

Check the user's role
before allowing the action.

*/

class User {

public:

    string username;

    string role;

    User(string username,
         string role) {

        this->username = username;
        this->role = role;

    }

};

class UserService {

public:

    void deleteUser(User user) {

        if(user.role == "Admin") {

            cout << "User Deleted\n";

        }
        else {

            cout << "Access Denied\n";

        }

    }

};

int main() {

    User admin("Alice", "Admin");

    User employee("Bob", "Employee");

    UserService service;

    service.deleteUser(admin);

    service.deleteUser(employee);

}

/*

Output:

User Deleted

Access Denied

Only Admin can delete users.

*/