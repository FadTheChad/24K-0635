#include <iostream>

using namespace std;

class Shape
{
protected:
    float position[2];
    string color;
    float borderThickness;

public:
    Shape(float pos[2], string c, float bT = 0) : color(c), borderThickness(bT)
    {
        position[0] = pos[0];
        position[1] = pos[1];
    }

    virtual void draw() {};
    virtual float calculateArea() {};
    virtual float calculatePerimeter() {};
};

class Circle : public Shape
{
};

int main()
{
}