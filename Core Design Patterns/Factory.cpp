#include <iostream>
using namespace std;

/*
====================================================
WITHOUT FACTORY
====================================================

Problem:
The client is responsible for creating objects.

Everywhere in the application, the client decides
which class to instantiate using if-else statements.

If tomorrow a new payment method (Wallet, PayPal, etc.)
is introduced, every if-else block must be modified.

Code:

class UPI {
public:
    void pay() {
        cout << "UPI Payment\n";
    }
};

class Card {
public:
    void pay() {
        cout << "Card Payment\n";
    }
};

int main() {

    string type = "UPI";

    if(type == "UPI") {

        UPI payment;
        payment.pay();

    }
    else {

        Card payment;
        payment.pay();

    }

}

Drawbacks:

- Client knows concrete classes.
- Object creation is scattered across the application.
- Difficult to extend.
- Violates the Open/Closed Principle.

====================================================
FACTORY PATTERN
====================================================

Solution:

Move the object creation logic into a dedicated
Factory class.

The client should not know which object is created.

Instead of:

    new UPI()

or

    new Card()

the client simply calls

    PaymentFactory::create(type)

Only the factory changes when a new payment
method is introduced.
*/

class Payment {
public:
    virtual void pay() = 0;
};

class UPI : public Payment {
public:
    void pay() override {
        cout << "UPI Payment\n";
    }
};

class Card : public Payment {
public:
    void pay() override {
        cout << "Card Payment\n";
    }
};

class PaymentFactory {
public:

    static Payment* create(string type) {

        if(type == "UPI")
            return new UPI();

        return new Card();

    }

};

int main() {

    Payment* payment =
        PaymentFactory::create("UPI");

    payment->pay();

}