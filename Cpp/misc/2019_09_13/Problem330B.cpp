#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m;
    bool bits[n - 1];
    fill(bits, bits + n, false);
    for (int i = 0; i < 2 * m; ++i) {
        cin >> a;
        bits[a - 1] = true;
    }
    int possibleCenter = -1;
    for (int i = 0; i < n; ++i) {
        if (!bits[i]) {
            possibleCenter = i + 1;
            break;
        }
    }
    cout << n - 1 << "\n";
    if (possibleCenter != -1)
        for (int i = 0; i < n; ++i) {
            if (i + 1 == possibleCenter) continue;
            cout << i + 1 << " " << possibleCenter << "\n";
        }
    return 0;
}
