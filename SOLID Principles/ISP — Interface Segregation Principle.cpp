#include <iostream>
using namespace std;

/*
====================================================
WITHOUT ISP
====================================================

Problem:

Suppose we have one interface called Machine.

Every machine must implement:

- print()
- scan()
- fax()

But a BasicPrinter only knows how to print.

It is forced to implement scan() and fax()
even though it doesn't support them.

*/

class Machine {

public:

    virtual void print() = 0;

    virtual void scan() = 0;

    virtual void fax() = 0;

};

class BasicPrinter : public Machine {

public:

    void print() override {

        cout << "Printing Document\n";

    }

    void scan() override {

        throw runtime_error("Scan Not Supported");

    }

    void fax() override {

        throw runtime_error("Fax Not Supported");

    }

};

int main() {

    BasicPrinter printer;

    printer.print();

}

/*

Problems:

- Classes implement methods they don't need.
- Unsupported operations throw exceptions.
- Large interfaces.
- Violates Interface Segregation Principle.

====================================================
WITH ISP
====================================================

Solution:

Break one large interface into
multiple smaller interfaces.

Each class implements only the
interfaces it actually needs.

*/

class Printer {

public:

    virtual void print() = 0;

};

class Scanner {

public:

    virtual void scan() = 0;

};

class Fax {

public:

    virtual void fax() = 0;

};

class BasicPrinter : public Printer {

public:

    void print() override {

        cout << "Printing Document\n";

    }

};

class MultiFunctionPrinter :
    public Printer,
    public Scanner,
    public Fax {

public:

    void print() override {

        cout << "Printing Document\n";

    }

    void scan() override {

        cout << "Scanning Document\n";

    }

    void fax() override {

        cout << "Sending Fax\n";

    }

};

int main() {

    BasicPrinter printer;

    printer.print();

    MultiFunctionPrinter officeMachine;

    officeMachine.print();
    officeMachine.scan();
    officeMachine.fax();

}

/*

Output:

Printing Document

Printing Document
Scanning Document
Sending Fax

Notice:

BasicPrinter only implements
what it supports.

MultiFunctionPrinter implements
all three interfaces because it
supports all three operations.

*/