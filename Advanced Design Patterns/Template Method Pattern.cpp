#include <iostream>
using namespace std;

/*
====================================================
WITHOUT TEMPLATE METHOD
====================================================

Problem:

Suppose we want to prepare Tea and Coffee.

Both follow almost the same steps.

Tea:

Boil Water
Brew Tea
Pour into Cup
Add Lemon

Coffee:

Boil Water
Brew Coffee
Pour into Cup
Add Milk

Code:

class Tea {

public:

    void prepare() {

        cout << "Boil Water\n";
        cout << "Brew Tea\n";
        cout << "Pour into Cup\n";
        cout << "Add Lemon\n";

    }

};

class Coffee {

public:

    void prepare() {

        cout << "Boil Water\n";
        cout << "Brew Coffee\n";
        cout << "Pour into Cup\n";
        cout << "Add Milk\n";

    }

};

Problems:

- Duplicate code.
- Difficult to maintain.
- Common steps repeated.
- If the process changes,
  every class must change.

====================================================
TEMPLATE METHOD PATTERN
====================================================

Solution:

Move the common algorithm
into a base class.

Allow child classes to customize
only the steps that are different.

The algorithm remains fixed.

*/

// Base Class
class Beverage {

public:

    void prepare() {

        boilWater();

        brew();

        pourIntoCup();

        addIngredients();

    }

    void boilWater() {

        cout << "Boil Water\n";

    }

    void pourIntoCup() {

        cout << "Pour into Cup\n";

    }

    virtual void brew() = 0;

    virtual void addIngredients() = 0;

};

// Child Class
class Tea : public Beverage {

public:

    void brew() override {

        cout << "Brew Tea\n";

    }

    void addIngredients() override {

        cout << "Add Lemon\n";

    }

};

// Child Class
class Coffee : public Beverage {

public:

    void brew() override {

        cout << "Brew Coffee\n";

    }

    void addIngredients() override {

        cout << "Add Milk\n";

    }

};

int main() {

    Tea tea;

    tea.prepare();

    cout << endl;

    Coffee coffee;

    coffee.prepare();

}

/*

Output:

Boil Water
Brew Tea
Pour into Cup
Add Lemon

Boil Water
Brew Coffee
Pour into Cup
Add Milk

Notice:

The prepare() function is never
changed by child classes.

Only brew() and addIngredients()
are different.

*/