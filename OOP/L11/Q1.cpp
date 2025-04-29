#include <iostream>

using namespace std;

class InvalidValueException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Value should be between 0-120";
    }
};

void validateAge(int age)
{
    if (age < 0 || age > 120) throw InvalidValueException();

    cout << "OK" << endl;
}

int main()
{
    int age;

    cin >> age;
    
    validateAge(age);
}