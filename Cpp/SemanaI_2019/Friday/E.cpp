#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s, t;
        cin >> s >> t;
        bool setS[26], setT[26];
        fill(setS, setS + 26, false);
        fill(setT, setT + 26, false);
        for (int j = 0; j < s.size(); ++j) {
            setS[s[j] - 'a'] = true;
            setT[t[j] - 'a'] = true;
        }
        bool canChange = false;
        for (int j = 0; j < 26; ++j) {
            if (setS[j] && setT[j])
                canChange = true;
        }
        if (canChange)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
