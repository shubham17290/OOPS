// 01 OOPs in Real Life
// Concept: Real-life entity "ATM Machine"
//
// An ATM has state (cashAvailable, cardInserted) and behaviors
// (insertCard, withdrawCash, checkBalance). It interacts with a
// BankAccount object — showing how objects collaborate in real life.

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount(double b) : balance(b >= 0 ? b : 0) {}
    bool withdraw(double amt) {
        if (amt <= 0 || amt > balance) return false;
        balance -= amt; return true;
    }
    double getBalance() const { return balance; }
};

class ATM {
private:
    double cashInMachine;
public:
    ATM(double cash) : cashInMachine(cash >= 0 ? cash : 0) {}

    void withdrawCash(BankAccount &acc, double amt) {
        cout << "ATM: requesting withdrawal of " << amt << "..." << endl;
        if (amt > cashInMachine) { cout << "ATM: not enough cash in machine!" << endl; return; }
        if (!acc.withdraw(amt)) { cout << "ATM: transaction declined (insufficient balance)." << endl; return; }
        cashInMachine -= amt;
        cout << "ATM: please collect your cash. Remaining account balance = "
             << acc.getBalance() << endl;
    }
    void checkBalance(BankAccount &acc) {
        cout << "ATM: your balance is " << acc.getBalance() << endl;
    }
};

int main() {
    BankAccount acc(5000); // account balance
    ATM atm(10000);

    atm.checkBalance(acc);
    atm.withdrawCash(acc, 1200);
    atm.withdrawCash(acc, 10000);  // should fail (insufficient balance)
    atm.checkBalance(acc);

    return 0;
}