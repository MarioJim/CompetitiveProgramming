#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n;
        cin >> n;
        int r = ceil(2*(sqrt(n) - 1));
        cout << r << "\n";
    }
}
