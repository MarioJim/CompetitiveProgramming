#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, bonus;
    cin >> n >> bonus;
    int performance[n];
    for (int i = 0; i < n; ++i) cin >> performance[i];
    int result[n];
    fill(result, result + n, 1);
    for (int i = 0; i < n; ++i) {
        int lidx = i == 0 ? n - 1 : i - 1;
        if (performance[i] == 0)
            result[i] = 0;
        else if (performance[i] > performance[lidx])
            result[i] = result[lidx] + 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        int ridx = i == n - 1 ? 0 : i + 1;
        if (performance[i] > performance[ridx])
            result[i] = max(result[ridx] + 1, result[i]);
    }
    cout << result[0] * bonus;
    for (int i = 1; i < n; ++i) {
        cout << " " << result[i] * bonus;
    }
    cout << '\n';
}
