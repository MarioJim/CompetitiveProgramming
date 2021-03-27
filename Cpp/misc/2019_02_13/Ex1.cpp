// FCTRL @ spoj.com
// https://www.spoj.com/problems/FCTRL/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    long x, result;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> x;
        result = 0;
        int j = 0;
        while (pow(5, j) < x)
        {
            j++;
            result += x / pow(5, j);
        }
        cout << result << "\n";
    }

    return 0;
}