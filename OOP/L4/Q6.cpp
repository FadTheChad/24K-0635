#include <iostream>
#include <iomanip>
using namespace std;

class Bank
{
    string accountNumber;
    string ownerName;
    double balance;

public:
    Bank()
    {
        accountNumber = "";
        ownerName = "";
        balance = 0.0;
    }

    Bank(string accountNumber, string ownerName, double balance = 0.0)
    {
        this->accountNumber = accountNumber;
        this->ownerName = ownerName;
        this->balance = balance;
    }

    void depositMoney()
    {
        if (accountNumber == "" || ownerName == "")
        {
            cout << "No account details found. Please create an account first." << endl;
            return;
        }

        double amount;
        cout << "Enter the deposit amount: ";
        cin >> amount;
        balance += amount;
        cout << "Success! $" << fixed << setprecision(2) << amount << " has been added to your account." << endl;
    }

    void withdrawMoney()
    {
        if (accountNumber == "" || ownerName == "")
        {
            cout << "No account details found. Please create an account first." << endl;
            return;
        }

        double amount;
        cout << "Enter the withdrawal amount: ";
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient funds! Your current balance is $" << fixed << setprecision(2) << balance << "." << endl;
            return;
        }

        balance -= amount;
        cout << "Transaction successful! You have withdrawn $" << fixed << setprecision(2) << amount << "." << endl;
    }

    void displayDetails()
    {
        if (accountNumber == "" || ownerName == "")
        {
            cout << "No account details found. Please create an account first." << endl;
            return;
        }

        cout << "\n--- Account Information ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << ownerName << endl;
        cout << "Available Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

int main()
{
    Bank b1;
    int choice;

    cout << "===== Welcome to iBank =====" << endl;
    cout << "1 - Open a new account" << endl;
    cout << "2 - Deposit funds" << endl;
    cout << "3 - Withdraw funds" << endl;
    cout << "4 - View account details" << endl;
    cout << "5 - Exit" << endl;

    while (true)
    {
        cout << "\nSelect an option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string accNum, name;
            double balance; 
            cin.ignore();
            cout << "Enter a new account number: ";
            getline(cin, accNum);
            cout << "Enter the account holder's name: ";
            getline(cin, name);
            cout << "Enter initial deposit amount: ";
            cin >> balance;
            b1 = Bank(accNum, name, balance);
            cout << "Account successfully created!" << endl;
            break;
        }
        case 2:
            b1.depositMoney();
            break;
        case 3:
            b1.withdrawMoney();
            break;
        case 4:
            b1.displayDetails();
            break;
        case 5:
            cout << "Thank you for using iBank! Goodbye." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please select a valid option." << endl;
        }
    }
}
