#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int tests[n];
    for (int i = 0; i < n; ++i) cin >> tests[i];
    int numProblems = 0;
    int first = 0;
    for (; first < n; ++first) {
        if (tests[first] > m) break;
        ++numProblems;
    }
    for (int i = n - 1; i > first; --i) {
        if (tests[i] > m) break;
        ++numProblems;
    }
    cout << numProblems << endl;
    return 0;
}
