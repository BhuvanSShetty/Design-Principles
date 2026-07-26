#include <iostream>
using namespace std;

/*
====================================================
WITHOUT SRP
====================================================

Problem:

The UserService class is responsible for:

1. Validating the user
2. Saving the user
3. Sending an email

If tomorrow the validation logic changes,
UserService changes.

If tomorrow the email provider changes,
UserService changes.

If tomorrow database logic changes,
UserService changes.

This class has multiple reasons to change.

*/

class UserService {

public:

    void registerUser(string name) {

        // Validation
        cout << "Validating User\n";

        // Save to database
        cout << "Saving User\n";

        // Send email
        cout << "Sending Welcome Email\n";

    }

};

int main() {

    UserService user;

    user.registerUser("Bhuvan");

}

/*

Problems:

- Multiple responsibilities
- Difficult to test
- Difficult to maintain
- Violates SRP

====================================================
WITH SRP
====================================================

Solution:

Separate each responsibility into its own class.

Each class now has only one reason to change.

*/

class UserValidator {

public:

    void validate(string name) {

        cout << "Validating User\n";

    }

};

class UserRepository {

public:

    void save(string name) {

        cout << "Saving User\n";

    }

};

class EmailService {

public:

    void sendWelcomeEmail(string name) {

        cout << "Sending Welcome Email\n";

    }

};

class UserService {

private:

    UserValidator validator;

    UserRepository repository;

    EmailService email;

public:

    void registerUser(string name) {

        validator.validate(name);

        repository.save(name);

        email.sendWelcomeEmail(name);

    }

};

int main() {

    UserService user;

    user.registerUser("Bhuvan");

}

/*

Output:

Validating User
Saving User
Sending Welcome Email

Notice:

UserService now only coordinates the process.

Validation belongs to UserValidator.

Database logic belongs to UserRepository.

Email logic belongs to EmailService.

Each class has exactly one responsibility.

*/