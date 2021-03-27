#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    bool canChange = true;
    int len = s.length();
    if (len != t.length())
        canChange = false;
    for (int i = 0; i < len; ++i) {
        bool sVowel = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u';
        bool tVowel = t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u';
        if (sVowel != tVowel) canChange = false;
    }
    cout << (canChange ? "Yes" : "No") << endl;
    return 0;
}
