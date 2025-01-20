#include <iostream>
using namespace std;

/*
Q4: You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
*/

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
