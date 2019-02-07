// BALLSUM @ spoj.com
// https://www.spoj.com/problems/BALLSUM/

#include <iostream>
using namespace std;

long gcda(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcda(b, a % b);
}

int main()
{
    long long n, k, numer, denom;
    cin >> n >> k;

    while (n != -1 || k != -1)
    {
        if (k < 3)
            cout << "0\n";
        else
        {
            numer = ((k - 1) * (k - 1)) / 4;
            denom = n * (n - 1) / 2;

            long divis = gcda(numer, denom);

            cout << numer / divis << "/" << denom / divis << "\n";
        }
        cin >> n >> k;
    }
    return 0;
}
