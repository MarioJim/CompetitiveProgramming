#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n;
        cin >> n;
        int weights[n];
        for (int i = 0; i < n; ++i)
            cin >> weights[i];
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        sort(weights, weights + n);
        int maxTeams = 0;
        int minWeight = weights[0] + weights[1];
        int maxWeight = weights[n - 1] + weights[n - 2];
        for (int sum = minWeight; sum <= maxWeight; ++sum) {
            int teams = 0;
            int idx1 = 0, idx2 = n - 1;
            while (idx1 < idx2) {
                int currSum = weights[idx1] + weights[idx2];
                if (currSum == sum) {
                    teams++;
                    idx1++;
                    idx2--;
                } else if (currSum < sum) {
                    idx1++;
                } else {
                    idx2--;
                }
            }
            maxTeams = max(teams, maxTeams);
        }
        cout << maxTeams << "\n";
    }
}
