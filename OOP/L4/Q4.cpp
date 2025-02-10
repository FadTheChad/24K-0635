#include <iostream>

using namespace std;

class Car
{
private:
    int carID;
    string model;
    int year;
    bool isRented;

public:
    Car() : isRented(false) {}

    Car(int cID, string m, int y, bool rented = false)
        : carID(cID), model(m), year(y), isRented(rented) {}

    void rentCar()
    {
        isRented = true;
    }

    void returnCar()
    {
        isRented = false;
    }

    bool isVintage()
    {
        return year < 2000;
    }
};

int main()
{
    Car car1(101, "Toyota Corolla", 1998);
    Car car2(102, "Honda Civic", 2005);

    cout << "Car 1 is vintage: " << car1.isVintage() << endl;
    cout << "Car 2 is vintage: " << car2.isVintage() << endl;

    cout << "Renting Car 1..." << endl;
    car1.rentCar();
    cout << "Car 1 rented status: " << car1.isRented << endl;

    cout << "Returning Car 1..." << endl;
    car1.returnCar();
    cout << "Car 1 rented status: " << car1.isRented << endl;

    return 0;
}
