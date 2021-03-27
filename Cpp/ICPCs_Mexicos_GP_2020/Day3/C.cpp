#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        long long n, k;
        cin >> n >> k;
        long long r = ((n + 2) * (n + 1)) / 2;
        r %= 1000000007;
        r *= k + 1;
        r %= 1000000007;
        cout << r << "\n";
    }
}
