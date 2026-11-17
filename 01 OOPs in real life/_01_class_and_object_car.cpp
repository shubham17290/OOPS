// 01 OOPs in Real Life
// Concept: Class (blueprint) & Object (real instance)
//
// Real life: "Car" is a concept/blueprint. A specific car you drive
// (red Honda Civic, number plate KA-01-AB-1234) is an OBJECT.
//
// State (data)  : color, brand, speed, fuel
// Behavior (methods): accelerate(), brake(), honk()

#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    // ---- state (attributes) ----
    string brand;
    string color;
    int speed;
    int fuel;

    // ---- behavior (methods) ----
    void accelerate() {
        if (fuel <= 0) { cout << brand << " has no fuel!" << endl; return; }
        speed += 10;
        fuel -= 1;
        cout << brand << " accelerated. Speed = " << speed
             << " km/h, Fuel = " << fuel << " L" << endl;
    }
    void brake() {
        if (speed >= 10) speed -= 10;
        else speed = 0;
        cout << brand << " braked. Speed = " << speed << " km/h" << endl;
    }
    void honk() {
        cout << brand << ": Beep Beep!" << endl;
    }
    void status() {
        cout << "---- " << brand << " (" << color << ") ----" << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Fuel : " << fuel << " L" << endl;
    }
};

int main() {
    // Object 1: Shubham's car
    Car myCar;
    myCar.brand = "Honda Civic";
    myCar.color = "Red";
    myCar.speed = 0;
    myCar.fuel = 5;

    // Object 2: Friend's car
    Car friendsCar;
    friendsCar.brand = "Maruti Swift";
    friendsCar.color = "Blue";
    friendsCar.speed = 0;
    friendsCar.fuel = 3;

    cout << "=== Shubham's Car ===" << endl;
    myCar.accelerate();
    myCar.accelerate();
    myCar.honk();
    myCar.status();

    cout << "\n=== Friend's Car ===" << endl;
    friendsCar.accelerate();
    friendsCar.brake();
    friendsCar.status();

    // Each object has its OWN copy of state
    cout << "\nmyCar speed      : " << myCar.speed << endl;
    cout << "friendsCar speed : " << friendsCar.speed << endl;

    return 0;
}