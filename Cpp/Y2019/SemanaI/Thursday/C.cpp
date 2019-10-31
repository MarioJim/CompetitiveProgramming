#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; ++i)
        cin >> coins[i];
    long long counter = 0;
    int zeroes = 0, negatives = 0;
    for (int i = 0; i < n; ++i) {
        if (coins[i] < 0) ++negatives;
        if (coins[i] != 0) counter += abs(coins[i]) - 1;
        else ++zeroes;
    }
    if (zeroes > 0) {
        counter += zeroes;
    } else if (negatives % 2 == 1) {
        counter += 2;
    }
    cout << counter << endl;
    return 0;
}
