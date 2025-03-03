#include <iostream>

using namespace std;

class LoanHelper
{
private:
    const float interestRate;
    float amount;
    float monthsLeft;

public:
    LoanHelper(float a, float m, float iR) : interestRate(iR)
    {
        amount = a;
        monthsLeft = m;
    }

    void calc()
    {
        if (monthsLeft <= 0)
        {
            cout << "Paid" << endl;
            return;
        }

        float monthly = (amount / monthsLeft) * (1 + (interestRate / 100));

        cout << "You have to pay " << monthly << " every month over the span of " << monthsLeft << " months";
    }
};

int main()
{
    float amount, monthsLeft, interestRate;
    cout << "Amount: ";
    cin >> amount;

    cout << "Months left: ";
    cin >> monthsLeft;

    cout << "Interest Rate: ";
    cin >> interestRate;

    LoanHelper lh(amount, monthsLeft, interestRate);

    lh.calc();
}