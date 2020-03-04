#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int indexes[m];
        for (int i = 0; i < m; ++i) cin >> indexes[i];
        sort(indexes, indexes + m);
        deque<int> tries;
        for (int i = 0; i < m; ++i) tries.push_back(indexes[i]);
        long timesPressed[26];
        fill(timesPressed, timesPressed + 26, 0);
        for (int i = 0; i < n; ++i) {
            while (!tries.empty() && i == tries.front())
                tries.pop_front();
            int curr = s[i] - 'a';
            timesPressed[curr] += tries.size() + 1;
        }
        cout << timesPressed[0];
        for (int i = 1; i < 26; ++i)
            cout << " " << timesPressed[i];
        cout << "\n";
    }
}
