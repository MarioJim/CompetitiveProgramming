#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    if (x > a) {
        cout << "NO\n";
        return 0;
    }
    a -= x;
    if (y > a + b) {
        cout << "NO\n";
        return 0;
    }
    b -= y;
    if (z > a + b + c) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}
