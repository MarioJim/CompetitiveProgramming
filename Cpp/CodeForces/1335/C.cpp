#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n;
        cin >> n;
        int maxSame = 0;
        unordered_map<int, int> students;
        for (int i = 0; i < n; ++i) {
            int s;
            cin >> s;
            maxSame = max(++students[s], maxSame);
        }
        int maxDifferent = students.size();
        if (maxDifferent == maxSame) {
            cout << maxDifferent - 1 << "\n";
        } else {
            cout << min(maxDifferent, maxSame) << "\n";
        }
    }
}