#include <iostream>
using namespace std;

/*
====================================================
WITHOUT OCP
====================================================

Problem:

The Payment class decides how payment
should be processed.

Whenever a new payment method is added,
this class must be modified.

*/

class Payment {

public:

    void pay(string type) {

        if(type == "UPI") {

            cout << "UPI Payment\n";

        }
        else if(type == "CARD") {

            cout << "Card Payment\n";

        }
        else if(type == "WALLET") {

            cout << "Wallet Payment\n";

        }

    }

};

// int main() {

//     Payment payment;

//     payment.pay("UPI");

// }

/*

Problems:

- Large if-else chain.
- Every new payment method requires modifying
  the Payment class.
- High chance of introducing bugs.
- Violates Open/Closed Principle.

====================================================
WITH OCP
====================================================

Solution:

Create an abstract Payment class.

Each payment method becomes its own class.

To add a new payment method,
simply create another derived class.

Existing code never changes.

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

class Wallet : public Payment {

public:

    void pay() override {

        cout << "Wallet Payment\n";

    }

};

int main() {

    Payment* payment = new UPI();

    payment->pay();

}

/*

Output:

UPI Payment

Tomorrow if we introduce PayPal:

class PayPal : public Payment {

public:

    void pay() override {

        cout << "PayPal Payment\n";

    }

};

No existing class changes.

Only a new class is added.

*/