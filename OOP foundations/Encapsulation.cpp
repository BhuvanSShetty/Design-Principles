#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(std::string accountOwner, double initialBalance)
        : owner(std::move(accountOwner)), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    void display() const {
        std::cout << owner << " balance: " << balance << '\n';
    }
};

int main() {
    BankAccount account("Ava", 1000.0);
    account.deposit(250.0);
    account.withdraw(125.0);
    account.display();
    return 0;
}