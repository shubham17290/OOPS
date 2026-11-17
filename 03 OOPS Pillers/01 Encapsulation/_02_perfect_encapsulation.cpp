// Perfect Encapsulation: hide ALL data members, expose only a controlled
// public interface. No external code can touch the state directly.
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    int age;
    string name;
    string gf;          // completely hidden — never exposed

public:
    // constructor initializes state safely
    Student(int id, int age, string name) {
        this->id = id;
        this->age = (age > 0) ? age : 0;   // validation in constructor
        this->name = name;
    }

    // getters — read-only access to selected state
    int getId() const { return id; }
    int getAge() const { return age; }
    string getName() const { return name; }

    // setters — controlled mutation with validation
    void setAge(int newAge) {
        if (newAge > 0 && newAge < 120) {
            age = newAge;
        } else {
            cout << "Invalid age!" << endl;
        }
    }

    void setName(string newName) {
        if (!newName.empty()) {
            name = newName;
        }
    }

    // behavior that uses hidden state internally
    void study() { cout << name << " is studying." << endl; }
    void sleep()  { cout << name << " is sleeping." << endl; }

    // gf is private: only internal methods may reference it
    void chatWithGf() { cout << name << " is chatting with his gf." << endl; }
};

int main() {
    Student A(1, 20, "Shubham");
    A.study();
    A.setAge(21);
    cout << "Age after update: " << A.getAge() << endl;

    // A.id = 99;   // ❌ compile error — perfectly encapsulated
    // A.gf = "..."; // ❌ compile error — hidden completely

    return 0;
}
