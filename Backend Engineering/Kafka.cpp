#include <iostream>
#include <queue>
using namespace std;

/*
====================================================
WITHOUT KAFKA
====================================================

Problem:

Order Service directly calls
multiple services.

*/

class EmailService {

public:

    void sendEmail() {

        cout << "Email Sent\n";

    }

};

class InventoryService {

public:

    void updateInventory() {

        cout << "Inventory Updated\n";

    }

};

int main() {

    EmailService email;

    InventoryService inventory;

    cout << "Order Created\n";

    email.sendEmail();

    inventory.updateInventory();

}

/*

Problems:

- Tight coupling.
- Difficult to add new services.
- One slow service slows everything.

====================================================
WITH KAFKA
====================================================

Solution:

Order Service publishes an event.

Consumers process it independently.

*/

class Kafka {

private:

    queue<string> events;

public:

    void publish(string event) {

        events.push(event);

    }

    void consume(string consumerName) {

        queue<string> temp = events;

        while(!temp.empty()) {

            cout << consumerName
                 << " processed : "
                 << temp.front()
                 << endl;

            temp.pop();

        }

    }

};

int main() {

    Kafka kafka;

    kafka.publish("Order Created");

    kafka.consume("Email Service");

    kafka.consume("Inventory Service");

    kafka.consume("Analytics Service");

}

/*

Output:

Email Service processed : Order Created

Inventory Service processed : Order Created

Analytics Service processed : Order Created

Notice:

Multiple consumers
can process the same event.

*/