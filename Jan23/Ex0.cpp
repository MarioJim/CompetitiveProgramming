#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long numer, denom, decimals, tempRes, res;
    for (int i = 0; i < t; i++)
    {
        cin >> numer >> denom >> decimals;
        res = 1;
        numer %= denom;
        for (int j = 0; j < decimals; j++)
        {
            numer *= 10;
            tempRes = numer / denom;
            res *= (tempRes == 0) ? 1 : tempRes;
            res %= 188888881;
            numer %= denom;
        }
        cout << res << endl;
    }
    return 0;
}