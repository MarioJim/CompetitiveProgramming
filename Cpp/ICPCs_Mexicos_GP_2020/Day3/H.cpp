#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, g;
    cin >> n >> g;
    int problems[n];
    for (int i = 0; i < n; ++i) cin >> problems[i];
    bool found[n+1];
    fill(found, found + n+1, true);
    int sumProblems = 0;
    for (int i = 0; i < n; ++i) sumProblems += problems[i];

    unordered_map<int, vector<vector<int>>> dict;
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0, count = 0;
        for (int j = 0; j <= n; ++j) {
            if (i & (1 << j)) {
                ++count;
                sum += problems[j];
            }
        }
        int grade = (sum * 100) / sumProblems;
        if (grade < g || !found[count]) continue;
        vector<int> probs = {grade};
        for (int j = 0; j <= n; ++j)
            if (i & (1 << j))
                probs.push_back(j);
        if (found[count+1])
            for (int j = count+1; j <= n; ++j)
                found[j] = false;
        dict[count].push_back(probs);
    }
    auto el = dict.begin();
    cout << el->first << " " << el->second.size() << "\n";
    for (auto & it : el->second) {
        cout << it[0];
        for (int i = 1; i < it.size(); ++i) {
            cout << " " << it[i] + 1;
        }
        cout << "\n";
    }
}
