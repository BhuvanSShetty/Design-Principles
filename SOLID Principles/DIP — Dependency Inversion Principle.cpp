#include <iostream>
using namespace std;

/*
====================================================
WITHOUT DIP
====================================================

Problem:

UserService directly depends on MySQLDatabase.

If tomorrow the database changes to PostgreSQL,
UserService must also change.

*/

class MySQLDatabase {

public:

    void saveUser() {

        cout << "Saving User in MySQL\n";

    }

};

class UserService {

private:

    MySQLDatabase database;

public:

    void registerUser() {

        database.saveUser();

    }

};

// int main() {

//     UserService user;

//     user.registerUser();

// }

/*

Problems:

- Tight coupling.
- Difficult to replace MySQL.
- Difficult to unit test.
- UserService depends on a concrete class.

====================================================
WITH DIP
====================================================

Solution:

Create an abstraction (Database).

UserService depends on Database instead
of MySQLDatabase.

Now any database implementation can be used
without modifying UserService.

*/

class Database {

public:

    virtual void saveUser() = 0;

};

class MySQLDatabase : public Database {

public:

    void saveUser() override {

        cout << "Saving User in MySQL\n";

    }

};

class PostgreSQLDatabase : public Database {

public:

    void saveUser() override {

        cout << "Saving User in PostgreSQL\n";

    }

};

class UserService {

private:

    Database* database;

public:

    UserService(Database* database) {

        this->database = database;

    }

    void registerUser() {

        database->saveUser();

    }

};

int main() {

    Database* database = new MySQLDatabase();

    UserService user(database);

    user.registerUser();

}

/*

Output:

Saving User in MySQL

Tomorrow if we want PostgreSQL,

Database* database =
    new PostgreSQLDatabase();

UserService user(database);

Nothing inside UserService changes.

*/