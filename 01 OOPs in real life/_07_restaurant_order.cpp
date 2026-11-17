// 01 OOPs in Real Life
// Concept: Real-life entities "MenuItem" and "Order"
//
// A restaurant order is made of multiple MenuItem objects.
// This shows composition: an Order HAS-A list of MenuItems.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MenuItem {
public:
    string name;
    double price;
    MenuItem(string n, double p) : name(n), price(p) {}
};

class Order {
private:
    vector<MenuItem> items;
public:
    void addItem(const MenuItem &m) {
        items.push_back(m);
        cout << "Added " << m.name << " (Rs. " << m.price << ")" << endl;
    }
    double total() const {
        double sum = 0;
        for (size_t i = 0; i < items.size(); i++) sum += items[i].price;
        return sum;
    }
    void printBill() const {
        cout << "\n----- BILL -----" << endl;
        for (size_t i = 0; i < items.size(); i++)
            cout << items[i].name << " : Rs. " << items[i].price << endl;
        cout << "Total : Rs. " << total() << endl;
        cout << "----------------" << endl;
    }
};

int main() {
    MenuItem m1("Burger", 120);
    MenuItem m2("Fries", 60);
    MenuItem m3("Coke", 40);

    Order order;
    order.addItem(m1);
    order.addItem(m2);
    order.addItem(m3);

    order.printBill();

    return 0;
}