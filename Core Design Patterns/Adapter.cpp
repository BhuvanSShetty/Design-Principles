#include <iostream>
using namespace std;

/*
====================================================
WITHOUT ADAPTER
====================================================

Problem:

Our application expects every payment service
to have a function called:

    pay()

However, different third-party libraries expose
different function names.

Stripe:

    makePayment()

PayPal:

    sendPayment()

Razorpay:

    processTransaction()

Code:

class Stripe {

public:

    void makePayment() {

        cout << "Stripe Payment\n";

    }

};

int main() {

    Stripe stripe;

    stripe.makePayment();

}

Suppose tomorrow we also integrate PayPal.

class PayPal {

public:

    void sendPayment() {

        cout << "PayPal Payment\n";

    }

};

Now the client has to write:

if(provider == "Stripe")
    stripe.makePayment();

else if(provider == "PayPal")
    paypal.sendPayment();

Problems:

- Client knows every third-party API.
- Different method names.
- Lots of if-else statements.
- Tight coupling with external libraries.

====================================================
ADAPTER PATTERN
====================================================

Solution:

Create a common interface that our application
understands.

Then create an Adapter for each third-party library.

The Adapter translates our application's method

    pay()

into the library-specific method

    makePayment()

The client only works with the common interface.
*/

// Interface expected by our application
class Payment {

public:

    virtual void pay() = 0;

};

// Third-party library (cannot be modified)
class Stripe {

public:

    void makePayment() {

        cout << "Stripe Payment\n";

    }

};

// Adapter
class StripeAdapter : public Payment {

private:

    Stripe stripe;

public:

    void pay() override {

        stripe.makePayment();

    }

};

int main() {

    Payment* payment =
        new StripeAdapter();

    payment->pay();

}

/*
Output:

Stripe Payment

Notice:

Application calls

    payment->pay()

Adapter converts it into

    stripe.makePayment()

The application never knows how Stripe actually works.

Benefits:

- Client is independent of third-party APIs.
- Easy to replace Stripe with another provider.
- No changes required in client code.
- Follows Dependency Inversion Principle.
*/