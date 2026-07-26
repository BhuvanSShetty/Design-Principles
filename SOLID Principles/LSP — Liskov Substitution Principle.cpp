#include <iostream>
using namespace std;

/*
====================================================
WITHOUT LSP
====================================================

Problem:

Assume every Bird can fly.

Since Penguin is also a Bird,
it inherits fly().

But Penguins cannot fly.

This breaks the expectation that every
Bird can fly.

*/

class Bird {

public:

    virtual void fly() {

        cout << "Bird is flying\n";

    }

};

class Sparrow : public Bird {

public:

    void fly() {

        cout << "Sparrow is flying\n";

    }

};

class Penguin : public Bird {

public:

    void fly()  {

        throw runtime_error("Penguins cannot fly!");

    }

};

// void makeBirdFly(Bird* bird) {

//     bird->fly();

// }

// int main() {

//     Sparrow sparrow;

//     Penguin penguin;

//     makeBirdFly(&sparrow);

//     makeBirdFly(&penguin);

// }

/*

Problems:

- Penguin cannot replace Bird.
- Program crashes.
- Child class changes expected behaviour.
- Violates Liskov Substitution Principle.

====================================================
WITH LSP
====================================================

Solution:

Do not force Penguin to inherit behaviour
that it cannot support.

Create separate abstractions.

*/

class Bird {

public:


    virtual void eat() {

        cout << "Bird is eating\n";

    }

};

class FlyingBird : public Bird {

public:

    virtual void fly() {

        cout << "Flying Bird\n";

    }

};

class Sparrow : public FlyingBird {

public:

    void fly() override {

        cout << "Sparrow is flying\n";

    }

};

class Penguin : public Bird {

public:

    void eat() {

        cout << "Penguin is eating\n";

    }

};

int main() {

    Sparrow sparrow;

    Penguin penguin;

    sparrow.fly();

    penguin.eat();

}

/*

Output:

Sparrow is flying
Penguin is eating

Notice:

Penguin is no longer forced to implement
fly().

Each class behaves correctly.

Any FlyingBird can safely replace another
FlyingBird.

*/