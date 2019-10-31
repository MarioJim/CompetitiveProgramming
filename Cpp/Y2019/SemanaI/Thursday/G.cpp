#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    bool lillies[n];
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        lillies[i] = c == '1';
    }
    int lastPos = 0, pos = 0, jumps = 0;
    while (pos != n - 1) {
        int lastPos = pos;
        for (int j = pos + 1; j < k + pos + 1 && j < n; ++j)
            if (lillies[j])
                lastPos = j;
        if (lastPos == pos) {
            cout << "-1\n";
            return 0;
        }
        pos = lastPos;
        ++jumps;
    }
    cout << jumps << endl;
    return 0;
}
