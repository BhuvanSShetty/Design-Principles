#include <iostream>
#include <unordered_map>
#include <ctime>
using namespace std;

/*
====================================================
WITHOUT RATE LIMITING
====================================================

Problem:

Every request is accepted.

*/

class LoginService {

public:

    void login() {

        cout << "Login Request Accepted\n";

    }

};

int main() {

    LoginService service;

    for(int i=0;i<10;i++) {

        service.login();

    }

}

/*

Output:

Login Request Accepted
Login Request Accepted
Login Request Accepted
...

Problems:

- Unlimited requests
- Vulnerable to abuse
- Easy target for brute-force attacks
- Can overload the server

====================================================
WITH RATE LIMITING
====================================================

Solution:

Allow only 5 requests
per minute.

*/

class RateLimiter {

private:

    unordered_map<string,int> requestCount;

public:

    bool allowRequest(string user) {

        if(requestCount[user] >= 5) {

            return false;

        }

        requestCount[user]++;

        return true;

    }

};

int main() {

    RateLimiter limiter;

    for(int i=1;i<=7;i++) {

        if(limiter.allowRequest("bhuvan")) {

            cout << "Request Accepted\n";

        }

        else {

            cout << "Too Many Requests\n";

        }

    }

}

/*

Output:

Request Accepted
Request Accepted
Request Accepted
Request Accepted
Request Accepted
Too Many Requests
Too Many Requests

*/