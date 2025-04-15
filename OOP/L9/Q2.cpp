#include <iostream>
#include <string>

using namespace std;

class SmartDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice
{
private:
    bool isOn;
    int brightness;

public:
    LightBulb() : isOn(false), brightness(0) {}

    void turnOn() override
    {
        isOn = true;
        brightness = 50;
    }

    void turnOff() override
    {
        isOn = false;
        brightness = 0;
    }

    string getStatus() override
    {
        return "LightBulb - " + string(isOn ? "ON" : "OFF") +
               ", Brightness: " + to_string(brightness) + "%";
    }
};

class Thermostat : public SmartDevice
{
private:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(20.0) {}

    void turnOn() override
    {
        isOn = true;
    }

    void turnOff() override
    {
        isOn = false;
    }

    string getStatus() override
    {
        return "Thermostat - " + string(isOn ? "ON" : "OFF") +
               ", Temperature: " + to_string(temperature) + "°C";
    }
};

int main()
{
    LightBulb light;
    Thermostat thermo;

    light.turnOn();
    thermo.turnOn();

    cout << light.getStatus() << endl;
    cout << thermo.getStatus() << endl;

    light.turnOff();

    cout << light.getStatus() << endl;

    return 0;
}