#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n;
        cin >> n;
        int piranhas[n];
        for (int i = 0; i < n; ++i) cin >> piranhas[i];
        bool found = false;
        for (int i = 0; i < n; ++i) {
            int size = piranhas[i];
            int l = i - 1;
            int r = i + 1;
            bool couldFinish = true;
            while (l >= 0 || r < n) { // l == -1 r == n
                if (l >= 0 && piranhas[l] < size) {
                    size += 1;
                    l -= 1;
                } else if (r < n && piranhas[r] < size) {
                    size += 1;
                    r += 1;
                } else {
                    couldFinish = false;
                    break;
                }
            }
            if (couldFinish) {
                cout << i + 1 << "\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "-1\n";
    }
}
