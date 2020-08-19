#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        for (int i = 0; i < n; ++i) {
            s.push_back('a' + i % b);
        }
        cout << s << '\n';
    }
}