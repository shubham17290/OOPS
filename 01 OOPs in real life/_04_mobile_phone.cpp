// 01 OOPs in Real Life
// Concept: Real-life entity "Mobile Phone"
//
// A phone has state (brand, battery, storage) and behaviors
// (call, charge, installApp). Different phones = different objects,
// each with its own state.

#include <iostream>
#include <string>
using namespace std;

class Mobile {
private:
    string brand;
    int battery;     // 0..100
    int storage;     // GB free

public:
    Mobile(string b, int bat, int stor) {
        brand = b;
        battery = (bat >= 0 && bat <= 100) ? bat : 100;
        storage = (stor >= 0) ? stor : 0;
    }

    void call(string to) {
        if (battery < 5) { cout << brand << ": battery too low to call!" << endl; return; }
        battery -= 5;
        cout << brand << " calling " << to << "... (battery " << battery << "%)" << endl;
    }
    void charge(int mins) {
        battery += mins / 2;
        if (battery > 100) battery = 100;
        cout << brand << " charged. Battery = " << battery << "%" << endl;
    }
    void installApp(string app, int size) {
        if (size > storage) { cout << brand << ": not enough storage for " << app << endl; return; }
        storage -= size;
        cout << brand << " installed " << app << ". Free storage = " << storage << " GB" << endl;
    }
    void status() {
        cout << "---- " << brand << " ----" << endl;
        cout << "Battery : " << battery << "%" << endl;
        cout << "Storage : " << storage << " GB free" << endl;
    }
};

int main() {
    Mobile phone1("iPhone 15", 80, 128);
    Mobile phone2("Samsung S24", 40, 64);

    phone1.call("Mom");
    phone1.installApp("WhatsApp", 30);
    phone1.status();

    cout << endl;

    phone2.call("Dad");
    phone2.charge(60);
    phone2.installApp("PUBG", 80);  // should fail (not enough storage)
    phone2.status();

    return 0;
}