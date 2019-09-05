#include <iostream>
#include <cmath>

using namespace std;

long long factorial(int top, int bot, int bot2);

int main(int argc, char **argv)
{
    int tests, n, k, maxDiv, minDiv;
    long long result;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> n >> k;
        maxDiv = max(n - k, k - 1);
        minDiv = min(n - k, k - 1);
        result = factorial(n - 1, maxDiv, minDiv);
        cout << result << endl;
    }
    return 0;
}

long long factorial(int top, int bot, int bot2)
{
    long long result = 1;
    int bot2counter = 1;
    for (int i = bot + 1; i <= top; i++)
    {
        result *= i;
        if (bot2counter <= bot2)
        {
            result /= bot2counter;
            bot2counter++;
        }
    }
    return result;
}
