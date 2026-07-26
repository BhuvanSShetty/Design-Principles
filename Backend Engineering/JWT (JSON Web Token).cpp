#include <iostream>
using namespace std;

/*
====================================================
WITHOUT JWT
====================================================

Problem:

Every request requires
username and password.

*/

class AuthService {

public:

    bool authenticate(string username,
                      string password) {

        return username == "bhuvan"
            && password == "password123";

    }

};

int main() {

    AuthService auth;

    if(auth.authenticate("bhuvan",
                         "password123")) {

        cout << "Access Granted\n";

    }

}

/*

Problems:

- Password sent repeatedly.
- More database lookups.
- Slower requests.

====================================================
WITH JWT
====================================================

Solution:

Login once.

Generate a JWT.

Future requests send only
the JWT.

*/

class JWTService {

public:

    string generateToken() {

        return "JWT_TOKEN_ABC123";

    }

    bool verifyToken(string token) {

        return token == "JWT_TOKEN_ABC123";

    }

};

int main() {

    JWTService jwt;

    string token =
        jwt.generateToken();

    cout << "Generated Token: "
         << token << endl;

    if(jwt.verifyToken(token)) {

        cout << "Access Granted\n";

    }

}

/*

Output:

Generated Token: JWT_TOKEN_ABC123

Access Granted

*/