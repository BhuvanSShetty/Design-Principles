#include <iostream>
using namespace std;

/*
====================================================
WITHOUT OAUTH
====================================================

Problem:

Application asks for
the user's password.

*/

class Google {

public:

    bool login(string username,
               string password) {

        return username == "bhuvan@gmail.com"
            && password == "password123";

    }

};

int main() {

    Google google;

    if(google.login("bhuvan@gmail.com",
                    "password123")) {

        cout << "Access Granted\n";

    }

}

/*

Problems:

- Password shared with third-party.
- Security risk.
- User must trust every application.

====================================================
WITH OAUTH
====================================================

Solution:

Google authenticates the user.

Google returns an Access Token.

The application never sees
the user's password.

*/

class GoogleOAuth {

public:

    string authorize() {

        return "ACCESS_TOKEN_ABC123";

    }

};

class Application {

public:

    void login(string accessToken) {

        if(accessToken == "ACCESS_TOKEN_ABC123") {

            cout << "Login Successful\n";

        }

    }

};

int main() {

    GoogleOAuth google;

    string token =
        google.authorize();

    Application app;

    app.login(token);

}

/*

Output:

Login Successful

Notice:

The application never receives
the user's password.

*/