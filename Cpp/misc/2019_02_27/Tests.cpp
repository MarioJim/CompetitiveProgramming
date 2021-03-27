#include <iostream>
#include <algorithm>

using namespace std;

void testingPointers()
{
    int m = 1000;
    int n = 2000;
    int *x = &m;

    cout << "m: " << m << "\n";
    cout << "n: " << n << "\n";
    cout << "x: " << x << "\n";
    cout << "*x: " << *x << "\n";
    cout << "*x+1: " << *(x + 1) << "\n";
}

void testingBinarySearch()
{
    int *up, *low;
    int *nums = new int[10];
    for (int i = 0; i < 10; i++)
        nums[i] = i * 2;
    for (int i = 0; i < 10; i++)
        cout << nums[i] << " ";
    cout << "\n";
    up = upper_bound(nums, nums + 10, 6);
    low = lower_bound(nums, nums + 10, 6);
    cout << "Upper bound: " << up - nums << endl;
    cout << "Lower bound: " << low - nums << endl;
}

int main()
{
    testingBinarySearch();
    return 0;
}