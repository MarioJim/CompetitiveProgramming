#include <bits/stdc++.h>
using namespace std;

int main() {
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; ++i) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 2 && s[0] >= s[1]) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n2\n";
        cout << s[0] << " " << s.substr(1, n) << "\n";
    }
    return 0;
}
