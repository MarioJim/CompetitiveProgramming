#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n;
        cin >> n;
        short bookshelf[n];
        for (int i = 0; i < n; ++i) cin >> bookshelf[i];
        int zeros = 0;
        int currZeros = 0;
        int i = 0;
        while (bookshelf[i] == 0) {
            ++i;
        }
        for (; i < n; ++i) {
            if (bookshelf[i] == 0) {
                currZeros += 1;
            } else {
                zeros += currZeros;
                currZeros = 0;
            }
        }
        cout << zeros << "\n";
    }
}
