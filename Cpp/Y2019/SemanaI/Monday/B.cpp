#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int positive = 0, negative = 0, temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp > 0) ++positive;
        if (temp < 0) ++negative;
    }
    if (positive >= (n+1)/2)
        cout << "1\n";
    else if (negative >= (n+1)/2)
        cout << "-1\n";
    else
        cout << "0\n";
    return 0;
}
