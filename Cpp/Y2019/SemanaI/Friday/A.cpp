#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        string s = to_string(i);
        set<char> setS(s.begin(), s.end());
        if (setS.size() == s.size()) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
