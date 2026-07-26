#include <iostream>
using namespace std;

/*
====================================================
WITHOUT STRATEGY
====================================================

Problem:

Suppose an application supports multiple payment methods.

- UPI
- Credit Card
- Wallet

The client decides which algorithm to execute
using if-else statements.

Code:

class Payment {

public:

    void pay(string method) {

        if(method == "UPI") {

            cout << "Paying using UPI\n";

        }
        else if(method == "CARD") {

            cout << "Paying using Credit Card\n";

        }
        else if(method == "WALLET") {

            cout << "Paying using Wallet\n";

        }

    }

};

int main() {

    Payment payment;

    payment.pay("UPI");

}

Problems:

- Large if-else chain.
- Every new payment method requires modifying
  the existing class.
- Violates Open/Closed Principle.
- Business logic and algorithm selection are mixed.

====================================================
STRATEGY PATTERN
====================================================

Solution:

Move each algorithm into its own class.

Create a common interface.

The client chooses which strategy to use at runtime.

Instead of changing the Payment class,
we simply provide a different strategy object.
*/

// Common Strategy Interface
class PaymentStrategy {

public:

    virtual void pay() = 0;

};

// Strategy 1
class UPI : public PaymentStrategy {

public:

    void pay() override {

        cout << "Paying using UPI\n";

    }

};

// Strategy 2
class CreditCard : public PaymentStrategy {

public:

    void pay() override {

        cout << "Paying using Credit Card\n";

    }

};

// Strategy 3
class Wallet : public PaymentStrategy {

public:

    void pay() override {

        cout << "Paying using Wallet\n";

    }

};

// Context
class Payment {

private:

    PaymentStrategy* strategy;

public:

    Payment(PaymentStrategy* strategy) {

        this->strategy = strategy;

    }

    void makePayment() {

        strategy->pay();

    }

};

int main() {

    Payment payment(new UPI());

    payment.makePayment();

}

/*
Output:

Paying using UPI

Notice:

The Payment class does not know HOW payment is made.

It simply delegates the work to the selected strategy.

Tomorrow, if we introduce:

- PayPal
- Apple Pay
- Crypto

We simply create another strategy class.

The Payment class remains unchanged.

Benefits:

- Removes if-else chains.
- Easy to add new algorithms.
- Algorithms can be switched at runtime.
- Follows Open/Closed Principle.
*/