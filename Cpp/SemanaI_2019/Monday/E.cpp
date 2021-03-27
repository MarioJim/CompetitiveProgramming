#include <bits/stdc++.h>
using namespace std;

long long distTo(long long a, long long b, long long x, long long y) {
    long long diagonal = min(abs(a - x), abs(b - y));
    return abs(a - x) + abs(b - y) - diagonal;
}

int main() {
    long long n, x, y;
    cin >> n >> x >> y;
    long long distToWhite = distTo(1,1,x,y);
    long long distToBlack = distTo(n,n,x,y);
    if (distToBlack >= distToWhite) cout << "White\n";
    else cout << "Black\n";
    return 0;
}
