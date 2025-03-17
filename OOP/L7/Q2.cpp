#include <iostream>
#include <cmath>

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

    virtual void draw() = 0;
    virtual float calculateArea() = 0;
    virtual float calculatePerimeter() = 0;
};

class Circle : public Shape
{
protected:
    float radius;

public:
    Circle(float r, float pos[2], string c, float bT) : radius(r), Shape(pos, c, bT) {}

    void draw()
    {
        cout << "Drawing a Circle at (" << position[0] << ", " << position[1] << ") with radius " << radius << endl;
    }

    float calculateArea()
    {
        return 3.14 * radius * radius;
    }

    float calculatePerimeter()
    {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape
{
protected:
    float width, height;

public:
    Rectangle(float w, float h, float pos[2], string c, float bT) : width(w), height(h), Shape(pos, c, bT) {}

    void draw()
    {
        cout << "Drawing a Rectangle at (" << position[0] << ", " << position[1] << ") with width " << width << " and height " << height << endl;
    }

    float calculateArea()
    {
        return width * height;
    }

    float calculatePerimeter()
    {
        return 2 * (width + height);
    }
};

class Triangle : public Shape
{
protected:
    float base, height;

public:
    Triangle(float b, float h, float pos[2], string c, float bT) : base(b), height(h), Shape(pos, c, bT) {}

    void draw()
    {
        cout << "Drawing a Triangle at (" << position[0] << ", " << position[1] << ") with base " << base << " and height " << height << endl;
    }

    float calculateArea()
    {
        return 0.5 * base * height;
    }

    float calculatePerimeter()
    {
        return 3 * base;
    }
};

class Polygon : public Shape
{
protected:
    float *sides;
    int numSides;

public:
    Polygon(float *s, int n, float pos[2], string c, float bT) : sides(s), numSides(n), Shape(pos, c, bT) {}

    void draw()
    {
        cout << "Drawing a Polygon with " << numSides << " sides at (" << position[0] << ", " << position[1] << ")" << endl;
    }

    float calculateArea()
    {
        float perimeter = 0;
        for (int i = 0; i < numSides; ++i)
        {
            perimeter += sides[i];
        }
        return perimeter * 1.0;
    }

    float calculatePerimeter()
    {
        float perimeter = 0;
        for (int i = 0; i < numSides; ++i)
        {
            perimeter += sides[i];
        }
        return perimeter;
    }
};

int main()
{
    float pos1[2] = {0, 0};
    Circle c(5.0, pos1, "Red", 1.0);
    c.draw();
    cout << "Area: " << c.calculateArea() << endl;
    cout << "Perimeter: " << c.calculatePerimeter() << endl;

    float pos2[2] = {2, 3};
    Rectangle r(4.0, 6.0, pos2, "Blue", 1.5);
    r.draw();
    cout << "Area: " << r.calculateArea() << endl;
    cout << "Perimeter: " << r.calculatePerimeter() << endl;

    float pos3[2] = {5, 5};
    Triangle t(3.0, 4.0, pos3, "Green", 0.5);
    t.draw();
    cout << "Area: " << t.calculateArea() << endl;
    cout << "Perimeter: " << t.calculatePerimeter() << endl;

    float sides[] = {3.0, 3.0, 3.0, 3.0};
    Polygon p(sides, 4, pos1, "Yellow", 2.0);
    p.draw();
    cout << "Area: " << p.calculateArea() << endl;
    cout << "Perimeter: " << p.calculatePerimeter() << endl;

    return 0;
}
