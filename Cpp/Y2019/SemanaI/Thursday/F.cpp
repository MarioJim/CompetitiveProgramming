#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    long long totalCost = 0, currentTank = 0;
    for (int i = 1; i <= n; ++i) {
        if (n - i > currentTank) {
            int toAdd = min(v, n - i) - currentTank;
            currentTank += toAdd;
            totalCost += i * toAdd;
        }
        --currentTank;
    }
    cout << totalCost << endl;
    return 0;
}
