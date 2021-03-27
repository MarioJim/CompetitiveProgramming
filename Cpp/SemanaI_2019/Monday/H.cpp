#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; ++i) {
        long long n, m;
        cin >> n >> m;
        if (n == m + 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
