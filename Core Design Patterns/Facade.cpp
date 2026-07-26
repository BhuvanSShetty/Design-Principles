#include <iostream>
using namespace std;

/*
====================================================
WITHOUT FACADE
====================================================

Problem:

Suppose an E-Commerce application performs
the following steps while placing an order.

1. Check Inventory
2. Process Payment
3. Generate Invoice
4. Send Email
5. Send SMS

Every client has to call each subsystem
individually.

Code:

class Inventory {
public:
    void check() {
        cout << "Inventory Checked\n";
    }
};

class Payment {
public:
    void pay() {
        cout << "Payment Successful\n";
    }
};

class Invoice {
public:
    void generate() {
        cout << "Invoice Generated\n";
    }
};

class Email {
public:
    void send() {
        cout << "Email Sent\n";
    }
};

class SMS {
public:
    void send() {
        cout << "SMS Sent\n";
    }
};

int main() {

    Inventory inventory;
    Payment payment;
    Invoice invoice;
    Email email;
    SMS sms;

    inventory.check();
    payment.pay();
    invoice.generate();
    email.send();
    sms.send();

}

Problems:

- Client knows every subsystem.
- Client is responsible for calling them
  in the correct order.
- High coupling.
- Any subsystem change affects every client.
- Business logic gets duplicated.

====================================================
FACADE PATTERN
====================================================

Solution:

Create one class (Facade) that internally
coordinates all subsystem classes.

The client communicates with only one class.

The Facade hides the complexity of the system.
*/

// Subsystem 1
class Inventory {

public:

    void check() {

        cout << "Inventory Checked\n";

    }

};

// Subsystem 2
class Payment {

public:

    void pay() {

        cout << "Payment Successful\n";

    }

};

// Subsystem 3
class Invoice {

public:

    void generate() {

        cout << "Invoice Generated\n";

    }

};

// Subsystem 4
class Email {

public:

    void send() {

        cout << "Email Sent\n";

    }

};

// Subsystem 5
class SMS {

public:

    void send() {

        cout << "SMS Sent\n";

    }

};

// Facade
class CheckoutFacade {

private:

    Inventory inventory;
    Payment payment;
    Invoice invoice;
    Email email;
    SMS sms;

public:

    void placeOrder() {

        inventory.check();

        payment.pay();

        invoice.generate();

        email.send();

        sms.send();

    }

};

int main() {

    CheckoutFacade checkout;

    checkout.placeOrder();

}

/*
Output:

Inventory Checked
Payment Successful
Invoice Generated
Email Sent
SMS Sent

Notice:

The client now knows only one class:

    CheckoutFacade

instead of knowing

- Inventory
- Payment
- Invoice
- Email
- SMS

Tomorrow, if invoice generation changes,
only CheckoutFacade needs to change.

The client remains untouched.

Benefits:

- Hides system complexity.
- Reduces coupling.
- Provides one simple interface.
- Easier to maintain.
- Easier to reuse.

Real Backend Example:

Instead of writing

inventory.check();
payment.pay();
invoice.generate();
email.send();
sms.send();

everywhere,

the client simply writes

checkout.placeOrder();

Another Example:

UserService.createUser()

Internally it may

- Validate input
- Save user
- Send welcome email
- Publish Kafka event
- Write audit log

The controller only calls

userService.createUser();

UserService acts as the Facade.
*/