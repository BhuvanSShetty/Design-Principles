#include <iostream>
#include <queue>
using namespace std;

/*
====================================================
WITHOUT MESSAGE QUEUE
====================================================

Problem:

Every request immediately
calls the Email Service.

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

    cout << "Response Sent\n";

}

/*

Output:

Order Created
Sending Email...
Response Sent

Problems:

- Client waits.
- Slow response.
- Tight coupling.
- If Email Service crashes,
  request fails.

====================================================
WITH MESSAGE QUEUE
====================================================

Solution:

Push requests into a queue.

Worker processes them later.

*/

class MessageQueue {

private:

    queue<string> messages;

public:

    void publish(string message) {

        messages.push(message);

    }

    void consume() {

        while(!messages.empty()) {

            cout << "Processing: "
                 << messages.front()
                 << endl;

            messages.pop();

        }

    }

};

int main() {

    MessageQueue queue;

    cout << "Order Created\n";

    queue.publish("Send Welcome Email");

    cout << "Response Sent Immediately\n";

    queue.consume();

}

/*

Output:

Order Created
Response Sent Immediately
Processing: Send Welcome Email

Notice:

The client doesn't wait
for the email.

*/