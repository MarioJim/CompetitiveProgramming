#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long cost[n];
    for (int i = 0; i < n; ++i)
        cin >> cost[i];
    int forest[n];
    for (int i = 0; i < n; ++i) {
        forest[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int friend1, friend2;
        cin >> friend1 >> friend2;
        --friend1; --friend2;
        for (int j = 0; j < n; ++j)
            if (forest[j] == friend2)
                forest[j] = forest[friend1];
    }
    map<int, long long> minCosts;
    for (int i = 0; i < n; ++i) {
        auto it = minCosts.find(forest[i]);
        if (it == minCosts.end()) {
            minCosts.insert({ forest[i], cost[i] });
        } else {
            minCosts.insert_or_assign(forest[i], min(it->second, cost[i]));
        }
    }
    long long totalCost = 0;
    for (auto it = minCosts.begin(); it != minCosts.end(); ++it) {
        totalCost += it->second;
    }
    cout << totalCost << endl;
    return 0;
}
