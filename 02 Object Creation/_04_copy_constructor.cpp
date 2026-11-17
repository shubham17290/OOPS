#include <iostream>
#include <string>
using namespace std;

class Student {
  public:
    int id;
    int age;
    string name;
    int nos;

    // Parameterised ctor
    Student(int id, int age, string name, int nos) {
        cout << "Student Parameterised ctor called" << endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
    }

    // Copy ctor
    Student(const Student &other) {
        cout << "Student Copy ctor called" << endl;
        this->id = other.id;
        this->age = other.age;
        this->name = other.name;
        this->nos = other.nos;
    }

    // Behaviour / Methods / Functions
    void study() { cout << this->name << " Studying" << endl; }

    void sleep() { cout << this->name << " Sleeping" << endl; }
};

int main() {
    Student A(1, 20, "Shubham", 6);   // parameterized ctor
    Student B = A;                      // copy ctor
    A.study();
    B.sleep();
    return 0;
}
