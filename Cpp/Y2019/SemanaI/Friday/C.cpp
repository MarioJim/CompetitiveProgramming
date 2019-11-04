#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];
    for (int i = 2; i < 100100; ++i) {
        bool prime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime)
            primes.push_back(i);
    }
    long long minDiff = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long diff = 0;
        for (int j = 0; j < m; ++j) {
            diff += *lower_bound(primes.begin(), primes.end(), arr[i][j]) - arr[i][j];
        }
        minDiff = min(diff, minDiff);
    }
    for (int i = 0; i < m; ++i) {
        long long diff = 0;
        for (int j = 0; j < n; ++j) {
            diff += *lower_bound(primes.begin(), primes.end(), arr[j][i]) - arr[j][i];
        }
        minDiff = min(diff, minDiff);
    }
    cout << minDiff << endl;
    return 0;
}
