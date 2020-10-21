#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 2; i < n; ++i) {
        if (i * 2 == n)
            continue;
        ans *= i;
    }
    cout << ans << "\n";
}
