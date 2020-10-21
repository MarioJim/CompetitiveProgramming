#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n;
        cin >> n;
        bool allEqual = true;
        int districts[n];
        for (int i = 0; i < n; ++i) {
            cin >> districts[i];
            if (districts[i] != districts[0])
                allEqual = false;
        }
        if (allEqual) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        map<int, vector<int>> gangs;
        for (int i = 0; i < n; ++i) {
            gangs[districts[i]].push_back(i + 1);
        }
        int dist1 = -1, dist2 = -1;
        for (auto gang : gangs) {
            if (dist1 == -1)
                dist1 = gang.second[0];
            else if (dist2 == -1)
                dist2 = gang.second[0];
            else
                break;
        }
        int gangNum = 0;
        for (const auto& gang : gangs) {
            for (auto dist : gang.second) {
                if (gangNum == 0) {
                    cout << dist << " " << dist2 << "\n";
                } else if (dist != dist2) {
                    cout << dist << " " << dist1 << "\n";
                }
            }
            ++gangNum;
        }
    }
}
