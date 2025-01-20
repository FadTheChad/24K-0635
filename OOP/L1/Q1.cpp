/*
Q1: Write a C++ program to check whether a given number is prime or not. Allow
the user to input a number and display whether it's prime or not?
*/

#include <iostream>

using namespace std;

bool is_prime(int x)
{
    if (x <= 1)
        return false;

    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int x;

    cout << "Enter x: ";
    cin >> x;

    cout << (is_prime(x) ? "Prime" : "Not prime");
    return 0;
}