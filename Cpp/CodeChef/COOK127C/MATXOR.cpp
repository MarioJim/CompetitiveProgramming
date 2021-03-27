#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long result = 0;
    auto [low, high] = minmax(n, m);
    for (int i = 0; i < low / 2; ++i) {
      result ^= k + 2 * (i + 1);
      result ^= k + (low - i) + (high - i);
    }
    if (low % 2 == 1) {
      int midLow = (low + 1) / 2;
      for (int i = midLow; i <= high - midLow + 1; ++i) {
        result ^= k + midLow + i;
      }
    }
    cout << result << endl;
  }
}
