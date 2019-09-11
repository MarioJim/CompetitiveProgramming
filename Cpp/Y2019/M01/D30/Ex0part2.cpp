#include <iostream>
using namespace std;

int main()
{
    long t, numer, denom, decimals, periodMult, periodLength;
    long res;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> numer >> denom >> decimals;
        numer %= denom;
        res = 1;
        periodMult = 1;
        periodLength = 0;
        bool foundMod[denom];
        for (int j = 0; j < denom; ++j)
            foundMod[j] = false;
        // Encontrar periodo en periodMult
        while (!foundMod[numer])
        {
            foundMod[numer] = true;
            ++periodLength;
            numer *= 10;
            periodMult *= (numer / denom == 0) ? 1 : numer / denom;
            periodMult %= 188888881;
            numer %= denom;
        }
        // Multiplicar resultado por periodo, int dec/longDePer veces
        for (int j = 0; j < decimals / periodLength; ++j)
        {
            res *= periodMult;
            res %= 188888881;
        }
        // Multiplicar resultado por periodo, dec%longDePer veces
        for (int j = 0; j < decimals % periodLength; ++j)
        {
            numer *= 10;
            res *= (numer / denom == 0) ? 1 : numer / denom;
            res %= 188888881;
            numer %= denom;
        }
        cout << periodMult << ", " << periodLength << "\n";
        cout << res << "\n";
    }
    return 0;
}