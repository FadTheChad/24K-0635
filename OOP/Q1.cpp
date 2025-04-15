#include <iostream>

using namespace std;

class Vehicle
{
protected:
    string model;
    double rate;

public:
    Vehicle(string m, double r) : model(m), rate(r) {}
    virtual ~Vehicle() {}

    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
};

class Car : public Vehicle
{
public:
    Car(string m, double r) : Vehicle(m, r) {}

    double getDailyRate()
    {
        return rate;
    }

    void displayDetails()
    {
        cout << "Car Model: " << model << endl;
        cout << "Rate: " << rate << endl;
    }
};

class Bike : public Vehicle
{
public:
    Bike(string m, double r) : Vehicle(m, r) {}

    double getDailyRate()
    {
        return rate;
    }

    void displayDetails()
    {
        cout << "Bike Model: " << model << endl;
        cout << "Rate: " << rate << endl;
    }
};

int main()
{
    Car c("Honda Civic", 15000000);
    Bike b("Sanchez", 345000);

    c.displayDetails();

    cout << endl;

    b.displayDetails();
}