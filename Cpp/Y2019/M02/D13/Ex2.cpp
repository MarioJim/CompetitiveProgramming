// Distinct primes @ spoj.com
// https://www.spoj.com/problems/AMR11E/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int t, x;
    cin >> t;

    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};
    cout << sizeof(primes) / sizeof(primes[0]) << "\n";

    set<int> luckyNums;

    for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); ++i)
    {
        for (int j = i + 1; j < sizeof(primes) / sizeof(primes[0]); ++j)
        {
            for (int k = j + 1; k < sizeof(primes) / sizeof(primes[0]); ++k)
            {
                luckyNums.insert(primes[i] * primes[j] * primes[k]);
                cout << "i: " << primes[i] << ", j: " << primes[j] << ", k:" << primes[k] << ", result: " << primes[i] * primes[j] * primes[k] << "\n";
                if (luckyNums.size() > 100)
                    break;
            }
            if (luckyNums.size() > 100)
                break;
        }
        if (luckyNums.size() > 100)
            break;
    }

    for (int i = 0; i < t; i++)
    {
        cin >> x;
        // for (auto elem : luckyNums)
        // {
        //     cout << elem << " , ";
        // }
        // cout << "\n";
    }

    return 0;
}