#include <iostream>
#include <string>

class Person {
protected:
    std::string name;

public:
    explicit Person(std::string personName) : name(std::move(personName)) {}

    void introduce() const {
        std::cout << "I am " << name << '\n';
    }
};

class Student : public Person {
private:
    int rollNumber;

public:
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {}

    void showDetails() const {
        introduce();
        std::cout << "Roll number: " << rollNumber << '\n';
    }
};

int main() {
    Student student("Noah", 42);
    student.showDetails();
    return 0;
}