#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int h;
        cin >> h;
        int houses[h];
        for (int i = 0; i < h; ++i) {
            cin >> houses[i];
        }
        int dp[h+1];
        dp[0] = 0;
        dp[1] = houses[0];
        for (int i = 1; i < h; ++i) {
            dp[i+1] = max(dp[i], dp[i-1] + houses[i]);
        }
        cout << dp[h] << "\n";
    }
}
