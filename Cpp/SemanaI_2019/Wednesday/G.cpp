#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin.clear(); cin.ignore();
    getline(cin, s);
    int count = 0, maxCount = 0;
    for (int j = 0; j < n; ++j) {
        if (s[j] == ' ') {
            maxCount = max(count, maxCount);
            count = 0;
        }
        if (s[j] >= 'A' && s[j] <= 'Z')
            ++count;
    }
    maxCount = max(count, maxCount);
    cout << maxCount << endl;
    return 0;
}
