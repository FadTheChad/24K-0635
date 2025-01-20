/*
Q3: Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may
not use the same element twice.You can return the answer in any order.
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    int target;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter target: ";
    cin >> target;

    int *nums = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                cout << "[" << i << ", " << j << "]";
                return 0;
            }
        }
    }

    cout << "No pair found";
}