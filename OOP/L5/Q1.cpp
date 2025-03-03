#include <iostream>

using namespace std;

class Square
{
private:
    float sideLength;
    float area;
    static float allAreas;

public:
    Square()
    {
        sideLength = 0;
        area = 0;
    }

    Square(float sL)
    {
        sideLength = sL;
    }

    float getSideLength() const { return sideLength; }
    float getArea() const { return area; }
    static float getAllAreas() { return allAreas; }

    void setSideLength(const float sL) { sideLength = sL; }
    void setArea(const float a) { area = a; }
    void setAllAreas(const float aA) { allAreas = aA; }

    void calcArea()
    {
        area = sideLength * sideLength;
        allAreas += area;
    }
};

float Square::allAreas = 0;

int main()
{
    Square s1(10), s2(15), s3(20);

    s1.calcArea();
    s2.calcArea();
    s3.calcArea();

    cout << "s1: " << s1.getArea() << endl;
    cout << "s2: " << s2.getArea() << endl;
    cout << "s3: " << s3.getArea() << endl;

    cout << "All Areas: " << Square::getAllAreas() << endl;
}