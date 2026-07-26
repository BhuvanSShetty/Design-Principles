#include <iostream>
using namespace std;

/*
====================================================
WITHOUT BUILDER
====================================================

Problem:

Suppose a User object has many fields.

As the number of fields increases, the constructor
becomes very long and difficult to read.

Code:

class User {

public:

    string name;
    string email;
    int age;

    User(string name,
         string email,
         int age) {

        this->name = name;
        this->email = email;
        this->age = age;

    }

};

int main() {

    User user(
        "Bhuvan",
        "bhuvan@gmail.com",
        21
    );

}

Imagine if User had:

- phone
- address
- city
- state
- country
- salary
- company
- department
- ...

The constructor would become huge.

Problems:

- Constructor has too many parameters.
- Difficult to remember parameter order.
- Optional parameters become messy.
- Object creation is not readable.

====================================================
BUILDER PATTERN
====================================================

Solution:

Instead of passing everything to one constructor,
build the object step-by-step.

The Builder stores the object internally.

Each setter updates one field and returns the Builder
itself.

Finally, build() returns the completed object.
*/

class User {

public:

    string name;
    string email;
    int age;

};

class UserBuilder {

private:

    User user;

public:

    UserBuilder& setName(string name) {

        user.name = name;

        return *this;

    }

    UserBuilder& setEmail(string email) {

        user.email = email;

        return *this;

    }

    UserBuilder& setAge(int age) {

        user.age = age;

        return *this;

    }

    User build() {

        return user;

    }

};

int main() {

    User user =
        UserBuilder()
            .setName("Bhuvan")
            .setEmail("bhuvan@gmail.com")
            .setAge(21)
            .build();

    cout << user.name << endl;
    cout << user.email << endl;
    cout << user.age << endl;

}

/*
Output:

Bhuvan
bhuvan@gmail.com
21

Notice:

Instead of writing one huge constructor,

User(
    ...many parameters...
)

we construct the object gradually.

Benefits:

- Readable
- Easy to maintain
- Optional fields are easy to add
- No confusion about parameter order
*/