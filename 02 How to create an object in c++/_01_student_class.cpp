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
    // brhaviors /methods /functions
    void study() { cout << this->name << "studying : " << endl; }
    void sleeping() { cout << this->name << "sleeping : " << endl; }
    void bunck() { cout << this->name << "buncking : " << endl; }
};
int main() {
    Student A;
    A.id = 1;
    A.age = 20;
    A.name = "Shubham";
    A.nos = 6;
    return 0;
}
