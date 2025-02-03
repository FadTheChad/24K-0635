#include <iostream>
#include <iomanip>
using namespace std;

class Angle
{
private:
    int degrees;
    float minutes;
    char direction;

public:
    Angle(int deg, float min, char dir) : degrees(deg), minutes(min), direction(dir) {}

    void getAngle()
    {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;
    }

    void displayAngle() const
    {
        cout << degrees << "\xF8" << fixed << setprecision(1) << minutes << "' " << direction << endl;
    }
};

int main()
{
    Angle angle(149, 34.8, 'W');

    angle.displayAngle();

    while (true)
    {
        angle.getAngle();
        angle.displayAngle();
    }

    return 0;
}
