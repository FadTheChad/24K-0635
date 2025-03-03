#include <iostream>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int aN, string aHN, double b) : accountNumber(aN), accountHolderName(aHN), balance(b) {}

    void deposit(double amount)
    {
        balance += amount;

        cout << endl
             << "Deposited " << amount << endl
             << endl;
    }

    void withdraw(double amount)
    {
        if (balance < amount)
        {
            cout << endl
                 << "Insufficient balance" << endl
                 << endl;
            return;
        }

        balance -= amount;

        cout << endl
             << "Withdrew " << amount << endl
             << endl;
    }

    void display()
    {
        cout << endl;
        cout << "\t\t=====================" << endl;
        cout << "\t\t|| ACCOUNT DETAILS ||" << endl;
        cout << "\t\t=====================" << endl
             << endl;
        cout << "ACC NO\t\tACC HOLDER NAME\t\tBALANCE" << endl;
        cout << accountNumber << "\t\t" << accountHolderName << "\t\t" << balance << endl;
    }
};

int main()
{
    BankAccount accounts[3] = {BankAccount(1, "Fadil Faisal", 5000), BankAccount(2, "Ahmed Rashidi", 0), BankAccount(3, "Zain Ahmad", 1000)};

    for (int i = 0; i < 3; i++)
    {
        BankAccount account = accounts[i];
        account.display();

        account.deposit(500.0);
        account.display();

        account.withdraw(200.0);
        account.display();
    }

    return 0;
}