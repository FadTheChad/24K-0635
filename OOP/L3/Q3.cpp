#include <iostream>

using namespace std;

int objectCount = 0;

class SerialNumberedObject
{
private:
    int serialNumber;

public:
    SerialNumberedObject()
    {
        serialNumber = ++objectCount;
    }

    void report() const
    {
        cout << "I am object number " << serialNumber << endl;
    }
};

int main()
{
    SerialNumberedObject obj1, obj2, obj3;

    obj1.report();
    obj2.report();
    obj3.report();

    return 0;
}