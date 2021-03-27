#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int countA = 0, maxCountA = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (s[i] == 'a') ++countA;
        while (countA > k) {
            if (s[j] == 'a') --countA;
            ++j;
        }
        maxCountA = max(maxCountA, i - j + 1);
    }
    int countB = 0, maxCountB = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (s[i] == 'b') ++countB;
        while (countB > k) {
            if (s[j] == 'b') --countB;
            ++j;
        }
        maxCountB = max(maxCountB, i - j + 1);
    }
    cout << max(maxCountA, maxCountB) << endl;
    return 0;
}
