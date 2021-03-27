#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long c = n - (-3 + sqrt(9 + 8 * (n + k))) / 2;
    cout << c << endl;
    return 0;
}
