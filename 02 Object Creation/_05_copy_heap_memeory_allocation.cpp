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

    // Destructor (to track memory cleanup)
    ~Student() { cout << "Destructor called for " << this->name << endl; }
};

int main() {
    cout << "--- Stack Allocation ---" << endl;
    // 1. Stack allocation (Parameterized)
    Student A(1, 20, "Shubham", 6);

    // 2. Stack allocation (Copy Constructor)
    Student B = A;

    A.study();
    B.sleep();

    cout << "\n--- Heap Allocation ---" << endl;
    // 3. Heap allocation (Parameterized)
    // 'new' returns a pointer, so we use 'Student*'
    Student *C = new Student(2, 21, "Rahul", 8);

    // 4. Heap allocation (Copy Constructor)
    // We pass *C (dereferenced pointer) to copy it
    Student *D = new Student(*C);

    // Use '->' instead of '.' for pointers to access methods
    C->study();
    D->sleep();

    // --- IMPORTANT: Memory Cleanup ---
    // Heap memory does NOT get deleted automatically!
    delete C;
    delete D;

    cout << "\n--- End of Main ---" << endl;
    return 0;
}
