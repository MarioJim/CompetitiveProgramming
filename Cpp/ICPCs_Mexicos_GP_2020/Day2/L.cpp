#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, c;
    cin >> l >> c;
    vector<string> board;
    for (int i = 0; i < l; ++i) cin >> board[i];
    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; ++i) cin >> words[i];
    map<pair<int,int>, unordered_set<int>> resultMap;
    // Horizontal
    for (int i = 0; i < l; ++i) {
        for (int k = 0; k < words.size(); ++k) {
            // Horizontal
            if (l - i > words[k].size()) {
                multiset<char> lettersLeft(words[k].begin(), words[k].end());
                for (int m = 0; m < words[k].size(); ++m) {

                }
            }
            // Vertical


            // Diagonal


        }
    }
    int result = 0;
    for (const auto& it: resultMap)
        if (it.second.size() > 1)
            ++result;
    cout << result << "\n";
}
