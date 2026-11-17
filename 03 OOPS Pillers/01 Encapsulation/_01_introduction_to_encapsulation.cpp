// there is mainly four pillers of the encapsulation of the oops
//  and the very first one is : encapsulation
#include <iostream>
using namespace std;
class student {

  public:
    int id;
    int nos;
    int age;
    string name;

  private:
    string gf;

    //    methods / functions
    //  study
  public:
    void study() { cout << "student is studying : " << endl; }
    //  sleep
    void sleeping() { cout << "student is sleeping : " << endl; }
    // chatting
    void gfchatting() { cout << "student is chatting with his gf: " << endl; }
    // bunk
    void bunk() { cout << "student is bunking : " << endl; }
};

int main() {

    student A;
    A.study();

    return 0;
}
