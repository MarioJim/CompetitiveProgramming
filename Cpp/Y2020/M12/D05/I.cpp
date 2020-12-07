#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    sort(n, n + 3);
    if (n[0] >= 500) {
        cout << n[0] + n[1] + n[2] - 300 << endl;
    } else if (n[0] + n[1] >= 500 && n[2] >= 500) {
        cout << n[0] + n[1] + n[2] - 200 << endl;
    } else if (n[0] + n[1] + n[2] >= 500) {
        cout << n[0] + n[1] + n[2] - 100 << endl;
    } else {
        cout << n[0] + n[1] + n[2]  << endl;
    }

}
