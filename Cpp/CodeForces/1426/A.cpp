#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n, x;
        cin >> n >> x;
        n -= 2;
        if (n <= 0){
            cout << "1\n";
        } else {
            int floors = 1;
            while (n > 0) {
                n -= x;
                ++floors;
            }
            cout << floors << "\n";
        }
    }
}
