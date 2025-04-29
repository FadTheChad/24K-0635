#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <iomanip> // For setprecision

using namespace std;

class InsufficientFundsException : public exception {
private:
    string message;

public:
    InsufficientFundsException(double deficitAmount) noexcept {
        stringstream ss;
        ss << fixed << setprecision(2); // Format deficit to 2 decimal places
        ss << "InsufficientFundsException - Insufficient balance: Short by $" << deficitAmount;
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

    // Virtual destructor
    virtual ~InsufficientFundsException() noexcept {}
};

template <typename T>
class BankAccount {
private:
    T balance;

public:
    BankAccount(T initialBalance) : balance(initialBalance) {}

    T getBalance() const {
        return balance;
    }

    void deposit(T amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit of $" << fixed << setprecision(2) << amount << " was successful. New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be greater than zero!" << endl;
        }
    }

    void withdraw(T amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive!" << endl;
            return;
        }
        if (amount > balance) {
            double deficit = static_cast<double>(amount - balance);
            throw InsufficientFundsException(deficit);
        }
        balance -= amount;
        cout << "Withdrawal of $" << fixed << setprecision(2) << amount << " was successful. Remaining balance: $" << balance << endl;
    }
};

int main() {
    BankAccount<double> myAccount(500.00);

    cout << fixed << setprecision(2); // Set output precision for currency
    cout << "Initial Balance: $" << myAccount.getBalance() << endl << endl;

    double requestedWithdrawal = 600.00;
    cout << "Attempting to withdraw $" << requestedWithdrawal << "..." << endl;

    try {
        myAccount.withdraw(requestedWithdrawal);
        cout << "Withdrawal was unexpectedly successful." << endl;
    } catch (const InsufficientFundsException& e) {
        cout << "Attempt to withdraw $" << requestedWithdrawal << ": " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
    }

    cout << "\nAttempting to withdraw $150.00..." << endl;
    try {
        myAccount.withdraw(150.00);
    } catch (const InsufficientFundsException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "\nFinal Balance: $" << myAccount.getBalance() << endl;

    return 0;
}
