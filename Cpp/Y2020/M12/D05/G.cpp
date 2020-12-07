#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, r = 0;
    scanf("%lld", &n);
    long long table[n][4];
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", table[i], table[i] + 1, table[i] + 2);
        table[i][3] = table[i][0];
    }
    for (int i = 0; i < n; ++i) {
        for (long long j = table[i][1]; j <= table[i][2] && i + j < n; ++j) {
            table[i + j][3] = max(table[i + j][3], table[i][3] + table[i + j][0]);
        }
        r = max(r, table[i][3]);
    }
    printf("%lld\n", r);
}
