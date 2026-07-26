#include <iostream>
using namespace std;

/*
====================================================
WITHOUT COMMAND
====================================================

Problem:

The Remote directly controls the TV.

Whenever a new operation is added,
the Remote class must be modified.

Code:

class TV {

public:

    void on() {

        cout << "TV Turned ON\n";

    }

};

class Remote {

private:

    TV tv;

public:

    void pressButton() {

        tv.on();

    }

};

int main() {

    Remote remote;

    remote.pressButton();

}

Problems:

- Remote depends directly on TV.
- Difficult to support multiple commands.
- No undo functionality.
- Cannot queue commands.
- Tight coupling.

====================================================
COMMAND PATTERN
====================================================

Solution:

Create a Command interface.

Each operation becomes a separate Command object.

The Remote executes Commands instead of
calling TV directly.

*/

// Receiver
class TV {

public:

    void on() {

        cout << "TV Turned ON\n";

    }

};

// Command Interface
class Command {

public:

    virtual void execute() = 0;

};

// Concrete Command
class TurnOnCommand : public Command {

private:

    TV* tv;

public:

    TurnOnCommand(TV* tv) {

        this->tv = tv;

    }

    void execute() override {

        tv->on();

    }

};

// Invoker
class Remote {

private:

    Command* command;

public:

    Remote(Command* command) {

        this->command = command;

    }

    void pressButton() {

        command->execute();

    }

};

int main() {

    TV tv;

    Command* command = new TurnOnCommand(&tv);

    Remote remote(command);

    remote.pressButton();

}

/*

Output:

TV Turned ON

Notice:

The Remote does not know anything about TV.

It simply executes a Command.

Tomorrow we can add:

- TurnOffCommand
- VolumeUpCommand
- MuteCommand

without changing the Remote.

*/