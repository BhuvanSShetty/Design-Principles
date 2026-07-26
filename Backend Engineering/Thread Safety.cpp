#include <iostream>
#include <thread>
using namespace std;

/*
====================================================
WITHOUT THREAD SAFETY
====================================================

Problem:

Two threads increment the same counter.

*/

int counter = 0;

void increment() {

    for(int i = 0; i < 100000; i++) {

        counter++;

    }

}

int main() {

    thread t1(increment);

    thread t2(increment);

    t1.join();

    t2.join();

    cout << counter << endl;

}

/*

Expected:

200000

Actual:

198734
199112
199876

Every execution may produce
a different result.

Problems:

- Race Condition
- Data Corruption
- Unpredictable behaviour

====================================================
WITH THREAD SAFETY
====================================================

Solution:

Protect the shared resource
using a mutex.

*/

#include <mutex>

int safeCounter = 0;

mutex mtx;

void safeIncrement() {

    for(int i = 0; i < 100000; i++) {

        mtx.lock();

        safeCounter++;

        mtx.unlock();

    }

}

int main() {

    thread t1(safeIncrement);

    thread t2(safeIncrement);

    t1.join();

    t2.join();

    cout << safeCounter << endl;

}

/*

Output:

200000

Every execution gives
the correct result.

*/