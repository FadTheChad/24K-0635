#include <iostream>
using namespace std;

// arr(9)=[0,1,2,3,4,5,6,7,8];
// xlength=j-i
// if arr[j]<arr[i]
// ylength=arr[j]
// else
// ylength=arr[i]
// area= xlength * ylength

int main()
{
    int n;
    int h, d, area = 0;
    int max_area = 0;

    cout << "Enter n: ";
    cin >> n;

    int *heights = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> heights[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            d = j - i;

            if (heights[i] < heights[j])
                h = heights[i];
            else
                h = heights[j];

            area = d * h;

            if (area > max_area)
                max_area = area;
        }
    }

    cout << "Max Area: " << max_area;
    return 0;
}