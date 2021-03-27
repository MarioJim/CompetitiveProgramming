#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n, m;
        cin >> n >> m;
        int tiles[n][4];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> tiles[i][j];
            }
        }
        if (m % 2 == 1) {
            cout <<"NO\n";
            continue;
        }
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (tiles[i][1] == tiles[i][2]) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout <<"NO\n";
        }
    }
}
