#include <iostream>
using namespace std;

/*
====================================================
WITHOUT DEPENDENCY INJECTION
====================================================

Problem:

UserService directly creates
its own Database object.

If tomorrow we change the database,
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

- Tight coupling
- Hard to replace database
- Hard to test
- Violates Dependency Inversion Principle

====================================================
WITH DEPENDENCY INJECTION
====================================================

Solution:

UserService no longer creates
its own Database.

Someone else creates the Database
and injects it.

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

    Database* database =
        new MySQLDatabase();

    UserService service(database);

    service.registerUser();

}

/*

Output:

Saving User in MySQL

Tomorrow

Database* database =
new PostgreSQLDatabase();

UserService remains unchanged.

*/