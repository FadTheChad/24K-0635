#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount() { balance = 0.0; }
    BankAccount(double b) { balance = b; }
    BankAccount(const BankAccount &other) { balance = other.balance; }
    double getBalance() const { return balance; }
    void deduct(double amount) { if (amount <= balance) balance -= amount; }
};

int main() {
    BankAccount account1;
    cout << "ACC 1: " << account1.getBalance() << endl;

    BankAccount account2(1000.0);
    cout << "ACC 2: " << account2.getBalance() << endl;

    BankAccount account3(account2);
    account3.deduct(200);
    cout << "ACC 3: " << account3.getBalance() << endl;
    cout << "ACC 2: " << account2.getBalance() << endl; // yeh change nahi hoga

    return 0;
}