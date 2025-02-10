#include <iostream>

using namespace std;

class Account
{
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account()
    {
        balance = 0;
    }

    Account(string an, string ahn, double b)
    {
        accountNumber = an;
        accountHolderName = ahn;
        balance = b;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount >= balance)
        {
            cout << "Insufficient Balance" << endl;
            return;
        }

        balance -= amount;
        cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
    }

    void checkBalance() const
    {
        cout << "BAL: " << balance << endl;
    }
};

int main()
{
    Account acc1("123456", "Alice", 500.0);
    Account acc2("789101", "Bob", 1000.0);

    cout << "Account 1 - Initial Balance: ";
    acc1.checkBalance();

    cout << "Account 2 - Initial Balance: ";
    acc2.checkBalance();

    acc1.deposit(200.0);
    acc1.withdraw(100.0);

    acc2.deposit(500.0);
    acc2.withdraw(1600.0);

    cout << "Account 1 - Final Balance: ";
    acc1.checkBalance();

    cout << "Account 2 - Final Balance: ";
    acc2.checkBalance();

    return 0;
}
