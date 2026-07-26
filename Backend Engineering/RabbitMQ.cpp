#include <iostream>
#include <queue>
using namespace std;

/*
====================================================
WITHOUT RABBITMQ
====================================================

Problem:

Order Service directly sends email.

*/

class EmailService {

public:

    void sendEmail() {

        cout << "Sending Email...\n";

    }

};

int main() {

    EmailService email;

    cout << "Order Created\n";

    email.sendEmail();

    cout << "Order Completed\n";

}

/*

Problems:

- Client waits.
- Tight coupling.
- If Email Service fails,
  Order Service also fails.

====================================================
WITH RABBITMQ
====================================================

Solution:

Producer sends message
to RabbitMQ.

Consumer processes it later.

*/

class RabbitMQ {

private:

    queue<string> tasks;

public:

    void publish(string task) {

        tasks.push(task);

    }

    void consume() {

        while(!tasks.empty()) {

            cout << "Processing: "
                 << tasks.front()
                 << endl;

            tasks.pop();

        }

    }

};

int main() {

    RabbitMQ rabbit;

    cout << "Order Created\n";

    rabbit.publish("Send Email");

    cout << "Order Response Sent\n";

    rabbit.consume();

}

/*

Output:

Order Created

Order Response Sent

Processing: Send Email

Notice:

Client receives response
before email processing starts.

*/