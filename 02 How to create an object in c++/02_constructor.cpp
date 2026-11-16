#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    // attributes
    int id;
    int age;
    string name;
    int nos;

    // default constructor
    Student() : id(0), age(0), name(""), nos(0) {
        cout << "student default ctor is called" << endl;
    }

    // parameterized constructor (optional but convenient)
    Student(int id, int age, string name, int nos) : id(id), age(age), name(name), nos(nos) {
        cout << "student parameterized ctor is called" << endl;
    }

    // behaviors / methods
    void study() { cout << this->name << " studying :" << endl; }
    void sleeping() { cout << this->name << " sleeping :" << endl; }
    void bunk() { cout << this->name << " bunking :" << endl; }

    // destructor
    ~Student() { cout << "student default dtor called" << endl; }
};

int main() {
    Student A; // creation of the object
    A.id = 1;
    A.age = 20;
    A.name = "Shubham";
    A.nos = 6;

    A.study();
    A.sleeping();
    A.bunk();
    return 0;
}
