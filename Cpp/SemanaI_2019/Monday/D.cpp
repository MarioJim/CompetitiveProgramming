#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int broken[n];
    for (int i = 0; i < n; ++i)
        cin >> broken[i];
    int spaces[n-1];
    for (int i = 0; i < n - 1; ++i)
        spaces[i] = broken[i + 1] - broken[i] - 1;
    sort(spaces, spaces + n - 1, greater<int>());
    int brokenLength = broken[n-1] - broken[0] + 1;
    for (int i = 0; i < k - 1; ++i)
        brokenLength -= spaces[i];
    cout << brokenLength << endl;
    return 0;
}
