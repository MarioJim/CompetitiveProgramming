#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        int signL = l % 2 == 1 ? -1 : 1;
        int valAtL = (signL * 2 * l + signL - 1) / 4;
        int signR = r % 2 == 1 ? -1 : 1;
        int valAtR = (signR * 2 * r + signR - 1) / 4;
        cout << valAtR - valAtL << "\n";
    }
    return 0;
}
