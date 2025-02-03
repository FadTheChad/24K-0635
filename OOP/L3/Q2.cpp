#include <iostream>
#include <conio.h>

using namespace std;

class TollBooth
{
private:
    unsigned int totalCars;
    double amount;

public:
    TollBooth()
    {
        totalCars = 0;
        amount = 0;
    }

    void payingCar()
    {
        totalCars++;
        amount += 0.50;
    }

    void nopayCar()
    {
        totalCars++;
    }

    void display()
    {
        cout << "Total Cars: " << totalCars << endl;
        cout << "Amount: " << amount << endl;
    }
};

int main()
{
    TollBooth tb;
    while (true)
    {
        cout << "Enter (P for Pay | N for No Pay): ";
        char c = _getch();

        if (c == 27)
            break;

        if (c == 'P' || c == 'p')
        {
            tb.payingCar();
            cout << "Paid";
        }
        else if (c == 'N' || c == 'n')
        {
            tb.nopayCar();
            cout << "Not Paid";
        }

        cout << endl;
    }

    cout << endl;
    tb.display();
}