#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> triangularNums;
    for (int i = 1; i * (i + 1) / 2 <= n; ++i) {
        triangularNums.push_back(i * (i + 1) / 2);
    }
    for (int i = 0; i < triangularNums.size(); ++i) {
        if (binary_search(triangularNums.begin(), triangularNums.end(), n - triangularNums[i])) {
            cout << "YES\n";
            return 0;
        }
    }
    cout <<"NO\n";
    return 0;
}
