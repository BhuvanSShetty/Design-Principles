#include <iostream>
using namespace std;

/*
====================================================
WITHOUT PROXY
====================================================

Problem:

Suppose we have a Database class.

Every client directly accesses the database.

Code:

class Database {

public:

    void readData() {

        cout << "Reading Database\n";

    }

};

int main() {

    Database db;

    db.readData();

}

Problems:

- No security.
- No logging.
- No caching.
- No access control.
- Every client directly talks to Database.

====================================================
PROXY PATTERN
====================================================

Solution:

Introduce a DatabaseProxy.

Clients communicate with DatabaseProxy.

DatabaseProxy decides whether
the request should be forwarded
to the real Database object.

*/

// Common Interface
class Database {

public:

    virtual void readData() = 0;

};

// Real Object
class RealDatabase : public Database {

public:

    void readData() override {

        cout << "Reading Database\n";

    }

};

// Proxy
class DatabaseProxy : public Database {

private:

    RealDatabase database;

public:

    void readData() override {

        cout << "Checking User Permission...\n";

        database.readData();

        cout << "Logging Database Access...\n";

    }

};

int main() {

    Database* db = new DatabaseProxy();

    db->readData();

}

/*

Output:

Checking User Permission...

Reading Database

Logging Database Access

Notice:

Client never talks to RealDatabase.

Everything goes through DatabaseProxy.

The Proxy decides what should happen
before and after calling the real object.

*/