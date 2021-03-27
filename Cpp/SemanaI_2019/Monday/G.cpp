#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> team, possibleIndexes;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        pair<set<int>::iterator, bool> wasInserted = team.insert(temp);
        if (wasInserted.second)
            possibleIndexes.insert(i + 1);
    }
    if (team.size() >= k) {
        cout << "YES\n";
        int count = 0;
        for (auto it = possibleIndexes.begin(); count < k; ++it) {
            cout << *it << " ";
            ++count;
        }
        cout << endl;
    } else cout << "NO\n";
    return 0;
}
