#include <iostream>
#include <unordered_set>
using namespace std;

/*
====================================================
WITHOUT IDEMPOTENCY
====================================================

Problem:

Every payment request
creates a new payment.

*/

class PaymentService {

public:

    void processPayment(string orderId) {

        cout << "Payment Processed for "
             << orderId << endl;

    }

};

int main() {

    PaymentService payment;

    payment.processPayment("ORDER101");

    payment.processPayment("ORDER101");

}

/*

Output:

Payment Processed for ORDER101
Payment Processed for ORDER101

Problems:

- Duplicate payment
- Customer charged twice
- Duplicate invoices
- Duplicate emails

====================================================
WITH IDEMPOTENCY
====================================================

Solution:

Every request carries
an Idempotency Key.

If the key has already been processed,
ignore the duplicate request.

*/

class PaymentService {

private:

    unordered_set<string> processedRequests;

public:

    void processPayment(string requestId) {

        if(processedRequests.count(requestId)) {

            cout << "Duplicate Request Ignored\n";

            return;

        }

        processedRequests.insert(requestId);

        cout << "Payment Processed\n";

    }

};

int main() {

    PaymentService payment;

    payment.processPayment("REQ-123");

    payment.processPayment("REQ-123");

}

/*

Output:

Payment Processed
Duplicate Request Ignored

Only one payment is processed.

*/