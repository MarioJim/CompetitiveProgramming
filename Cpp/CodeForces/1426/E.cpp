#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[3], b[3];
    for (int & i : a) cin >> i;
    for (int & i : b) cin >> i;
    int minimum = n, maximum = 0;
    for (int i = 0; i < 3; ++i) {
        maximum += min(a[i], b[(i+1)%3]);
    }
    for (int i = 0; i < 3; ++i) {
        if (a[(i+1)%3] < b[i]) {
            minimum -= a[(i+1)%3];
            a[(i+1)%3] = 0;
        } else {
            minimum -= b[i];
            b[i] = 0;
        }
    }
    for (int i = 0; i < 3; ++i) {
        minimum -= min(a[i], b[i]);
    }
    minimum = max(0, minimum);
    cout << minimum << " " << maximum << "\n";
}
