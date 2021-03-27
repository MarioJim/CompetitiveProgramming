#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        int n;
        cin >> n;
        string binary;
        cin >> binary;
        int subseq_idx[n];
        int last_subseq_idx = 0;
        unordered_set<int> end_in_zero, end_in_one;
        for (int i = 0; i < n; ++i) {
            if (binary[i] == '1') {
                if (end_in_zero.empty()) {
                    subseq_idx[i] = ++last_subseq_idx;
                } else {
                    auto it = end_in_zero.begin();
                    subseq_idx[i] = *it;
                    end_in_zero.erase(it);
                }
                end_in_one.insert(subseq_idx[i]);
            } else {
                if (end_in_one.empty()) {
                    subseq_idx[i] = ++last_subseq_idx;
                } else {
                    auto it = end_in_one.begin();
                    subseq_idx[i] = *it;
                    end_in_one.erase(it);
                }
                end_in_zero.insert(subseq_idx[i]);
            }
        }
        cout << last_subseq_idx << "\n";
        for (int i = 0; i < n; ++i)
            cout << subseq_idx[i] << " ";
        cout << "\n";
    }
}
