#include <iostream>
#include <cmath>
using namespace std;

// Stein's Algorithm
long gcd(int v, int u)
{
    int twoPow = 0;
    if (u <= 1)
        return v;
    if (v <= 1)
        return u;
    for (; (u % 2 == 0) && (v % 2 == 0); ++twoPow)
    {
        u /= 2;
        v /= 2;
    }
    while (u % 2 == 0)
        u /= 2;
    do
    {
        while (v % 2 == 0)
            v /= 2;
        if (u > v)
        {
            int t = v;
            v = u;
            u = t;
        }
        v = v - u;
    } while (v != 0);
    return u * pow(2, twoPow);
}

int main()
{
    int nums[2];
    cin >> nums[0] >> nums[1];
    while (nums[0] != -1 && nums[1] != -1)
    {
        cout << gcd(nums[0], nums[1]) << endl;
        cin >> nums[0] >> nums[1];
    }
    return 0;
}