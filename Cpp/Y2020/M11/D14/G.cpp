#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int maxBalance = 100;
    int balance = 100;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        balance += x;
        maxBalance = max(maxBalance, balance);
    }
    cout << maxBalance << endl;
}
