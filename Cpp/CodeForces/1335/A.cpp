#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        long candies;
        cin >> candies;
        cout << max((candies - 1) / 2, 0l) << "\n";
    }
}