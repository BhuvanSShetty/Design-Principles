#include <iostream>
using namespace std;

/*
====================================================
WITHOUT DECORATOR
====================================================

Problem:

Suppose we have a Coffee class.

Initially, coffee costs £100.

Tomorrow the customer wants:

- Milk (+£20)
- Sugar (+£10)
- Cream (+£30)

Without Decorator, we keep creating new classes.

Code:

class Coffee {
public:
    int cost() {
        return 100;
    }
};

class CoffeeWithMilk {
public:
    int cost() {
        return 120;
    }
};

class CoffeeWithMilkSugar {
public:
    int cost() {
        return 130;
    }
};

class CoffeeWithMilkSugarCream {
public:
    int cost() {
        return 160;
    }
};

int main() {

    CoffeeWithMilkSugar coffee;

    cout << coffee.cost();

}

Problems:

- Too many classes.
- Every new combination requires another class.
- Existing classes must be modified frequently.
- Difficult to maintain.

====================================================
DECORATOR PATTERN
====================================================

Solution:

Keep the original Coffee class unchanged.

Instead of modifying it,
wrap it with Decorator classes.

Each Decorator adds one extra behaviour.

Multiple decorators can be combined at runtime.

*/

// Common Interface
class Coffee {

public:

    virtual int cost() = 0;

};

// Original Object
class SimpleCoffee : public Coffee {

public:

    int cost() override {

        return 100;

    }

};

// Decorator 1
class MilkDecorator : public Coffee {

private:

    Coffee* coffee;

public:

    MilkDecorator(Coffee* coffee) {

        this->coffee = coffee;

    }

    int cost() override {

        return coffee->cost() + 20;

    }

};

// Decorator 2
class SugarDecorator : public Coffee {

private:

    Coffee* coffee;

public:

    SugarDecorator(Coffee* coffee) {

        this->coffee = coffee;

    }

    int cost() override {

        return coffee->cost() + 10;

    }

};

int main() {

    Coffee* coffee = new SimpleCoffee();

    coffee = new MilkDecorator(coffee);

    coffee = new SugarDecorator(coffee);

    cout << coffee->cost();

}

/*
Output:

130

Execution:

SimpleCoffee

Cost = 100

↓

MilkDecorator

Cost = 120

↓

SugarDecorator

Cost = 130

Notice:

The SimpleCoffee class was never modified.

Each Decorator wraps the previous object
and adds new behaviour.

Tomorrow if we need Cream,

we simply create

class CreamDecorator

without modifying any existing classes.

Benefits:

- Existing classes remain unchanged.
- Behaviour can be added dynamically.
- Avoids creating many subclasses.
- Follows Open/Closed Principle.

Real Backend Example:

Express Middleware

Request

↓

Authentication Middleware

↓

Logging Middleware

↓

Compression Middleware

↓

Controller

Each middleware wraps the request,
adds behaviour,
and passes it to the next middleware.
*/