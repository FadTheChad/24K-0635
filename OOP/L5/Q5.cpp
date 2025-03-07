#include <iostream>

using namespace std;

class Engine
{
private:
    bool started;

public:
    Engine()
    {
        started = false;
        cout << "Engine installed" << endl;
    }

    void start()
    {
        if (!started)
        {
            started = true;
            cout << "Engine started" << endl;
        }
    }

    void stop()
    {
        if (started)
        {
            started = false;
            cout << "Engine stopped" << endl;
        }
    }

    ~Engine()
    {
        started = false;
        cout << "Engine uninstalled" << endl;
    }
};

class Wheel
{
private:
    bool inflated;

public:
    Wheel()
    {
        inflated = true;
        cout << "Wheel installed" << endl;
    }

    void inflate()
    {
        if (!inflated)
        {
            inflated = true;
            cout << "Wheel inflated" << endl;
        }
    }

    void deflate()
    {
        if (inflated)
        {
            inflated = false;
            cout << "Wheel deflated" << endl;
        }
    }

    ~Wheel()
    {
        inflated = false;
        cout << "Wheel uninstalled" << endl;
    }
};

class Headlights
{
private:
    bool on;

public:
    Headlights()
    {
        on = false;
        cout << "Headlights installed" << endl;
    }

    void turnOn()
    {
        if (!on)
        {
            on = true;
            cout << "Headlights turned on" << endl;
        }
    }

    void turnOff()
    {
        if (on)
        {
            on = false;
            cout << "Headlights turned off" << endl;
        }
    }

    ~Headlights()
    {
        on = false;
        cout << "Headlights uninstalled" << endl;
    }
};

class Steering
{
private:
    bool functional;

public:
    Steering()
    {
        functional = true;
        cout << "Steering installed" << endl;
    }

    void lock()
    {
        if (functional)
        {
            functional = false;
            cout << "Steering locked" << endl;
        }
    }

    void unlock()
    {
        if (!functional)
        {
            functional = true;
            cout << "Steering unlocked" << endl;
        }
    }

    ~Steering()
    {
        functional = false;
        cout << "Steering uninstalled" << endl;
    }
};

class Car
{
private:
    Engine *engine;
    Wheel *wheels[4];
    Headlights headlights;
    Steering steering;

public:
    // Constructor that uses pointers for aggregation and direct objects for composition
    Car(Engine *engine, Wheel *wheels[4])
        : engine(engine)
    {
        for (int i = 0; i < 4; ++i)
        {
            this->wheels[i] = wheels[i];
        }
    }

    void startCar()
    {
        engine->start();
        headlights.turnOn();
        cout << "Car is starting..." << endl;
    }

    void drive()
    {
        steering.unlock();
        cout << "Driving the car..." << endl;
    }

    void stopCar()
    {
        headlights.turnOff();
        cout << "Car is stopping..." << endl;
    }
};

int main()
{
    Engine engine;
    Wheel wheel1, wheel2, wheel3, wheel4;
    Wheel *wheels[4] = {&wheel1, &wheel2, &wheel3, &wheel4};

    Car car(&engine, wheels);

    car.startCar();
    car.drive();
    car.stopCar();

    return 0;
}
