#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool occuppied[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            occuppied[i][j] = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        r--; c --;
        if (d == 0) {
            for (int j = 0; j < l; ++j) {
                if (r >= 10 || c + j >= 10 || occuppied[r][c+j]){
                    cout << "N\n";
                    return 0;
                }
                occuppied[r][c+j] = true;
            }
        } else {
            for (int j = 0; j < l; ++j) {
                if (r + j >= 10 || c >= 10 || occuppied[r+j][c]){
                    cout << "N\n";
                    return 0;
                }
                occuppied[r+j][c] = true;
            }
        }
    }
    cout << "Y\n";
}
