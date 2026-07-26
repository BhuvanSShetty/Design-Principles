#include <iostream>
#include <vector>
using namespace std;

/*
====================================================
WITHOUT OBSERVER
====================================================

Problem:

Suppose we have a YouTube Channel.

Whenever a new video is uploaded,
every subscriber should receive a notification.

Without Observer, the Channel explicitly
calls every subscriber.

Code:

class Channel {

public:

    void uploadVideo() {

        cout << "Video Uploaded\n";

        notifyAlice();
        notifyBob();
        notifyCharlie();

    }

    void notifyAlice() {
        cout << "Alice Notified\n";
    }

    void notifyBob() {
        cout << "Bob Notified\n";
    }

    void notifyCharlie() {
        cout << "Charlie Notified\n";
    }

};

int main() {

    Channel channel;

    channel.uploadVideo();

}

Problems:

- Channel knows every subscriber.
- New subscriber requires modifying Channel.
- Tight coupling.
- Difficult to maintain.
- Violates Open/Closed Principle.

====================================================
OBSERVER PATTERN
====================================================

Solution:

Create a common Observer interface.

The Channel stores a list of observers.

Whenever something changes,
the Channel simply notifies every observer.

The Channel never needs to know who the
actual subscribers are.
*/

// Common Observer Interface
class Observer {

public:

    virtual void update() = 0;

};

// Concrete Observer
class Subscriber : public Observer {

private:

    string name;

public:

    Subscriber(string name) {

        this->name = name;

    }

    void update() override {

        cout << name << " received notification\n";

    }

};

// Subject
class Channel {

private:

    vector<Observer*> subscribers;

public:

    void subscribe(Observer* observer) {

        subscribers.push_back(observer);

    }

    void notifyAll() {

        for(auto observer : subscribers) {

            observer->update();

        }

    }

    void uploadVideo() {

        cout << "Video Uploaded\n";

        notifyAll();

    }

};

int main() {

    Channel channel;

    Subscriber s1("Alice");
    Subscriber s2("Bob");
    Subscriber s3("Charlie");

    channel.subscribe(&s1);
    channel.subscribe(&s2);
    channel.subscribe(&s3);

    channel.uploadVideo();

}

/*
Output:

Video Uploaded

Alice received notification
Bob received notification
Charlie received notification

Notice:

The Channel no longer knows:

- Alice
- Bob
- Charlie

It only knows:

Observer*

Tomorrow if David subscribes,

Subscriber s4("David");
channel.subscribe(&s4);

No changes are required inside Channel.

Benefits:

- Loose coupling.
- Easy to add/remove subscribers.
- One event automatically notifies everyone.
- Follows Open/Closed Principle.
*/