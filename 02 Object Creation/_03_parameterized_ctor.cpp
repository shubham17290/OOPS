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

    // default ctor - needed because `Student A;` requires it
    Student() : id(0), age(0), name(""), nos(0) { cout << "student default ctor called" << endl; }

    // parameterized ctor - now actually initializes the members
    Student(int id, int age, string name, int nos) : id(id), age(age), name(name), nos(nos) {
        cout << "student parameterized ctor called" << endl;
    }

    // behaviors
    void study() { cout << name << " studying" << endl; }
    void sleeping() { cout << name << " sleeping" << endl; }
    void bunk() { cout << name << " bunking" << endl; }

    void print() {
        cout << "id=" << id << ", age=" << age << ", name=" << name << ", nos=" << nos << endl;
    }

    // destructor
    ~Student() { cout << "student dtor called for " << name << endl; }
};

int main() {
    Student A; // uses default ctor
    A.id = 1;
    A.age = 20;
    A.name = "Shubham";
    A.nos = 6;

    Student B(1, 20, "Rahul", 6); // uses parameterized ctor

    A.print();
    B.print();

    A.study();
    B.sleeping();
    B.bunk();

    return 0;
}
