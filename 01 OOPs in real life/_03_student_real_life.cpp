// 01 OOPs in Real Life
// Concept: Real-life entity "Student" modeled as a class
//
// A student has identity (id), state (age, name, marks) and
// behaviors (study, play, takeExam). Multiple students = multiple objects.

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    int marks;

    void study() {
        cout << name << " is studying." << endl;
    }
    void play() {
        cout << name << " is playing." << endl;
    }
    void takeExam() {
        cout << name << " is taking an exam (marks = " << marks << ")." << endl;
    }
    void introduce() {
        cout << "Hi, I am " << name << ", age " << age
             << ", roll no. " << id << "." << endl;
    }
};

int main() {
    Student s1, s2;

    s1.id = 1; s1.name = "Shubham"; s1.age = 20; s1.marks = 85;
    s2.id = 2; s2.name = "Priya";    s2.age = 19; s2.marks = 92;

    s1.introduce();
    s1.study();
    s1.takeExam();

    cout << endl;

    s2.introduce();
    s2.play();
    s2.takeExam();

    return 0;
}