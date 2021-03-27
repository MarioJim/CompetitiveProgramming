#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int x, sum, j;
    bool canFinish;

    for (int i = 0; i < t; i++)
    {
        canFinish = true;
        sum = 1;
        j = 2;
        cin >> x;
        while ((x - sum) % j != 0 && canFinish)
        {
            if (sum > x)
                canFinish = false;
            sum += j;
            j++;
        }
        if (canFinish)
            cout << (x - sum) / j << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}