#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, radius;
    cin >> n >> radius;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int ans = 0;
    for (int heatedUntil = -1; heatedUntil < n - 1;) {
        int pos = -1;
        for (int i = n - 1; i > max(-1, heatedUntil - radius + 1); --i) {
            if (arr[i] == 1 && i - radius <= heatedUntil) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            ans = -1;
            break;
        }
        ans++;
        heatedUntil = pos + radius - 1;
    }
    cout << ans << "\n";
}