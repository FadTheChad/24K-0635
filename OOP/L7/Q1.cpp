#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account
{
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
    string *transactionHistory;
    int transactionCount;
    int transactionCapacity;

public:
    Account(string accNum, string holderName, double initialBalance, string type = "")
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance), accountType(type), transactionCount(0), transactionCapacity(10)
    {
        transactionHistory = new string[transactionCapacity];
    }

    virtual ~Account()
    {
        delete[] transactionHistory;
    }

    virtual void deposit(double amount)
    {
        balance += amount;
        if (transactionCount >= transactionCapacity)
        {
            transactionCapacity *= 2;
            string *newTransactionHistory = new string[transactionCapacity];
            for (int i = 0; i < transactionCount; ++i)
            {
                newTransactionHistory[i] = transactionHistory[i];
            }
            delete[] transactionHistory;
            transactionHistory = newTransactionHistory;
        }
        transactionHistory[transactionCount++] = "Deposited: " + to_string(amount);
    }

    virtual bool withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            if (transactionCount >= transactionCapacity)
            {
                transactionCapacity *= 2;
                string *newTransactionHistory = new string[transactionCapacity];
                for (int i = 0; i < transactionCount; ++i)
                {
                    newTransactionHistory[i] = transactionHistory[i];
                }
                delete[] transactionHistory;
                transactionHistory = newTransactionHistory;
            }
            transactionHistory[transactionCount++] = "Withdrew: " + to_string(amount);
            return true;
        }
        return false;
    }

    virtual void calculateInterest() {}

    void printStatement()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
        cout << "Transactions:" << endl;
        for (int i = 0; i < transactionCount; ++i)
        {
            cout << transactionHistory[i] << endl;
        }
    }

    void getAccountInfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string holderName, double initialBalance, double rate)
        : Account(accNum, holderName, initialBalance, "Savings"), interestRate(rate) {}

    void calculateInterest() override
    {
        double interest = balance * (interestRate / 100);
        balance += interest;
        if (transactionCount >= transactionCapacity)
        {
            transactionCapacity *= 2;
            string *newTransactionHistory = new string[transactionCapacity];
            for (int i = 0; i < transactionCount; ++i)
            {
                newTransactionHistory[i] = transactionHistory[i];
            }
            delete[] transactionHistory;
            transactionHistory = newTransactionHistory;
        }
        transactionHistory[transactionCount++] = "Interest Added: " + to_string(interest);
    }
};

class CheckingAccount : public Account
{
private:
    double minimumBalance;

public:
    CheckingAccount(string accNum, string holderName, double initialBalance, double minBalance)
        : Account(accNum, holderName, initialBalance, "Checking"), minimumBalance(minBalance) {}

    bool withdraw(double amount) override
    {
        if (balance - amount >= minimumBalance)
        {
            balance -= amount;
            if (transactionCount >= transactionCapacity)
            {
                transactionCapacity *= 2;
                string *newTransactionHistory = new string[transactionCapacity];
                for (int i = 0; i < transactionCount; ++i)
                {
                    newTransactionHistory[i] = transactionHistory[i];
                }
                delete[] transactionHistory;
                transactionHistory = newTransactionHistory;
            }
            transactionHistory[transactionCount++] = "Withdrew: " + to_string(amount);
            return true;
        }
        return false;
    }
};

class FixedDepositAccount : public Account
{
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(string accNum, string holderName, double initialBalance, double rate, string maturity)
        : Account(accNum, holderName, initialBalance, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    void calculateInterest()
    {
        double interest = balance * (fixedInterestRate / 100);
        balance += interest;
        if (transactionCount >= transactionCapacity)
        {
            transactionCapacity *= 2;
            string *newTransactionHistory = new string[transactionCapacity];
            for (int i = 0; i < transactionCount; ++i)
            {
                newTransactionHistory[i] = transactionHistory[i];
            }
            delete[] transactionHistory;
            transactionHistory = newTransactionHistory;
        }
        transactionHistory[transactionCount++] = "Interest Added: " + to_string(interest);
    }

    void printStatement()
    {
        Account::printStatement();
        cout << "Maturity Date: " << maturityDate << endl;
    }
};

int main()
{
    SavingsAccount savings("SA123", "John Doe", 1000.0, 5.0);
    CheckingAccount checking("CA123", "Alice Smith", 500.0, 100.0);
    FixedDepositAccount fixedDeposit("FDA123", "Bob Johnson", 2000.0, 6.0, "2026-12-31");

    savings.deposit(200);
    savings.withdraw(150);
    savings.calculateInterest();
    savings.printStatement();

    cout << "\n";

    checking.deposit(300);
    checking.withdraw(600);
    checking.printStatement();

    cout << "\n";

    fixedDeposit.deposit(500);
    fixedDeposit.calculateInterest();
    fixedDeposit.printStatement();

    return 0;
}
