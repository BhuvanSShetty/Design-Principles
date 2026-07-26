#include <iostream>
using namespace std;

/*
====================================================
WITHOUT IMMUTABILITY
====================================================

Problem:

User objects are mutable.

Any part of the application
can modify them.

*/

class User {

public:

    string name;

    User(string name) {

        this->name = name;

    }

};

// void updateUser(User& user) {

//     user.name = "Rahul";

// }

// int main() {

//     User user("Bhuvan");

//     updateUser(user);

//     cout << user.name << endl;

// }

/*

Output:

Rahul

Problems:

- Anyone can modify the object.
- Difficult to predict changes.
- Unsafe when shared.
- Hard to debug.

====================================================
WITH IMMUTABILITY
====================================================

Solution:

Do not allow modification.

Instead,

create a new object.

*/

class User {

private:

    string name;

public:

    User(string name) {

        this->name = name;

    }

    string getName() const {

        return name;

    }

};

User updateUser(User user) {

    return User("Rahul");

}

int main() {

    User original("Bhuvan");

    User updated =
        updateUser(original);

    cout << original.getName() << endl;

    cout << updated.getName() << endl;

}

/*

Output:

Bhuvan
Rahul

Notice:

Original object never changes.

A new object is created instead.

*/