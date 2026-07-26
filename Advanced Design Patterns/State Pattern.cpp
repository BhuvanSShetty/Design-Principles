#include <iostream>
using namespace std;

/*
====================================================
WITHOUT STATE
====================================================

Problem:

Suppose we have an Order.

The Order can be in one of three states:

- Pending
- Shipped
- Delivered

The behaviour changes based on
the current state.

*/

class Order {

private:

    string state = "Pending";

public:

    void nextState() {

        if(state == "Pending") {

            cout << "Order Shipped\n";

            state = "Shipped";

        }
        else if(state == "Shipped") {

            cout << "Order Delivered\n";

            state = "Delivered";

        }
        else {

            cout << "Order Already Delivered\n";

        }

    }

};

// int main() {

//     Order order;

//     order.nextState();

//     order.nextState();

//     order.nextState();

// }

/*

Problems:

- Large if-else chain.
- Every new state modifies Order.
- Difficult to maintain.
- Violates Open/Closed Principle.

====================================================
STATE PATTERN
====================================================

Solution:

Move each state into its own class.

Order delegates its behaviour
to the current State object.

Changing state simply means
changing the current State object.

*/

// State Interface
class State {

public:

    virtual void next() = 0;

};

// State 1
class Pending : public State {

public:

    void next() override {

        cout << "Order Shipped\n";

    }

};

// State 2
class Shipped : public State {

public:

    void next() override {

        cout << "Order Delivered\n";

    }

};

// State 3
class Delivered : public State {

public:

    void next() override {

        cout << "Order Already Delivered\n";

    }

};

// Context
class Order {

private:

    State* state;

public:

    Order(State* state) {

        this->state = state;

    }

    void nextState() {

        state->next();

    }

};

int main() {

    Order pendingOrder(new Pending());

    pendingOrder.nextState();

    Order shippedOrder(new Shipped());

    shippedOrder.nextState();

    Order deliveredOrder(new Delivered());

    deliveredOrder.nextState();

}

/*

Output:

Order Shipped
Order Delivered
Order Already Delivered

Notice:

Order never checks

if(state == "...")

It simply delegates the work
to the current State object.

Adding a new state only requires
creating another State class.

*/