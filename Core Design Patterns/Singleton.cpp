#include <iostream>
using namespace std;

/*
====================================================
WITHOUT SINGLETON
====================================================

Problem:

Every module creates its own Logger object.

Suppose an application has:

- User Service
- Payment Service
- Order Service

Each service creates its own Logger.

Code:

class Logger {
public:
    void log(string msg) {
        cout << msg << endl;
    }
};

int main() {

    Logger logger1;
    Logger logger2;
    Logger logger3;

    logger1.log("User Login");
    logger2.log("Payment Success");
    logger3.log("Order Created");

}

Problems:

- Multiple Logger objects are created.
- Wastes memory and resources.
- Different modules may maintain different states.
- We actually need only ONE Logger object.

====================================================
SINGLETON PATTERN
====================================================

Solution:

Make the constructor private so nobody can create
Logger objects directly.

Provide one static function called getInstance().

The Logger class itself creates exactly one object
and returns the same object every time.

No matter how many times getInstance() is called,
only one Logger object exists.
*/

class Logger {

private:

    // Prevent object creation from outside
    Logger() {}

public:

    // Global access point
    static Logger& getInstance() {

        // Created only once
        static Logger instance;

        return instance;

    }

    void log(string msg) {

        cout << msg << endl;

    }

};

int main() {

    Logger& logger1 = Logger::getInstance();

    Logger& logger2 = Logger::getInstance();

    logger1.log("User Login");

    logger2.log("Payment Success");

    cout << &logger1 << endl;
    cout << &logger2 << endl;

}

/*
Output:

User Login
Payment Success

0x61ff20
0x61ff20

Notice:

Both addresses are identical.

Both references point to the same Logger object.
*/