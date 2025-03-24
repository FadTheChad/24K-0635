#include <iostream>
#include <string>

using namespace std;

class Device
{
protected:
    string id;
    string type;
    double powerRating;
    bool status;

public:
    Device(string i, string t, double p) : id(i), type(t), powerRating(p), status(false)
    {
    }

    virtual void turnOn()
    {
        status = true;
    }

    virtual void turnOff()
    {
        status = false;
    }

    virtual double calculatePowerUsage(int hours) = 0;
};

class Light : public Device
{
public:
    double calculatePowerUsage(int hours)
    {
        return powerRating * hours;
    }
};

class Fan : public Device
{
private:
    int speedFactor;

public:
    Fan(string i, string t, double p, int sF) : Device(i, t, p), speedFactor(sF)
    {
    }

    double calculatePowerUsage(int hours)
    {
        return powerRating * hours * speedFactor;
    }
};

class AC : public Device
{
private:
    float currentTemp;
    float desiredTemp;

public:
    AC(string i, string t, double p, float dT) : Device(i, t, p), desiredTemp(dT)
    {
    }

    void turnOn()
    {
        status = true;
        cout << "Current Temp: ";
        cin >> currentTemp;
    }

    double calculatePowerUsage(int hours)
    {
        return powerRating * hours * (1 - (currentTemp - desiredTemp) / 100);
    }
};

class SecuritySystem : public Device
{
private:
    int userAccessLvl;
    string userRole;
    string logs; // Logs stored as a single string

public:
    friend class MaintainanceTool;
    friend void accessSecurityLogs(const SecuritySystem &system);

    SecuritySystem(string i, string t, double p, float u, string uR) : Device(i, t, p), userAccessLvl(u), userRole(uR), logs("")
    {
    }

    void turnOff()
    {
        if (userAccessLvl == 0)
        {
            cout << "Not Authorized" << endl;
            logs += "Unauthorized attempt to turn off the system.\n";
            return;
        }

        status = false;
        logs += "System turned off.\n";
    }

    double calculatePowerUsage(int hours)
    {
        if (userAccessLvl == 0)
        {
            cout << "Not Authorized" << endl;
            logs += "Unauthorized attempt to calculate power usage.\n";
            return 0;
        }

        double usage = powerRating * hours;
        logs += "Power usage calculated: " + to_string(usage) + " units.\n";
        return usage;
    }
};

class MaintainanceTool
{
private:
    string userRole;

public:
    MaintainanceTool(string u) : userRole(u)
    {
    }

    void reset(SecuritySystem &system)
    {
        if (userRole != "Maintenance")
        {
            cout << "Not authorized";
            return;
        }

        system.logs = "";
        cout << "Cleared" << endl;
    }
};

void accessSecurityLogs(const SecuritySystem &system)
{
    if (system.userRole != "Maintenance")
    {
        cout << "Not authorized";
        return;
    }

    cout << "Accessing logs:\n"
         << system.logs;
}

int main()
{
}
