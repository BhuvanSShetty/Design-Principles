#include <iostream>
using namespace std;

/*
====================================================
WITHOUT CHAIN OF RESPONSIBILITY
====================================================

Problem:

Suppose every request goes through:

1. Authentication
2. Authorization
3. Logging

The client manually calls each service.

Code:

class Authentication {

public:

    bool check() {

        cout << "Authentication Successful\n";

        return true;

    }

};

class Authorization {

public:

    bool check() {

        cout << "Authorization Successful\n";

        return true;

    }

};

class Logger {

public:

    void log() {

        cout << "Request Logged\n";

    }

};

int main() {

    Authentication auth;

    Authorization permission;

    Logger logger;

    if(auth.check()) {

        if(permission.check()) {

            logger.log();

            cout << "Processing Request\n";

        }

    }

}

Problems:

- Client controls the execution order.
- Tight coupling.
- Difficult to insert new handlers.
- Every client repeats the same code.

====================================================
CHAIN OF RESPONSIBILITY PATTERN
====================================================

Solution:

Create a common Handler interface.

Each handler performs one task and forwards
the request to the next handler.

The client only starts the chain.

*/

// Base Handler
class Handler {

protected:

    Handler* next = nullptr;

public:

    void setNext(Handler* handler) {

        next = handler;

    }

    virtual void handle() {

        if(next)

            next->handle();

    }

};

// Handler 1
class Authentication : public Handler {

public:

    void handle() override {

        cout << "Authentication Successful\n";

        Handler::handle();

    }

};

// Handler 2
class Authorization : public Handler {

public:

    void handle() override {

        cout << "Authorization Successful\n";

        Handler::handle();

    }

};

// Handler 3
class Logger : public Handler {

public:

    void handle() override {

        cout << "Request Logged\n";

        Handler::handle();

    }

};

int main() {

    Authentication auth;

    Authorization permission;

    Logger logger;

    auth.setNext(&permission);

    permission.setNext(&logger);

    auth.handle();

}

/*

Output:

Authentication Successful
Authorization Successful
Request Logged

Notice:

The client only starts the chain.

Authentication decides to call Authorization.

Authorization decides to call Logger.

Each handler knows only the next handler.

The client does not control the flow.

*/