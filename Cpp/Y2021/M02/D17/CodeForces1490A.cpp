#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    long long n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) cin >> array[i];
    long long needed = 0;
    for (int i = 0; i < n - 1; ++i) {
      auto [a, b] = minmax(array[i], array[i+1]);
      if (a == b) continue;
      double log2Diff = log2(b / (double) a);
      needed += ceil(log2Diff - 1);
    }
    cout << needed << endl;
  }
}