// 01 OOPs in Real Life
// Concept: State & Behavior using a Bank Account
//
// Real life: A bank account has private state (balance) that NOBODY
// can touch directly. You interact only through behaviors (deposit,
// withdraw, checkBalance). This is encapsulation in real life.

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    // state is hidden (private) — like a bank vault
    string owner;
    double balance;

public:
    // constructor sets initial state safely
    BankAccount(string name, double initial) {
        owner = name;
        balance = (initial >= 0) ? initial : 0;
    }

    // behavior: deposit money
    void deposit(double amt) {
        if (amt <= 0) { cout << "Invalid deposit amount!" << endl; return; }
        balance += amt;
        cout << owner << " deposited " << amt
             << ". New balance = " << balance << endl;
    }

    // behavior: withdraw money
    void withdraw(double amt) {
        if (amt <= 0) { cout << "Invalid amount!" << endl; return; }
        if (amt > balance) { cout << "Insufficient funds!" << endl; return; }
        balance -= amt;
        cout << owner << " withdrew " << amt
             << ". New balance = " << balance << endl;
    }

    // behavior: read-only access to balance
    double getBalance() const { return balance; }
    string getOwner() const { return owner; }
};

int main() {
    BankAccount acc1("Shubham", 1000);
    BankAccount acc2("Rahul", 500);

    acc1.deposit(500);
    acc1.withdraw(200);
    acc1.withdraw(5000);   // should fail

    acc2.deposit(100);
    acc2.withdraw(600);    // should fail

    cout << "\n" << acc1.getOwner() << " final balance: " << acc1.getBalance() << endl;
    cout << acc2.getOwner() << " final balance: " << acc2.getBalance() << endl;

    // acc1.balance = 999999;  // ❌ compile error — state is protected!

    return 0;
}