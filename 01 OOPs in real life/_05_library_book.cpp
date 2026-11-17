// 01 OOPs in Real Life
// Concept: Real-life entity "Library Book"
//
// A book has state (title, author, isIssued) and behaviors
// (issue, return, display). The library manages many book objects.

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool isIssued;

public:
    Book(string t, string a) {
        title = t;
        author = a;
        isIssued = false;
    }

    void issue(string to) {
        if (isIssued) { cout << "'" << title << "' already issued!" << endl; return; }
        isIssued = true;
        cout << "'" << title << "' issued to " << to << "." << endl;
    }
    void returnBook() {
        if (!isIssued) { cout << "'" << title << "' was not issued." << endl; return; }
        isIssued = false;
        cout << "'" << title << "' returned. Thank you!" << endl;
    }
    void display() const {
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Status : " << (isIssued ? "Issued" : "Available") << endl;
    }
};

int main() {
    Book b1("Clean Code", "Robert C. Martin");
    Book b2("The Pragmatic Programmer", "Andrew Hunt");

    b1.display();
    cout << endl;
    b1.issue("Shubham");
    b1.issue("Rahul");   // already issued
    cout << endl;
    b1.returnBook();
    b1.display();

    cout << "\n--- Second book ---" << endl;
    b2.display();

    return 0;
}